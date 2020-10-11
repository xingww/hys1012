#include "mapform.h"
#include "ui_mapform.h"
#include "models/taskmodel.h"
#include "models/gpsmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include <QSqlRecord>
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDebug>

MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    ui->setupUi(this);
    initUI();
}

MapForm::~MapForm()
{
    delete ui;
    delete[] this->selfPoints;

    QList<M_POINT*> tmpPoints = this->targetPointsMap.values();
    for(int i=0;i<tmpPoints.count();i++) {
        M_POINT *tmp = tmpPoints.at(i);
        delete[] tmp;
    }

    delete[] selfPoints;
}

void MapForm::initUI()
{
    this->mapWidget = this->ui->mapWidget;
    this->lbTaskTitle = this->ui->lbTaskTitle;
    this->lbStart = this->ui->lbStart;
    this->lbEnd = this->ui->lbEnd;
    this->slider = this->ui->slider;
    this->btnStart = this->ui->btnStart;
    this->btnStop = this->ui->btnStop;
    this->btnFastforward = this->ui->btnFastforward;
    this->slider->installEventFilter(this);

    QString str = QApplication::applicationDirPath().append("/WorkDir");
    if(!this->mapWidget->Init(str.toLatin1().data()))
    {
        QMessageBox::warning(NULL, "init", "init failed!");
        return ;
    }

    this->mapWidget->RefreshDrawer(this->mapWidget->width(), this->mapWidget->height(), 0,0);
    this->mapWidget->SetCurrentScale(520);
    this->mapWidget->CenterMap(M_POINT(1230000000, 320000000));
    this->mapWidget->ReDrawWidgetMap(true);

    QString mapPath = "C:/Qt/000_C11-12/C1100102.000";
    this->mapWidget->OpenMap(mapPath.toUtf8().data());
//    this->mapWidget->tmOpenMapDataFile("MarineMap\\marineMap.ymc", true);
    this->mapWidget->SetIfShowGrid(true);

    this->mapWidget->tmAppendLayer(ALL_LINE);
    this->lineLayerPos = this->mapWidget->tmGetLayerCount() - 1;
    this->mapWidget->tmSetLayerName(this->lineLayerPos, "LineLayer");
    this->mapWidget->tmAddLayerAttribute(this->lineLayerPos, M_STRING, "Name");
    this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
    this->fastftimes = 1;//reset
    this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
}

void MapForm::setCurrentTaskId(int taskId)
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
    this->lbTaskTitle->setText(record.value("title").toString());
    this->globalStartTime = record.value("start_time").toDateTime();
    this->globalEndTime = record.value("end_time").toDateTime();

    this->globalStartTime = QDateTime::fromString("2018-10-13 08:07:25", "yyyy-MM-dd hh:mm:ss");
    this->globalEndTime = QDateTime::fromString("2018-10-13 08:11:30", "yyyy-MM-dd hh:mm:ss");

    this->timeInterval = this->globalEndTime.toSecsSinceEpoch() - this->globalStartTime.toSecsSinceEpoch();
    this->slider->setMinimum(0);
    this->slider->setMaximum(this->timeInterval);
    this->lbStart->setText(this->globalStartTime.toString("yyyy-MM-dd hh:mm:ss"));
    this->lbEnd->setText(this->globalEndTime.toString("yyyy-MM-dd hh:mm:ss"));

    delete model;

    GpsModel *gpsModel = new GpsModel(this, HysDbHelper::getInstance()->getDb());
    // 本舰
    gpsModel->setFilter(QString("task_id=%1 and target_id=0").arg(taskId));
    gpsModel->select();

    if (gpsModel->rowCount() > 0) {
        int count = gpsModel->rowCount();
        for (int i=0;i<count;i++) {
            QSqlRecord record = gpsModel->record(i);
            QDateTime crawlTime = record.value("crawl_time").toDateTime();
            QString strTime = crawlTime.toString("yyyy-MM-dd hh:mm:ss");
            double longitude = record.value("longitude").toDouble();
            double latitude = record.value("latitude").toDouble();
            M_POINT gpsPoint;
            gpsPoint.x = longitude * this->mapWidget->GetGeoCoorMultiFactor();
            gpsPoint.y = latitude * this->mapWidget->GetGeoCoorMultiFactor();

            this->selfGpsData.insert(strTime, gpsPoint);
        }
        this->selfPoints = new M_POINT[count];

        this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
        int lineCurObjPos = this->mapWidget->tmGetLayerObjectCount(this->lineLayerPos) - 1;
        M_GEO_OBJ_POS selfObjPos = M_GEO_OBJ_POS(this->lineLayerPos, lineCurObjPos);
        this->mapWidget->tmSetLineObjectCoors(selfObjPos, 0, NULL);
//        this->mapWidget->tmSetLineObjectStyle(selfObjPos, true, true, 10, 5, 2, M_COLOR(255,255,0), 0, 1, NULL);
        this->layerObj.insert(0, selfObjPos);
    }

    // 目标舰列表
    TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
    targetModel->setFilter(QString("task_id=%1").arg(taskId));
    targetModel->select();
    if (targetModel->rowCount() > 0) {
        int count = targetModel->rowCount();
        for(int i=0;i<count;i++) {
            QSqlRecord record = targetModel->record(i);
            int targetId = record.value("id").toInt();
            this->targetIds.append(targetId);
        }
    }
    delete targetModel;

    int idCount = this->targetIds.count();
    if (idCount > 0) {

        for(int i=0;i<idCount;i++) {
            int itemId = this->targetIds.at(i);

            gpsModel->setFilter(QString("task_id=%1 and target_id=%2").arg(taskId).arg(itemId));
            gpsModel->select();
            if (gpsModel->rowCount() > 0) {
                QMultiMap<QString, M_POINT> targetGpsMap;

                int count = gpsModel->rowCount();
                for (int i=0;i<count;i++) {
                    QSqlRecord record = gpsModel->record(i);
                    QDateTime crawlTime = record.value("crawl_time").toDateTime();
                    QString strTime = crawlTime.toString("yyyy-MM-dd hh:mm:ss");
                    double longitude = record.value("longitude").toDouble();
                    double latitude = record.value("latitude").toDouble();
                    M_POINT gpsPoint;
                    gpsPoint.x = longitude * this->mapWidget->GetGeoCoorMultiFactor();
                    gpsPoint.y = latitude * this->mapWidget->GetGeoCoorMultiFactor();

                    targetGpsMap.insert(strTime, gpsPoint);
                }

                this->targetGpsDataMap.insert(itemId, targetGpsMap);

                M_POINT *tmp = new M_POINT[count];
                this->targetPointsMap.insert(itemId, tmp);

                this->targetPointCountMap.insert(itemId, 0);
            }

            this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
            int lineCurObjPos = this->mapWidget->tmGetLayerObjectCount(this->lineLayerPos) - 1;
            M_GEO_OBJ_POS targetObjPos = M_GEO_OBJ_POS(this->lineLayerPos, lineCurObjPos);
            this->mapWidget->tmSetLineObjectCoors(targetObjPos, 0, NULL);
//            this->mapWidget->tmSetLineObjectStyle(targetObjPos, true, true, 10, 5, 2, M_COLOR(255,255, 0), 0, 1, NULL);
            this->layerObj.insert(itemId, targetObjPos);
        }
    }

    delete gpsModel;
}

void MapForm::timerEvent(QTimerEvent *e)
{
    int pos = this->timerCount * this->speed;
    this->slider->setValue(pos);
    QDateTime current = this->globalStartTime.addSecs(pos);

    this->timerCount++;
    if (current > this->globalEndTime) {
        this->killTimer(this->timerId);
        this->reset();
        this->fastftimes = 1;//reset
        this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
        return;
    }

    QString strTimeProcess = this->globalStartTime.toString("yyyy-MM-dd hh:mm:ss") + "/" + current.toString("hh:mm:ss");
    this->lbStart->setText(strTimeProcess);


    // 本舰目标
    for (int i=0;i<this->speed;i++) {
        QDateTime tmpFutureTime = current.addSecs(i);
        QList<M_POINT> result= selfGpsData.values(tmpFutureTime.toString("yyyy-MM-dd hh:mm:ss"));
        int sCount = result.count();
        for(int i=0;i<sCount;i++) {
            this->selfPoints[this->selfPointCount++] = result.at(i);
        }
    }

    M_GEO_OBJ_POS selfObjPos = this->layerObj.value(0);
    this->mapWidget->tmSetLineObjectCoors(selfObjPos, this->selfPointCount, this->selfPoints);
    this->mapWidget->tmSetLineObjectStyle(selfObjPos, true, true, 10, 5, 2, M_COLOR(255,100,100), 0, 1, NULL);

    // 目标数据
    for(int i=0;i<this->targetIds.count();i++) {
        int targetId = this->targetIds.at(i);
        QMultiMap<QString, M_POINT> tmpMap = this->targetGpsDataMap.value(targetId);
        if (tmpMap.isEmpty()) {
            continue;
        }

        M_POINT *tmpGps = this->targetPointsMap.value(targetId);
        int tmpCount = this->targetPointCountMap.value(targetId);

        for (int i=0;i<this->speed;i++){
            QDateTime tmpFutureTime = current.addSecs(i);
            QList<M_POINT> tmp_result = tmpMap.values(tmpFutureTime.toString("yyyy-MM-dd hh:mm:ss"));

            int sCount = tmp_result.count();
            for(int i=0;i<sCount;i++) {
                tmpGps[tmpCount++] = tmp_result.at(i);
            }
        }

        this->targetPointCountMap.insert(targetId, tmpCount);

        M_GEO_OBJ_POS targetObjPos = this->layerObj.value(targetId);
        this->mapWidget->tmSetLineObjectCoors(targetObjPos, tmpCount, tmpGps);
        this->mapWidget->tmSetLineObjectStyle(targetObjPos, true, true, 10, 5, 2, M_COLOR(255, 255, 0), 0, 1, NULL);
    }
    update();
}

void MapForm::reset()
{
    this->runStatus = STOP;
    this->timerCount = 0;
    this->speed = 1;
    this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
    this->fastftimes = 1;//reset
    this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
}

void MapForm::on_btnStart_clicked()
{
    if (this->runStatus == UNSTART || this->runStatus == STOP) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->slider->setValue(this->timerCount);
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
    } else if (this->runStatus == PAUSE) {
        this->timerId = this->startTimer(1000);
        this->runStatus = RUNNING;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/pause.png);"));
    } else if (this->runStatus == RUNNING) {
        this->killTimer(this->timerId);
        this->runStatus = PAUSE;
        this->btnStart->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/start.png);"));
        this->fastftimes = 1;//reset
        this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
    }
}

void MapForm::on_btnStop_clicked()
{
   if (this->runStatus == UNSTART) {
       return;
   }

   if (this->runStatus == RUNNING) {
       this->killTimer(this->timerId);
   }

   this->reset();
   this->slider->setValue(this->timerCount);
   this->fastftimes = 1;//reset
   this->btnFastforward->setStyleSheet(QString::fromLatin1("border-image: url(:/destop/icons/Fastforward.png);"));
}

bool MapForm::eventFilter(QObject *obj, QEvent *event)
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

void MapForm::on_btnFastforward_clicked()
{
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

