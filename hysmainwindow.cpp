#include "hysmainwindow.h"
#include "ui_hysmainwindow.h"
#include "hysdb.h"
#include "newtaskdialog.h"
#include "parsedata.h"
#include "newattentiondialog.h"
#include "viewattentiondialog.h"
#include "settingdialog.h"
#include <QMultiMap>
#include <QVector>
#include <QMessageBox>
#include <QMetaType>
#include <QtCore/qmath.h>

//执行父类 QWidget 的构造函数，创建一个 Ui::Widget 类的对象 ui。
//这个 ui 就是 Widget 的 private 部分定义的指针变量 ui。
HysMainWindow::HysMainWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::HysMainWindow)
{
    //setupUi(this)是由.ui文件生成的类的构造函数，
    //这个函数的作用是对界面进行初始化，它按照我们在Qt设计器里设计的样子把窗体画出来，
    //把我们在Qt设计器里面定义的信号和槽建立起来。
    //也可以说，setupUi是我们画界面和写程序之间的桥梁。
    ui->setupUi(this);

    //窗体透明设计
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //对标题栏进行事件过滤。因为这个ui是动态创建的，ui是一个指针，所以用ui->来调用成员函数
    installEventFilter(ui->titleBar);

    init();

    qRegisterMetaType<QVector<double>>("QVector<double>&");
    qRegisterMetaType<QMap<QString,QVector<double>>>("QMap<QString,QVector<double>>&");

    connect(this->ui->titleBar, SIGNAL(setForm(int)), this, SLOT(setCurrent(int)));
    connect(this->ui->titleBar, SIGNAL(openSetting()), this, SLOT(openSetting()));

}

HysMainWindow::~HysMainWindow()
{
    delete ui;
}

//定义私有函数paintEvent
void HysMainWindow::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width()-10, this->height()-10);

    //QPainter painter(this)是构造在栈上的出了作用域自动析构
    //new出来的 通过管理指针来自己管理析构 生命范围为全局 除非你自己delete了
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0;i<5;i++) {
        QPainterPath tmpPath;
        tmpPath.setFillRule(Qt::WindingFill);
        tmpPath.addRect(5-i, 5-i, this->width()-(5-i)*2, this->height()-(5-i)*2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(tmpPath);
    }
}

//私有函数，初始化
void HysMainWindow::init()
{
    if (!HysDbHelper::getInstance()->init()) {
        QMessageBox::StandardButton rtButton = QMessageBox::information(this, QString::fromLocal8Bit("数据库连接失败"), QString::fromLocal8Bit("当前数据库连接失败,请检查数据库连接，输入正确的连接信息"));
        if (rtButton == QMessageBox::Ok) {
            SettingDialog *settingDialog = new SettingDialog(this);
            settingDialog->show();

        }
    }
    //
    this->homeWidget = new HomeForm(this);
    this->mapWidget = new MapForm(this);
    this->anaWidget = new AnalysisForm(this);
    this->exWidget = new ExportForm(this);

    //提供一个窗口，一次只能显示一个窗口
    QStackedWidget *stackedWidget = this->ui->stackedWidget;
    stackedWidget->addWidget(this->homeWidget);//主页面
    stackedWidget->addWidget(this->mapWidget);//地图
    stackedWidget->addWidget(this->anaWidget);//数据分析
    stackedWidget->addWidget(this->exWidget);//数据导出

    connect(this, SIGNAL(update_ana_taskId(int)), this->anaWidget, SLOT(setCurrentTaskId(int)));
    connect(this, SIGNAL(update_map_taskId(int)), this->mapWidget, SLOT(setCurrentTaskId(int)));
    connect(this, SIGNAL(update_export_taskId(int)), this->exWidget, SLOT(setCurrentTaskId(int)));
    this->ui->stackedWidget->setCurrentIndex(0);
}

//窗口显示
void HysMainWindow::setCurrent(int index)
{
    if (index == this->currentForm)
        return;

    //只要index非0，即数据采集页面，则跳出信息窗口（并且未选择数据）
    if (index != 0) {
        // 复盘分析
        int taskId = this->homeWidget->getCurrentTask();
        if (taskId == -1) {
            //弹出消息窗口
            QMessageBox::information(this, QString::fromLocal8Bit("选择任务"), QString::fromLocal8Bit("还没有选择任务，请先选中一个任务"));
            this->ui->titleBar->resetMenu(this->currentForm);
            return;
        }

        //获取数据，此为数据模型
        TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );
        //根据taskId获取数据
        model->setFilter(QString("id=%1").arg(taskId));
        model->select();

        //选择任务
        if (model->rowCount() != 1) {
            delete model;
            QMessageBox::warning(this, QString::fromLocal8Bit("任务不存在"), QString::fromLocal8Bit("选择任务不存在"));
            this->ui->titleBar->resetMenu(this->currentForm);

            return;
        }
        delete model;

        this->ui->stackedWidget->setCurrentIndex(index);
        //态势生成
        if (index == 1) {
            emit update_map_taskId(taskId);
            //复盘分析
        } else if (index == 2) {
            emit update_ana_taskId(taskId);

            //整编导出
        } else if (index == 3) {
            emit update_export_taskId(taskId);

        } else {
            // nothing
        }
    } else {
        this->ui->stackedWidget->setCurrentIndex(index);
    }

    this->ui->titleBar->resetMenu(index);
    this->currentForm = index;
}

//打开设置
void HysMainWindow::openSetting()
{
    SettingDialog *settingDialog = new SettingDialog(this);
    settingDialog->show();
}
