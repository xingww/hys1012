#include "screenpas.h"
#include "widgetscreen.h"
#include "ui_screenpas.h"
#include "run_status.h"
#include "hysmainwindow.h"
#include "hysdb.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"

#include <QMessageBox>
#include <QWidget>
#include <QDebug>
#include <QSqlRecord>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QHeaderView>

extern bool isMatlabInit;

Screenpas::Screenpas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screenpas)
{
    ui->setupUi(this);
    initUI();

    //modify1
    this->curveplot = new curvePlot();

    //新线程
    this->pThread = new QThread(this);
    this->pThread->setObjectName("screendata_parser");

    //场景数据解析
    this->parser = new Screenparsedata();
    this->parser->moveToThread(this->pThread);

    connect(this, &Screenpas::start_parse, this->parser, &Screenparsedata::parse);
    //信号与槽连接， 数据->图片
    //modify1
   // connect(this->parser, &Screenparsedata::send_cpdata, this, &Screenpas::updateCpDatacurve);
    connect(this->parser, &Screenparsedata::send_cpdata, this, &Screenpas::updateCpData);
    connect(this->parser, &Screenparsedata::send_eddata, this, &Screenpas::updateEdData);
    connect(this->parser, &Screenparsedata::send_noiseldata, this, &Screenpas::updateNoiseLData);
    connect(this->parser, &Screenparsedata::send_noisesdata, this, &Screenpas::updateNoiseSData);
    connect(this->parser, &Screenparsedata::send_fsddata, this, &Screenpas::updateFsdData);
    connect(this->parser, &Screenparsedata::send_lofardata, this, &Screenpas::updateLofarData);
    connect(this->parser, &Screenparsedata::send_demondata, this, &Screenpas::updateDemonData);
    connect(this->parser, &Screenparsedata::send_echodata, this, &Screenpas::updateEchoData);
    connect(this->parser, &Screenparsedata::send_nodata, this, &Screenpas::updateNoData);

    this->pThread->start();
}

Screenpas::~Screenpas()
{
    delete ui;
    delete this->pDialog;

    this->pThread->quit();
    this->pThread->wait();
    delete this->parser;
    delete this->pThread;
}

//初始化二维曲线
void Screenpas::initPlotcurve()
{
    //初始化xdata,x对应长度为5的坐标，y初始全为0
    for(int i=1;i<timeInterval+1;i++){
        cpxdata.append(i);
        cpydata.append(0);
    }

    for(int i=1;i<timeInterval+1;i++){
        lofarxdata.append(i);
        lofarydata.append(0);
    }

    for(int i=1;i<timeInterval+1;i++){
        demonxdata.append(i);
        demonydata.append(0);
    }
    //设置曲线信息，抬头，背景，标签，坐标轴等信息
    cpPlotcurve->setCanvasBackground(Qt::white);//设置背景
    cpPlotcurve->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//设置标签位置

    lofarcvPlotcurve->setCanvasBackground(Qt::white);//设置背景
    lofarcvPlotcurve->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//设置标签位置

    demoncvPlotcurve->setCanvasBackground(Qt::white);//设置背景
    demoncvPlotcurve->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//设置标签位置

    cpcurve = new QwtPlotCurve();//创建对象
    cpcurve->setPen( Qt::yellow, 1 );//曲线的颜色 宽度;
    cpcurve->setPen(QColor(255,0,255),2,Qt::DotLine);//设置曲线特性,颜色/线宽/线形

    lofarcurve = new QwtPlotCurve();//创建对象
    lofarcurve->setPen( Qt::yellow, 1 );//曲线的颜色 宽度;
    lofarcurve->setPen(QColor(255,0,255),2,Qt::DotLine);//设置曲线特性,颜色/线宽/线形

    demoncurve = new QwtPlotCurve();//创建对象
    demoncurve->setPen( Qt::yellow, 1 );//曲线的颜色 宽度;
    demoncurve->setPen(QColor(255,0,255),2,Qt::DotLine);//设置曲线特性,颜色/线宽/线形

    QTime curtime;//设置时间
    curtime=curtime.currentTime();//获取当前时间

    cpPlotcurve->setAxisScale(QwtPlot::yLeft,-1.1,1.1,1);//设置y轴坐标范围
    cpPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    cpPlotcurve->setAxisScale(QwtPlot::xBottom,0,timeInterval,int (timeInterval/10));//设置x轴坐标范围
    cpPlotcurve->enableAxis(QwtPlot::xBottom, false);

    lofarcvPlotcurve->setAxisScale(QwtPlot::yLeft,-1.1,1.1,1);//设置y轴坐标范围
    lofarcvPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    lofarcvPlotcurve->setAxisScale(QwtPlot::xBottom,0,timeInterval,int (timeInterval/10));//设置x轴坐标范围
    lofarcvPlotcurve->enableAxis(QwtPlot::xBottom, false);

    demoncvPlotcurve->setAxisScale(QwtPlot::yLeft,-1.1,1.1,1);//设置y轴坐标范围
    demoncvPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    demoncvPlotcurve->setAxisScale(QwtPlot::xBottom,0,timeInterval,int (timeInterval/10));//设置x轴坐标范围
    demoncvPlotcurve->enableAxis(QwtPlot::xBottom, false);

 //   cpPlotcurve->enableAxis(QwtPlot::xTop,true);//设置x轴上坐标有效
 //   cpPlotcurve->setAxisScale()
    //设置缩放
    QwtPlotZoomer *cpzoomer = new QwtPlotZoomer( cpPlotcurve->canvas());//canvas画布
    cpzoomer->setRubberBandPen( QColor( Qt::blue ) );//设置缩放框颜色
    cpzoomer->setTrackerPen( QColor( Qt::white ) );//设置跟踪器颜色
    cpzoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier);//设置鼠标模式，右键拖放放大
    cpzoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);//设置鼠标模式，右键恢复
    QwtPlotMagnifier *cpmagnifier = new QwtPlotMagnifier( cpPlotcurve->canvas() );//默认的滑轮及右键缩放功能  图形的整体缩放

    QwtPlotZoomer *lofarzoomer = new QwtPlotZoomer( lofarcvPlotcurve->canvas());//canvas画布
    lofarzoomer->setRubberBandPen( QColor( Qt::blue ) );//设置缩放框颜色
    lofarzoomer->setTrackerPen( QColor( Qt::white ) );//设置跟踪器颜色
    lofarzoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier);//设置鼠标模式，右键拖放放大
    lofarzoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);//设置鼠标模式，右键恢复
    QwtPlotMagnifier *lofarmagnifier = new QwtPlotMagnifier( lofarcvPlotcurve->canvas() );//默认的滑轮及右键缩放功能  图形的整体缩放

    QwtPlotZoomer *demonzoomer = new QwtPlotZoomer( demoncvPlotcurve->canvas());//canvas画布
    demonzoomer->setRubberBandPen( QColor( Qt::blue ) );//设置缩放框颜色
    demonzoomer->setTrackerPen( QColor( Qt::white ) );//设置跟踪器颜色
    demonzoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier);//设置鼠标模式，右键拖放放大
    demonzoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);//设置鼠标模式，右键恢复
    QwtPlotMagnifier *demonmagnifier = new QwtPlotMagnifier( demoncvPlotcurve->canvas() );//默认的滑轮及右键缩放功能  图形的整体缩放


    //magnifier->setMouseButton(Qt::LeftButton);     //设置哪个按钮与滑轮为缩放画布  如果不设置(注册掉当前行)按钮默认为滑轮以及右键为缩放
    //设置网格
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableX( false );//设置X轴网格线
    grid->enableY( false );//设置Y轴网格线
    grid->setMajorPen( Qt::black, 0, Qt::DotLine);//设置网格线形
    grid->attach(cpPlotcurve);//将网格线贴到画布上。
    grid->attach(lofarcvPlotcurve);//将网格线贴到画布上。
    grid->attach(demoncvPlotcurve);//将网格线贴到画布上。

    cplastpointtime = 0;
    lofarlastpointtime = 0;
    demonlastpointtime = 0;

}

//初始化
void Screenpas::initUI()
{
    this->pDialog = new QProgressDialog(this);
    this->pDialog->setStyleSheet("QLabel {border-image:none;}");//显示图片效果
    this->pDialog->setModal(true);
    this->pDialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    this->pDialog->setCancelButton(NULL);
    this->pDialog->setMaximum(0);
    this->pDialog->setMinimum(0);
    this->pDialog->reset();

    //变量建立对应映射关系
    this->navalDepthvalue = this->ui->navalDepthvalue;
    this->navalDirectionvalue = this->ui->navalDirectionvalue;
    this->navalSpeedvalue = this->ui->navalSpeedvalue;
    this->navalLtvalue = this->ui->navalLtvalue;
    this->navalLatvalue = this->ui->navalLatvalue;
    this->navalBroadvalue = this->ui->navalBroadvalue;
    this->navalDirvalue = this->ui->navalDirvalue;
    this->soundSpeedvalue = this->ui->soundSpeedvalue;
    this->recordTimevalue = this->ui->recordTimevalue;
    this->beijingTimevalue = this->ui->beijingTimevalue;
    //变量赋初始值
    this->navalDepthvalue->setValue(0.0);
    this->navalDirectionvalue->setText(QString::fromLocal8Bit("东北偏南"));
    this->navalSpeedvalue->setValue(0.0);
    this->navalLtvalue->setValue(0.0);
    this->navalLatvalue->setValue(0.0);
    this->navalBroadvalue->setValue(0.0);
    this->navalDirvalue->setValue(0.0);
    this->soundSpeedvalue->setValue(0.0);

    this->currentTime = QDateTime::currentDateTime();
    this->recordTimevalue->setText(this->currentTime.toString("yyyy-MM-dd hh:mm:ss"));
    this->beijingTimevalue->setText(this->currentTime.toString("yyyy-MM-dd hh:mm:ss"));

    this->lbStartTime = this->ui->lbStart;
    this->lbEndTime = this->ui->lbEnd;

    this->btnStart = this->ui->btnStart;
    this->btnStop = this->ui->btnStop;
    this->btnFastforward = this->ui->btnFastforward;
    this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
    this->btnFastbackward = this->ui->btnFastbackward;
    this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));

    this->slider = this->ui->slider;
    this->slider->installEventFilter(this);

    this->vlayout = this->ui->widgetScreen;

    this->screenpasForm = new Ui::widgetScreen();
    this->screenpasWidget = new QWidget(NULL);
    //先构建一个QWidget界面，再加载xml构建出我们创建的ui界面
    this->screenpasForm->setupUi(this->screenpasWidget);
    this->screenpasWidget->setParent(vlayout);

    //modify1
    this->cpPlotcurve = this->screenpasForm->cpPlotcurve;
    this->lofarcvPlotcurve = this->screenpasForm->lofarcvPlotcurve;
    this->demoncvPlotcurve = this->screenpasForm->demoncvPlotcurve;


    this->cpPlot = this->screenpasForm->cpPlot;
    this->cpPlot->setDimension(480, 780);

    this->pasPlot = this->screenpasForm->pasPlot;
    this->pasPlot->setDimension(480, 780);

    this->lofarcvPlot = this->screenpasForm->lofarcvPlot;
    this->lofarcvPlot->setDimension(480, 780);

    this->lofarcoPlot = this->screenpasForm->lofarcoPlot;
    this->lofarcoPlot->setDimension(480, 780);

    this->demoncvPlot = this->screenpasForm->demoncvPlot;
    this->demoncvPlot->setDimension(480, 780);

    this->demoncoPlot = this->screenpasForm->demoncoPlot;
    this->demoncoPlot->setDimension(480, 780);

    this->echoTxt = this->screenpasForm->echoTxt;

    this->type = FormType::ACTIVE;

}

void Screenpas::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    //SELF_DATA=0
    if (this->targetId == HysMainWindow::SELF_DATA) {
        TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );
        //根据taskID进行筛选
        model->setFilter(QString("id=%1").arg(this->taskId));//筛选，按照字符串filter对数据库进行筛选
        model->select();
        //获取行数
        if (model->rowCount() != 1) {
            delete model;
            return;
        }
        //封装数据库所有记录
        //获取当前行的记录
        QSqlRecord record = model->record(0);
        //获取记录中"start_time"字段的值并将其转换为日期时间
        this->startTime = record.value("start_time").toDateTime();
        //获取记录中"end_time"字段的值并将其转换为日期时间
        this->endTime = record.value("end_time").toDateTime();
        //获取记录中"dat_data_path"字段的值并将其转换为字符串
        this->datFileName = record.value("dat_data_path").toString();
        delete model;
    } else {
        TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
        targetModel->setFilter(QString("id=%1").arg(this->targetId));
        targetModel->select();
        if (targetModel->rowCount() != 1) {
            delete targetModel;
            return;
        }

        QSqlRecord record = targetModel->record(0);
        this->startTime = record.value("start_time").toDateTime();
        this->endTime = record.value("end_time").toDateTime();
        this->datFileName = record.value("dat_data_path").toString();

        delete targetModel;
    }

    this->runStatus = UNSTART;
    this->receivedDataCount = 0;
    // 模拟数据，数据固化
    this->datFileName = "D:/9Test.dat";//模拟数据存放路径
    this->startTime = QDateTime::fromString("2020-01-06 19:47:35", "yyyy-MM-dd hh:mm:ss");
    this->endTime = QDateTime::fromString("2020-01-06 19:53:00", "yyyy-MM-dd hh:mm:ss");

    //获取从开始到介绍之间的时间间隔
    this->timeInterval = this->endTime.toSecsSinceEpoch() - this->startTime.toSecsSinceEpoch();
    this->timerCount = 0;

    //初始化时间进度条
    this->ui->slider->setMinimum(0);
    this->ui->slider->setMaximum(this->timeInterval);

    this->cpData.clear();//主动宽带警戒
    this->edData.clear();//窄带警戒
    this->fsdData.clear();//多普勒
    this->noiseLData.clear();//噪声历程长
    this->noiseSData.clear();//噪声历程短
    this->lofarData.clear();//Lofar
    this->demonData.clear();//demon
    this->echoData.clear();//回声目标
    this->noData.clear();//噪声目标

    this->lbStartTime->setText(this->startTime.toString("yyyy-MM-dd hh:mm:ss"));
    this->lbEndTime->setText(this->endTime.toString("yyyy-MM-dd hh:mm:ss"));

    //设置图形开始及结束时间
    this->cpPlot->setGlobalInterval(this->startTime, this->endTime);
    //modify1
    this->cpPlotcurve->setGlobalInterval(this->startTime, this->endTime);
    this->lofarcvPlotcurve->setGlobalInterval(this->startTime, this->endTime);
    this->demoncvPlotcurve->setGlobalInterval(this->startTime, this->endTime);

    this->pasPlot->setGlobalInterval(this->startTime, this->endTime);
    this->lofarcvPlot->setGlobalInterval(this->startTime, this->endTime);
    this->lofarcoPlot->setGlobalInterval(this->startTime, this->endTime);
    this->demoncvPlot->setGlobalInterval(this->startTime, this->endTime);
    this->demoncoPlot->setGlobalInterval(this->startTime, this->endTime);

    //modify1
    //需要在此次进行初始化，因为函数中所调用的timeInterval赋值先后会有影响。
    initPlotcurve();
}

void Screenpas::on_navalSelec_currentIndexChanged(int index)
{
    if(index == 0){
        this->ui->navalDirection->setText(QString::fromLocal8Bit("本艇航向:"));
        this->ui->navalSpeed->setText(QString::fromLocal8Bit("本艇航速:"));
        this->ui->navalDepth->show();
        this->ui->navalDepthvalue->show();
    }else{
        this->ui->navalDirection->setText(QString::fromLocal8Bit("本舰航向:"));
        this->ui->navalSpeed->setText(QString::fromLocal8Bit("本舰航速:"));
        this->ui->navalDepth->hide();
        this->ui->navalDepthvalue->hide();
    }

}

//图形同步更新定时器
void Screenpas::timerEvent(QTimerEvent *e)
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    if (current > this->endTime) {
        this->killTimer(this->timerId);//停止计时
        this->runStatus = STOP;
        this->timerCount = 0;
        this->receivedDataCount = 0;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        this->fastftimes = 1;//reset
        this->fastbtimes = 1;//reset
        this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
        this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));

        emit enableTaskComboBox(true);

        return;
    }

    //计时条
    this->slider->setValue(this->timerCount);

    //定时更新
    this->cpPlot->setTimerCount(this->timerCount);
    this->cpPlot->update();

    //modify1
    this->cpPlotcurve->setTimerCount(this->timerCount);
    this->lofarcvPlotcurve->setTimerCount(this->timerCount);
    this->demoncvPlotcurve->setTimerCount(this->timerCount);

    //this->cpPlotcurve->update();
    this->updatecpPlotcurve();
    this->updatelofarPlotcurve();
    this->updatedemonPlotcurve();


    this->pasPlot->setTimerCount(this->timerCount);
    this->pasPlot->update();

    this->lofarcvPlot->setTimerCount(this->timerCount);
    this->lofarcvPlot->update();

    this->lofarcoPlot->setTimerCount(this->timerCount);
    this->lofarcoPlot->update();

    this->demoncvPlot->setTimerCount(this->timerCount);
    this->demoncvPlot->update();

    this->demoncoPlot->setTimerCount(this->timerCount);
    this->demoncoPlot->update();

    this->updateEchoDisplay();
  //  this->updateNoDisplay();

    this->timerCount++;
}

void Screenpas::updatecpPlotcurve()
{
    //以下时间需要更新为时间轴
    int eltime = timerCount;
    int size = (eltime - cplastpointtime);

    if(size>0){//有数据传入
        cpydata.erase(cpydata.begin(),cpydata.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;i++){
 //          ydata.append(curveplot->getData());//重新获取数据
              cpydata.append(curveplot->getData1((((double)cplastpointtime+i)/1000)));//重新获取数据
        }
        cplastpointtime = eltime;
    }

    double temp = cpydata.value(cpydata.size()-1);//参数读取后删除掉了。另外需要注意读取的参数为size-1
    double cpMax = axisYMaximum(temp);
    double cpMin = axisYMinimum(temp);

    //modify1
    cpPlotcurve->setAxisScale(QwtPlot::yLeft,cpMin,cpMax,1);//设置y轴坐标范围
    cpcurve->setSamples(cpxdata,cpydata);//设置采样
    cpcurve->attach(this->cpPlotcurve);//将曲线附加到qwtPlot上
    cpPlotcurve->replot();//重画
}

void Screenpas::updatelofarPlotcurve()
{
    //以下时间需要更新为时间轴
    int eltime = timerCount;
    int size = (eltime - lofarlastpointtime);

    if(size>0){//有数据传入
        lofarydata.erase(lofarydata.begin(),lofarydata.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;i++){
 //          lofarydata.append(curveplot->getData());//重新获取数据
              lofarydata.append(curveplot->getData1((((double)lofarlastpointtime+i)/1000)));//重新获取数据
        }
        lofarlastpointtime = eltime;
    }

    double temp = lofarydata.value(lofarydata.size()-1);//参数读取后删除掉了。另外需要注意读取的参数为size-1
    double lofarMax = axisYMaximum(temp);
    double lofarMin = axisYMinimum(temp);

    //modify1
    lofarcvPlotcurve->setAxisScale(QwtPlot::yLeft,lofarMin,lofarMax,1);//设置y轴坐标范围
    lofarcurve->setSamples(lofarxdata,lofarydata);//设置采样
    lofarcurve->attach(this->lofarcvPlotcurve);//将曲线附加到qwtPlot上
    lofarcvPlotcurve->replot();//重画
}

void Screenpas::updatedemonPlotcurve()
{
    //以下时间需要更新为时间轴
    int eltime = timerCount;
    int size = (eltime - demonlastpointtime);

    if(size>0){//有数据传入
        demonydata.erase(demonydata.begin(),demonydata.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;i++){
 //          demonydata.append(curveplot->getData());//重新获取数据
              demonydata.append(curveplot->getData1((((double)demonlastpointtime+i)/1000)));//重新获取数据
        }
        demonlastpointtime = eltime;
    }

    double temp = demonydata.value(demonydata.size()-1);//参数读取后删除掉了。另外需要注意读取的参数为size-1
    double demonMax = axisYMaximum(temp);
    double demonMin = axisYMinimum(temp);

    //modify1
    demoncvPlotcurve->setAxisScale(QwtPlot::yLeft,demonMin,demonMax,1);//设置y轴坐标范围
    demoncurve->setSamples(demonxdata,demonydata);//设置采样
    demoncurve->attach(this->demoncvPlotcurve);//将曲线附加到qwtPlot上
    demoncvPlotcurve->replot();//重画
}

void Screenpas::on_btnStart_clicked()
{
    //MATLAB数据库初始化失败
    if (!isMatlabInit) {
        QMessageBox warningBox(QMessageBox::Warning, QString::fromLocal8Bit("初始化失败"), QString::fromLocal8Bit("Matlab初始化尚未完成，请等待!"));
        warningBox.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        warningBox.setStyleSheet("QPushButton {background-color:#00008B;color:#EBECFB;}"
                                 "QPushButton:hover {color:#398AF1;}"
                                 "QMessageBox {background-image:url(:/destop/dia_bg.png);}");
        warningBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
        warningBox.exec();

        return;
    }

    //未启动
    if (this->runStatus == UNSTART) {
        if (this->datFileName.isEmpty()) {//文件如果为空
            QMessageBox warningBox(QMessageBox::Warning, QString::fromLocal8Bit("运行失败"), QString::fromLocal8Bit("数据文件不存在,请检查数据文件"));
            warningBox.setStyleSheet("QPushButton {background-color:#00008B;color:#EBECFB;}"
                                     "QPushButton:hover {color:#398AF1;}"
                                     "QMessageBox {background-image:url(:/destop/dia_bg.png);}");
            warningBox.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
            warningBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
            warningBox.exec();

            return;
        }
        this->pDialog->setLabelText(QString::fromLocal8Bit("正在解析数据，请等待!"));

        this->pDialog->show();//解析数据

        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        emit enableTaskComboBox(false);

        emit start_parse(this->taskId, this->targetId, this->datFileName, this->cpData, this->edData, this->noiseLData
                         , this->noiseSData, this->fsdData, this->lofarData, this->demonData, this->echoData, this->noData);

    } else if (this->runStatus == PAUSE) {  //暂停
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

    } else if (this->runStatus == RUNNING) {//运行
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        this->fastftimes = 1;//reset
        this->fastbtimes = 1;//reset
        this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
        this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));

    } else if (this->runStatus == STOP) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        this->timerCount = 0;
        this->slider->setValue(this->timerCount);

        this->cpPlot->reset();
        this->cpPlotcurve->reset();
        this->lofarcvPlotcurve->reset();
        this->demoncvPlotcurve->reset();

        cpydata.clear();
        for(int i=1;i<timeInterval+1;i++){
            cpxdata.append(i);
            cpydata.append(0);
        }
        cplastpointtime = 0;

        lofarydata.clear();
        for(int i=1;i<timeInterval+1;i++){
            lofarxdata.append(i);
            lofarydata.append(0);
        }
        lofarlastpointtime = 0;

        demonydata.clear();
        for(int i=1;i<timeInterval+1;i++){
            demonxdata.append(i);
            demonydata.append(0);
        }
        demonlastpointtime = 0;


        this->pasPlot->reset();
        this->lofarcvPlot->reset();
        this->lofarcoPlot->reset();
        this->demoncvPlot->reset();
        this->demoncoPlot->reset();

        emit enableTaskComboBox(false);
    }
}

//停止按钮
void Screenpas::on_btnStop_clicked()
{
    if (this->runStatus == UNSTART)
        return;

    if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
    }

    this->cpPlot->reset();

    this->pasPlot->reset();
    this->lofarcvPlot->reset();
    this->lofarcoPlot->reset();
    this->demoncvPlot->reset();
    this->demoncoPlot->reset();

    this->runStatus = STOP;
    this->timerCount = 0;
    this->slider->setValue(this->timerCount);
    this->receivedDataCount = 0;
    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
    this->fastftimes = 1;//reset
    this->fastbtimes = 1;//reset
    this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
    this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));

    //modify1
    //该处的重新赋值非常重要，否则画面无法正常重启，且会出现故障。
    cpydata.clear();
    for(int i=1;i<timeInterval+1;i++){
        cpxdata.append(i);
        cpydata.append(0);
    }
    cplastpointtime = 0;

    lofarydata.clear();
    for(int i=1;i<timeInterval+1;i++){
        lofarxdata.append(i);
        lofarydata.append(0);
    }
    lofarlastpointtime = 0;

    demonydata.clear();
    for(int i=1;i<timeInterval+1;i++){
        demonxdata.append(i);
        demonydata.append(0);
    }
    demonlastpointtime = 0;

    tempMax = 0;
    tempMin = 0;
    cpMin = 0;
    cpMax = 0;
    lofarMin = 0;
    lofarMax = 0;
    demonMax = 0;
    demonMin = 0;
    cpcurve->setSamples(cpxdata,cpydata);//设置采样
    cpPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    cpcurve->attach(this->cpPlotcurve);//将曲线附加到qwtPlot上
    cpPlotcurve->replot();//重画

    lofarcurve->setSamples(lofarxdata,lofarydata);//设置采样
    lofarcvPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    lofarcurve->attach(this->lofarcvPlotcurve);//将曲线附加到qwtPlot上
    lofarcvPlotcurve->replot();//重画

    demoncurve->setSamples(demonxdata,demonydata);//设置采样
    demoncvPlotcurve->setAxisAutoScale(QwtPlot::yLeft,true);//Y轴坐标自动自动调整
    demoncurve->attach(this->demoncvPlotcurve);//将曲线附加到qwtPlot上
    demoncvPlotcurve->replot();//重画

    emit enableTaskComboBox(true);
}

//开始计时
void Screenpas::checkOrStartTimer()
{
    if (this->receivedDataCount == this->ALL_DATA_COUNT) {
        this->pDialog->hide();
        this->timerId = startTimer(1000);//调用 startTimer启动一个定时器,每1000ms就触发一次，直到调用killTimer()。
    }
}

//更新主动宽带警戒数据
void Screenpas::updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive cp data:"<<values.size();//输出"接收cp数据"
    this->receivedDataCount++;//所接收到的数据计数
    this->cpPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//modify1
void Screenpas::updateCpDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive cp data:"<<values.size();//输出"接收cp数据"
    this->receivedDataCount++;//所接收到的数据计数
    this->cpPlotcurve->setRawDatacurve(values, startTime, endTime);
    checkOrStartTimer();
}

void Screenpas::updatelofarDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive cp data:"<<values.size();//输出"接收cp数据"
    this->receivedDataCount++;//所接收到的数据计数
    this->lofarcvPlotcurve->setRawDatacurve(values, startTime, endTime);
    checkOrStartTimer();
}

void Screenpas::updatedemonDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive cp data:"<<values.size();//输出"接收cp数据"
    this->receivedDataCount++;//所接收到的数据计数
    this->demoncvPlotcurve->setRawDatacurve(values, startTime, endTime);
    checkOrStartTimer();
}

void Screenpas::updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive ed data:"<<values.size();
    this->receivedDataCount++;
    this->pasPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void Screenpas::updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive fsd data:"<<values.size();
    this->receivedDataCount++;
    this->lofarcvPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void Screenpas::updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive noiseL data"<<values.size();
    this->receivedDataCount++;
    this->lofarcoPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void Screenpas::updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive noiseS data"<<values.size();
    this->receivedDataCount++;

    this->demoncvPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void Screenpas::updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive lofar data"<<values.size();
    this->receivedDataCount++;

    this->demoncoPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void Screenpas::updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"receive echo data"<<values.size();

    this->receivedDataCount++;

    checkOrStartTimer();
}

void Screenpas::updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"receive no data"<<values.size();

    this->receivedDataCount++;

    checkOrStartTimer();
}

void Screenpas::updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive Demon data"<<values.size();

    this->receivedDataCount++;

    checkOrStartTimer();
}

//更新回声显示及相关参数赋值
//tmp.at(???)表示不同位置数据功能
void Screenpas::updateEchoDisplay()
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    QList<QVector<quint8>> result = this->echoData.values(current.toString("yyyy-MM-dd hh:mm:ss"));

    if (!result.isEmpty()) {
        //执行SQL语句后返回的结果集，
        QVector<quint8> tmp = result.at(0);//at() ：获得现在query指向的记录在结果集中的编号。
        int pihao = 5;//批号
        QString status = tmp.at(1) == 0 ? QString::fromLocal8Bit("实测值") : QString::fromLocal8Bit("预测值");//状态字
        QString trackWay = tmp.at(2) == 0 ? QString::fromLocal8Bit("调频") : QString::fromLocal8Bit("单频");//跟踪方式
        int bomen = tmp.at(3);//波门
        QString strBomen;
        if (bomen == 0){
            strBomen = QString::fromLocal8Bit("大");
        } else if (bomen == 1) {
            strBomen = QString::fromLocal8Bit("中");
        } else if (bomen == 2) {
            strBomen = QString::fromLocal8Bit("小");
        } else {
             strBomen = QString::fromLocal8Bit("丢失");
        }
        double fangwei = (tmp.at(4) + tmp.at(5)) * 180.0 / 32768;  //32768为2的15次方 目标方位
        double distance = tmp.at(6) + tmp.at(7)*256 + tmp.at(8)*256*256 + tmp.at(9)*256*256*256;//目标距离

        quint8 speedA = tmp.at(10), speedB = tmp.at(11);
        qint16 speed = 0;
        if (speedA & 0x80) {
            quint8 r_speedA = ~speedA + 1;
            quint8 r_speedB = ~speedB + 1;
            speed = ((qint16)r_speedA << 8) | r_speedB;//目标速度
        } else {
            speed = ((qint16)speedA << 8) | speedB;
        }
        int targetType = tmp.at(12);//目标类型
        QString strTargetType = QString::fromLocal8Bit("不明");
        switch (targetType) {
        case 0:
            strTargetType = QString::fromLocal8Bit("水面舰");
            break;
        case 1:
            strTargetType = QString::fromLocal8Bit("商铺船");
            break;
        case 2:
            strTargetType = QString::fromLocal8Bit("潜艇");
            break;
        case 3:
            strTargetType = QString::fromLocal8Bit("鱼雷");
            break;
        default:
            break;
        }
        int targetBeam = tmp.at(13) + tmp.at(14)*256;//目标波束号
        int targetLine = tmp.at(15) + tmp.at(16)*256;//目标线号
        QString str = QString::fromLocal8Bit("目标批号:%1\n状态字:%2\n跟踪方式:%3\n玻门类型:%4\n目标方位:%5\n目标距离:%6\n目标速度:%7\n目标类型:%8\n目标波束号:%9\n目标线号:%10\n")
                .arg(pihao).arg(status).arg(trackWay).arg(strBomen).arg(fangwei).arg(distance).arg(speed).arg(strTargetType).arg(targetBeam).arg(targetLine);
//        this->echoTxt->setPlainText(str);
        tableDisplay(QString::fromLocal8Bit("pihao%1").arg(pihao),status,trackWay,strBomen,QString::fromLocal8Bit("fangwei%1").arg(fangwei),QString::fromLocal8Bit("distance%1").arg(distance),QString::fromLocal8Bit("speed%1").arg(speed),strTargetType,QString::fromLocal8Bit("targetBeam%1").arg(targetBeam),QString::fromLocal8Bit("targetLine%1").arg(targetLine));
    } else {
        QString str = QString::fromLocal8Bit("目标批号:\n状态字:\n跟踪方式:\n玻门类型:\n目标方位:\n目标距离:\n目标速度:\n目标类型:\n目标波束号:\n目标线号:\n");
//        this->echoTxt->setPlainText(str);
        int pihao = 0;
        QString status = "";
        QString trackWay = "";
        QString strBomen = "";
        QString fangwei = "";
        QString distance = "";
        QString speed = "";
        QString strTargetType = "";
        QString targetBeam = "";
        QString targetLine = "";
        tableDisplay(QString::fromLocal8Bit("pihao%1").arg(pihao),status,trackWay,strBomen,QString::fromLocal8Bit("fangwei%1").arg(fangwei),QString::fromLocal8Bit("distance%1").arg(distance),QString::fromLocal8Bit("speed%1").arg(speed),strTargetType,QString::fromLocal8Bit("targetBeam%1").arg(targetBeam),QString::fromLocal8Bit("targetLine%1").arg(targetLine));
     }
}

void Screenpas::tableDisplay(QString pihao,QString status,QString trackWay,QString strBomen,QString fangwei,QString distance,QString speed,QString strTargetType,QString targetBeam,QString targetLine)
{
    echoTxt->setColumnCount(4);    //设置列数
    echoTxt->setRowCount(5);       //设置行数
    echoTxt->horizontalHeader()->setVisible(false);//隐藏列表头
    echoTxt->verticalHeader()->setVisible(false);//隐藏行表头

    echoTxt->setRowHeight(0,38);//设置1行高
    echoTxt->setRowHeight(1,38);//设置2行高
    echoTxt->setRowHeight(2,38);//设置3行高
    echoTxt->setRowHeight(3,38);//设置4行高
    echoTxt->setRowHeight(4,38);//设置5行高
    echoTxt->setColumnWidth(0,100);//设置1列宽
    echoTxt->setColumnWidth(1,215);//设置2列宽
    echoTxt->setColumnWidth(2,100);//设置3列宽
    echoTxt->setColumnWidth(3,215);//设置4列宽

    QTableWidgetItem* vHeader0=new QTableWidgetItem(QString::fromLocal8Bit("目标批号:"));
    QTableWidgetItem* vHeader1=new QTableWidgetItem(QString::fromLocal8Bit("状态字:"));//
    QTableWidgetItem* vHeader2=new QTableWidgetItem(QString::fromLocal8Bit("跟踪方式:"));//
    QTableWidgetItem* vHeader3=new QTableWidgetItem(QString::fromLocal8Bit("玻门类型:"));//
    QTableWidgetItem* vHeader4=new QTableWidgetItem(QString::fromLocal8Bit("目标方位:"));//
    QTableWidgetItem* vHeader5=new QTableWidgetItem(QString::fromLocal8Bit("目标距离:"));//
    QTableWidgetItem* vHeader6=new QTableWidgetItem(QString::fromLocal8Bit("目标速度:"));//
    QTableWidgetItem* vHeader7=new QTableWidgetItem(QString::fromLocal8Bit("目标类型:"));//
    QTableWidgetItem* vHeader8=new QTableWidgetItem(QString::fromLocal8Bit("目标波束号:"));//
    QTableWidgetItem* vHeader9=new QTableWidgetItem(QString::fromLocal8Bit("目标线号:"));//

    echoTxt->setItem(0,0,vHeader0);//设置行表头名称
    echoTxt->setItem(1,0,vHeader1);//设置行表头名称
    echoTxt->setItem(2,0,vHeader2);//设置行表头名称
    echoTxt->setItem(3,0,vHeader3);//设置行表头名称
    echoTxt->setItem(4,0,vHeader4);//设置行表头名称
    echoTxt->setItem(0,2,vHeader5);//设置行表头名称
    echoTxt->setItem(1,2,vHeader6);//设置行表头名称
    echoTxt->setItem(2,2,vHeader7);//设置行表头名称
    echoTxt->setItem(3,2,vHeader8);//设置行表头名称
    echoTxt->setItem(4,2,vHeader9);//设置行表头名称

}
void Screenpas::updateNoDisplay()
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    QList<QVector<quint8>> result = this->noData.values(current.toString("yyyy-MM-dd hh:mm:ss"));
    if (!result.isEmpty()) {
        QVector<quint8> tmp = result.at(0);    //取一条即可
        int pihao = 5;    //批号
        QString status = tmp.at(1) == 0 ? QString::fromLocal8Bit("实测值") : QString::fromLocal8Bit("预测值");  //状态字

        //目标方位
        double fangwei = (tmp.at(2) + tmp.at(3)) * 180.0 / 32768;  //32768为2的15次方

        int targetType = tmp.at(4);
        QString strTargetType = QString::fromLocal8Bit("不明");
        switch (targetType) {
        case 0:
            strTargetType = QString::fromLocal8Bit("水面舰");
            break;
        case 1:
            strTargetType = QString::fromLocal8Bit("商铺船");
            break;
        case 2:
            strTargetType = QString::fromLocal8Bit("潜艇");
            break;
        case 3:
            strTargetType = QString::fromLocal8Bit("鱼雷");
            break;
        default:
            break;
        }

        QString str = QString::fromLocal8Bit("目标批号:%1\n状态字:%2\n目标方位:%3\n目标类型:%4\n")
                .arg(pihao).arg(status).arg(fangwei).arg(strTargetType);
        this->noTxt->setPlainText(str);
    } else {
        QString str = QString::fromLocal8Bit("目标批号:\n状态字:\n目标方位:\n目标类型:\n");
        this->noTxt->setPlainText(str);
    }
}

//快进按钮，实现快速计数1倍速，2倍速，4倍速
void Screenpas::on_btnFastforward_clicked()
{
    if(fastbtimes != 1){
        fastbtimes = 1;
        this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));
    }

    if(this->runStatus == RUNNING)//未开始的情况下，点击无效
    {
        this->killTimer(this->timerId);//先停止计时
        fastftimes++;
        if(fastftimes == 2)
        {
            this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X2.png);"));
        }
        if(fastftimes == 3){
            fastftimes = 4;
            this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X4.png);"));

        }
        if(fastftimes == 5){
            fastftimes = 8;
            this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X8.png);"));
        }
        if(fastftimes == 9){
            fastftimes = 1;
            this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
        }
        this->timerId = startTimer(1000/fastftimes);//重启定时器。
    }else
    {
    //什么也不执行
    }
}

void Screenpas::on_btnFastbackward_clicked()
{
    if(fastftimes != 1){
        fastftimes = 1;
        this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
    }
    if(this->runStatus == RUNNING)//未开始的情况下，点击无效
    {
        this->killTimer(this->timerId);//先停止计时
        fastbtimes++;
        if(fastbtimes == 2)
        {
            this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X2.png);"));
        }
        if(fastbtimes == 3){
            fastbtimes = 4;
            this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X4.png);"));

        }
        if(fastbtimes == 5){
            fastbtimes = 8;
            this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/X8.png);"));
        }
        if(fastbtimes == 9){
            fastbtimes = 1;
            this->btnFastbackward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastbackward.png);"));
        }
        this->timerId = startTimer(1000/fastbtimes);//重启定时器。
    }else
    {
    //什么也不执行
    }
}

//鼠标拖拽功能
bool Screenpas::eventFilter(QObject *obj, QEvent *event)
{
   if (obj == this->slider) {
       if (event->type() == QEvent::MouseButtonPress) {
           if (this->runStatus == RUNNING) {
               this->runStatus = PAUSE;
               this->killTimer(this->timerId);
               this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
           }
       } else if (event->type() == QEvent::MouseButtonRelease) {
           QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
           if (mouseEvent->button() == Qt::LeftButton) {
               int dur = this->slider->maximum() - this->slider->minimum();
               int pos = this->slider->minimum() + dur * ((double)mouseEvent->x() / this->slider->width());
               this->timerCount = pos;
               this->slider->setValue(this->timerCount);

               if (this->runStatus == PAUSE) {
                   this->timerId = this->startTimer(1000);
                   this->runStatus = RUNNING;
                   this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
               }
           }
       }
   }
   return QWidget::eventFilter(obj, event);
}

double Screenpas::axisYMaximum(double temp)
{
    if(tempMax < temp)
        tempMax = temp;
    return tempMax;
}
double Screenpas::axisYMinimum(double temp)
{
    if(tempMin > temp)
        tempMin = temp;
    return tempMin;
}
