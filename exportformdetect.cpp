#include "exportformdetect.h"
#include "ui_exportformdetect.h"
#include "exportformdisplay.h"
#include "ui_exportformdisplay.h"

exportFormdetect::exportFormdetect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exportFormdetect)
{
    ui->setupUi(this);
}

exportFormdetect::~exportFormdetect()
{
    delete ui;
}

void exportFormdetect::initUI()
{
    this->vlayout = this->ui->exportformdisplay;
    this->screenForm = new Ui::exportformdisplay();
    this->screenWidget = new QWidget(NULL);
    //先构建一个QWidget界面，再加载xml构建出我们创建的ui界面
    this->screenForm->setupUi(this->screenWidget);
    this->screenWidget->setParent(vlayout);

    this->actfullscreenPlot = this->screenForm->actfullscreenPlot;
    this->actfullscreenPlot->setDimension(480, 780);

    this->pasfullscreenPlot = this->screenForm->pasfullscreenPlot;
    this->pasfullscreenPlot->setDimension(480, 780);

}
