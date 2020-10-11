#ifndef GPSMODEL_H
#define GPSMODEL_H

#include <QSqlTableModel>

class GpsModel : public QSqlTableModel
{
    Q_OBJECT

public:
    GpsModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

private:
};

#endif // GPSMODEL_H
