#ifndef EXPORTFORMDETECT_H
#define EXPORTFORMDETECT_H

#include <QWidget>
#include "mpcolorplot.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "exportformdisplay.h"
#include "ui_exportformdisplay.h"


namespace Ui {
class exportFormdetect;
}

class exportFormdetect : public QWidget
{
    Q_OBJECT

public:
    explicit exportFormdetect(QWidget *parent = nullptr);
    ~exportFormdetect();

private:
    Ui::exportFormdetect *ui;

    void initUI();

    MpColorPlot *actfullscreenPlot;
    MpColorPlot *pasfullscreenPlot;
    QPushButton *btnExport;
    QPushButton *bbtnGenerate;
    QWidget *vlayout;

    Ui::exportformdisplay *screenForm;
    QWidget *screenWidget;

};

#endif // EXPORTFORMDETECT_H
