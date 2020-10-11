#ifndef NEWTASKDIALOG_H
#define NEWTASKDIALOG_H

#include <QSqlRecord>
#include <QWidget>
#include <QFrame>
#include "models/taskmodel.h"

namespace Ui {
class NewTaskDialog;
}

class NewTaskDialog : public QFrame
{
    Q_OBJECT

public:
    explicit NewTaskDialog(QWidget *parent = nullptr);
    ~NewTaskDialog();

signals:
    void update_table();

private slots:
    void on_btnSave_clicked();
    void setTaskId(int taskId);

private:
    void clearTxt();
    void saveTask();

    Ui::NewTaskDialog *ui;

    // 如果是编辑任务，则taskId不等于-1
    int taskId = -1;
    TaskModel *model;
    QSqlRecord record;
};

#endif // NEWTASKDIALOG_H
