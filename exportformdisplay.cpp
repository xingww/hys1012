#include "exportformdisplay.h"
#include "ui_exportformdisplay.h"

exportformdisplay::exportformdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exportformdisplay)
{
    ui->setupUi(this);
}

exportformdisplay::~exportformdisplay()
{
    delete ui;
}
