//数据结构C++

#include "taskmodel.h"
#include <QSize>

TaskModel::TaskModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    //将所要操作的数据库表命名为tableName即"task"。不从表中选择数据，仅获取其字段信息。
    setTable("task");
    //将编辑数据库中的值的策略设置为“策略”。这将还原所有挂起的更改。
    setEditStrategy(OnManualSubmit);
    //将列的排序顺序设置为“排序”。这不会影响当前数据，要使用新的排序顺序刷新数据，请调用select（）。
    setSort(20, Qt::DescendingOrder);
    //将标头中具有指定方向的给定角色和节的数据设置为提供的值。
    setHeaderData(1,Qt::Horizontal, QString::fromLocal8Bit("数据名称"));
    setHeaderData(2,Qt::Horizontal, QString::fromLocal8Bit("任务简称"));
    setHeaderData(3,Qt::Horizontal, QString::fromLocal8Bit("任务海区"));
    setHeaderData(4,Qt::Horizontal, QString::fromLocal8Bit("任务时间"));
    setHeaderData(5,Qt::Horizontal, QString::fromLocal8Bit("本舰名称"));
//    setHeaderData(6,Qt::Horizontal, QString::fromLocal8Bit("本舰类型"));
//    setHeaderData(7,Qt::Horizontal, QString::fromLocal8Bit("声纳类型"));
    setHeaderData(6,Qt::Horizontal, QString::fromLocal8Bit("值更长"));
    setHeaderData(7,Qt::Horizontal, QString::fromLocal8Bit("整编人"));

}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    if (Qt::TextAlignmentRole == role) {
        value = Qt::AlignCenter;
    }
    return value;
}

Qt::ItemFlags TaskModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlTableModel::flags(index);

    return flags;
}
