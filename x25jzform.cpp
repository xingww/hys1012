#include "x25jzform.h"
#include "ui_x25jzform.h"
#include "run_status.h"
#include <QWidget>

X25JzForm::X25JzForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X25JzForm)
{
    ui->setupUi(this);
}

X25JzForm::~X25JzForm()
{
    delete ui;
}

void X25JzForm::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    this->runStatus = UNSTART;
}
