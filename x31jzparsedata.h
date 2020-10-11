#ifndef X31JZPARSEDATA_H
#define X31JZPARSEDATA_H

#include "mclmcrrt.h"
#include "mclcppclass.h"
#include <QFile>
#include <QDataStream>
#include <QObject>
#include <QVector>

class X31JzParseData : public QObject
{
    Q_OBJECT
public:
    X31JzParseData();
    ~X31JzParseData();

    void initParams(int taskId, int targetId, QString &fileName);
    void parse();

signals:
    void send_data(QVector<double> xkMfmData, QVector<double> sxPwdData, QVector<double> sxMbLofarData, QVector<double> sxTLobarData, QVector<double> sxTDemonData);
    void complete_parse();

public:
    const static int BATCH_NUMBER = 10;
    const static int CROSS_ROWS = 8192;
    const static int CROSS_COLUMNS = 384;

public slots:
    void setRunningEnable(bool running);
    void reset();
    void setStartPoint(int startPoint);
    void setScaleX(int scaleX);

private:
    void operateDataAfterParse(mwArray &inData, QVector<double> &output);

private:
    int startPoint = 0;
    int pausePoint = 0;

    int taskId;
    int targetId;
    QString fileName;

    int scaleXForTrackLofar = -1;

    bool isRunning = false;
    bool isReachEnd = false;
    bool runningEnabled = true;
};

#endif // X31JZPARSEDATA_H
