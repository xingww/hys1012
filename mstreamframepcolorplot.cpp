﻿#include "mstreamframepcolorplot.h"
#include <QMultiMap>
#include <QTime>
#include <QDateTime>
#include <QStack>
#include <QMouseEvent>
#include <QtCore/QtMath>
#include <QToolTip>

MStreamFramepColorPlot::MStreamFramepColorPlot(QWidget *parent) : QwtPlot(parent)
{
    d_spectrogram = new MFrameSpectrogram();
//    d_spectrogram->setRenderThreadCount(0);
    d_spectrogram->setColorMap(new TLinearColorMapRGB(TLinearColorMapRGB::JETRGB));

    d_spectrogram->attach(this);
}

void MStreamFramepColorPlot::setDimension(int columns, int rows)
{
    this->columns = columns;
    this->rows = rows;

    setAxisScale(Axis::xBottom, 0, this->columns);
    setAxisScale(Axis::yLeft, 0, this->rows);

    enableAxis(Axis::xBottom, false);
    enableAxis(Axis::yLeft, false);
}

void MStreamFramepColorPlot::setUpdateData(QVector<double> &values)
{
    QwtRasterData *tmp_data = this->d_spectrogram->data();
    if (tmp_data == NULL) {
        this->data = new SpectrogramData(this->columns, this->rows);
        this->d_spectrogram->setData(this->data);
    }

    this->updateValues = values;
}

void MStreamFramepColorPlot::update()
{
    if (this->updateValues.isEmpty())
        return;

    this->data->prependDataValue(this->updateValues);

    replot();
}

void MStreamFramepColorPlot::reset()
{
    if (this->data == NULL)
        return;

    this->data->reset();
    replot();
}

void MStreamFramepColorPlot::mouseReleaseEvent(QMouseEvent *event)
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

