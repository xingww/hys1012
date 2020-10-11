#ifndef VIEWATTENTIONDIALOG_H
#define VIEWATTENTIONDIALOG_H

#include <QFrame>

namespace Ui {
class ViewAttentionDialog;
}

class ViewAttentionDialog : public QFrame
{
    Q_OBJECT

public:
    explicit ViewAttentionDialog(QWidget *parent = nullptr);
    ~ViewAttentionDialog();

public slots:
    void setDatum(int taskId, int targetId);

private:
    Ui::ViewAttentionDialog *ui;

    int taskId;
    int dataType;
};

#endif // VIEWATTENTIONDIALOG_H
