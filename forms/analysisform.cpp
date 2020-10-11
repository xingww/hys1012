#include "analysisform.h"
#include "ui_analysisform.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include "hysmainwindow.h"
#include "screenpas.h"//新增图片
#include "screenact.h"//新增图片

#include <QMessageBox>
#include <QSqlRecord>
#include <QDebug>

AnalysisForm::AnalysisForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalysisForm)
{
    ui->setupUi(this);
    initUI();//初始化

    //如果要在Qt信号槽中使用自定义类型，需要注意使用qRegisterMetaType对自定义类型进行注册，当然在不跨线程时使用自定义类型signal/slot来传递，可能不会出现什么问题；
    //一旦涉及跨线程就很容易出错，回想下信号槽的作用就是用来对象与对象之间通信的，难免会跨线程，建议在使用自定义类型利用信号槽通信时，最好先通过qRegisterMetaType()将自定义类型进行注册，以免出错
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>&");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>*");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<quint8>>&");
}

AnalysisForm::~AnalysisForm()
{
    delete ui;
}

void AnalysisForm::initUI()
{
    this->lbTitle = this->ui->lbTitle;
    this->lhContainer = this->ui->hlContainer;

    this->cbActpas = this->ui->cbActpas;
    //创建一个Screenpas的对象
    this->screenpas = new Screenpas(); //新增图片
    this->screenact = new Screenact(); //新增图片

    connect(this->screenpas, &Screenpas::enableTaskComboBox, this, &AnalysisForm::enableComboBox);
    connect(this->screenact, &Screenact::enableTaskComboBox, this, &AnalysisForm::enableComboBox);
    this->lhContainer->addWidget(this->screenpas);//新增图片
    this->lhContainer->addWidget(this->screenact);//新增图片
    this->hideWidget();

    this->cbActpas->setCurrentIndex(1);//默认显示界面"被动探测"
    this->cbActpasValue = 1;
    this->screenpas->initTask(this->taskId, this->cbActpasValue);//初始化使解析可以正常进行

    this->screenpas->show();
}

//taskID实际上指的是所建立的任务名称
void AnalysisForm::setCurrentTaskId(int taskId)
{
    if (taskId == this->taskId)
    {
        return;
    }
    //任务模型
    this->taskId = taskId;
    TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );
    model->setFilter(QString("id=%1").arg(taskId));//仅选择taskID相关数据
    model->select();//选择数据

    //模型为空
    if (model->rowCount() != 1) {
        delete model;
        QMessageBox::warning(this, QString::fromLocal8Bit("任务不存在"), QString::fromLocal8Bit("选择任务不存在"));
        return;
    }

    this->sonarMap.clear();
    this->fileMap.clear();

    //设置任务抬头
    QSqlRecord record = model->record(0);
    QString taskTitle = record.value("title").toString();
    this->lbTitle->setText(taskTitle);

    //读取声纳类型
    this->sonarTypeValue = record.value("sonar_type").toInt();
    //读取基阵数据文件名称
    QString jzFileName = record.value("jz_data_path").toString();
    //读取场景数据文件名称
    QString datFileName = record.value("dat_data_path").toString();

    //设置
    this->sonarMap.insert(HysMainWindow::SELF_DATA, this->sonarTypeValue);

    //QMap是一个模板类，提供了一个红黑树结构的查找字典。 注：红黑树结构是自平衡二叉树
    if (!jzFileName.isEmpty()) {
        this->fileMap.insert(QString("%1_%2_jz").arg(this->taskId).arg(HysMainWindow::SELF_DATA), jzFileName);
    }
    if (!datFileName.isEmpty()) {
        this->fileMap.insert(QString("%1_%2_dat").arg(this->taskId).arg(HysMainWindow::SELF_DATA), datFileName);
    }

    //目标模型
    TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
    targetModel->setFilter(QString("task_id=%1").arg(taskId));
    targetModel->select();
    int count = targetModel->rowCount();

    //目标
    if (count != 0) {
        for (int i=0;i<count;i++) {
            QSqlRecord record = targetModel->record(i);
            int id = record.value("id").toInt();
            QString name = record.value("name").toString();
            int sonarValue = record.value("sonar_type").toInt();
            QString jzFileName = record.value("jz_data_path").toString();
            QString datFileName = record.value("dat_data_path").toString();

            this->sonarMap.insert(id, sonarValue);

            if (!jzFileName.isEmpty()) {
                this->fileMap.insert(QString("%1_%2_jz").arg(this->taskId).arg(id), jzFileName);
            }
            if (!datFileName.isEmpty()) {
                this->fileMap.insert(QString("%1_%2_dat").arg(this->taskId).arg(id), datFileName);
            }
        }
    }

    delete targetModel;
    delete model;
}

void AnalysisForm::on_cbActpas_currentIndexChanged(int index)
{
    if(index == 0){
        this->cbActpasValue = 0;
    }else
        this->cbActpasValue = 1;

    switchForm();
}

//更新代码
void AnalysisForm::switchForm()
{
    this->hideWidget();

    if (this->cbActpasValue == 0) {
        this->screenpas->initTask(this->taskId, this->cbActpasValue);
        this->screenact->show();

    } else{
        this->screenact->initTask(this->taskId, this->cbActpasValue);
        this->screenpas->show();
    }
}

void AnalysisForm::hideWidget()
{
    this->screenact->hide();
    this->screenpas->hide();
}

void AnalysisForm::enableComboBox(bool enable)
{
    if (enable) {
        this->cbActpas->setEnabled(true);
    } else {
        this->cbActpas->setEnabled(false);
    }
}

