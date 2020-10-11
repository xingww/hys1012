#ifndef NEWATTENTIONDIALOG_H
#define NEWATTENTIONDIALOG_H

#include <QLabel>
#include <QFrame>

namespace Ui {
class NewAttentionDialog;
}

class NewAttentionDialog : public QFrame
{
    Q_OBJECT

public:
    explicit NewAttentionDialog(QWidget *parent = nullptr);
    ~NewAttentionDialog();

public slots:
    void setDatum(int taskId, int targetId);

private slots:
    void on_btnSave_clicked();

private:
    Ui::NewAttentionDialog *ui;
    QLabel *lbTaskTitle;

    int taskId = -1;
    int targetId = -1;
};

#endif // NEWATTENTIONDIALOG_H
