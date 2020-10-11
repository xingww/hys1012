#include "exportformnchart.h"
#include "ui_exportformnchart.h"
#include "models/taskmodel.h"
#include "models/gpsmodel.h"
#include "models/targetmodel.h"
#include "hysdb.h"
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

exportFormnchart::exportFormnchart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exportFormnchart)
{
    ui->setupUi(this);
    initUI();

}

exportFormnchart::~exportFormnchart()
{
    delete ui;
}

void exportFormnchart::initUI()
{
    this->mapWidget = this->ui->mapWidget;
    this->taskInfoTree = this->ui->treeWidget;

    QString str = QApplication::applicationDirPath().append("/WorkDir");
    if(!this->mapWidget->Init(str.toLatin1().data()))
    {
        QMessageBox::warning(NULL, "init", "init failed!");
        return ;
    }

    this->mapWidget->RefreshDrawer(this->mapWidget->width(), this->mapWidget->height(), 0,0);
    this->mapWidget->SetCurrentScale(5200000);

    this->mapWidget->CenterMap(M_POINT(1230000000, 320000000));

    this->mapWidget->ReDrawWidgetMap(true);

    this->mapWidget->tmOpenMapDataFile("MarineMap\\marineMap.ymc", true);
    this->mapWidget->SetIfShowGrid(false);

    this->mapWidget->tmAppendLayer(ALL_LINE);
    this->lineLayerPos = this->mapWidget->tmGetLayerCount() - 1;
    this->mapWidget->tmSetLayerName(this->lineLayerPos, "LineLayer");
    this->mapWidget->tmAddLayerAttribute(this->lineLayerPos, M_STRING, "Name");
    this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
}


void exportFormnchart::setCurrentTaskId(int taskId)
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
    QString taskTitle = record.value("title").toString();

    delete model;

    GpsModel *gpsModel = new GpsModel(this, HysDbHelper::getInstance()->getDb());
    // 本舰
    gpsModel->setFilter(QString("task_id=%1 and target_id=0").arg(taskId));
    gpsModel->select();
    if (gpsModel->rowCount() > 0) {
        int count = gpsModel->rowCount();
        M_POINT *points = new M_POINT[count];
        for (int i=0;i<count;i++) {
            QSqlRecord record = gpsModel->record(i);

            double longitude = record.value("longitude").toDouble();
            double latitude = record.value("latitude").toDouble();
            M_POINT gpsPoint;
            gpsPoint.x = longitude * this->mapWidget->GetGeoCoorMultiFactor();
            gpsPoint.y = latitude * this->mapWidget->GetGeoCoorMultiFactor();

            points[i] = gpsPoint;
        }
        this->pointsMap.insert(0, points);
        this->pointsCountMap.insert(0, count);

        this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
        int lineCurObjPos = this->mapWidget->tmGetLayerObjectCount(this->lineLayerPos) - 1;
        M_GEO_OBJ_POS selfObjPos = M_GEO_OBJ_POS(this->lineLayerPos, lineCurObjPos);
        this->mapWidget->tmSetLineObjectCoors(selfObjPos, count, points);
        this->mapWidget->tmSetLineObjectStyle(selfObjPos, true, true, 10, 5, 2, M_COLOR(255,100,100), 0, 1, NULL);
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
                int count = gpsModel->rowCount();
                M_POINT *points = new M_POINT[count];

                for (int i=0;i<count;i++) {
                    QSqlRecord record = gpsModel->record(i);
                    QDateTime crawlTime = record.value("crawl_time").toDateTime();
                    QString strTime = crawlTime.toString("yyyy-MM-dd hh:mm:ss");
                    double longitude = record.value("longitude").toDouble();
                    double latitude = record.value("latitude").toDouble();
                    M_POINT gpsPoint;
                    gpsPoint.x = longitude * this->mapWidget->GetGeoCoorMultiFactor();
                    gpsPoint.y = latitude * this->mapWidget->GetGeoCoorMultiFactor();

                    points[i] = gpsPoint;
                }
                this->pointsMap.insert(itemId, points);
                this->pointsCountMap.insert(itemId, count);

                this->mapWidget->tmAppendObjectInLayer(this->lineLayerPos, TYPE_LINE);
                int lineCurObjPos = this->mapWidget->tmGetLayerObjectCount(this->lineLayerPos) - 1;
                M_GEO_OBJ_POS targetObjPos = M_GEO_OBJ_POS(this->lineLayerPos, lineCurObjPos);
                this->mapWidget->tmSetLineObjectCoors(targetObjPos, count, points);
                this->mapWidget->tmSetLineObjectStyle(targetObjPos, true, true, 10, 5, 2, M_COLOR(255,100,100), 0, 1, NULL);
            }
        }
    }

    delete gpsModel;
}
