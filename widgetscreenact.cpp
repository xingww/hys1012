#include "widgetscreenact.h"
#include "ui_widgetscreenact.h"

widgetscreenact::widgetscreenact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetscreenact)
{
    ui->setupUi(this);
}

widgetscreenact::~widgetscreenact()
{
    delete ui;
}
