#ifndef X25SCENEFORM_H
#define X25SCENEFORM_H

#include "run_status.h"
#include <QDateTime>
#include <QWidget>

namespace Ui {
class X25SceneForm;
}

class X25SceneForm : public QWidget
{
    Q_OBJECT

public:
    explicit X25SceneForm(QWidget *parent = nullptr);
    ~X25SceneForm();

    void initTask(int taskId, int targetId);

private:
    Ui::X25SceneForm *ui;

    int taskId;
    int targetId;
    QString datFileName;
    QDateTime startTime;
    QDateTime endTime;

    Running runStatus = UNSTART;
};

#endif // X25SCENEFORM_H
