#ifndef TARGETMODEL_H
#define TARGETMODEL_H

#include <QSqlTableModel>

class TargetModel : public QSqlTableModel
{
    Q_OBJECT

public:
    TargetModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
};

#endif // TARGETMODEL_H
