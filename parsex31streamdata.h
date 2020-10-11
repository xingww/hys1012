#ifndef PARSESTREAMDATA_H
#define PARSESTREAMDATA_H

#include <QObject>
#include <QFile>
#include <QDataStream>

class ParseX31StreamData : public QObject
{
    Q_OBJECT
public:
    explicit ParseX31StreamData(QObject *parent = nullptr);
    ~ParseX31StreamData();

public slots:
    bool init(const QString &fileName);
    bool close();

    void read(int taskId, int targetId, int dataCate, long startPoint);

signals:
    void update_data(QVector<double> mfmValues, QVector<double> pwdValues, QVector<double> mbLofarValues, QVector<double> tLofarValues, QVector<double> tDemonValues);

private:
    QString fileName;
    QFile *targetFile;
    QDataStream targetDataS;

    float *lastValues;
    int crossRows;
    int crossColumns;
};

#endif // PARSESTREAMDATA_H
