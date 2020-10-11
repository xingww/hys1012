#include "x25sceneform.h"
#include "ui_x25sceneform.h"
#include "run_status.h"
#include <QWidget>

X25SceneForm::X25SceneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X25SceneForm)
{
    ui->setupUi(this);
}

X25SceneForm::~X25SceneForm()
{
    delete ui;
}

void X25SceneForm::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    this->runStatus = UNSTART;
}
