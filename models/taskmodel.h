#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QSqlTableModel>

//任务模型
//QSqlTableModel  继承QSqlQueryModel类
//该类提供了一个可读写单张SQL表的可编辑数据模型，功能：修改，插入，删除，查询，和排序
class TaskModel : public QSqlTableModel
{
    Q_OBJECT

public:
    TaskModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
};

#endif // TASKMODEL_H
