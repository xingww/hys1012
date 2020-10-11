#ifndef CURVEPLOT_H
#define CURVEPLOT_H

#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_color_map.h>
#include <QMultiMap>
#include <QDateTime>
#include <QVector>
#include <QString>
#include "m_colormap.h"
#include "m_raster_data.h"

class curvePlot: public QwtPlot
{
public:
    QwtPlotSpectrogram *d_spectrogram = NULL;
    SpectrogramData *data = NULL;
    curvePlot(QWidget * = NULL);
    void setRawDatacurve(QMultiMap<QString, QVector<double>> &values, const QDateTime &startTime, const QDateTime &endTime);
    void setGlobalInterval(const QDateTime &start, const QDateTime &end);

    void setTimerCount(int timerCount);
    void update();
    void reset();
    double getData();
    double getData1(double time);

private:
    int columns;
    int rows;
    int timercount;
    // 原始数据
    QMultiMap<QString, QVector<double>> rawValues;
    QDateTime dataStartTime;
    QDateTime dataEndTime;
    QDateTime globalStartTime;
    QDateTime globalEndTime;
    QString strStartTime;
private:

};

#endif // CURVEPLOT_H
