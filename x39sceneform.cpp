#include "x39sceneform.h"
#include "ui_x39sceneform.h"
#include "run_status.h"
#include "hysmainwindow.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QMouseEvent>
#include <QWidget>

extern bool isMatlabInit;


X39SceneForm::X39SceneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X39SceneForm)
{
    ui->setupUi(this);
    initUI();

    //新线程
    this->pThread = new QThread(this);
    this->pThread->setObjectName("x39_scene_parser");

    //场景数据解析
    this->parser = new X39SceneParseData();
    this->parser->moveToThread(this->pThread);
    connect(this, &X39SceneForm::start_parse, this->parser, &X39SceneParseData::parse);

    //信号与槽连接， 数据->图片
    connect(this->parser, &X39SceneParseData::send_cpdata, this, &X39SceneForm::updateCpData);
    connect(this->parser, &X39SceneParseData::send_eddata, this, &X39SceneForm::updateEdData);
    connect(this->parser, &X39SceneParseData::send_noiseldata, this, &X39SceneForm::updateNoiseLData);
    connect(this->parser, &X39SceneParseData::send_noisesdata, this, &X39SceneForm::updateNoiseSData);
    connect(this->parser, &X39SceneParseData::send_fsddata, this, &X39SceneForm::updateFsdData);
    connect(this->parser, &X39SceneParseData::send_lofardata, this, &X39SceneForm::updateLofarData);
    connect(this->parser, &X39SceneParseData::send_demondata, this, &X39SceneForm::updateDemonData);
    connect(this->parser, &X39SceneParseData::send_echodata, this, &X39SceneForm::updateEchoData);
    connect(this->parser, &X39SceneParseData::send_nodata, this, &X39SceneForm::updateNoData);

    this->pThread->start();
}

//析构函数，释放内存
X39SceneForm::~X39SceneForm()
{
    delete ui;
    delete this->pDialog;

    this->pThread->quit();
    this->pThread->wait();
    delete this->parser;
    delete this->pThread;
}

//界面初始化
void X39SceneForm::initUI()
{
    this->pDialog = new QProgressDialog(this);
    this->pDialog->setStyleSheet("QLabel {border-image:none;}");//显示图片效果
    this->pDialog->setModal(true);
    this->pDialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    this->pDialog->setCancelButton(NULL);
    this->pDialog->setMaximum(0);
    this->pDialog->setMinimum(0);
    this->pDialog->reset();

    this->lbStartTime = this->ui->lbStart;
    this->lbEndTime = this->ui->lbEnd;

    this->btnStart = this->ui->btnStart;
    this->btnStop = this->ui->btnStop;
    this->slider = this->ui->slider;
    this->slider->installEventFilter(this);

    //主动及被动数据选择
    this->rbActive = this->ui->rbActive;
    this->rbPassive = this->ui->rbPassive;

    this->vlayout = this->ui->vlContainer;

    this->tabWidget = this->ui->tabWidget;
    //窄带警戒widget(0)
    this->edPlot = this->tabWidget->widget(0)->findChildren<MpColorPlot *>("edPlot").at(0);
    this->edPlot->setDimension(480, 780);
    //噪声历程长widget(1)
    this->noiseLPlot = (MpColorPlot *)this->tabWidget->widget(1)->findChildren<MpColorPlot *>("noiseLPlot").at(0);
    this->noiseLPlot->setDimension(480, 780);
    //噪声历程短widget(2)
    this->noiseSPlot = (MpColorPlot *)this->tabWidget->widget(2)->findChildren<MpColorPlot *>("noiseSPlot").at(0);
    this->noiseSPlot->setDimension(480, 780);
    //多普勒widget(3)
    this->fsdPlot = (MpColorPlot *)this->tabWidget->widget(3)->findChildren<MpColorPlot *>("fsdPlot").at(0);
    this->fsdPlot->setDimension(480, 780);

    this->tabWidget->setCurrentIndex(0);

    // 右侧主动宽带警戒界面
    this->x39AcForm = new Ui::X39ScActiveForm();
    this->x39AcWidget = new QWidget(NULL);
    //先构建一个QWidget界面，再加载xml构建出我们创建的ui界面
    this->x39AcForm->setupUi(this->x39AcWidget);
    this->cpPlot = this->x39AcForm->cpPlot;
    this->cpPlot->setDimension(480, 780);

    // 右侧被动界面
    this->x39PaForm = new Ui::X39ScPassiveForm();
    this->x39PaWidget = new QWidget(NULL);
    //先构建一个QWidget界面，再加载xml构建出我们创建的ui界面
    this->x39PaForm->setupUi(this->x39PaWidget);
    //LOFAR
    this->lofarPlot = this->x39PaForm->lofarPlot;
    this->lofarPlot->setDimension(129, 300);
    //DEMON
    this->demonPlot = this->x39PaForm->demonPlot;
    this->demonPlot->setDimension(900, 300);
    //回声目标跟踪数据
    this->echoTxt = this->x39PaForm->echoTxt;
    //噪声目标跟踪数据
    this->noTxt = this->x39PaForm->noTxt;

    //默认显示主动
    this->vlayout->addWidget(this->x39AcWidget);
    this->type = FormType::ACTIVE;
    this->rbActive->setChecked(true);
}

//任务初始化
void X39SceneForm::initTask(int taskId, int targetId)
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
    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);

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
    this->edPlot->setGlobalInterval(this->startTime, this->endTime);
    this->fsdPlot->setGlobalInterval(this->startTime, this->endTime);
    this->noiseLPlot->setGlobalInterval(this->startTime, this->endTime);
    this->noiseSPlot->setGlobalInterval(this->startTime, this->endTime);
    this->lofarPlot->setGlobalInterval(this->startTime, this->endTime);
    this->demonPlot->setGlobalInterval(this->startTime, this->endTime);

}

//图形同步更新定时器
void X39SceneForm::timerEvent(QTimerEvent *e)
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    if (current > this->endTime) {
        this->killTimer(this->timerId);//停止计时
        this->runStatus = STOP;
        this->timerCount = 0;
        this->receivedDataCount = 0;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        emit enableTaskComboBox(true);

        return;
    }

    //计时条
    this->slider->setValue(this->timerCount);

    //定时更新
    this->cpPlot->setTimerCount(this->timerCount);
    this->cpPlot->update();

    this->edPlot->setTimerCount(this->timerCount);
    this->edPlot->update();

    this->fsdPlot->setTimerCount(this->timerCount);
    this->fsdPlot->update();

    this->noiseSPlot->setTimerCount(this->timerCount);
    this->noiseSPlot->update();

    this->noiseLPlot->setTimerCount(this->timerCount);
    this->noiseLPlot->update();

    this->lofarPlot->setTimerCount(this->timerCount);
    this->lofarPlot->update();

    this->demonPlot->setTimerCount(this->timerCount);
    this->demonPlot->update();
    this->updateEchoDisplay();
    this->updateNoDisplay();

    this->timerCount++;
}

void X39SceneForm::on_btnStart_clicked()
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
    } else if (this->runStatus == STOP) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        this->timerCount = 0;
        this->slider->setValue(this->timerCount);

        this->cpPlot->reset();
        this->edPlot->reset();
        this->fsdPlot->reset();
        this->noiseSPlot->reset();
        this->noiseLPlot->reset();
        this->lofarPlot->reset();
        this->demonPlot->reset();

        emit enableTaskComboBox(false);
    }
}

//停止按钮
void X39SceneForm::on_btnStop_clicked()
{
    if (this->runStatus == UNSTART)
        return;

    if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
    }

    this->cpPlot->reset();
    this->edPlot->reset();
    this->fsdPlot->reset();
    this->noiseSPlot->reset();
    this->noiseLPlot->reset();
    this->lofarPlot->reset();
    this->demonPlot->reset();

    this->runStatus = STOP;
    this->timerCount = 0;
    this->slider->setValue(this->timerCount);
    this->receivedDataCount = 0;
    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));

    emit enableTaskComboBox(true);
}

//主动界面
void X39SceneForm::on_rbActive_toggled(bool checked)
{
    if (checked) {
        this->x39AcWidget->setParent(this);
        this->x39PaWidget->setParent(NULL);

        this->vlayout->removeWidget(this->x39PaWidget);
        this->vlayout->addWidget(this->x39AcWidget);
    }
}

//被动界面
void X39SceneForm::on_rbPassive_toggled(bool checked)
{
    if (checked) {
        this->x39AcWidget->setParent(NULL);
        this->x39PaWidget->setParent(this);

        this->vlayout->addWidget(this->x39PaWidget);
        this->vlayout->removeWidget(this->x39AcWidget);
    }
}
//开始计时
void X39SceneForm::checkOrStartTimer()
{
    if (this->receivedDataCount == this->ALL_DATA_COUNT) {
        this->pDialog->hide();

        qDebug()<<"start timer";
        this->timerId = startTimer(1000);//调用 startTimer启动一个定时器,每1000ms就触发一次，直到调用killTimer()。
    }
}

//更新主动宽带警戒数据
void X39SceneForm::updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive cp data:"<<values.size();//输出"接收cp数据"
    this->receivedDataCount++;//所接收到的数据计数
    this->cpPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive ed data:"<<values.size();

    this->receivedDataCount++;
    this->edPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive fsd data:"<<values.size();

    this->receivedDataCount++;
    this->fsdPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive noiseL data";

    this->receivedDataCount++;
    this->noiseLPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive noiseS data";

    this->receivedDataCount++;
    this->noiseSPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"receive lofar data";

    this->receivedDataCount++;
    this->lofarPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

void X39SceneForm::updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"receive echo data";

    this->receivedDataCount++;

    checkOrStartTimer();
}

void X39SceneForm::updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"receive no data";

    this->receivedDataCount++;

    checkOrStartTimer();
}

void X39SceneForm::updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    this->receivedDataCount++;
    this->demonPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新回声显示及相关参数赋值
//tmp.at(???)表示不同位置数据功能
void X39SceneForm::updateEchoDisplay()
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    QList<QVector<quint8>> result = this->echoData.values(current.toString("yyyy-MM-dd hh:mm:ss"));
    if (!result.isEmpty()) {
        //执行SQL语句后返回的结果集，
        QVector<quint8> tmp = result.at(0);//at() ：获得现在query指向的记录在结果集中的编号。
        int pihao = 5;//批号
        QString status = tmp.at(1) == 0 ? QString::fromLocal8Bit("实测值") : QString::fromLocal8Bit("预测值");
        QString trackWay = tmp.at(2) == 0 ? QString::fromLocal8Bit("调频") : QString::fromLocal8Bit("单频");
        int bomen = tmp.at(3);
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

        double fangwei = (tmp.at(4) + tmp.at(5)) * 180.0 / 32768;  //32768为2的15次方
        double distance = tmp.at(6) + tmp.at(7)*256 + tmp.at(8)*256*256 + tmp.at(9)*256*256*256;

        quint8 speedA = tmp.at(10), speedB = tmp.at(11);
        qint16 speed = 0;
        if (speedA & 0x80) {
            quint8 r_speedA = ~speedA + 1;
            quint8 r_speedB = ~speedB + 1;
            speed = ((qint16)r_speedA << 8) | r_speedB;
        } else {
            speed = ((qint16)speedA << 8) | speedB;
        }

        int targetType = tmp.at(12);
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
        int targetBeam = tmp.at(13) + tmp.at(14)*256;
        int targetLine = tmp.at(15) + tmp.at(16)*256;

        QString str = QString::fromLocal8Bit("目标批号:%1\n状态字:%2\n跟踪方式:%3\n玻门类型:%4\n目标方位:%5\n目标距离:%6\n目标速度:%7\n目标类型:%8\n目标波束号:%9\n目标线号:%10\n")
                .arg(pihao).arg(status).arg(trackWay).arg(strBomen).arg(fangwei).arg(distance).arg(speed).arg(strTargetType).arg(targetBeam).arg(targetLine);

        this->echoTxt->setPlainText(str);
    } else {
        QString str = QString::fromLocal8Bit("目标批号:\n状态字:\n跟踪方式:\n玻门类型:\n目标方位:\n目标距离:\n目标速度:\n目标类型:\n目标波束号:\n目标线号:\n");
        this->echoTxt->setPlainText(str);
    }
}

void X39SceneForm::updateNoDisplay()
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

//消息过滤
bool X39SceneForm::eventFilter(QObject *obj, QEvent *event)
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

