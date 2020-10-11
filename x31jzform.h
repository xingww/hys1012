#ifndef X31JZFORM_H
#define X31JZFORM_H

#include "run_status.h"
#include "ui_x31jzactiveform.h"
#include "ui_x31jzpassiveform.h"
#include "x31jzparsedata.h"
#include "mstreamframepcolorplot.h"
#include "mstreampcolorplot.h"
#include <QDateTime>
#include <QProgressDialog>
#include <QThread>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QRadioButton>
#include <QQueue>
#include <QWidget>
#include <QDebug>

namespace Ui {
class X31JzForm;
}

class X31JzForm : public QWidget
{
    Q_OBJECT

public:
    explicit X31JzForm(QWidget *parent = nullptr);
    ~X31JzForm();

    void initTask(int taskId, int targetId);
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void enableTaskComboBox(bool enable);
    void start_parse();
    void set_running_enable(bool running);
    void reset_runnable();
    void set_start_point(int pos);
    void set_scale_x(int scaleX);

protected:
    void timerEvent( QTimerEvent *e ) override;

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_rbActive_toggled(bool checked);

    void on_rbPassive_toggled(bool checked);

    void updateData(QVector<double> cpData, QVector<double> pwdData, QVector<double> mbLofarData, QVector<double> lofarData, QVector<double> demonData);

    void completedParseFile();

private:
    void initUI();
    void checkOrSendParseSignal();

private:
    Ui::X31JzForm *ui;
    Ui::X31JzActiveForm *x31AcForm;//定义变量
    Ui::X31JzPassiveForm *x31PaForm;//定义变量

    QProgressDialog *pDialog;

    QThread *pThread;
    X31JzParseData *parser;

    QWidget *x31PaWidget;
    QWidget *x31AcWidget;

    QTabWidget *tabWidget;
    QVBoxLayout *vLayout;

    QPushButton *btnStart;
    QPushButton *btnStop;
    QSlider *slider;

    QLabel *lbStartTime;
    QLabel *lbEndTime;

    QRadioButton *rbActive;
    QRadioButton *rbPassive;

    MStreamFramepColorPlot *cpPlot;
    MStreampColorPlot *pwdPlot;
    MStreampColorPlot *mbLofarPlot;
    MStreampColorPlot *lofarPlot;
    MStreampColorPlot *demonPlot;

    int taskId;
    int targetId;
    QString jzFileName;
    QDateTime startTime;
    QDateTime endTime;

    int fileBlockSize = 0;

    int timerId;
    int timerCount = 0;
    int timeInterval;

    Running runStatus = UNSTART;
    FormType type;
    bool isActivePause = false;
    bool isParseCompleted = false;

    QQueue<QVector<double>> cpDataQueue, pwdDataQueue, mbLofarDataQueue, lofarDataQueue, demonDataQueue;
};

#endif // X31JZFORM_H
