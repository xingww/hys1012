#ifndef ATTENTIONMODEL_H
#define ATTENTIONMODEL_H

#include <QSqlTableModel>

class AttentionModel : public QSqlTableModel
{
    Q_OBJECT

public:
    AttentionModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;


private:
};

#endif // ATTENTIONMODEL_H
