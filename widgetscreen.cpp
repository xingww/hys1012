#include "widgetscreen.h"
#include "ui_widgetscreen.h"

widgetScreen::widgetScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetScreen)
{
    ui->setupUi(this);
}

widgetScreen::~widgetScreen()
{
    delete ui;
}
