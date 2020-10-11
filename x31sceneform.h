#ifndef X31SCENEFORM_H
#define X31SCENEFORM_H

#include "ui_x31scactiveform.h"
#include "ui_x31scpassiveform.h"
#include "mframepcolorplot.h"
#include "mpcolorplot.h"
#include "run_status.h"
#include "x31sceneparsedata.h"
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QWidget>
#include <QProgressDialog>

namespace Ui {
class X31SceneForm;
}

class X31SceneForm : public QWidget
{
    Q_OBJECT

public:
    explicit X31SceneForm(QWidget *parent = nullptr);
    ~X31SceneForm();

    void initTask(int taskId, int targetId);
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void enableTaskComboBox(bool enable);

protected:
    virtual void timerEvent( QTimerEvent *e );

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_rbActive_toggled(bool checked);

    void on_rbPassive_toggled(bool checked);

    void updateCpData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void updateLofarData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void updateDemonData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void updatePassiveData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void updateMultiLofarData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<double>> &values);
    void updateHfmTrackData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);
    void updatePassiveTrackData(const QDateTime startTime, const QDateTime endTime, QMultiMap<QString, QVector<quint8>> &values);

private:
    void initUI();
    void resetRunnable();
    void checkOrStartTimer();

    void updateHfmTrackDisplay();
    void updatePassiveTrackDisplay();

private:
    Ui::X31SceneForm *ui;
    Ui::X31ScActiveForm *x31AcForm;
    Ui::X31ScPassiveForm *x31PaForm;

    QProgressDialog *pDialog;

    QWidget *x31AcWidget;
    QWidget *x31PaWidget;

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
    MpColorPlot *multiLofarPlot;
    MpColorPlot *lofarPlot;
    MpColorPlot *demonPlot;
    MpColorPlot *passivePlot;

    QDateTime acStartTime, acEndTime;
    QTextBrowser *tbAcSearchText;
    QDateTime paStartTime, paEndTime;
    QTextBrowser *tbPaSearchText;

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

    X31SceneCpRunnable *cpRunnable = NULL;
    X31SceneLofarRunnable *lofarRunnable = NULL;
    X31SceneDemonRunnable *demonRunnable = NULL;
    X31ScenePassiveRunnable *passiveRunnable = NULL;
    X31SceneMultiLofarRunnable *multiLofarRunnable = NULL;
    X31SceneHfmTrackRunnable *hfmTrackRunnable = NULL;
    X31ScenePassiveTrackRunnable *passiveTrackRunnable = NULL;

    const int ALL_DATA_COUNT = 7;
    int receivedDataCount = 0;
    QMultiMap<QString, QVector<double>> cpData, lofarData, demonData, multiLofarData, passiveData;
    QMultiMap<QString, QVector<quint8>> passiveTrackData, hfmTrackData;
};

#endif // X31SCENEFORM_H
