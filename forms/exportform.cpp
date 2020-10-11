#include "exportform.h"
#include "ui_exportform.h"
#include "models/taskmodel.h"
#include "models/gpsmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

ExportForm::ExportForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExportForm)
{
    ui->setupUi(this);
    initUI();
}

ExportForm::~ExportForm()
{
    delete ui;
}

void ExportForm::initUI()
{
    this->navdetSel = this->ui->navdetSel;
    this->lbTitle = this->ui->lbTitle;
//    this->lbTitle->setText(taskTitle);

    this->exportformdetect = new exportFormdetect(); //新增图片
    this->exportformnchart = new exportFormnchart(); //新增图片

    this->lhContainer = this->ui->lhContainer;
    this->lhContainer->addWidget(this->exportformdetect);//新增图片
    this->lhContainer->addWidget(this->exportformnchart);//新增图片
    this->hideWidget();

    this->navdetSel->setCurrentIndex(0);//默认海图显示
    this->navdetSelValue = 0;
//    this->exportformnchart->initTask(this->taskId, this->navdetSelValue);//初始化使解析可以正常进行
    this->exportformnchart->show();
}


void ExportForm::on_navdetSel_currentIndexChanged(int index)
{
    if(index == 0){
        this->navdetSelValue = 0;
    }else
        this->navdetSelValue = 1;

    switchForm();
}

//更新代码
void ExportForm::switchForm()
{
    this->hideWidget();

    if (this->navdetSelValue == 0) {
//        this->exportformnchart->initTask(this->taskId, this->navdetSelValue);
        this->exportformnchart->show();

    } else{
//        this->screenact->initTask(this->taskId, this->cbActpasValue);
        this->exportformdetect->show();
    }
}

void ExportForm::hideWidget()
{
    this->exportformnchart->hide();
    this->exportformdetect->hide();
}

//增加此代码使得hysmainwindow的setCurrentTaskId的函数可以传递下去
void ExportForm::setCurrentTaskId(int taskId)
{
    exportformnchart->setCurrentTaskId(taskId);
}
