#ifndef SCREENACT_H
#define SCREENACT_H

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
#include "ui_widgetscreenact.h"
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
class Screenact;
}

class Screenact : public QWidget
{
    Q_OBJECT

public:
    explicit Screenact(QWidget *parent = nullptr);
    ~Screenact();
    void setDimension(int columns, int rows);
    void initTask(int taskId, int targetId);
    bool eventFilter(QObject *obj, QEvent *event) override;

    int fastftimes = 1;
    int fastbtimes = 1;
    QWidget *screenactWidget;

signals:
    void start_parse(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                     , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                     , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    void enableTaskComboBox(bool enable);

private slots:
    //modify1
    void updatemfDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updatewavDatacurve(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);

    void on_btnStart_clicked();
    void on_btnStop_clicked();

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
    Ui::Screenact *ui;
    Ui::widgetscreenact *screenactForm;
    widgetScreen *widget;
    QVBoxLayout *vlContainer;

    QProgressDialog *pDialog;

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

    QThread *pThread;
    Screenparsedata *parser;

    QSlider *slider;

    QString datFileName;

    QDateTime startTime;
    QDateTime endTime;
    QDateTime currentTime;

    MpColorPlot *actPlot;
    MpColorPlot *mfPlot;
    MpColorPlot *mfaPlot;
    MpColorPlot *wavPlot;
    MpColorPlot *sftPlot;

    QDateTime echoStartTime, echoEndTime;
//    QTextBrowser *echoactTxt;
    QTableWidget *echoactTxt;

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

    //modify1
    curvePlot *mfPlotcurve;
    curvePlot *wavPlotcurve;
    curvePlot *curveplot;

    QVector<double> mfxdata;
    QVector<double> mfydata;
    QVector<double> wavxdata;
    QVector<double> wavydata;
    QwtPlotCurve *mfcurve ;
    QwtPlotCurve *wavcurve ;
    QTimer updateTimer;
    int mflastpointtime;
    int wavlastpointtime;
    double tempMax = 0;
    double tempMin = 0;
    double mfMax = 0;
    double mfMin = 0;
    double wavMax = 0;
    double wavMin = 0;

private:
    void checkOrStartTimer();
    void initUI();
    void updateEchoDisplay();
    void updateNoDisplay();

    //modify1
    void initPlotcurve();
    void updatemfPlotcurve();
    void updatewavPlotcurve();
    double axisYMaximum(double temp);
    double axisYMinimum(double temp);

protected:
    virtual void timerEvent( QTimerEvent *e );

};

#endif // SCREENACT_H

