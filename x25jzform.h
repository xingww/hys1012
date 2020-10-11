#ifndef X25JZFORM_H
#define X25JZFORM_H

#include "run_status.h"
#include <QDateTime>
#include <QWidget>

namespace Ui {
class X25JzForm;
}

class X25JzForm : public QWidget
{
    Q_OBJECT

public:
    explicit X25JzForm(QWidget *parent = nullptr);
    ~X25JzForm();

    void initTask(int taskId, int targetId);

private:
    Ui::X25JzForm *ui;

    int taskId;
    int targetId;
    QString datFileName;
    QDateTime startTime;
    QDateTime endTime;

    Running runStatus = UNSTART;
};

#endif // X25JZFORM_H
