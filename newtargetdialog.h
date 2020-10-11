#ifndef NEWTARGETDIALOG_H
#define NEWTARGETDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QComboBox>
#include <QLineEdit>

namespace Ui {
class NewTargetDialog;
}

class NewTargetDialog : public QFrame
{
    Q_OBJECT

public:
    explicit NewTargetDialog(QWidget *parent = nullptr);
    ~NewTargetDialog();

    void initUI();

public slots:
    void setTaskId(int taskId);

private slots:
    void on_btnSave_clicked();

private:
    Ui::NewTargetDialog *ui;

    QLabel *lbTaskTitle;
    QLineEdit *leTargetName;
    QLineEdit *leShipType;
    QComboBox *cbSonarType;

    int taskId;
};

#endif // NEWTARGETDIALOG_H
