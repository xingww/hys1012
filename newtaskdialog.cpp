#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"
#include "hysmainwindow.h"
#include "hysdb.h"
#include <QtCore/qmath.h>
#include <QMessageBox>
#include <QSqlDriver>
#include <QDebug>
#include <QSqlQuery>

NewTaskDialog::NewTaskDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NewTaskDialog)
{
    ui->setupUi(this);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Raised);
    setLineWidth(2);
    setMidLineWidth(2);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("新建任务"));
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    installEventFilter(ui->titleBar);

    this->ui->cbSonarType->insertItem(0, QString::fromLocal8Bit("3X9"), HysMainWindow::X39);
    this->ui->cbSonarType->insertItem(1, QString::fromLocal8Bit("3X1"), HysMainWindow::X31);
    this->ui->cbSonarType->insertItem(2, QString::fromLocal8Bit("2X5"), HysMainWindow::X25);
    this->ui->cbSonarType->setCurrentIndex(-1);
}

NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}

void NewTaskDialog::clearTxt()
{
    this->ui->inTitle->clear();
    this->ui->inAbbr->clear();
    this->ui->inArea->clear();
    this->ui->inDate->setDate(QDate::fromString("2020-01-01"));
    this->ui->inShipName->clear();
    this->ui->inShipType->clear();
    this->ui->cbSonarType->setCurrentIndex(0);
    this->ui->inActor->clear();
    this->ui->inAuthor->clear();
    this->ui->inComment->clear();
}

void NewTaskDialog::setTaskId(int taskId)
{
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("编辑任务"));

    this->taskId = taskId;

    this->model = new TaskModel(this, HysDbHelper::getInstance()->getDb());
    this->model->setFilter(QString("id=%1").arg(taskId));
    this->model->select();
    // 根据id过滤，最多只有一条
    if (model->rowCount() == 1){
        this->record = model->record(0);

        this->ui->inTitle->setText(record.value("title").toString());
        this->ui->inAbbr->setText(record.value("abbr").toString());
        this->ui->inArea->setText(record.value("area").toString());
        this->ui->inDate->setDate(QDate::fromString(record.value("crawl_time").toString()));
        this->ui->inShipName->setText(record.value("ship_name").toString());
        this->ui->inShipType->setText(record.value("ship_type").toString());

        int sonar = record.value("sonar_type").toInt();
        switch (sonar) {
        case HysMainWindow::X25:
            this->ui->cbSonarType->setCurrentIndex(2);
            break;
        case HysMainWindow::X31:
            this->ui->cbSonarType->setCurrentIndex(1);
            break;
        case HysMainWindow::X39:
            this->ui->cbSonarType->setCurrentIndex(0);
            break;
        }

        this->ui->inActor->setText(record.value("actor").toString());
        this->ui->inAuthor->setText(record.value("author").toString());
        this->ui->inComment->setPlainText(record.value("comment").toString());
    }
}
void NewTaskDialog::on_btnSave_clicked()
{
    saveTask();
}

void NewTaskDialog::saveTask()
{
    QString title = this->ui->inTitle->text();
    QString abbr = this->ui->inAbbr->text();
    QString area = this->ui->inArea->text();
    QString shipName = this->ui->inShipName->text();
    QString shipType = this->ui->inShipType->text();
    QVariant sonarType = this->ui->cbSonarType->currentData();
    QString resPerson = this->ui->inActor->text();
    QString author = this->ui->inAuthor->text();
    QString comment = this->ui->inComment->toPlainText();
    QDate date = this->ui->inDate->date();

    if (title.isEmpty() || area.isEmpty() || shipName.isEmpty() || !sonarType.isValid() || author.isEmpty()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("添加任务"), QString::fromLocal8Bit("必填项不能为空！"));
        return;
    }

    if (taskId == -1) {
        this->model = new TaskModel(this, HysDbHelper::getInstance()->getDb());
        this->record = model->record();

        this->record.setGenerated("id", false);
        this->record.setValue("title", title);
        this->record.setValue("abbr", abbr);
        this->record.setValue("area", area);
        this->record.setValue("crawl_time", date.toString("yyyy-MM-dd"));
        this->record.setValue("ship_name", shipName);
        this->record.setValue("ship_type", shipType);
        this->record.setValue("sonar_type", sonarType.toInt());
        this->record.setValue("actor", resPerson);
        this->record.setValue("author", author);
        this->record.setValue("comment", comment);
        this->record.setGenerated("raw_data_path", false);
        this->record.setGenerated("dat_data_path", false);
        this->record.setGenerated("gps_data_path", false);
        this->record.setGenerated("jz_data_path", false);
        this->record.setGenerated("listen_data_path", false);
        this->record.setGenerated("env_data_path", false);
        this->record.setGenerated("start_time", false);
        this->record.setGenerated("end_time", false);

        QDateTime now = QDateTime::currentDateTime();
        QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
        record.setValue("created_time", nowStr);
        record.setValue("modified_time", nowStr);

        model->insertRecord(-1, record);
    } else {
        // record已经在setTaskId获取到
        this->record.setValue("title", title);
        this->record.setValue("abbr", abbr);
        this->record.setValue("area", area);
        this->record.setValue("crawl_time", date.toString("yyyy-MM-dd"));
        this->record.setValue("ship_name", shipName);
        this->record.setValue("ship_type", shipType);
        this->record.setValue("sonar_type", sonarType.toInt());
        this->record.setValue("actor", resPerson);
        this->record.setValue("author", author);
        this->record.setValue("comment", comment);

        QDateTime now = QDateTime::currentDateTime();
        QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
        record.setValue("modified_time", nowStr);

        model->setRecord(0, this->record);
    }

    bool result = model->submitAll();

    if (result) {
        QMessageBox::information(this, QString::fromLocal8Bit("完成"), QString::fromLocal8Bit("任务保存成功"));
        emit update_table();
        close();
    } else {
        QMessageBox::critical(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("任务保存失败，请检查数据！"));
    }
}

