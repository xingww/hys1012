//数据结构C++

#include "gpsmodel.h"

GpsModel::GpsModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("gps_data");
    setSort(7, Qt::DescendingOrder);
}
