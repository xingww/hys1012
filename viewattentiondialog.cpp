#include "viewattentiondialog.h"
#include "ui_viewattentiondialog.h"
#include "models/attentionmodel.h"
#include "hysdb.h"
#include <QTableView>

ViewAttentionDialog::ViewAttentionDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ViewAttentionDialog)
{
    ui->setupUi(this);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("人工记录"));
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

}

ViewAttentionDialog::~ViewAttentionDialog()
{
    delete ui;
}

void ViewAttentionDialog::setDatum(int taskId, int targetId)
{
    this->taskId = taskId;
    this->dataType = targetId;

    QTableView *attTable = this->ui->tableAttention;
    attTable->verticalHeader()->hide();
    attTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    attTable->setSelectionMode(QAbstractItemView::NoSelection);
    attTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    AttentionModel *model = new AttentionModel(attTable, HysDbHelper::getInstance()->getDb());
    model->setFilter(QString("task_id=%1 and target_id=%2").arg(taskId).arg(targetId));
    model->select();
    attTable->setModel(model);

    attTable->hideColumn(0);
    attTable->hideColumn(1);
    attTable->hideColumn(3);
    attTable->hideColumn(8);
    attTable->hideColumn(9);
}
