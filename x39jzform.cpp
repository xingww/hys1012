#include "x39jzform.h"
#include "ui_x39jzform.h"

X39JzForm::X39JzForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::X39JzForm)
{
    ui->setupUi(this);
}
//析构函数
X39JzForm::~X39JzForm()
{
    delete ui;//释放内存
}

//成员函数“初始化”
void X39JzForm::initTask(int taskId, int targetId)
{
    this->taskId = taskId;
    this->targetId = targetId;

    this->runStatus = UNSTART;
}
