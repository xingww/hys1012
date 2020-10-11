#include "analysisform_old.h"
#include "models/taskmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include "ui_analysisform.h"
#include "hysmainwindow.h"
#include <qwt_plot_layout.h>
#include <qwt_matrix_raster_data.h>
#include <QMessageBox>
#include <QSqlRecord>
#include <QFile>
#include <QDebug>

AnalysisForm::AnalysisForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalysisForm)
{
    ui->setupUi(this);
    initUI();

    this->pThread = new QThread(this);
    pThread->setObjectName("ana_parser");

    this->parser = new ParseData();
    this->parser->moveToThread(pThread);

    this->streamParser = new ParseX31StreamData();
    this->streamParser->moveToThread(pThread);

    this->pThread->start();

    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>&");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>*");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<double>>");
    qRegisterMetaType<QMultiMap<QString, QVector<double>>>("QMultiMap<QString,QVector<quint8>>&");

    connect(this, &AnalysisForm::start_parse, this->parser, &ParseData::read);
    connect(this->parser, &ParseData::parse_status, this, &AnalysisForm::process);
    connect(this, &AnalysisForm::start_stream_parse, this->streamParser, &ParseX31StreamData::read);

    connect(this->parser, &ParseData::send_cpdata, this, &AnalysisForm::updateCpData);
    connect(this->parser, &ParseData::send_eddata, this, &AnalysisForm::updateEdData);
    connect(this->parser, &ParseData::send_noiseldata, this, &AnalysisForm::updateNoiseLData);
    connect(this->parser, &ParseData::send_noisesdata, this, &AnalysisForm::updateNoiseSData);
    connect(this->parser, &ParseData::send_fsddata, this, &AnalysisForm::updateFsdData);
    connect(this->parser, &ParseData::send_lofardata, this, &AnalysisForm::updateLofarData);
    connect(this->parser, &ParseData::send_demondata, this, &AnalysisForm::updateDemonData);
    connect(this->parser, &ParseData::send_echodata, this, &AnalysisForm::updateEchoData);
    connect(this->parser, &ParseData::send_nodata, this, &AnalysisForm::updateNoData);

    connect(this->streamParser, &ParseX31StreamData::update_data, this, &AnalysisForm::updateX31JzData);
}

AnalysisForm::~AnalysisForm()
{
    delete ui;
    delete pDialog;
    delete jzForm;
    delete cjiForm;

    this->pThread->quit();
    this->pThread->wait();
    delete this->parser;
    delete this->pThread;
}

void AnalysisForm::initUI()
{
    this->pDialog = new QProgressDialog(this);
    this->pDialog->setModal(true);
    this->pDialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    this->pDialog->setCancelButton(NULL);
    this->pDialog->setMaximum(0);
    this->pDialog->setMinimum(0);
    this->pDialog->reset();

    this->ly = this->ui->lyGraph;

    this->cjiForm = new CJInitiativeForm();
    this->jzForm = new X31Form();

    this->lbTitle = this->ui->lbTitle;
    this->lbStartTime = this->ui->lbStart;
    this->lbEndTime = this->ui->lbEnd;
    this->lbRunningTime = this->ui->lbRunningTime;
    this->cbWay = this->ui->cbWay;
    this->cbTarget = this->ui->cbTarget;
    this->slider = this->ui->slider;
    this->btnStart = this->ui->btnStart;
    this->btnStop = this->ui->btnStop;

    this->cbWay->insertItem(0, QString::fromLocal8Bit("场景数据"), HysMainWindow::SCENE_DATA);
    this->cbWay->insertItem(1, QString::fromLocal8Bit("基阵数据"), HysMainWindow::JZ_DATA);
    this->cbWay->setCurrentIndex(-1);

    connect(this, &AnalysisForm::update_cpplot, this->cjiForm, &CJInitiativeForm::updateCpPlot);
    connect(this, &AnalysisForm::update_edplot, this->cjiForm, &CJInitiativeForm::updateEdPlot);
    connect(this, &AnalysisForm::update_noiselplot, this->cjiForm, &CJInitiativeForm::updateNoiseLPlot);
    connect(this, &AnalysisForm::update_noisesplot, this->cjiForm, &CJInitiativeForm::updateNoiseSPlot);
    connect(this, &AnalysisForm::update_fsdplot, this->cjiForm, &CJInitiativeForm::updateFsdPlot);
    connect(this, &AnalysisForm::update_lofarplot, this->cjiForm, &CJInitiativeForm::updateLofarPlot);
    connect(this, &AnalysisForm::update_demonplot, this->cjiForm, &CJInitiativeForm::updateDemonPlot);
    connect(this, &AnalysisForm::update_echotext, this->cjiForm, &CJInitiativeForm::updateEchoText);
    connect(this, &AnalysisForm::update_notext, this->cjiForm, &CJInitiativeForm::updateNoText);

    // 默认3x9场景
    this->ly->addWidget(this->cjiForm);
}

void AnalysisForm::setCurrentTaskId(int taskId)
{
    if (taskId == this->taskId)
        return;

    this->taskId = taskId;
    TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb() );
    model->setFilter(QString("id=%1").arg(taskId));
    model->select();

    if (model->rowCount() != 1) {
        delete model;
        QMessageBox::warning(this, QString::fromLocal8Bit("任务不存在"), QString::fromLocal8Bit("选择任务不存在"));
        return;
    }

    QSqlRecord record = model->record(0);

    this->taskTitle = record.value("title").toString();
    this->startTime = record.value("start_time").toDateTime();
    this->endTime = record.value("end_time").toDateTime();
    this->datFile = record.value("dat_data_path").toString();
    this->jzFile = record.value("jz_data_path").toString();
    this->sonarTypeValue = record.value("sonar_type").toInt();

    this->timeInterval = this->endTime.toSecsSinceEpoch() - this->startTime.toSecsSinceEpoch();
    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);

    this->lbTitle->setText(this->taskTitle);
    this->lbStartTime->setText(this->startTime.toString("hh:mm:ss"));
    this->lbEndTime->setText(this->endTime.toString("hh:mm:ss"));
    this->lbRunningTime->setText("");

    this->cbTarget->insertItem(0, QString::fromLocal8Bit("本舰数据"), HysMainWindow::SELF_DATA);
    TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
    targetModel->setFilter(QString("task_id=%1").arg(taskId));
    targetModel->select();
    int count = targetModel->rowCount();
    if (count != 0) {
        for (int i=0;i<count;i++) {
            QSqlRecord record = targetModel->record(i);
            int id = record.value("id").toInt();
            QString name = record.value("name").toString();

            this->cbTarget->insertItem(i+1, name, id);
        }
    }

    delete targetModel;
    delete model;

    this->cbTarget->setCurrentIndex(-1);
    this->cbWay->setCurrentIndex(-1);
}

void AnalysisForm::timerEvent(QTimerEvent *e)
{
    if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
        this->cjiForm->update();
        this->slider->setValue(timercount);

        QDateTime current = this->startTime.addSecs(timercount);
        this->lbRunningTime->setText(current.toString("hh:mm:ss"));
        this->lbRunningTime->setVisible(true);
        if (current > this->endTime) {
            qDebug()<<"kill timer:"<<e->timerId();
            this->killTimer(e->timerId());
        }
    } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
        // 开始读文件
        emit start_stream_parse(this->taskId, this->cbTargetValue, HysMainWindow::DataCate::JZ_DATA, this->timercount);

    }

    this->timercount++;
}

void AnalysisForm::process(const int status, const QString &text)
{
    qDebug()<<status<<":"<<text;
    if (status == 0 || status == 100) {

        this->pDialog->setLabelText(text);
        this->pDialog->show();
    } else if (status == 200) {
        this->pDialog->reset();
        this->pDialog->hide();

        qDebug()<<"start timer";

        this->cjiForm->setGlobalTimeInterval(this->startTime, this->endTime);
        this->timerId = this->startTimer(1000);
    }
}

void AnalysisForm::updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_cpplot(startTime, endTime, values);
}

void AnalysisForm::updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_edplot(startTime, endTime, values);
}

void AnalysisForm::updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_fsdplot(startTime, endTime, values);
}

void AnalysisForm::updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_noiselplot(startTime, endTime, values);
}

void AnalysisForm::updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_noisesplot(startTime, endTime, values);
}

void AnalysisForm::updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_lofarplot(startTime, endTime, values);
}

void AnalysisForm::updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    emit update_echotext(startTime, endTime, values);
}

void AnalysisForm::updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values)
{
    emit update_notext(startTime, endTime, values);
}

void AnalysisForm::updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values)
{
    emit update_demonplot(startTime, endTime, values);
}

void AnalysisForm::on_btnStart_clicked()
{
    // 判断是本舰还是目标
    if (this->cbTargetValue == -1 || this->cbWayValue == -1) {
        QMessageBox::warning(this, QString::fromLocal8Bit("选择类型"), QString::fromLocal8Bit("请选择数据类型！"));
        return;
    }

    if (this->runStatus == UNSTART) {
        this->historyTargetValue = this->cbTargetValue;
        this->historyWayValue = this->cbWayValue;

        if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
            QFile datFile(this->datFile);
            if (!datFile.exists()) {
                QMessageBox::warning(this, QString::fromLocal8Bit("文件不存在"), QString::fromLocal8Bit("场景文件不存在,请检查文件"));
                return;
            }

            this->datFile = "C:/QtProjects/9Test.dat";
            emit start_parse(this->taskId, this->cbTargetValue, HysMainWindow::DataCate::SCENE_DATA, this->datFile, cpData, edData, noiseLData, noiseSData, fsdData, lofarData, demonData, echoData, noData);

        } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
            QFile jzFile(this->jzFile);
            if (!jzFile.exists()) {
                QMessageBox::warning(this, QString::fromLocal8Bit("文件不存在"), QString::fromLocal8Bit("基阵文件不存在,请检查文件"));
                return;
            }

            this->ly->removeWidget(this->cjiForm);
            this->ly->addWidget(this->jzForm);

            this->jzFile = "C:/QtProjects/Test_dataForX1.jz";
            if (!this->streamParser->init(this->jzFile))
            {
                QMessageBox::warning(this, QString::fromLocal8Bit("解析器初始化失败"), QString::fromLocal8Bit("解析器初始化失败,请检查文件是否存在!"));
                return;
            }

            this->timerId = this->startTimer(250);
        }

        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

    } else if (this->runStatus == PAUSE) {
        if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
            this->timerId = this->startTimer(1000);
        } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
            this->timerId = this->startTimer(250);
        }

        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

    } else if (this->runStatus == STOP) {
        this->historyTargetValue = this->cbTargetValue;
        this->historyWayValue = this->cbWayValue;

        if ((this->historyTargetValue == this->cbTargetValue) && (this->historyWayValue == this->cbWayValue)) {
            if (this->sonarTypeValue == HysMainWindow::X39) {
                this->timerId = this->startTimer(1000);
            } else {
                // todo
            }
        } else {
            if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
                QFile datFile(this->datFile);
                if (!datFile.exists()) {
                    QMessageBox::warning(this, QString::fromLocal8Bit("文件不存在"), QString::fromLocal8Bit("场景文件不存在,请检查文件"));
                    return;
                }

                this->datFile = "C:/QtProjects/9Test.dat";
                emit start_parse(this->taskId, this->cbTargetValue, HysMainWindow::DataCate::SCENE_DATA, this->datFile, cpData, edData, noiseLData, noiseSData, fsdData, lofarData, demonData, echoData, noData);

            } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
                QFile jzFile(this->jzFile);
                if (!jzFile.exists()) {
                    QMessageBox::warning(this, QString::fromLocal8Bit("文件不存在"), QString::fromLocal8Bit("基阵文件不存在,请检查文件"));
                    return;
                }

                this->ly->removeWidget(this->cjiForm);
                this->ly->addWidget(this->jzForm);

                this->jzFile = "C:/QtProjects/Test_dataForX1.jz";
                if (this->streamParser->init(this->jzFile))
                {
                    QMessageBox::warning(this, QString::fromLocal8Bit("解析器初始化失败"), QString::fromLocal8Bit("解析器初始化失败,请检查文件是否存在!"));
                    return;
                }

                this->timerId = this->startTimer(250);
            }
        }

        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));

    } else if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
    }

    this->cbWay->setEnabled(false);
    this->cbTarget->setEnabled(false);
}

void AnalysisForm::on_cbWay_currentIndexChanged(int index)
{
    if (index == -1) {
        this->cbWayValue = -1;
        return;
    }
    this->cbWayValue = this->cbWay->itemData(index).toInt();

    if (this->cbTargetValue == -1) {
        return;
    }

    // 切换显示界面
    if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
        qDebug()<<this->cbWayValue<<":"<<this->sonarTypeValue;
        this->ly->removeWidget(this->jzForm);
        this->jzForm->hide();

        this->ly->addWidget(this->cjiForm);
        this->cjiForm->show();
    } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
        this->ly->removeWidget(this->cjiForm);
        this->cjiForm->hide();

        this->ly->addWidget(this->jzForm);
        this->jzForm->show();

    }
}

void AnalysisForm::on_cbTarget_currentIndexChanged(int index)
{
    if (index == -1) {
        this->cbTargetValue = -1;
        return;
    }
    this->cbTargetValue = this->cbTarget->itemData(index).toInt();

    if (this->cbWayValue == -1) {
        return;
    }


    if (this->cbTargetValue == HysMainWindow::SELF_DATA){
        TaskModel *taskModel = new TaskModel(this, HysDbHelper::getInstance()->getDb());
        taskModel->setFilter(QString("id=%1").arg(this->taskId));
        taskModel->select();
        if (taskModel->rowCount() == 1) {
            QSqlRecord record = taskModel->record(0);
            this->startTime = record.value("start_time").toDateTime();
            this->endTime = record.value("end_time").toDateTime();
            this->datFile = record.value("dat_data_path").toString();
            this->jzFile = record.value("jz_data_path").toString();
            this->sonarTypeValue = record.value("sonar_type").toInt();
        }

        delete taskModel;
    } else {
        TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
        targetModel->setFilter(QString("id=%1").arg(this->cbTargetValue));
        targetModel->select();
        int count = targetModel->rowCount();
        if (count == 1) {
            for (int i=0;i<count;i++) {
                QSqlRecord record = targetModel->record(i);
                this->startTime = record.value("start_time").toDateTime();
                this->endTime = record.value("end_time").toDateTime();
                this->datFile = record.value("dat_data_path").toString();
                this->jzFile = record.value("jz_data_path").toString();
                this->sonarTypeValue = record.value("sonar_type").toInt();
            }
        }

        delete targetModel;
    }

    // 注意根据数据类型更新
    this->startTime = QDateTime::fromString("2020-01-06 19:47:35", "yyyy-MM-dd hh:mm:ss");
    this->endTime = QDateTime::fromString("2020-01-06 19:53:00", "yyyy-MM-dd hh:mm:ss");
    this->timeInterval = this->endTime.toSecsSinceEpoch() - this->startTime.toSecsSinceEpoch();
    this->lbStartTime->setText(this->startTime.toString("hh:mm:ss"));
    this->lbEndTime->setText(this->endTime.toString("hh:mm:ss"));
    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);

    // 切换显示界面
    if (this->cbWayValue == HysMainWindow::SCENE_DATA && this->sonarTypeValue == HysMainWindow::X39) {
        this->ly->removeWidget(this->jzForm);
        this->jzForm->hide();

        this->ly->addWidget(this->cjiForm);
        this->cjiForm->show();
    } else if (this->cbWayValue == HysMainWindow::JZ_DATA && this->sonarTypeValue == HysMainWindow::X31) {
        this->ly->removeWidget(this->cjiForm);
        this->cjiForm->hide();

        this->ly->addWidget(this->jzForm);
        this->jzForm->show();
    }
}

void AnalysisForm::on_btnStop_clicked()
{
    if (this->runStatus == RUNNING || this->runStatus == PAUSE) {
        if (this->runStatus == RUNNING) {
            this->killTimer(this->timerId);
        }

        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        this->slider->setValue(0);
        this->timercount = 0;
        this->runStatus = STOP;

        if (this->cbWayValue == HysMainWindow::JZ_DATA) {
            this->jzForm->reset();
        } else if (this->cbWayValue == HysMainWindow::SCENE_DATA) {
            this->cjiForm->reset();
        }

        this->cbWay->setEnabled(true);
        this->cbTarget->setEnabled(true);
    }
}

void AnalysisForm::updateX31JzData(QVector<double> mfmValues, QVector<double> pwdValues, QVector<double> mbLofarValues, QVector<double> tLofarValues, QVector<double> tDemonValues)
{
//    qDebug()<<"mfmValues:"<<mfmValues;
//    qDebug()<<"pwdValues"<<pwdValues;
//    qDebug()<<"mbLofarValues"<<mbLofarValues;
//    qDebug()<<"tLofarValues"<<tLofarValues;
//    qDebug()<<"tDemonValues"<<tDemonValues;
}
