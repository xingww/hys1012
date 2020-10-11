#ifndef ANALYSISFORM_H
#define ANALYSISFORM_H

#include "pcolorplot.h"
#include "curveplot.h"
#include "parsedata.h"
#include "parsex31streamdata.h"
#include "cjinitiativeform.h"
#include "x31form.h"
#include <QThread>
#include <QWidget>
#include <QVBoxLayout>
#include <QDateTime>
#include <QThread>
#include <QProgressDialog>
#include <QComboBox>
#include <QSlider>

namespace Ui {
class AnalysisForm;
}

class AnalysisForm : public QWidget
{
    Q_OBJECT

    enum Running {
        UNSTART = 0,
        PAUSE = 1,
        RUNNING = 2,
        STOP = 3
    };

public:
    explicit AnalysisForm(QWidget *parent = nullptr);
    ~AnalysisForm();

signals:
    void start_parse(int taskId, int targetId, int dataCate, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                     , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                     , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);
    void start_stream_parse(int taskId, int targetId, int dataCate, long startPoint);

    void update_cpplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_edplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_noiselplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_noisesplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_fsdplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_lofarplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_demonplot(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void update_echotext(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);
    void update_notext(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);

protected:
    virtual void timerEvent( QTimerEvent *e );

private slots:
    void setCurrentTaskId(int taskId);

    void updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);

    void process(const int status, const QString &text);

    void updateX31JzData(QVector<double> mfmValues, QVector<double> pwdValues, QVector<double> mbLofarValues, QVector<double> tLofarValues, QVector<double> tDemonValues);

    void on_btnStart_clicked();

    void on_cbWay_currentIndexChanged(int index);

    void on_cbTarget_currentIndexChanged(int index);

    void on_btnStop_clicked();

private:
    void initUI();

private:
    Ui::AnalysisForm *ui;
    QVBoxLayout *ly;
    CJInitiativeForm *cjiForm;
    X31Form *jzForm;

    QLabel *lbTitle;
    QLabel *lbStartTime;
    QLabel *lbEndTime;
    QLabel *lbRunningTime;

    QPushButton *btnStart;
    QPushButton *btnStop;
    QSlider *slider;

    QComboBox *cbWay;
    QComboBox *cbTarget;

    int cbWayValue = -1;
    int cbTargetValue = -1;
    int sonarTypeValue = -1;
    int historyTargetValue = -1;
    int historyWayValue = -1;

    QProgressDialog *pDialog;
    QThread *pThread;
    ParseData *parser;
    ParseX31StreamData *streamParser;

    int taskId;
    QString taskTitle;
    QDateTime startTime;
    QDateTime endTime;
    QString datFile;
    QString jzFile;

    int timeInterval;
    int timerId;
    long timercount = 0;
    Running runStatus = UNSTART;

    QMultiMap<QString, QVector<double>> cpData, edData, fsdData, noiseLData, noiseSData, lofarData, demonData;
    QMultiMap<QString, QVector<quint8>> echoData, noData;
    QVector<double> xkMfmData;
};

#endif // ANALYSISFORM_H
