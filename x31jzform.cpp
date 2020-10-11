#include "x31jzform.h"
#include "ui_x31jzform.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include "hysmainwindow.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QFileInfo>
#include <QMouseEvent>
#include <QPoint>

extern bool isMatlabInit;

//X31JzForm对象
X31JzForm::X31JzForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X31JzForm)
{
    ui->setupUi(this);
    initUI();

    this->pThread = new QThread(this);
    this->pThread->setObjectName("x31_jz_parser");

    //创建对象parse，类为X31JzParseData()
    this->parser = new X31JzParseData();
    this->parser->moveToThread(this->pThread);

    //信号与槽连接
    connect(this, &X31JzForm::start_parse, this->parser, &X31JzParseData::parse);
    connect(this->parser, &X31JzParseData::send_data, this, &X31JzForm::updateData);
    connect(this->parser, &X31JzParseData::complete_parse, this, &X31JzForm::completedParseFile);

    this->pThread->start();
}

//析构函数，释放内存
X31JzForm::~X31JzForm()
{
    delete ui;
    delete this->pDialog;

    this->pThread->quit();
    this->pThread->wait();
    delete this->parser;
    delete this->pThread;
}

//初始化界面
void X31JzForm::initUI()
{
    this->pDialog = new QProgressDialog(this);//初始化时进度对话框
    this->pDialog->setStyleSheet("QLabel {border-image:none;}");//显示图片效果
    this->pDialog->setModal(true);//
    this->pDialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//设置窗口
    this->pDialog->setCancelButton(NULL);//没有取消按钮”NULL“
    this->pDialog->setMaximum(0);//设置最大值
    this->pDialog->setMinimum(0);//设置最小值
    this->pDialog->reset();//恢复

    this->lbStartTime = this->ui->lbStart;//开始时间
    this->lbEndTime = this->ui->lbEnd;//结束时间

    this->btnStart = this->ui->btnStart;//开始按钮
    this->btnStop = this->ui->btnStop;//结束按钮
    this->slider = this->ui->slider;//进度条
    this->slider->installEventFilter(this);//安装一个事件过滤对象

    this->rbActive = this->ui->rbActive;//主动按钮
    this->rbPassive = this->ui->rbPassive;//被动按钮

    this->vLayout = this->ui->hlvContainer;//容器

    this->tabWidget = this->ui->tabWidget;//多个页面公用一个区域
    this->pwdPlot = this->tabWidget->widget(0)->findChildren<MStreampColorPlot *>("pwdPlot").at(0);
    this->pwdPlot->setDimension(165, 20);
    this->pwdPlot->installEventFilter(this);
    this->mbLofarPlot = this->tabWidget->widget(1)->findChildren<MStreampColorPlot *>("mbLofarPlot").at(0);
    this->mbLofarPlot->setDimension(41, 5000);

    this->tabWidget->setCurrentIndex(0);//设置当前序号为0

    this->x31AcForm = new Ui::X31JzActiveForm();//创建X31JzActiveForm()的对象
    this->x31AcWidget = new QWidget(NULL);//
    this->x31AcForm->setupUi(this->x31AcWidget);//开启显示
    this->cpPlot = this->x31AcForm->cpPlot;//cp显示主动宽带警戒显示
    this->cpPlot->setDimension(492, 480);

    this->x31PaForm = new Ui::X31JzPassiveForm();//创建对象
    this->x31PaWidget = new QWidget(NULL);//空
    this->x31PaForm->setupUi(this->x31PaWidget);//开启显示
    this->lofarPlot = this->x31PaForm->lofarPlot;//
    this->lofarPlot->setDimension(482, 20);
    this->demonPlot = this->x31PaForm->demonPlot;
    this->demonPlot->setDimension(410, 20);

    this->vLayout->addWidget(this->x31AcWidget);
    this->type = FormType::ACTIVE;//初始主动科举FormTypde默认出发
    this->rbActive->setChecked(true);//主动按钮确人活着
}

//初始化任务
void X31JzForm::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    if (this->targetId == HysMainWindow::SELF_DATA) {
        TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );//TaskModel为QSqlTableModel的派生类。
         model->setFilter(QString("id=%1").arg(this->taskId));//筛选，按照字符串filter对数据库进行筛选

        model->select();
        if (model->rowCount() != 1) {//model数据行数
            delete model;//如果函数不等于1行，则释放model数据
            return;
        }

        QSqlRecord record = model->record(0);//获得一条记录
        this->startTime = record.value("start_time").toDateTime();//返回表示Integer值的DateTime对象
        this->endTime = record.value("end_time").toDateTime();
        //获取记录中"dat_data_path"字段的值并将其转换为字符串
        this->jzFileName = record.value("jz_data_path").toString();//返回表示 Integer 值的 String 对象。

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
        //获取记录中"start_time"字段的值并将其转换为日期时间
        this->startTime = record.value("start_time").toDateTime();
        this->endTime = record.value("end_time").toDateTime();
        //获取记录中"dat_data_path"字段的值并将其转换为字符串
        this->jzFileName = record.value("jz_data_path").toString();

        delete targetModel;
    }

    this->runStatus = UNSTART;

    // 模拟数据
    this->jzFileName = "D:/Test_dataForX1.jz";
    this->startTime = QDateTime::fromString("2020-01-06 19:19:35", "yyyy-MM-dd hh:mm:ss");
    this->endTime = QDateTime::fromString("2020-01-06 21:05:00", "yyyy-MM-dd hh:mm:ss");

    this->lbStartTime->setText(this->startTime.toString("yyyy-MM-dd hh:mm:ss"));
    this->lbEndTime->setText(this->endTime.toString("yyyy-MM-dd hh:mm:ss"));

    //计算时间间隔
    this->timeInterval = this->endTime.toSecsSinceEpoch() - this->startTime.toSecsSinceEpoch();
    this->timerCount = 0;

    QFileInfo fileInfo(this->jzFileName);
    qint64 fileSize = fileInfo.size();//64type数据类型即8字节，返回文件大小
    this->fileBlockSize = fileSize / (X31JzParseData::CROSS_ROWS * X31JzParseData::CROSS_COLUMNS * 4);

    //计算时间间隔
    this->timeInterval = this->fileBlockSize;
    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);
    this->slider->setValue(this->timerCount);

    QDateTime realEndTime = this->startTime.addSecs(this->timeInterval);
    this->lbEndTime->setText(realEndTime.toString("yyyy-MM-dd hh:mm:ss"));

    this->isActivePause = true;
    this->isParseCompleted = false;

    this->cpDataQueue.clear();
    this->mbLofarDataQueue.clear();
    this->pwdDataQueue.clear();
    this->lofarDataQueue.clear();
    this->demonDataQueue.clear();

    //初始化参数
    this->parser->initParams(this->taskId, this->targetId, this->jzFileName);
}

//时间事件
void X31JzForm::timerEvent(QTimerEvent *e)
{
    if (this->timerCount > this->timeInterval) {
        this->killTimer(this->timerId);//计时结束

        this->slider->setValue(this->timerCount);
        this->runStatus = STOP;
        this->timerCount = 0;

        this->cpDataQueue.clear();
        this->pwdDataQueue.clear();
        this->mbLofarDataQueue.clear();
        this->lofarDataQueue.clear();
        this->demonDataQueue.clear();

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));//显示图形切换
        emit enableTaskComboBox(true);

        return;
    }

    //主动宽带警戒
    if (!this->cpDataQueue.isEmpty()) {
        QVector<double> cpDataItem = this->cpDataQueue.dequeue();//移除并返回队列的首个项
        this->cpPlot->setUpdateData(cpDataItem);
        this->cpPlot->update();

        this->slider->setValue(this->timerCount++);
    }

    //被动宽带警戒
    if (!this->pwdDataQueue.isEmpty()) {
        QVector<double> pwdDataItem = this->pwdDataQueue.dequeue();
        this->pwdPlot->setUpdateData(pwdDataItem);
        this->pwdPlot->update();
    }

    //被动窄带多波束Lofar
    if (!this->mbLofarDataQueue.isEmpty()) {
        QVector<double> mbLofarDataItem = this->mbLofarDataQueue.dequeue();
        this->mbLofarPlot->setUpdateData(mbLofarDataItem);
        this->mbLofarPlot->update();
    }

    //lofarplot
    if (!this->lofarDataQueue.isEmpty()) {
        QVector<double> lofarDataItem = this->lofarDataQueue.dequeue();
        this->lofarPlot->setUpdateData(lofarDataItem);
        this->lofarPlot->update();
    }

    //Demon
    if (!this->demonDataQueue.isEmpty()) {
        QVector<double> demonDataItem = this->demonDataQueue.dequeue();
        this->demonPlot->setUpdateData(demonDataItem);
        this->demonPlot->update();
    }

    //cp队列为空和解析未结束
    if (this->cpDataQueue.isEmpty() && !this->isParseCompleted) {
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;
        this->isActivePause = false;

        if (!this->pDialog->isVisible()) {
            this->pDialog->show();
        }
    }
}

void X31JzForm::checkOrSendParseSignal()
{
}

//开始按钮
void X31JzForm::on_btnStart_clicked()
{
    //MATLAB初始化未完成
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

    //运行状态"未开始"
    if (this->runStatus == UNSTART) {
        //基阵文件空
        if (this->jzFileName.isEmpty()) {
            QMessageBox warningBox(QMessageBox::Warning, QString::fromLocal8Bit("运行失败"), QString::fromLocal8Bit("数据文件不存在,请检查数据文件"));
            warningBox.setStyleSheet("QPushButton {background-color:#00008B;color:#EBECFB;}"
                                     "QPushButton:hover {color:#398AF1;}"
                                     "QMessageBox {background-image:url(:/destop/dia_bg.png);}");
            warningBox.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
            warningBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
            warningBox.exec();

            return;
        }

        //解析数据对话框
        this->pDialog->setLabelText(QString::fromLocal8Bit("正在解析数据，请等待!"));
        this->pDialog->show();

        //图像显示
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        emit enableTaskComboBox(false);
        emit start_parse();

    }
    //运行状态"暂停"
    else if (this->runStatus == PAUSE) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->isActivePause = true;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
    }
    //运行状态"正在运行"
    else if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;
        this->isActivePause = true;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
    }
    //运行状态"停止"
    else if (this->runStatus == STOP) {
        this->pDialog->setLabelText(QString::fromLocal8Bit("正在解析数据，请等待!"));
        this->pDialog->show();

        this->cpPlot->reset();
        this->mbLofarPlot->reset();
        this->pwdPlot->reset();
        this->lofarPlot->reset();
        this->demonPlot->reset();

        this->cpDataQueue.clear();
        this->pwdDataQueue.clear();
        this->mbLofarDataQueue.clear();
        this->lofarDataQueue.clear();
        this->demonDataQueue.clear();

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

        this->slider->setValue(this->timerCount);
        emit enableTaskComboBox(false);
        emit start_parse();
    }
}

//停止按钮
void X31JzForm::on_btnStop_clicked()
{
    //"未开始"
    if (this->runStatus == UNSTART)
        return;

    //"运行中"
    if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);//停止计时
    }
    //停止
    this->parser->setRunningEnable(false);

    this->cpPlot->reset();
    this->mbLofarPlot->reset();
    this->pwdPlot->reset();
    this->lofarPlot->reset();
    this->demonPlot->reset();

    this->cpDataQueue.clear();
    this->pwdDataQueue.clear();
    this->mbLofarDataQueue.clear();
    this->lofarDataQueue.clear();
    this->demonDataQueue.clear();

    this->isActivePause = true;
    this->isParseCompleted = false;
    this->runStatus = STOP;
    this->timerCount = 0;
    this->slider->setValue(this->timerCount);
    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));

    emit enableTaskComboBox(true);//控制任务选择框是否有效
}

//主动按钮
void X31JzForm::on_rbActive_toggled(bool checked)
{
    if (checked) {
        this->x31AcWidget->setParent(this);
        this->x31PaWidget->setParent(NULL);

        this->vLayout->removeWidget(this->x31PaWidget);
        this->vLayout->addWidget(this->x31AcWidget);
    }
}
//被动按钮
void X31JzForm::on_rbPassive_toggled(bool checked)
{
    if (checked) {
        this->x31PaWidget->setParent(this);
        this->x31AcWidget->setParent(NULL);

        this->vLayout->removeWidget(this->x31AcWidget);
        this->vLayout->addWidget(this->x31PaWidget);
    }
}

//更新数据
void X31JzForm::updateData(QVector<double> cpData, QVector<double> pwdData, QVector<double> mbLofarData, QVector<double> lofarData, QVector<double> demonData)
{
    this->cpDataQueue.enqueue(cpData);
    this->pwdDataQueue.enqueue(pwdData);
    this->mbLofarDataQueue.enqueue(mbLofarData);
    this->lofarDataQueue.enqueue(lofarData);
    this->demonDataQueue.enqueue(demonData);

    //如果运行状态为："未开始"，"停止"，"暂停"
    if (this->runStatus == UNSTART || this->runStatus == STOP || (this->runStatus == PAUSE && !this->isActivePause)) {
        if (cpDataQueue.size() >= X31JzParseData::BATCH_NUMBER) {
            if (this->pDialog->isVisible()) {
                this->pDialog->hide();
            }

            if (this->runStatus == PAUSE) {
                this->isActivePause = true;
            }

            this->runStatus = RUNNING;
            this->timerId = this->startTimer(1000);
        }
    }
}
//完成文件解析
void X31JzForm::completedParseFile()
{
    if (this->runStatus == UNSTART || this->runStatus == STOP || (this->runStatus == PAUSE && !this->isActivePause)) {
        if (this->pDialog->isVisible()) {
            this->pDialog->hide();
        }

        this->isParseCompleted = true;
        this->isActivePause = true;
        this->runStatus = RUNNING;
        this->timerId = this->startTimer(1000);
    }
}

//事件过滤器
bool X31JzForm::eventFilter(QObject *obj, QEvent *event)
{
    //时间进度条
    if (obj == this->slider) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug()<<"current slider:"<<this->slider->value();

            if (this->runStatus == RUNNING) {
                this->parser->setRunningEnable(false);

                this->cpDataQueue.clear();
                this->pwdDataQueue.clear();
                this->mbLofarDataQueue.clear();
                this->lofarDataQueue.clear();
                this->demonDataQueue.clear();

                this->runStatus = PAUSE;
                this->killTimer(this->timerId);
                this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                int dur = this->slider->maximum() - this->slider->minimum();
                int startPoint = dur * ((double)mouseEvent->x() / this->slider->width());
                int pos = this->slider->minimum() + startPoint;
                this->timerCount = pos;
                qDebug()<<"slide pos:"<<this->timerCount;
                this->slider->setValue(this->timerCount);
                this->parser->setStartPoint(startPoint);

                if (this->runStatus == PAUSE) {
                    emit start_parse();
                    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
                }
            }
        }
    }

    //被动宽带警戒
    if (obj == this->pwdPlot) {
        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::RightButton) {
                if (this->pwdPlot->isDataInit()) {
                    QPoint currentPos = mouseEvent->pos();

                    const QwtScaleMap xmap = this->pwdPlot->canvasMap(QwtPlot::xBottom);
                    double scaleX = xmap.invTransform(currentPos.x());

                    int intX = qRound(scaleX);
                    this->parser->setScaleX(intX);
                }
            }
        }
    }

    return QWidget::eventFilter(obj, event);
}


