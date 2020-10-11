#include "newattentiondialog.h"
#include "ui_newattentiondialog.h"
#include "hysmainwindow.h"
#include "hysdb.h"
#include "models/attentionmodel.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

NewAttentionDialog::NewAttentionDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NewAttentionDialog)
{
    ui->setupUi(this);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("添加人工记录"));
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    this->ui->inEvent->addItem(QString::fromLocal8Bit("工况变化"), HysMainWindow::EventType::CONDITION);
    this->ui->inEvent->addItem(QString::fromLocal8Bit("探测方式变化"), HysMainWindow::EventType::PROBE);
    this->ui->inEvent->addItem(QString::fromLocal8Bit("人工记录"), HysMainWindow::EventType::MANUAL);
}

NewAttentionDialog::~NewAttentionDialog()
{
    delete ui;
}

void NewAttentionDialog::setDatum(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;
}

void NewAttentionDialog::on_btnSave_clicked()
{
    int eventType = this->ui->inEvent->currentData().toInt();
    QDateTime time = this->ui->inCrawlTime->dateTime();
    QString longitude = this->ui->inLong->text();
    QString latitude = this->ui->inLati->text();
    QString comment = this->ui->inComment->toPlainText();

    if (longitude.isEmpty() || latitude.isEmpty()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("添加人工记录"), QString::fromLocal8Bit("必填项不能为空！"));
        return;
    }

    double lng = longitude.toDouble();
    double lat = latitude.toDouble();

    AttentionModel *model = new AttentionModel(this, HysDbHelper::getInstance()->getDb());
    QSqlRecord record = model->record();
    record.setGenerated("id", false);
    record.setValue("task_id", this->taskId);
    record.setValue("event_type", eventType);
    record.setValue("target_id", this->targetId);
    record.setValue("crawl_time", time.toString("yyyy-MM-dd hh:mm:ss"));
    record.setValue("longitude", lng);
    record.setValue("latitude", lat);
    record.setValue("comment", comment);

    QDateTime now = QDateTime::currentDateTime();
    QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
    record.setValue("created_time", nowStr);
    record.setValue("modified_time", nowStr);

    model->insertRecord(-1, record);

    bool result = model->submitAll();
    delete model;

    if (result) {
        QMessageBox::information(this, QString::fromLocal8Bit("完成"), QString::fromLocal8Bit("保存成功"));
        close();
    } else {
        qDebug()<<model->lastError().text();
        QMessageBox::critical(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("保存失败，请检查数据！"));
    }

}
