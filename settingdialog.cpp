#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "hysdb.h"
#include <QDir>
#include <QFile>
#include <QPainter>
#include <QtCore/qmath.h>
#include <QMessageBox>
#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("数据库配置"));
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    initUI();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::initUI()
{
    HysDbHelper *dbhelper = HysDbHelper::getInstance();
    if (dbhelper->isOpen()) {
        this->ui->btnModified->show();
        this->ui->btnSave->hide();
        this->ui->btnCancel->hide();
    } else {
        this->ui->btnModified->hide();
        this->ui->btnSave->show();
        this->ui->btnCancel->show();
    }

    if (!dbhelper->getHost().isEmpty()) {
        this->ui->inHost->setText(dbhelper->getHost());
    }
    if (!dbhelper->getPort().isEmpty()) {
        this->ui->inPort->setText(dbhelper->getPort());
    }
    if (!dbhelper->getUser().isEmpty()) {
        this->ui->inUser->setText(dbhelper->getUser());
    }
    if (!dbhelper->getPwd().isEmpty()) {
        this->ui->inPwd->setText(dbhelper->getPwd());
    }
}

void SettingDialog::on_btnSave_clicked()
{
    QString host = this->ui->inHost->text();
    QString port = this->ui->inPort->text();
    port = port.isEmpty() ? "3306" : port;
    QString user = this->ui->inUser->text();
    QString password = this->ui->inPwd->text();

    if (host.isEmpty() || port.isEmpty() || user.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("保存连接"), QString::fromLocal8Bit("数据不能为空！"));
        return;
    }

    bool result = HysDbHelper::getInstance()->save(host, user, password, port);
    if (result) {
        QMessageBox::information(this, QString::fromLocal8Bit("保存连接"), QString::fromLocal8Bit("保存成功！请重新启动程序！"));
        close();
        exit(0);
    } else {
        QMessageBox::warning(this, QString::fromLocal8Bit("保存连接"), QString::fromLocal8Bit("保存失败！"));
    }
}

void SettingDialog::on_btnModified_clicked()
{
    this->ui->btnModified->hide();
    this->ui->btnSave->show();
    this->ui->btnCancel->show();
}

void SettingDialog::on_btnTest_clicked()
{
    QString host = this->ui->inHost->text();
    QString port = this->ui->inPort->text();
    port = port.isEmpty() ? "3306" : port;
    QString user = this->ui->inUser->text();
    QString password = this->ui->inPwd->text();

    if (host.isEmpty() || port.isEmpty() || user.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("测试连接"), QString::fromLocal8Bit("数据不能为空！"));
        return;
    }

    bool result = HysDbHelper::getInstance()->test(host, user, password, port);
    if (result) {
        QMessageBox::information(this, QString::fromLocal8Bit("测试连接"), QString::fromLocal8Bit("连接成功！"));
    } else {
        QMessageBox::warning(this, QString::fromLocal8Bit("测试连接"), QString::fromLocal8Bit("数据库连接失败，请检查连接配置！"));
    }
}
