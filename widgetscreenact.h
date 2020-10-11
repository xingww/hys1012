#ifndef WIDGETSCREENACT_H
#define WIDGETSCREENACT_H
#include "mpcolorplot.h"

#include <QWidget>

namespace Ui {
class widgetscreenact;
}

class widgetscreenact : public QWidget
{
    Q_OBJECT

public:
    explicit widgetscreenact(QWidget *parent = nullptr);
    ~widgetscreenact();

private:
    Ui::widgetscreenact *ui;

/*
    MpColorPlot *actPlot;
    MpColorPlot *mfPlot;
    MpColorPlot *mfaPlot;
    MpColorPlot *wavPlot;
    MpColorPlot *sftPlot;
*/
};

#endif // WIDGETSCREENACT_H
