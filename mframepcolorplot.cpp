#include "mframepcolorplot.h"
#include <QMultiMap>
#include <QTime>
#include <QDateTime>
#include <QStack>
#include <QMouseEvent>
#include <QToolTip>
#include <QtCore/QtMath>

MFramepColorPlot::MFramepColorPlot(QWidget *parent) : QwtPlot(parent)
{
    d_spectrogram = new MFrameSpectrogram();
//    d_spectrogram->setRenderThreadCount(0);
    d_spectrogram->setColorMap(new TLinearColorMapRGB(TLinearColorMapRGB::JETRGB));

    d_spectrogram->attach(this);
}

void MFramepColorPlot::setDimension(int columns, int rows)
{
    this->columns = columns;
    this->rows = rows;

    setAxisScale(Axis::xBottom, 0, this->columns);
    setAxisScale(Axis::yLeft, 0, this->rows);

    enableAxis(Axis::xBottom, false);
    enableAxis(Axis::yLeft, false);
}

void MFramepColorPlot::setGlobalInterval(const QDateTime &start, const QDateTime &end)
{
    this->globalStartTime = start;
    this->globalEndTime = end;
}

void MFramepColorPlot::setRawData(QMultiMap<QString, QVector<double>> &values, const QDateTime &startTime, const QDateTime &endTime)
{
    this->timercount = 0;
    this->dataStartTime = startTime;
    this->dataEndTime = endTime;
    this->rawValues = values;

    QwtRasterData *tmp_data = this->d_spectrogram->data();
    if (tmp_data == NULL) {
        this->data = new SpectrogramData(this->columns, this->rows);
        this->d_spectrogram->setData(this->data);
    }
}

void MFramepColorPlot::setTimerCount(int timerCount)
{
    this->timercount = timerCount;
}

void MFramepColorPlot::update()
{
    QDateTime current = this->globalStartTime.addSecs(this->timercount);

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

    this->data->prependDataValue(values);

    replot();
}

void MFramepColorPlot::reset()
{
    if (this->data == NULL)
        return;

    this->data->reset();
    this->timercount = 0;
    replot();
}

void MFramepColorPlot::mouseReleaseEvent(QMouseEvent *event)
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
