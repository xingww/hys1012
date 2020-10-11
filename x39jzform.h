#ifndef X39JZFORM_H
#define X39JZFORM_H

#include "run_status.h"
#include <QDateTime>
#include <QWidget>

namespace Ui {
class X39JzForm;
}

class X39JzForm : public QWidget
{
    Q_OBJECT

public:
    explicit X39JzForm(QWidget *parent = nullptr);
    ~X39JzForm();

    void initTask(int taskId, int targetId);

private:
    Ui::X39JzForm *ui;

    int taskId;
    int targetId;
    QString datFileName;
    QDateTime startTime;
    QDateTime endTime;

    Running runStatus = UNSTART;
};

#endif // X39JZFORM_H
