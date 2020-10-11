#include "homeform.h"
#include "ui_homeform.h"
#include "hysmainwindow.h"
#include "models/taskmodel.h"
#include "models/attentionmodel.h"
#include "models/targetmodel.h"
#include "newattentiondialog.h"
#include "viewattentiondialog.h"
#include "newtaskdialog.h"
#include "newtargetdialog.h"
#include "hysdb.h"
#include <QTreeView>
#include <QTreeView>
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QDebug>

HomeForm::HomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeForm)
{
    ui->setupUi(this);
    init();

    this->pThread = new QThread();
    this->pThread->setObjectName("parser");

    this->parser = new ParseData();
    this->parser->moveToThread(pThread);
    this->pThread->start();

    this->pBarDialog = new QProgressDialog(this);
    this->pBarDialog->reset();            // 防止自动弹出
    this->pBarDialog->setWindowModality(Qt::WindowModal);
    this->pBarDialog->setMinimum(0);
    this->pBarDialog->setMaximum(0);
    this->pBarDialog->setWindowTitle(QString::fromLocal8Bit("上传数据"));

    connect(this, &HomeForm::start_parse, this->parser, &ParseData::parse);
    connect(this->parser, SIGNAL(update_taskinfo()), this, SLOT(refresh_tree()));
    connect(this->parser, &ParseData::parse_status, this, &HomeForm::process);
}

HomeForm::~HomeForm()
{
    delete ui;
    delete pBarDialog;

    this->pThread->quit();
    this->pThread->wait();
    delete pThread;

    delete parser;
}

void HomeForm::init()
{
    QTableView *taskTable = this->ui->tableTask;
    taskTable->verticalHeader()->hide();
    taskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    taskTable->setSelectionMode(QAbstractItemView::SingleSelection);
    taskTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    taskTable->setContextMenuPolicy(Qt::CustomContextMenu);

    TaskModel *model = new TaskModel(taskTable, HysDbHelper::getInstance()->getDb());
    model->select();
    taskTable->setModel(model);
//    taskTable->setColumnWidth(1, 250);//仅第一列设置宽度未250
//    taskTable->resizeColumnsToContents();//所有列根据内容调整宽度，多余宽度自动留给最后一列
    taskTable->setColumnWidth(1, 250);//仅第一列设置宽度未250
    taskTable->setColumnWidth(2, 250);//仅第一列设置宽度未250
    taskTable->setColumnWidth(3, 200);//仅第一列设置宽度未250
    taskTable->setColumnWidth(4, 180);//仅第一列设置宽度未250
    taskTable->setColumnWidth(5, 180);//仅第一列设置宽度未250
    taskTable->setColumnWidth(6, 180);//仅第一列设置宽度未250
    taskTable->setColumnWidth(7, 180);//仅第一列设置宽度未250

    taskTable->hideColumn(0);
    taskTable->hideColumn(8);
    taskTable->hideColumn(9);
    taskTable->hideColumn(10);
    taskTable->hideColumn(11);
    taskTable->hideColumn(12);
    taskTable->hideColumn(13);
    taskTable->hideColumn(14);
    taskTable->hideColumn(15);
    taskTable->hideColumn(16);
    taskTable->hideColumn(17);
    taskTable->hideColumn(18);
    taskTable->hideColumn(19);
    taskTable->hideColumn(20);

    taskTable->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal{ background: #191970;}");
    // TreeWidget
    this->ui->taskInfoTree->setContextMenuPolicy(Qt::CustomContextMenu);
    QTreeWidgetItem *self = new QTreeWidgetItem(this->ui->taskInfoTree);
    self->setText(0, QString::fromLocal8Bit("目前还没有选择任务信息"));

    this->ui->wtAdvSearch->hide();
}

//带参数返回值
//任务ID
int HomeForm::getCurrentTask()
{
    //在Qt5的QTabWidget类中，在默认情况下是以0开始作为标签索引值，
    //而currentIndex（）函数返回的值指的是在当前的页面切换的界面中所停留的那一个页面对应的标签索引值。
    QModelIndex index = this->ui->tableTask->currentIndex();
    //如果索引无效，则说明没有数据，返回-1
    if (!index.isValid())
        return -1;

    //获取当前行的列兄弟索引，即当前为第几行
    QModelIndex idIndex = index.siblingAtColumn(0);
    //如果索引无效，则说明没有选中数据，返回-1
    if (!idIndex.isValid())
        return -1;

    int taskId = idIndex.data().toInt();
    return taskId;
}

void HomeForm::refresh_table()
{
    TaskModel *model = (TaskModel *)this->ui->tableTask->model();
    model->setFilter("");
    model->select();

}

void HomeForm::on_tableTask_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex current = this->ui->tableTask->indexAt(pos);

    if (!current.isValid())
        return;

    int taskId = current.siblingAtColumn(0).data().toInt();
    QMenu *menu = new QMenu(this->ui->tableTask);

    QAction *addTarget = new QAction(QString::fromLocal8Bit("添加目标"), this->ui->tableTask);
    addTarget->setData(taskId);
    menu->addAction(addTarget);
    connect(addTarget, SIGNAL(triggered()), this, SLOT(add_target()));

    QAction *editTask = new QAction(QString::fromLocal8Bit("编辑任务"), this->ui->tableTask);
    editTask->setData(taskId);
    connect(editTask, SIGNAL(triggered()), this, SLOT(edit_task()));
    menu->addAction(editTask);

    QAction *delTask = new QAction(QString::fromLocal8Bit("删除任务"), this->ui->tableTask);
    delTask->setData(taskId);
    connect(delTask, SIGNAL(triggered()), this, SLOT(delete_task()));
    menu->addAction(delTask);

    menu->move(cursor().pos());
    menu->show();
}

void HomeForm::upload_raw_data()
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->currentItem();
    if (item == NULL) {
        return;
    }

    int taskId = item->parent()->data(1, Qt::EditRole).toInt();
    int targetId = item->data(1, Qt::EditRole).toInt();

    if (targetId == 0) {
        upload_self_data(taskId);
    } else {
        upload_target_data(taskId, targetId);
    }
}

//导入本舰数据
void HomeForm::upload_self_data(int taskId)
{
    //aFileName 为：D:/TEST_CH1
    //QDir::homePath()为：C:/Users/xingww
    QString aFileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择本舰数据"), QDir::homePath());
    if (aFileName.isEmpty())
        return;

    emit start_parse(taskId, HysMainWindow::SELF_DATA, HysMainWindow::DataCate::RAW_DATA, aFileName);
}
//导入目标数据
void HomeForm::upload_target_data(int taskId, int targetId)
{
    QString aFileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择目标数据"), QDir::homePath());
    if (aFileName == nullptr)
        return;

    emit start_parse(taskId, targetId, HysMainWindow::DataCate::RAW_DATA, aFileName);
}
//重新导入数据
void HomeForm::upload_cat_data()
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->currentItem();
    if (item == NULL) {
        return;
    }

    int taskId = item->parent()->parent()->data(1, Qt::EditRole).toInt();
    int targetId = item->parent()->data(1, Qt::EditRole).toInt();
    int dataCate = item->data(1, Qt::EditRole).toInt();

    QVariant value = item->data(2, Qt::EditRole);
    if (!value.isNull() && value.toBool()) {
        QMessageBox::StandardButton btn = QMessageBox::question(this, QString::fromLocal8Bit("重新上传数据"), QString::fromLocal8Bit("重新上传后，将删除历史数据!"));
        if (btn != QMessageBox::Yes) {
            return;
        }
    }

    QString title = dataCate == HysMainWindow::DataCate::GPS_DATA ? QString::fromLocal8Bit("上传GPS数据") : QString::fromLocal8Bit("上传基阵数据");
    QString filter = dataCate == HysMainWindow::DataCate::GPS_DATA ? "*.gps" : "*.jz";
    QString aFileName = QFileDialog::getOpenFileName(this, title, QDir::homePath(), filter);

    if (aFileName.isEmpty()) {
        return;
    }

    emit start_parse(taskId, targetId, dataCate, aFileName);
}

void HomeForm::add_target()
{
    QModelIndex idIndex = this->ui->tableTask->currentIndex().siblingAtColumn(0);
    if (idIndex.isValid()){
        int taskId = idIndex.data().toInt();

        NewTargetDialog *dialog = new NewTargetDialog(this);
        dialog->setWindowTitle(QString::fromLocal8Bit("添加目标"));
        connect(this, SIGNAL(add_target(int)), dialog, SLOT(setTaskId(int)));

        emit add_target(taskId);
        dialog->show();
    }
}

void HomeForm::delete_target()
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->currentItem();
    if (item == NULL) {
        return;
    }

    int taskId = item->parent()->data(1, Qt::EditRole).toInt();
    int targetId = item->data(1, Qt::EditRole).toInt();

    if (targetId == HysMainWindow::SELF_DATA)
    {
        return;
    }

    QMessageBox::StandardButton btn = QMessageBox::question(this, QString::fromLocal8Bit("确认删除此目标数据吗？"), QString::fromLocal8Bit("删除后，此目标所有相关数据都被清除！"));
    if (btn == QMessageBox::Yes)
    {
        TargetModel *model = new TargetModel(this, HysDbHelper::getInstance()->getDb());
        model->setFilter(QString("id=%1 and task_id=%2").arg(targetId).arg(taskId));
        model->select();
        model->removeRow(0);
        model->submitAll();

        item->parent()->removeChild(item);
    }
}

void HomeForm::delete_task()
{
    int row = this->ui->tableTask->currentIndex().row();
    QMessageBox::StandardButton btn = QMessageBox::question(this, QString::fromLocal8Bit("确认删除此任务数据吗？"), QString::fromLocal8Bit("删除后，此任务所有相关数据都被清除！"));
    if (btn == QMessageBox::Yes)
    {
        TaskModel *model = (TaskModel *)this->ui->tableTask->model();
         model->removeRow(row);
         model->submitAll();
    }
}

void HomeForm::edit_task()
{
    QModelIndex idIndex = this->ui->tableTask->currentIndex().siblingAtColumn(0);
    if (idIndex.isValid()){
        int taskId = idIndex.data().toInt();

        NewTaskDialog *dialog = new NewTaskDialog(this);
        connect(this, SIGNAL(edit_task(int)), dialog, SLOT(setTaskId(int)));

        emit edit_task(taskId);
        dialog->show();
    }
}

void HomeForm::add_attention()
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->currentItem();
    if (item == NULL) {
        return;
    }

    int taskId = item->parent()->parent()->data(1, Qt::EditRole).toInt();
    int dataType = item->parent()->data(1, Qt::EditRole).toInt();

    NewAttentionDialog *dialog = new NewAttentionDialog(this);
    dialog->setWindowTitle(QString::fromLocal8Bit("添加人工记录"));
    connect(this, SIGNAL(add_record(int, int)), dialog, SLOT(setDatum(int, int)));

    emit add_record(taskId, dataType);
    dialog->show();
}

void HomeForm::view_attention()
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->currentItem();
    if (item == NULL) {
        return;
    }

    int taskId = item->parent()->parent()->data(1, Qt::EditRole).toInt();
    int dataType = item->parent()->data(1, Qt::EditRole).toInt();

    ViewAttentionDialog *dialog = new ViewAttentionDialog(this);
    dialog->setWindowTitle(QString::fromLocal8Bit("人工记录"));
    connect(this, SIGNAL(view_attention(int, int)), dialog, SLOT(setDatum(int, int)));

    emit view_attention(taskId, dataType);
    dialog->show();
}

void HomeForm::process(const int status, const QString &text)
{
    if (status == 200) {
        this->pBarDialog->close();
    } else {
        this->pBarDialog->setLabelText(text);

        if (!this->pBarDialog->isVisible())
            this->pBarDialog->show();
    }
}

void HomeForm::refresh_tree()
{
    QModelIndex index = this->ui->tableTask->currentIndex();
    refresh_table();
    this->ui->tableTask->setCurrentIndex(index);
    refresh_taskinfo(index);
}

void HomeForm::refresh_taskinfo(const QModelIndex &index)
{
    QModelIndex idIndex = index.siblingAtColumn(0);
    if (!idIndex.isValid()) {
        return;
    }
    int taskId = idIndex.data().toInt();

    this->ui->taskInfoTree->clear();
    QString title = index.siblingAtColumn(1).data().toString();

    QTreeWidgetItem *me = new QTreeWidgetItem(this->ui->taskInfoTree);
    me->setText(0, title);
    me->setData(1, Qt::EditRole, taskId);

    QTreeWidgetItem *self_group = new QTreeWidgetItem(me, HysMainWindow::TreeItemType::SELF_ITEM);
    self_group->setText(0, QString::fromLocal8Bit("本舰数据"));
    self_group->setData(1, Qt::EditRole, HysMainWindow::SELF_DATA);
    QString self_raw_path = index.siblingAtColumn(11).data().toString();
    if (!self_raw_path.isEmpty()) {
        self_group->setIcon(0, QIcon(":/destop/icons/check.ico"));
        // 是否已经存在数据
        self_group->setData(2, Qt::EditRole, true);
    }

    QTreeWidgetItem *self_gps_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
    self_gps_item->setText(0, QString::fromLocal8Bit("GPS数据"));
    self_gps_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::GPS_DATA);
    QString self_gps_path = index.siblingAtColumn(13).data().toString();
    if (!self_gps_path.isEmpty()) {
        self_gps_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
        // 是否已经存在数据
        self_gps_item->setData(2, Qt::EditRole, true);
    }

    QTreeWidgetItem *self_scene_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
    self_scene_item->setText(0, QString::fromLocal8Bit("场景数据"));
    self_scene_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::SCENE_DATA);
    QString self_scene_path = index.siblingAtColumn(12).data().toString();
    if (!self_scene_path.isEmpty()) {
        self_scene_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
        self_scene_item->setData(2, Qt::EditRole, true);
    }

    QTreeWidgetItem *self_jz_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
    self_jz_item->setText(0, QString::fromLocal8Bit("基阵数据"));
    self_jz_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::JZ_DATA);
    QString self_jz_path = index.siblingAtColumn(14).data().toString();
    if (!self_jz_path.isEmpty()) {
        self_jz_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
        self_jz_item->setData(2, Qt::EditRole, true);
    }

    QTreeWidgetItem *self_man_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::EVENT_ITEM);
    self_man_item->setText(0, QString::fromLocal8Bit("人工记录"));

    QTreeWidgetItem *self_listen_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
    self_listen_item->setText(0, QString::fromLocal8Bit("收听数据"));
    self_listen_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::LISTEN_DATA);
    QString self_listen_path = index.siblingAtColumn(15).data().toString();
    if (!self_listen_path.isEmpty()) {
        self_listen_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
        self_listen_item->setData(2, Qt::EditRole, true);
    }

    QTreeWidgetItem *self_env_item = new QTreeWidgetItem(self_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
    self_env_item->setText(0, QString::fromLocal8Bit("环境数据"));
    self_env_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::ENV_DATA);
    QString self_env_path = index.siblingAtColumn(16).data().toString();
    if (!self_env_path.isEmpty()) {
        self_env_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
        self_env_item->setData(2, Qt::EditRole, true);
    }

    // 目标数据
    TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
    targetModel->setFilter(QString("task_id=%1").arg(taskId));
    targetModel->select();
    int count = targetModel->rowCount();
    if (count != 0 ) {
        for (int i=0;i<count;i++) {
            QSqlRecord record = targetModel->record(i);
            int targetId = record.value("id").toInt();
            QString name = record.value("name").toString();

            QTreeWidgetItem *target_group = new QTreeWidgetItem(me, HysMainWindow::TreeItemType::TARGET_ITEM);
            target_group->setText(0, name + QString::fromLocal8Bit("(目标)"));
            target_group->setData(1, Qt::EditRole, targetId);
            QString target_raw_path = record.value("raw_data_path").toString();
            if (!target_raw_path.isEmpty()) {
                target_group->setIcon(0, QIcon(":/destop/icons/check.ico"));
                // 是否已经存在数据
                target_group->setData(2, Qt::EditRole, true);
            }

            QTreeWidgetItem *target_gps_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
            target_gps_item->setText(0, QString::fromLocal8Bit("GPS数据"));
            target_gps_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::GPS_DATA);
            QString target_gps_path = record.value("gps_data_path").toString();
            if (!target_gps_path.isEmpty()) {
                target_gps_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
                target_gps_item->setData(2, Qt::EditRole, true);
            }

            QTreeWidgetItem *target_scene_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
            target_scene_item->setText(0, QString::fromLocal8Bit("场景数据"));
            target_scene_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::SCENE_DATA);
            QString target_scene_path = record.value("dat_data_path").toString();
            if (!target_scene_path.isEmpty()) {
                target_scene_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
                target_scene_item->setData(2, Qt::EditRole, true);
            }

            QTreeWidgetItem *target_jz_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
            target_jz_item->setText(0, QString::fromLocal8Bit("基阵数据"));
            target_jz_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::JZ_DATA);
            QString target_jz_path = record.value("jz_data_path").toString();
            if (!target_jz_path.isEmpty()) {
                target_jz_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
                target_jz_item->setData(2, Qt::EditRole, true);
            }

            QTreeWidgetItem *target_man_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::EVENT_ITEM);
            target_man_item->setText(0, QString::fromLocal8Bit("人工记录"));

            QTreeWidgetItem *target_listen_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
            target_listen_item->setText(0, QString::fromLocal8Bit("收听数据"));
            target_listen_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::LISTEN_DATA);
            QString target_listen_path = record.value("listen_data_path").toString();
            if (!target_listen_path.isEmpty()) {
                target_listen_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
                target_listen_item->setData(2, Qt::EditRole, true);
            }

            QTreeWidgetItem *target_env_item = new QTreeWidgetItem(target_group, HysMainWindow::TreeItemType::UPDATA_ITEM);
            target_env_item->setText(0, QString::fromLocal8Bit("环境数据"));
            target_env_item->setData(1, Qt::EditRole, HysMainWindow::DataCate::ENV_DATA);
            QString target_env_path = record.value("target_data_path").toString();
            if (!target_env_path.isEmpty()) {
                target_env_item->setIcon(0, QIcon(":/destop/icons/check.ico"));
                target_env_item->setData(2, Qt::EditRole, true);
            }
        }
    }

    this->ui->taskInfoTree->expandAll();

    QString comment = index.siblingAtColumn(8).data().toString();
    if (comment.isEmpty()) {
        this->ui->txtComment->setText(QString::fromLocal8Bit("此数据没有备注信息"));
    } else {
         this->ui->txtComment->setText(comment);
    }
}

void HomeForm::on_btnCreate_clicked()
{
    NewTaskDialog *dialog = new NewTaskDialog(this);
    connect(dialog, SIGNAL(update_table()), this, SLOT(refresh_table()));
    dialog->show();
}

void HomeForm::on_btnRefresh_clicked()
{
    this->refresh_table();
}

void HomeForm::on_btnSearch_clicked()
{
    TaskModel *model = (TaskModel *)this->ui->tableTask->model();
    QString condition;

    if (this->isAdanceSearch) {
        QString title = this->ui->inTitle->text();
        QString abbr = this->ui->inAbbr->text();
        QString area = this->ui->inArea->text();
        QString shipName = this->ui->inShipName->text();
        QString actor = this->ui->inActor->text();
        QString author = this->ui->inAuthor->text();

        if (!title.isEmpty()) {
            condition = QString("title like '%%1%'").arg(title);
        }
        if (!abbr.isEmpty()){
            condition = condition.isEmpty() ? QString("abbr like '%%1%'").arg(abbr) : condition.append(QString(" and abbr like '%%1%'").arg(abbr));
        }
        if (!area.isEmpty()){
            condition = condition.isEmpty() ? QString("area like '%%1%'").arg(area) : condition.append(QString(" and area like '%%1%'").arg(area));
        }
        if (!shipName.isEmpty()){
            condition = condition.isEmpty() ? QString("ship_name like '%%1%'").arg(shipName) : condition.append(QString(" and ship_name like '%%1%'").arg(shipName));
        }
        if (!actor.isEmpty()){
            condition = condition.isEmpty() ? QString("actor like '%%1%'").arg(actor) : condition.append(QString(" and actor like '%%1%'").arg(actor));
        }
        if (!author.isEmpty()) {
            condition = condition.isEmpty() ? QString("author like '%%1%'").arg(author) : condition.append(QString(" and author like '%%1%'").arg(author));
        }
    } else {
        QString keyword = this->ui->inKeyword->text();
        if (!keyword.isEmpty()) {
            condition = QString("title like '%%1%' or abbr like '%%2%' or area like '%%3%' or ship_name like '%%4%' or actor like '%%5%' or author like '%%6%'").arg(keyword).arg(keyword).arg(keyword).arg(keyword).arg(keyword).arg(keyword);
        }
    }

    if (!condition.isEmpty()) {
        model->setFilter(condition);
        model->select();
    }
}

void HomeForm::on_btnReset_clicked()
{
    if (this->isAdanceSearch) {
        this->ui->inTitle->clear();
        this->ui->inAbbr->clear();
        this->ui->inArea->clear();
        this->ui->inShipName->clear();
        this->ui->inActor->clear();
        this->ui->inAuthor->clear();
    } else {
        this->ui->inKeyword->clear();
    }
}

void HomeForm::on_tableTask_clicked(const QModelIndex &index)
{
    refresh_taskinfo(index);
}

void HomeForm::on_taskInfoTree_customContextMenuRequested(const QPoint &pos)
{
    QTreeWidgetItem *item = this->ui->taskInfoTree->itemAt(pos);
    if (item == NULL) {
        return;
    }

    if (item->type() == HysMainWindow::TreeItemType::UPDATA_ITEM) {

        QVariant value = item->data(2, Qt::EditRole);
        QString hint = QString::fromLocal8Bit("导入数据");
        if (!value.isNull() && value.toBool()) {
            hint = QString::fromLocal8Bit("重新导入数据");
        }

        QMenu *menu = new QMenu(this->ui->taskInfoTree);
        QAction *uploadData = new QAction(hint, this->ui->taskInfoTree);
        connect(uploadData, SIGNAL(triggered()), this, SLOT(upload_cat_data()));
        menu->addAction(uploadData);

        menu->move(cursor().pos());
        menu->show();
    } else if (item->type() == HysMainWindow::TreeItemType::EVENT_ITEM) {
        QMenu *menu = new QMenu(this->ui->taskInfoTree);
        QAction *addData = new QAction(QString::fromLocal8Bit("添加记录"), this->ui->taskInfoTree);
        connect(addData, SIGNAL(triggered()), this, SLOT(add_attention()));
        menu->addAction(addData);

        QAction *viewData = new QAction(QString::fromLocal8Bit("查看详情"), this->ui->taskInfoTree);
        connect(viewData, SIGNAL(triggered()), this, SLOT(view_attention()));
        menu->addAction(viewData);

        menu->move(cursor().pos());
        menu->show();
    } else if (item->type() == HysMainWindow::TreeItemType::SELF_ITEM) {
        QVariant value = item->data(2, Qt::EditRole);
        QString hint = QString::fromLocal8Bit("导入原始数据");
        if (!value.isNull() && value.toBool()) {
            hint = QString::fromLocal8Bit("重新导入数据");
        }

        QMenu *menu = new QMenu(this->ui->taskInfoTree);
        QAction *uploadData = new QAction(hint, this->ui->taskInfoTree);
        connect(uploadData, SIGNAL(triggered()), this, SLOT(upload_raw_data()));
        menu->addAction(uploadData);

        menu->move(cursor().pos());
        menu->show();
    } else if (item->type() == HysMainWindow::TreeItemType::TARGET_ITEM) {
        QVariant value = item->data(2, Qt::EditRole);
        QString hint = QString::fromLocal8Bit("导入原始数据");
        if (!value.isNull() && value.toBool()) {
            hint = QString::fromLocal8Bit("重新导入数据");
        }

        QMenu *menu = new QMenu(this->ui->taskInfoTree);
        QAction *uploadData = new QAction(hint, this->ui->taskInfoTree);
        connect(uploadData, SIGNAL(triggered()), this, SLOT(upload_raw_data()));
        menu->addAction(uploadData);

        QAction *delTarget = new QAction(QString::fromLocal8Bit("删除目标"), this->ui->taskInfoTree);
        connect(delTarget, SIGNAL(triggered()), this, SLOT(delete_target()));
        menu->addAction(delTarget);

        menu->move(cursor().pos());
        menu->show();
    }
}

void HomeForm::on_btnSearchType_clicked()
{
    this->isAdanceSearch = !this->isAdanceSearch;
    if (this->isAdanceSearch) {
        this->ui->wtAdvSearch->show();
        this->ui->inKeyword->hide();

        this->ui->btnSearchType->setText(QString::fromLocal8Bit(">>普通搜索"));
    } else {
        this->ui->wtAdvSearch->hide();
        this->ui->inKeyword->show();

        this->ui->btnSearchType->setText(QString::fromLocal8Bit(">>高级搜索"));
    }
}
