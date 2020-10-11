//数据结构C++

#include "targetmodel.h"

TargetModel::TargetModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{
    setTable("target_data");
    setEditStrategy(OnManualSubmit);
}
