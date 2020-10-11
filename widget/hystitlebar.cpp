#include "hystitlebar.h"
#include "ui_hystitlebar.h"
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
#include <QtDebug>

HysTitleBar::HysTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HysTitleBar)
{
   // ui->setupUi(this);
        //setupUi(this)是由.ui文件生成的类的构造函数，
        //这个函数的作用是对界面进行初始化，它按照我们在Qt设计器里设计的样子把窗体画出来，
        //把我们在Qt设计器里面定义的信号和槽建立起来。
        //也可以说，setupUi是我们画界面和写程序之间的桥梁。

    ui->setupUi(this);

    //设置窗体无边框，不可拖动拖拽拉伸
    setWindowFlags(Qt::FramelessWindowHint);

    //控件信息链接
    connect(this->ui->btnMin, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnMax, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnHome, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnMap, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnAnaly, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnExport, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(this->ui->btnSetting, SIGNAL(clicked()), this, SLOT(onClicked()));

}
//固定程序格式
HysTitleBar::~HysTitleBar()
{
    delete ui;
}

void HysTitleBar::setWindowTitle(const QString &title)
{
    //设置标题靠左
    ui->lbTitle->setAlignment(Qt::AlignLeft);
    //设置标题内容
    ui->lbTitle->setText(title);
}

//标题栏双击后等同于最大化按钮按下
void HysTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    ui->btnMax->click();
}

//鼠标按键按下
void HysTitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        //左键按下
        m_leftButtonPressed = true;
        //起始点，应值移动位置
        m_start = event->globalPos();
    }
}
//鼠标左键按下拖动
void HysTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    //鼠标左键按下后拖动窗口移动
    if (m_leftButtonPressed) {
        parentWidget()->move(parentWidget()->geometry().topLeft()+ event->globalPos() - m_start);
        m_start = event->globalPos();
    }
}
//鼠标左键释放
void HysTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = false;
    }
}
//事件过滤器
bool HysTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
   //窗口标题变更
    case QEvent::WindowTitleChange:
    {
        //obj实际指向QWidget类，所以可以正确投射为QWidget
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            ui->lbTitle->setText(pWidget->windowTitle());
            return true;
        }
    }
   //窗口图标变更
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            ui->lbIcon->setPixmap(icon.pixmap(ui->lbIcon->size()));
            return true;
        }
    }
    //窗口状态变化
    case QEvent::WindowStateChange:
    //适配大小
    case QEvent::Resize:
        updateMaximize();

        return true;
    }

    return QWidget::eventFilter(obj, event);
}
//更新为最大尺寸
void HysTitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        ui->btnMax->setStyle(QApplication::style());
    }
}
//用于ui的绘制
void HysTitleBar::paintEvent(QPaintEvent *event)
{
    //QStyleOption及其子类包含了QStyle函数绘制图形元素所需的所有信息。
    //由于性能原因，成员函数很少，并且对成员变量的访问是直接的(即。,使用。或- >操作符)。
    //这种低级的感觉使结构易于使用，并强调这些只是样式函数使用的参数。
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//点击事件
void HysTitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == ui->btnMin) {
            pWindow->showMinimized();
        } else if (pButton == ui->btnMax) {
            if (pWindow->isMaximized()) {
                pButton->setStyleSheet(QString::fromLocal8Bit("border-image: url(:/destop/max.png);"));
                pWindow->showNormal();
            } else {
                pButton->setStyleSheet(QString::fromLocal8Bit("border-image: url(:/destop/restore.png);"));
                pWindow->showMaximized();
            }
        } else if (pButton == ui->btnClose) {
            pWindow->close();
            exit(0);

        } else if (pButton == ui->btnHome) {
            emit setForm(0);
        } else if (pButton == ui->btnMap) {
            emit setForm(1);
        } else if (pButton == ui->btnAnaly) {
            emit setForm(2);
        } else if (pButton == ui->btnExport)
        {
            emit setForm(3);
        } else if (pButton == ui->btnSetting) {
            emit openSetting();
        }
    }
}

void HysTitleBar::resetMenu(int index)
{
    //数据采集按钮
    this->ui->btnHome->setChecked(false);
    //态势生成按钮
    this->ui->btnMap->setChecked(false);
    //复盘分析按钮
    this->ui->btnAnaly->setChecked(false);
    //整编导出按钮
    this->ui->btnExport->setChecked(false);

    switch (index) {
    case 0:
        this->ui->btnHome->setChecked(true);
        break;
    case 1:
        this->ui->btnMap->setChecked(true);
        break;
    case 2:
        this->ui->btnAnaly->setChecked(true);
        break;
    case 3:
        this->ui->btnExport->setChecked(true);
        break;
    }

}
