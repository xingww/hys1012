#ifndef WIDGETSCREEN_H
#define WIDGETSCREEN_H
#include "mpcolorplot.h"

#include <QWidget>

namespace Ui {
class widgetScreen;
}

class widgetScreen : public QWidget
{
    Q_OBJECT

public:
    explicit widgetScreen(QWidget *parent = nullptr);
    ~widgetScreen();

/*
    MpColorPlot *cpPlot;
    MpColorPlot *pasPlot;
    MpColorPlot *lofarcvPlot;
    MpColorPlot *lofarcoPlot;
    MpColorPlot *demoncvPlot;
    MpColorPlot *demoncoPlot;
*/

private:
    Ui::widgetScreen *ui;
};

#endif // WIDGETSCREEN_H
