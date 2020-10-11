#ifndef EXPORTFORMDISPLAY_H
#define EXPORTFORMDISPLAY_H

#include <QWidget>
#include "mpcolorplot.h"

namespace Ui {
class exportformdisplay;
}

class exportformdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit exportformdisplay(QWidget *parent = nullptr);
    ~exportformdisplay();

private:
    Ui::exportformdisplay *ui;
//    MpColorPlot *actfullscreenPlot;//不需要申请成员变量
//    MpColorPlot *pasfullscreenPlot;

};

#endif // EXPORTFORMDISPLAY_H
