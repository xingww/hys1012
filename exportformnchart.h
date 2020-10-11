#ifndef EXPORTFORMNCHART_H
#define EXPORTFORMNCHART_H

#include <QWidget>
#include <QMap>
#include <QTreeWidget>
#include <QComboBox>
#include "EncMapWidget.h"
#include <QHBoxLayout>

namespace Ui {
class exportFormnchart;
}

class exportFormnchart : public QWidget
{
    Q_OBJECT

public:
    explicit exportFormnchart(QWidget *parent = nullptr);
    ~exportFormnchart();
    QString taskTitle;

public slots:
    void setCurrentTaskId(int taskId);

private:
    Ui::exportFormnchart *ui;
    int taskId;
    EncMapWidget *mapWidget;
    QTreeWidget *taskInfoTree;
    QList<int> targetIds;
    QMap<int, M_POINT*> pointsMap;
    QMap<int, int> pointsCountMap;

    int lineLayerPos;

    void initUI();
};

#endif // EXPORTFORMNCHART_H
