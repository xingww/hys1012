#ifndef SCREENPARSEDATA_H
#define SCREENPARSEDATA_H

#include "mclmcrrt.h"
#include "mclcppclass.h"
#include <QMultiMap>
#include <QObject>
#include <QDateTime>
#include <QRunnable>
#include <QObject>

class Screenparsedata : public QObject
{
    Q_OBJECT
public:
    Screenparsedata();

public slots:
    void parse(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
              , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
              , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

signals:
    void send_cpdata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_eddata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_noiseldata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_noisesdata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_fsddata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_lofardata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_demondata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void send_echodata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);
    void send_nodata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);

private:
    bool checkDatFileSerialization(int taskId, int targetId);
    void parseDatFile(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                              , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                              , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    void deserializeDatFile(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                                    , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                                    , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    QString formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds);
    QString dataFileName(int taskId, int targetId, QString dType);
    void operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<double>> &output);
    void operateDataAfterParseAtByte(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<quint8>> &output);
};

#endif // SCREENPARSEDATA_H
