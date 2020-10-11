#ifndef MAPFORM_H
#define MAPFORM_H

#include "run_status.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QDateTime>
#include <QMultiMap>
#include <QSpinBox>
#include "EncMapWidget.h"

namespace Ui {
class MapForm;
}

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr);
    ~MapForm();

    bool eventFilter(QObject *obj, QEvent *event) override;

protected:
    virtual void timerEvent( QTimerEvent *e );

private slots:
    void setCurrentTaskId(int taskId);

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnFastforward_clicked();

private:
    void initUI();
    void reset();

private:
    Ui::MapForm *ui;
    EncMapWidget *mapWidget;
    QLabel *lbTaskTitle;
    QLabel *lbStart, *lbEnd;
    QPushButton *btnStart, *btnStop;
    QSlider *slider;

    QPushButton *btnFastforward;

    QDateTime globalStartTime, globalEndTime;

    int timeInterval;
    int timerId;
    int timerCount = 0;
    Running runStatus = UNSTART;

    int speed = 1;
    int fastftimes = 1;

    M_POINT gpsPoints[10];

    int taskId;
    QList<int> targetIds;

    QMultiMap<QString, M_POINT> selfGpsData;
    QMap<int, QMultiMap<QString, M_POINT>> targetGpsDataMap;

    M_POINT *selfPoints;
    int selfPointCount = 0;
    QMap<int, M_POINT*> targetPointsMap;
    QMap<int, int> targetPointCountMap;

    int lineLayerPos;
    QMap<int, M_GEO_OBJ_POS> layerObj;
};

#endif // MAPFORM_H
