#ifndef SCREENPAS_H
#define SCREENPAS_H

//新增图片
#include "mframepcolorplot.h"
#include "mpcolorplot.h"
#include "run_status.h"
#include <QDateTime>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QThread>
#include <QSlider>
#include <QLabel>
#include <QWidget>
#include <QProgressDialog>
#include <QComboBox>
#include "screenparsedata.h"
#include "widgetscreen.h"
#include "ui_widgetscreen.h"
#include <QGroupBox>
#include <QListView>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QTableWidget>
//modify
#include "curveplot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <math.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_grid.h>
#include <qwt_scale_draw.h>
#include <QTimer>

namespace Ui {
class Screenpas;
}

class Screenpas : public QWidget
{
    Q_OBJECT

public:
    explicit Screenpas(QWidget *parent = nullptr);
    ~Screenpas();
    void setDimension(int columns, int rows);
    void initTask(int taskId, int targetId);
    bool eventFilter(QObject *obj, QEvent *event) override;

    int fastftimes = 1;
    int fastbtimes = 1;
    QWidget *screenpasWidget;

signals:
    void start_parse(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                     , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                     , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    void enableTaskComboBox(bool enable);

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_navalSelec_currentIndexChanged(int index);

//modify1
    void updateCpDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updatelofarDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updatedemonDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);

    void updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);

    void on_btnFastforward_clicked();

    void on_btnFastbackward_clicked();

private:
    Ui::Screenpas *ui;
    Ui::widgetScreen *screenpasForm;
    widgetScreen *widget;
    QVBoxLayout *vlContainer;

    QProgressDialog *pDialog;

    QLabel *navalDepth;
    QLabel *navalDirection;
    QLabel *navalSpeed;
    QLabel *navalLt;
    QLabel *navalLat;
    QLabel *navalBroad;
    QLabel *navalDir;
    QLabel *soundSpeed;
    QLabel *recordTime;
    QLabel *beijingTime;
    QLabel *lbStartTime;
    QLabel *lbEndTime;

    QDoubleSpinBox *navalDepthvalue;
    QLineEdit *navalDirectionvalue;
    QDoubleSpinBox *navalSpeedvalue;
    QDoubleSpinBox *navalLtvalue;
    QDoubleSpinBox *navalLatvalue;
    QDoubleSpinBox *navalBroadvalue;
    QDoubleSpinBox *navalDirvalue;
    QDoubleSpinBox *soundSpeedvalue;
    QLineEdit *recordTimevalue;
    QLineEdit *beijingTimevalue;

    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnFastforward;
    QPushButton *btnFastbackward;

    QVBoxLayout *vLcurve;

    QThread *pThread;
    Screenparsedata *parser;

    QSlider *slider;

    QString datFileName;

    QDateTime startTime;
    QDateTime endTime;
    QDateTime currentTime;

    //modify1
    curvePlot *cpPlotcurve;
    curvePlot *lofarcvPlotcurve;
    curvePlot *demoncvPlotcurve;
    curvePlot *curveplot;
    QVector<double> cpxdata;
    QVector<double> cpydata;
    QVector<double> lofarxdata;
    QVector<double> lofarydata;
    QVector<double> demonxdata;
    QVector<double> demonydata;
    QwtPlotCurve *cpcurve ;
    QwtPlotCurve *lofarcurve ;
    QwtPlotCurve *demoncurve ;
    QTimer updateTimer;
    int cplastpointtime;
    int lofarlastpointtime;
    int demonlastpointtime;
    double tempMax = 0;
    double tempMin = 0;
    double cpMax = 0;
    double cpMin = 0;
    double lofarMax = 0;
    double lofarMin = 0;
    double demonMax = 0;
    double demonMin = 0;

    MpColorPlot *cpPlot;
    MpColorPlot *pasPlot;
    MpColorPlot *lofarcvPlot;
    MpColorPlot *lofarcoPlot;
    MpColorPlot *demoncvPlot;
    MpColorPlot *demoncoPlot;

    QDateTime echoStartTime, echoEndTime;
//    QTextBrowser *echoTxt;
      QTableWidget *echoTxt;

    QDateTime noStartTime, noEndTime;
    QTextBrowser *noTxt;

    QWidget *vlayout;

    int taskId;
    int targetId;
    int timerId;
    int timerCount = 0;
    int timeInterval;
    int receivedDataCount = 0;
    const int ALL_DATA_COUNT = 9;

    Running runStatus = UNSTART;
    FormType type;

    QMultiMap<QString, QVector<double>> cpData, edData, fsdData, noiseLData, noiseSData, lofarData, demonData;
    QMultiMap<QString, QVector<quint8>> echoData, noData;

private:
    void checkOrStartTimer();
    void initUI();
    //modify1
    void initPlotcurve();
    void updatecpPlotcurve();
    void updatelofarPlotcurve();
    void updatedemonPlotcurve();

    double axisYMaximum(double temp);
    double axisYMinimum(double temp);

    void autosetScalefunction();
    void updateEchoDisplay();
    void updateNoDisplay();
    void tableDisplay(QString pihao,QString status,QString trackWay,QString strBomen,QString fangwei,QString distance,QString speed,QString strTargetType,QString targetBeam,QString targetLine);

protected:
    virtual void timerEvent( QTimerEvent *e );

};

#endif // SCREENPAS_H
