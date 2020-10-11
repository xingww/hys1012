#ifndef LISENCEDIALOG_H
#define LISENCEDIALOG_H

#include <QWidget>

namespace Ui {
class LisenceDialog;
}

//权限对话框
class LisenceDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LisenceDialog(QWidget *parent = nullptr);
    ~LisenceDialog();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void initUI();

private slots:
    void on_btnSave_clicked();

private:
    Ui::LisenceDialog *ui;
};

#endif // LISENCEDIALOG_H
