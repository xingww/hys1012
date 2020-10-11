#include "x31sceneform.h"
#include "ui_x31sceneform.h"
#include "hysmainwindow.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QThreadPool>
#include <QMouseEvent>

extern bool isMatlabInit;

//X31SceneForm对象
X31SceneForm::X31SceneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X31SceneForm)
{
    ui->setupUi(this);
    initUI();
}

//析构函数，释放内存
X31SceneForm::~X31SceneForm()
{
    delete ui;
    delete this->pDialog;

    if (this->cpRunnable != NULL) {
        delete this->cpRunnable;
    }

    if (this->lofarRunnable != NULL) {
        delete this->lofarRunnable;
    }

    if (this->demonRunnable != NULL) {
        delete this->demonRunnable;
    }

    if (this->passiveRunnable != NULL) {
        delete this->passiveRunnable;
    }

    if (this->multiLofarRunnable != NULL) {
        delete this->multiLofarRunnable;
    }

    if (this->hfmTrackRunnable != NULL) {
        delete this->hfmTrackRunnable;
    }

    if (this->passiveTrackRunnable != NULL) {
        delete this->passiveRunnable;
    }
}

//初始化
void X31SceneForm::initUI()
{

    this->pDialog = new QProgressDialog(this);
    this->pDialog->setStyleSheet("QLabel {border-image:none;}");
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

    this->rbActive = this->ui->rbActive;
    this->rbPassive = this->ui->rbPassive;

    this->vlayout = this->ui->vlContainer;

    //左侧TabWidget
    this->tabWidget = this->ui->tabWidget;
    this->passivePlot = this->tabWidget->widget(0)->findChildren<MpColorPlot *>("fullPlot").at(0);
    this->passivePlot->setDimension(165, 100);
    this->multiLofarPlot = this->tabWidget->widget(1)->findChildren<MpColorPlot *>("zdLofarPlot").at(0);
    this->multiLofarPlot->setDimension(500, 100);

    this->tabWidget->setCurrentIndex(0);

    this->x31AcForm = new Ui::X31ScActiveForm();
    this->x31AcWidget = new QWidget(NULL);
    this->x31AcForm->setupUi(this->x31AcWidget);//
    this->cpPlot = this->x31AcForm->activePlot;
    this->cpPlot->setDimension(492, 768);
    this->tbAcSearchText = this->x31AcForm->tbAcSearch;

    this->x31PaForm = new Ui::X31ScPassiveForm();
    this->x31PaWidget = new QWidget(NULL);
    this->x31PaForm->setupUi(this->x31PaWidget);
    this->lofarPlot = this->x31PaForm->lofarPlot;
    this->lofarPlot->setDimension(410, 100);
    this->demonPlot = this->x31PaForm->demonPlot;
    this->demonPlot->setDimension(482, 100);
    this->tbPaSearchText = this->x31PaForm->tbPaSearch;

    this->vlayout->addWidget(this->x31AcWidget);
    this->type = FormType::ACTIVE;
    this->rbActive->setChecked(true);
}

//复位使能
void X31SceneForm::resetRunnable()
{
    if (this->cpRunnable == NULL) {
        this->cpRunnable = new X31SceneCpRunnable(this->taskId, this->targetId, this->datFileName, this->cpData);
        connect(this->cpRunnable, &X31SceneCpRunnable::send_cpdata, this, &X31SceneForm::updateCpData);
    }
    this->cpRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->lofarRunnable == NULL) {
        this->lofarRunnable = new X31SceneLofarRunnable(this->taskId, this->targetId, this->datFileName, this->lofarData);
        connect(this->lofarRunnable, &X31SceneLofarRunnable::send_lofardata, this, &X31SceneForm::updateLofarData);
    }
    this->lofarRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->demonRunnable == NULL) {
        this->demonRunnable = new X31SceneDemonRunnable(this->taskId, this->targetId, this->datFileName, this->demonData);
        connect(this->demonRunnable, &X31SceneDemonRunnable::send_demondata, this, &X31SceneForm::updateDemonData);
    }
    this->demonRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->passiveRunnable == NULL) {
        this->passiveRunnable = new X31ScenePassiveRunnable(this->taskId, this->targetId, this->datFileName, this->passiveData);
        connect(this->passiveRunnable, &X31ScenePassiveRunnable::send_passivedata, this, &X31SceneForm::updatePassiveData);
    }
    this->passiveRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->multiLofarRunnable == NULL) {
        this->multiLofarRunnable = new X31SceneMultiLofarRunnable(this->taskId, this->targetId, this->datFileName, this->multiLofarData);
        connect(this->multiLofarRunnable, &X31SceneMultiLofarRunnable::send_multilofardata, this, &X31SceneForm::updateMultiLofarData);
    }
    this->multiLofarRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->hfmTrackRunnable == NULL) {
        this->hfmTrackRunnable = new X31SceneHfmTrackRunnable(this->taskId, this->targetId, this->datFileName, this->hfmTrackData);
        connect(this->hfmTrackRunnable, &X31SceneHfmTrackRunnable::send_hfmtrackdata, this, &X31SceneForm::updateHfmTrackData);
    }
    this->hfmTrackRunnable->resetParam(this->taskId, this->targetId, this->datFileName);

    if (this->passiveTrackRunnable == NULL) {
        this->passiveTrackRunnable = new X31ScenePassiveTrackRunnable(this->taskId, this->targetId, this->datFileName, this->passiveTrackData);
        connect(this->passiveTrackRunnable, &X31ScenePassiveTrackRunnable::send_passivetrackdata, this, &X31SceneForm::updatePassiveTrackData);
    }
    this->passiveTrackRunnable->resetParam(this->taskId, this->targetId, this->datFileName);
}

//初始化任务
void X31SceneForm::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    if (this->targetId == HysMainWindow::SELF_DATA) {
        TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );
        model->setFilter(QString("id=%1").arg(this->taskId));
        model->select();
        if (model->rowCount() != 1) {
            delete model;
            return;
        }

        QSqlRecord record = model->record(0);
        this->startTime = record.value("start_time").toDateTime();
        this->endTime = record.value("end_time").toDateTime();
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

    // 模拟数据
    this->datFileName = "D:/Test_dataForX1.jz";
    this->startTime = QDateTime::fromString("2020-01-06 19:19:35", "yyyy-MM-dd hh:mm:ss");
    this->endTime = QDateTime::fromString("2020-01-06 21:05:00", "yyyy-MM-dd hh:mm:ss");

     //计算时间间隔
    this->timeInterval = this->endTime.toSecsSinceEpoch() - this->startTime.toSecsSinceEpoch();
    this->timerCount = 0;

    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);

    this->cpData.clear();
    this->lofarData.clear();
    this->demonData.clear();
    this->multiLofarData.clear();
    this->passiveData.clear();
    this->passiveTrackData.clear();
    this->hfmTrackData.clear();

    this->lbStartTime->setText(this->startTime.toString("yyyy-MM-dd hh:mm:ss"));
    this->lbEndTime->setText(this->endTime.toString("yyyy-MM-dd hh:mm:ss"));

    this->cpPlot->setGlobalInterval(this->startTime, this->endTime);
    this->lofarPlot->setGlobalInterval(this->startTime, this->endTime);
    this->demonPlot->setGlobalInterval(this->startTime, this->endTime);
    this->multiLofarPlot->setGlobalInterval(this->startTime, this->endTime);
    this->passivePlot->setGlobalInterval(this->startTime, this->endTime);

    resetRunnable();
}


void X31SceneForm::checkOrStartTimer()
{
    //确认接收所有的7组数据信息后，开始计时
    if (this->receivedDataCount == this->ALL_DATA_COUNT) {
        this->pDialog->hide();
        //调用 startTimer启动一个定时器,每1000ms就触发一次，直到调用killTimer()。
        this->timerId = startTimer(1000);
    }
}
//时间事件
void X31SceneForm::timerEvent(QTimerEvent *e)
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    if (current > this->endTime) {
        //如果计时结束
        this->killTimer(this->timerId);
        this->runStatus = STOP;
        this->timerCount = 0;
        this->receivedDataCount = 0;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        emit enableTaskComboBox(true);
        return;
    }

    this->slider->setValue(this->timerCount);

    this->cpPlot->setTimerCount(this->timerCount);
    this->cpPlot->update();

    this->multiLofarPlot->setTimerCount(this->timerCount);
    this->multiLofarPlot->update();

    this->lofarPlot->setTimerCount(this->timerCount);
    this->lofarPlot->update();

    this->demonPlot->setTimerCount(this->timerCount);
    this->demonPlot->update();

    this->passivePlot->setTimerCount(this->timerCount);
    this->passivePlot->update();

    //更新显示
    this->updateHfmTrackDisplay();
    this->updatePassiveTrackDisplay();

    this->timerCount++;
}

//开始按钮
void X31SceneForm::on_btnStart_clicked()
{
    //MATLAB未初始化
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

    //未开始
    if (this->runStatus == UNSTART) {
        if (this->datFileName.isEmpty()) {
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
        this->pDialog->show();

        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        emit enableTaskComboBox(false);

        QThreadPool::globalInstance()->start(this->cpRunnable);
        QThreadPool::globalInstance()->start(this->lofarRunnable);
        QThreadPool::globalInstance()->start(this->demonRunnable);
        QThreadPool::globalInstance()->start(this->passiveRunnable);
        QThreadPool::globalInstance()->start(this->multiLofarRunnable);
        QThreadPool::globalInstance()->start(this->hfmTrackRunnable);
        QThreadPool::globalInstance()->start(this->passiveTrackRunnable);
    }
    //暂停
    else if (this->runStatus == PAUSE) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
    }
    //运行中
    else if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
    }
    //停止
    else if (this->runStatus == STOP) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        emit enableTaskComboBox(false);
    }
}

//停止按钮
void X31SceneForm::on_btnStop_clicked()
{
    if (this->runStatus == UNSTART || this->runStatus == STOP)
        return;

    if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
    }

    this->cpPlot->reset();
    this->multiLofarPlot->reset();
    this->lofarPlot->reset();
    this->demonPlot->reset();
    this->passivePlot->reset();

    this->runStatus = STOP;
    this->timerCount = 0;
    this->slider->setValue(this->timerCount);
    this->receivedDataCount = 0;
    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));

    emit enableTaskComboBox(true);
}

//主动
void X31SceneForm::on_rbActive_toggled(bool checked)
{
    if (checked) {
        this->x31AcWidget->setParent(this);
        this->x31PaWidget->setParent(NULL);

        this->vlayout->removeWidget(this->x31PaWidget);
        this->vlayout->addWidget(this->x31AcWidget);
    }
}

//被动
void X31SceneForm::on_rbPassive_toggled(bool checked)
{
    if (checked) {
        this->x31PaWidget->setParent(this);
        this->x31AcWidget->setParent(NULL);

        this->vlayout->removeWidget(this->x31AcWidget);
        this->vlayout->addWidget(this->x31PaWidget);
    }
}

//更新Cp数据
void X31SceneForm::updateCpData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"update cp data:"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;
    this->cpPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新lofar数据
void X31SceneForm::updateLofarData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"update lofar data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;
    this->lofarPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新Demon数据
void X31SceneForm::updateDemonData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"update demon data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;
    this->demonPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新被动数据
void X31SceneForm::updatePassiveData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"update passive data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;
    this->passivePlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新multiLofar数据
void X31SceneForm::updateMultiLofarData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values)
{
    qDebug()<<"update multilofar data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;
    this->multiLofarPlot->setRawData(values, startTime, endTime);

    checkOrStartTimer();
}

//更新HfmTrackData数据
void X31SceneForm::updateHfmTrackData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"update hfmtrack data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;

    checkOrStartTimer();
}

//更新被动跟踪数据
void X31SceneForm::updatePassiveTrackData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    qDebug()<<"update passivetrack data"<<startTime<<"--"<<endTime;
    this->receivedDataCount++;

    checkOrStartTimer();
}

//回声目标跟踪数据
void X31SceneForm::updateHfmTrackDisplay()
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    QList<QVector<quint8>> result = this->hfmTrackData.values(current.toString("yyyy-MM-dd hh:mm:ss"));
    if (!result.isEmpty()) {//如果有数据
        QVector<quint8> tmp = result.at(0);//返回索引号为0的数据
        int batchNo = tmp.at(0);//批次号
        int status = tmp.at(1);//状态号
        QString strStatus = status == 0 ? QString::fromLocal8Bit("实测值") : QString::fromLocal8Bit("预测值");

        int trackWay = tmp.at(2);//跟踪方式
        QString strTrackWay = trackWay == 0 ? QString::fromLocal8Bit("调频") : QString::fromLocal8Bit("单频");

        int bomenType = tmp.at(3);//波门类型
        QString strBomen;
        if (bomenType == 0){
            strBomen = QString::fromLocal8Bit("大");
        } else if (bomenType == 1) {
            strBomen = QString::fromLocal8Bit("中");
        } else if (bomenType == 2) {
            strBomen = QString::fromLocal8Bit("小");
        } else {
             strBomen = QString::fromLocal8Bit("丢失");
        }

        int targetLoc1 = tmp.at(4);//目标位置1
        int targetLoc2 = tmp.at(5);//目标位置2
        int targetLoc = (targetLoc1 + 256 * targetLoc2) * 180.0 / 32768;

        int targetDis1 = tmp.at(6);//目标距离1
        int targetDis2 = tmp.at(7);//目标距离2
        int targetDis3 = tmp.at(8);//目标距离3
        int targetDis4 = tmp.at(9);//目标距离4
        int targetDis = targetDis1 + targetDis2 * 256 + targetDis3 * 256 * 256 + targetDis4 * 256 * 256;

        quint8 targetSpeed1 = tmp.at(10);//目标速度1
        quint8 targetSpeed2 = tmp.at(11);//目标速度2
        qint16 speed = 0;
        if (targetSpeed1 & 0x80) {
            quint8 r_targetSpeed1 = ~targetSpeed1 + 1;
            quint8 r_targetSpeed2 = ~targetSpeed2 + 1;
            speed = ((qint16)r_targetSpeed1 << 8) | r_targetSpeed2;
        } else {
            speed = ((qint16)targetSpeed1 << 8) | targetSpeed2;
        }
        speed = speed * 0.1;

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

        int boshuNo1 = tmp.at(13);//波束号1
        int boshuNo2 = tmp.at(14);//波束号2
        int boshu = boshuNo1 + boshuNo2 * 256;
        boshu = boshu > 492 ? 492 : boshu;

        int lineNo1 = tmp.at(15);//线号1
        int lineNo2 = tmp.at(16);//线号2
        int lineNo = lineNo1 + lineNo2 * 256;
        lineNo = lineNo > 768 ? 768 : lineNo;

        QString str = QString::fromLocal8Bit("目标批号:%1\n状态字:%2\n跟踪方式:%3\n玻门类型:%4\n目标方位:%5\n目标距离:%6\n目标速度:%7\n目标类型:%8\n目标波束号:%9\n目标线号:%10\n").
                arg(batchNo).arg(strStatus).arg(strTrackWay).arg(strBomen).
                arg(targetLoc).arg(targetDis).arg(speed).arg(strTargetType).arg(boshu).arg(lineNo);
        //主动搜索内容显示
        this->tbAcSearchText->setText(str);
    } else {
        QString str = QString::fromLocal8Bit("目标批号:\n状态字:\n跟踪方式:\n玻门类型:\n目标方位:\n目标距离:\n目标速度:\n目标类型:\n目标波束号:\n目标线号:\n");
        this->tbAcSearchText->setText(str);
    }
}

//更新被动跟踪显示
void X31SceneForm::updatePassiveTrackDisplay()
{
    QDateTime current = this->startTime.addSecs(this->timerCount);
    QList<QVector<quint8>> result = this->passiveTrackData.values(current.toString("yyyy-MM-dd hh:mm:ss"));
    if (!result.isEmpty()) {
        QVector<quint8> tmp = result.at(0);    //取一条即可
        int pihao = 5;    //批号
        QString status = tmp.at(1) == 0 ? QString::fromLocal8Bit("实测值") : QString::fromLocal8Bit("预测值");  //状态字

        quint8 targetAngle1 = tmp.at(2);//目标角度
        quint8 targetAngle2 = tmp.at(3);//目标角度
        qint16 angle = 0;
        if (targetAngle1 & 0x80) {
            quint8 r_targetAngle1 = ~targetAngle1 + 1;
            quint8 r_targetAngle2 = ~targetAngle2 + 1;
            angle = ((qint16)r_targetAngle1 << 8) | r_targetAngle2;//将两个8byte数据拼接为16byte数据
        } else {
            angle = ((qint16)targetAngle1 << 8) | targetAngle2;
        }
        angle = angle * 0.1;

        int targetType = tmp.at(4);//目标类型
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

        int boshuNo1 = tmp.at(5);//波束号1
        int boshuNo2 = tmp.at(6);//波束号2
        int boshu = boshuNo1 + boshuNo2 * 256;
        boshu = boshu > 492 ? 492 : boshu;

        QString str = QString::fromLocal8Bit("目标批号:%1\n状态字:%2\n目标舷角:%3\n目标类型:%4\n波束号:%5\n")
                .arg(pihao).arg(status).arg(angle).arg(strTargetType).arg(boshu);

        this->tbPaSearchText->setPlainText(str);
    } else {
        QString str = QString::fromLocal8Bit("目标批号:\n状态字:\n目标舷角:\n目标类型:\n波束号:\n");
        this->tbPaSearchText->setPlainText(str);
    }
}

//事件过滤器
bool X31SceneForm::eventFilter(QObject *obj, QEvent *event)
{//进度条
   if (obj == this->slider) {//鼠标按下
       if (event->type() == QEvent::MouseButtonPress) {//运行状态
           if (this->runStatus == RUNNING) {
               this->runStatus = PAUSE;
               this->killTimer(this->timerId);
               this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
           }
       }else if (event->type() == QEvent::MouseButtonRelease) { //鼠标释放
           QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
           if (mouseEvent->button() == Qt::LeftButton) {//左键
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

