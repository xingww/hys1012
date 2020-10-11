#ifndef X31SCENEPARSEDATA_H
#define X31SCENEPARSEDATA_H

#include "mclmcrrt.h"
#include "mclcppclass.h"
#include <QMultiMap>
#include <QObject>
#include <QDateTime>
#include <QRunnable>

class X31SceneRunnableBase : public QObject
{
public:
    virtual void resetParam(int taskId, int targetId, QString fileName) = 0;

protected:
    virtual void parse() = 0;
    virtual void sendSignal() = 0;
    virtual void parseFromSerialization(int taskId, int targetId, QString dType) = 0;
    virtual void operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime) = 0;

    QString dataFileName(int taskId, int targetId, QString dType);
    QString formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds);
    bool checkSerializationFile(int taskId, int targetId, QString dType);
};

class X31SceneDoubleRunnable : public QRunnable, public X31SceneRunnableBase
{
public:
    X31SceneDoubleRunnable(QString dType, int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &data);
    void run() override;

    void resetParam(int taskId, int targetId, QString fileName) override;

protected:
    void parseFromSerialization(int taskId, int targetId, QString dType) override;
    void operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime) override;

protected:
    QString dType;
    int taskId;
    int targetId;
    QString fileName;
    QDateTime startTime;
    QDateTime endTime;
    QMultiMap<QString, QVector<double>> data;
};

class X31SceneUnitRunnable : public QRunnable, public X31SceneRunnableBase
{
public:
    X31SceneUnitRunnable(QString dType, int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<quint8>> &data);
    void run() override;

    void resetParam(int taskId, int targetId, QString fileName) override;

protected:
    void parseFromSerialization(int taskId, int targetId, QString dType) override;
    void operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime) override;

protected:
    QString dType;
    int taskId;
    int targetId;
    QString fileName;
    QDateTime startTime;
    QDateTime endTime;
    QMultiMap<QString, QVector<quint8>> data;
};

class X31SceneCpRunnable: public X31SceneDoubleRunnable
{
    Q_OBJECT

public:
    X31SceneCpRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_cpdata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
};

class X31SceneLofarRunnable: public X31SceneDoubleRunnable
{
    Q_OBJECT

public:
    X31SceneLofarRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &lofarData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_lofardata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
};

class X31SceneDemonRunnable: public X31SceneDoubleRunnable
{
    Q_OBJECT

public:
    X31SceneDemonRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &demonData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_demondata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
};

class X31ScenePassiveRunnable: public X31SceneDoubleRunnable
{
    Q_OBJECT

public:
    X31ScenePassiveRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &passiveData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_passivedata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
};

class X31SceneMultiLofarRunnable: public X31SceneDoubleRunnable
{
    Q_OBJECT

public:
    X31SceneMultiLofarRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &multiLofarData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_multilofardata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
};

class X31SceneHfmTrackRunnable: public X31SceneUnitRunnable
{
    Q_OBJECT

public:
    X31SceneHfmTrackRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<quint8>> &hfmTrackData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_hfmtrackdata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);
};

class X31ScenePassiveTrackRunnable: public X31SceneUnitRunnable
{
    Q_OBJECT

public:
    X31ScenePassiveTrackRunnable(int taskId, int targetId, const QString &fileName,  QMultiMap<QString, QVector<quint8>> &passiveTrackData);

protected:
    void parse() override;
    void sendSignal() override;

signals:
    void send_passivetrackdata(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);
};

#endif // X31SCENEPARSEDATA_H
