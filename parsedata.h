#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <QObject>
#include <QDateTime>
#include <QMultiMap>
#include <QVector>
#include "mclmcrrt.h"
#include "mclcppclass.h"

class ParseData : public QObject
{
    Q_OBJECT
public:
    explicit ParseData(QObject *parent = nullptr);

public slots:
    void parse(int taskId, int targetId, int dataCate, const QString &fileName);
    void read(int taskId, int targetId, int dataCate, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
              , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
              , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

signals:
    void parse_status(const int status, const QString &text);
    void update_taskinfo();

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
    void parseFile(int taskId, int targetId, const QString &rawFileName);
    void parseRawFile(const QString &rawFileName);
    double parseAdFile(const QString &adFileName);
    void parseDatFile(const double &tstr, const QString &datFileName);
    void parseGpsFile(int taskId, int targetId, const QString &fileName);

    bool checkDatFileSerialization(int taskId, int targetId);
    void parseDatFileForScene(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                              , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                              , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);
    void deserializeDatFileForScene(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                                    , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                                    , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    void updateTask(int taskId, int targetId, const QString &rawFileName, const QString &datFileName, const QString &gpsFileName, const QString &jzFileName);

    QString formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds);

    void operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<double>> &output);
    void operateDataAfterParseAtByte(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<quint8>> &output);

};

#endif // PARSEDATA_H
