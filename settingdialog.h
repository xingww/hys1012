#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QFrame>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QFrame
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

private:
    void initUI();

private slots:
    void on_btnSave_clicked();

    void on_btnModified_clicked();

    void on_btnTest_clicked();

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
