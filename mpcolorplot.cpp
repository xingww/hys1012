#include "mpcolorplot.h"
#include <QMultiMap>
#include <QTime>
#include <QDateTime>
#include <QStack>
#include <QMouseEvent>
#include <QtCore/QtMath>
#include <QToolTip>
#include <QDebug>

MpColorPlot::MpColorPlot(QWidget *parent) : QwtPlot(parent)
{
    d_spectrogram = new QwtPlotSpectrogram();
    d_spectrogram->setColorMap(new TLinearColorMapRGB(TLinearColorMapRGB::JETRGB));
    d_spectrogram->attach(this);
}

//设置维度
void MpColorPlot::setDimension(int columns, int rows)
{
    this->columns = columns;
    this->rows = rows;

    setAxisScale(Axis::xBottom, 0, this->columns);
    setAxisScale(Axis::yLeft, 0, this->rows);

    enableAxis(Axis::xBottom, false);
    enableAxis(Axis::yLeft, false);
}

//设置全局间隔时间
void MpColorPlot::setGlobalInterval(const QDateTime &start, const QDateTime &end)
{
    this->globalStartTime = start;
    this->globalEndTime = end;
}

//设置未加工数据
void MpColorPlot::setRawData(QMultiMap<QString, QVector<double>> &values, const QDateTime &startTime, const QDateTime &endTime)
{
    this->timercount = 0;
    this->dataStartTime = startTime;
    this->dataEndTime = endTime;
    this->rawValues = values;

    QwtRasterData *tmp_data = this->d_spectrogram->data();

    //如果tmp_data为空，则赋默认值
    if (tmp_data == NULL) {
        this->data = new SpectrogramData(this->columns, this->rows);
        this->d_spectrogram->setData(this->data);
    }
}


//设置计时
void MpColorPlot::setTimerCount(int timerCount)
{
    this->timercount = timerCount;
}

//更新
void MpColorPlot::update()
{
    QDateTime current = this->globalStartTime.addSecs(this->timercount);

    //如果当前时间不在范围内，则直接退出
    if (current < this->dataStartTime || current > this->dataEndTime)
        return;

    // 最多仅读取rows行数据
    QVector<double> values;
    // 临时变量，保证vector的顺序
    QStack<QVector<double>> tmpStack;
    QList<QVector<double>> result = this->rawValues.values(current.toString("yyyy-MM-dd hh:mm:ss"));

    for (int i=0;i<result.size();i++) {
        QVector<double> tmp = result.at(i);
        tmpStack.push(tmp);
    }

    while (!tmpStack.isEmpty())
    {
        QVector<double> tmp = tmpStack.pop();
        values.append(tmp);
    }

    this->data->appendDataValue(values);

    replot();
}

//复位
void MpColorPlot::reset()
{
    if (this->data == NULL)
        return;

    this->data->reset();
    this->timercount = 0;
    replot();
}

//鼠标释放事件
void MpColorPlot::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->data == NULL)
        return;

    QPoint currentPos = event->pos();

    const QwtScaleMap ymap = this->canvasMap(QwtPlot::yLeft);
    const QwtScaleMap xmap = this->canvasMap(QwtPlot::xBottom);

    double scaleY = ymap.invTransform(currentPos.y());
    double scaleX = xmap.invTransform(currentPos.x());

    double valueZ = this->data->value(scaleX, scaleY);

    int intX = qRound(scaleX), intY = qRound(scaleY);

    QToolTip::showText(event->globalPos(), QString::fromLocal8Bit("值:%1\nX:%2, Y:%3").arg(valueZ).arg(intX).arg(intY));
}
