#include "newtargetdialog.h"
#include "ui_newtargetdialog.h"
#include "models/targetmodel.h"
#include "models/taskmodel.h"
#include "hysmainwindow.h"
#include "hysdb.h"
#include <QtCore/qmath.h>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

NewTargetDialog::NewTargetDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NewTargetDialog)
{
    ui->setupUi(this);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("添加目标"));
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    initUI();
}

NewTargetDialog::~NewTargetDialog()
{
    delete ui;
}

void NewTargetDialog::initUI()
{
    this->lbTaskTitle = this->ui->lbTaskTitle;
    this->leTargetName = this->ui->inTargetName;
    this->leShipType = this->ui->inShipType;
    this->cbSonarType = this->ui->cbSonarType;

    this->cbSonarType->insertItem(0, QString::fromLocal8Bit("3X9"), HysMainWindow::X39);
    this->cbSonarType->insertItem(1, QString::fromLocal8Bit("3X1"), HysMainWindow::X31);
    this->cbSonarType->insertItem(2, QString::fromLocal8Bit("2X5"), HysMainWindow::X25);
    this->cbSonarType->setCurrentIndex(-1);
}

void NewTargetDialog::setTaskId(int taskId)
{
    this->taskId = taskId;

    TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb());
    model->setFilter(QString("id=%1").arg(taskId));
    model->select();
    // 根据id过滤，最多只有一条
    if (model->rowCount() == 1){
        QSqlRecord record = model->record(0);
        this->lbTaskTitle->setText(record.value("title").toString());
    }

    delete model;
}

void NewTargetDialog::on_btnSave_clicked()
{
    QString name = this->leTargetName->text();
    QString shipType = this->leShipType->text();
    QVariant sonarType = this->cbSonarType->currentData();

    if (name.isEmpty() || !sonarType.isValid()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("添加目标"), QString::fromLocal8Bit("必填项不能为空！"));
        return;
    }

    TargetModel *model = new TargetModel(this, HysDbHelper::getInstance()->getDb());
    QSqlRecord record = model->record();

    record.setGenerated("id", false);
    record.setValue("task_id", this->taskId);
    record.setValue("name", name);
    record.setValue("ship_type", shipType);
    record.setValue("sonar_type", sonarType.toInt());
    record.setGenerated("raw_data_path", false);
    record.setGenerated("dat_data_path", false);
    record.setGenerated("gps_data_path", false);
    record.setGenerated("jz_data_path", false);
    record.setGenerated("listen_data_path", false);
    record.setGenerated("env_data_path", false);
    record.setGenerated("start_time", false);
    record.setGenerated("end_time", false);

    QDateTime now = QDateTime::currentDateTime();
    QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
    record.setValue("created_time", nowStr);
    record.setValue("modified_time", nowStr);

    model->insertRecord(-1, record);
    bool result = model->submitAll();
    qDebug()<<model->query().lastQuery();

    if (result) {
        QMessageBox::information(this, QString::fromLocal8Bit("完成"), QString::fromLocal8Bit("目标保存成功"));
        close();
    } else {
        QMessageBox::critical(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("目标保存失败，请检查数据！"));
    }

    delete model;
}
