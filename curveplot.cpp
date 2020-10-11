#include "curveplot.h"
#include <QMultiMap>
#include <QTime>
#include <QDateTime>
#include <QStack>
#include <QMouseEvent>
#include <QtCore/QtMath>
#include <QToolTip>
#include <QDebug>

curvePlot::curvePlot(QWidget *parent):QwtPlot(parent)
{
    d_spectrogram = new QwtPlotSpectrogram();
    d_spectrogram->setColorMap(new TLinearColorMapRGB(TLinearColorMapRGB::JETRGB));
    d_spectrogram->attach(this);
}

void curvePlot::setRawDatacurve(QMultiMap<QString, QVector<double>> &values, const QDateTime &startTime, const QDateTime &endTime)
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

void curvePlot::setGlobalInterval(const QDateTime &start, const QDateTime &end)
{
    this->globalStartTime = start;
    this->globalEndTime = end;
}
//设置计时
void curvePlot::setTimerCount(int timerCount)
{
    this->timercount = timerCount;
}

//更新
void curvePlot::update()
{

}

//复位
void curvePlot::reset()
{
    if (this->data == NULL)
        return;

    this->data->reset();
    this->timercount = 0;
    replot();
}

double curvePlot::getData(){
    QDateTime current = this->globalStartTime.addSecs(this->timercount);
    //如果当前时间不在范围内，则直接退出
    if (current < this->dataStartTime || current > this->dataEndTime)
        return 1.0;

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
    qDebug()<<"timercount:"<<timercount;
    if(!values.isEmpty())
    {
            return values.value(values.size()-1);
            qDebug()<<"Values' value"<<qCos(timercount * M_PI * 50);
    }
        else
    {
            return qCos(timercount * M_PI * 50);
            qDebug()<<"s value"<<qCos(timercount * M_PI * 50);
    }
}

double curvePlot::getData1(double time){
    double s = qCos( time * M_PI * 50 ) ;
    return s;
}
