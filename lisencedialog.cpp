#include "lisencedialog.h"
#include "ui_lisencedialog.h"
#include "hysauth.h"
#include <QMessageBox>
#include <QPainter>
#include <QtCore/qmath.h>

LisenceDialog::LisenceDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LisenceDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->ui->titleBar->setWindowTitle(QString::fromLocal8Bit("授权设置"));
    initUI();
}

LisenceDialog::~LisenceDialog()
{
    delete ui;
}

void LisenceDialog::initUI()
{

}

void LisenceDialog::on_btnSave_clicked()
{
    QString number = this->ui->inLisenceNo->text();
    if (number.isEmpty()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("保存序列号"), QString::fromLocal8Bit("序列号不能为空！"));
        return;
    }

    bool result = HysAuthHelper::getInstance()->checkAuthorization(number);
    if (result) {
        HysAuthHelper::getInstance()->save(number);
        QMessageBox::information(this, QString::fromLocal8Bit("授权成功"), QString::fromLocal8Bit("授权成功，请重新启动程序！"));
        exit(0);
    } else {
        QMessageBox::warning(this, QString::fromLocal8Bit("授权失败"), QString::fromLocal8Bit("序列号校验失败，请重新输入！"));
    }
}

void LisenceDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width()-10, this->height()-10);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0;i<5;i++) {
        QPainterPath tmpPath;
        tmpPath.setFillRule(Qt::WindingFill);
        tmpPath.addRect(5-i, 5-i, this->width()-(5-i)*2, this->height()-(5-i)*2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(tmpPath);
    }
}
