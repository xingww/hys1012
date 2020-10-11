#ifndef HOMEFORM_H
#define HOMEFORM_H

#include "parsedata.h"
#include <QWidget>
#include <QProgressDialog>

namespace Ui {
class HomeForm;
}

class HomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit HomeForm(QWidget *parent = nullptr);
    ~HomeForm();

    int getCurrentTask();

private slots:
    void on_tableTask_customContextMenuRequested(const QPoint &pos);

    void upload_raw_data();

    void upload_cat_data();

    void add_target();

    void delete_target();

    void delete_task();

    void edit_task();

    void refresh_table();

    void refresh_tree();

    void add_attention();

    void view_attention();

    void process(const int status, const QString &text);

    void on_btnCreate_clicked();

    void on_btnRefresh_clicked();

    void on_btnSearch_clicked();

    void on_btnReset_clicked();

    void on_tableTask_clicked(const QModelIndex &index);

    void on_taskInfoTree_customContextMenuRequested(const QPoint &pos);

    void on_btnSearchType_clicked();

signals:
    void start_parse(int taskId, int dataType, int dataCate, const QString &fileName);
    void edit_task(int taskId);
    void add_record(int taskId, int dataType);
    void add_target(int taskId);
    void view_attention(int taskId, int dataType);

private:
    void init();
    void refresh_taskinfo(const QModelIndex &index);

    void upload_self_data(int taskId);
    void upload_target_data(int taskId, int targetId);

private:
    Ui::HomeForm *ui;
    QThread *pThread;
    ParseData *parser;
    QProgressDialog *pBarDialog;

    bool isAdanceSearch = false;
};

#endif // HOMEFORM_H
