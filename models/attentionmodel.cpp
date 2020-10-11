//数据结构C++

#include "attentionmodel.h"
#include "hysmainwindow.h"

AttentionModel::AttentionModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("attention");
    setEditStrategy(OnManualSubmit);
    setSort(9, Qt::DescendingOrder);

    setHeaderData(2,Qt::Horizontal, QString::fromLocal8Bit("事件类型"));
    setHeaderData(4,Qt::Horizontal, QString::fromLocal8Bit("发生时间"));
    setHeaderData(5,Qt::Horizontal, QString::fromLocal8Bit("经度"));
    setHeaderData(6,Qt::Horizontal, QString::fromLocal8Bit("维度"));
    setHeaderData(7,Qt::Horizontal, QString::fromLocal8Bit("备注"));
}

QVariant AttentionModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);
    int column = index.column();

    // 事件类型列，对应event_type字段
    if (Qt::DisplayRole == role && column == 2) {
        int iValue = value.toInt();
        switch (iValue) {
        case HysMainWindow::EventType::CONDITION:
            value = QString::fromLocal8Bit("工况变化");
            break;
        case HysMainWindow::EventType::PROBE:
            value = QString::fromLocal8Bit("探测方式变化");
            break;
        case HysMainWindow::EventType::MANUAL:
            value = QString::fromLocal8Bit("人工记录");
            break;
        }
    }

    if (Qt::TextAlignmentRole == role) {
        value = Qt::AlignCenter;
    }

    return value;
}
