#ifndef X39SCENEFORM_H
#define X39SCENEFORM_H

#include "ui_x39scpassiveform.h"
#include "ui_x39scactiveform.h"
#include "mframepcolorplot.h"
#include "mpcolorplot.h"
#include "run_status.h"
#include "x39sceneparsedata.h"
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

//命名空间声明一个类
namespace Ui {
class X39SceneForm;
}

class X39SceneForm : public QWidget
{
    Q_OBJECT

public:
    explicit X39SceneForm(QWidget *parent = nullptr);
    ~X39SceneForm();

    void initTask(int taskId, int targetId);
    bool eventFilter(QObject *obj, QEvent *event) override;

//信号
signals:
    void start_parse(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                     , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                     , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData);

    void enableTaskComboBox(bool enable);

protected:
    virtual void timerEvent( QTimerEvent *e );

//信号槽
private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_rbActive_toggled(bool checked);

    void on_rbPassive_toggled(bool checked);

    void updateCpData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateFsdData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseLData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateNoiseSData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateLofarData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);
    void updateEchoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateNoData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updateDemonData(const QDateTime &startTime, const QDateTime &endTime, QMultiMap<QString, QVector<double>> &values);

private:
    void initUI();
    void checkOrStartTimer();

    void updateEchoDisplay();
    void updateNoDisplay();

private:
    Ui::X39SceneForm *ui;
    Ui::X39ScPassiveForm *x39PaForm;
    Ui::X39ScActiveForm *x39AcForm;

    QProgressDialog *pDialog;

    QThread *pThread;
    X39SceneParseData *parser;

    QWidget *x39PaWidget;
    QWidget *x39AcWidget;

    QTabWidget *tabWidget;
    QVBoxLayout *vlayout;

    QPushButton *btnStart;
    QPushButton *btnStop;
    QSlider *slider;

    QLabel *lbStartTime;
    QLabel *lbEndTime;

    QRadioButton *rbActive;
    QRadioButton *rbPassive;

    MFramepColorPlot *cpPlot;
    MpColorPlot *edPlot;
    MpColorPlot *fsdPlot;
    MpColorPlot *noiseLPlot;
    MpColorPlot *noiseSPlot;
    MpColorPlot *lofarPlot;
    MpColorPlot *demonPlot;

    QDateTime echoStartTime, echoEndTime;
    QTextBrowser *echoTxt;
    QDateTime noStartTime, noEndTime;
    QTextBrowser *noTxt;

    int taskId;
    int targetId;
    QString datFileName;
    QDateTime startTime;
    QDateTime endTime;

    int timerId;
    int timerCount = 0;
    int timeInterval;

    Running runStatus = UNSTART;
    FormType type;

    const int ALL_DATA_COUNT = 9;
    int receivedDataCount = 0;
    QMultiMap<QString, QVector<double>> cpData, edData, fsdData, noiseLData, noiseSData, lofarData, demonData;
    QMultiMap<QString, QVector<quint8>> echoData, noData;
};

#endif // X39SCENEFORM_H
