#ifndef MFRAMEPCOLORPLOT_H
#define MFRAMEPCOLORPLOT_H

#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_matrix_raster_data.h>
#include <qwt_color_map.h>
#include <QMultiMap>
#include <QDateTime>
#include <QVector>
#include <QString>
#include "m_colormap.h"
#include "m_raster_data.h"

class MFramepColorPlot: public QwtPlot
{
    Q_OBJECT
public:
    MFramepColorPlot(QWidget * = NULL);
    void setRawData(QMultiMap<QString, QVector<double>> &values, const QDateTime &startTime, const QDateTime &endTime);
    void setDimension(int columns, int rows);
    void setGlobalInterval(const QDateTime &start, const QDateTime &end);

    void setTimerCount(int timerCount);
    void update();
    void reset();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    MFrameSpectrogram *d_spectrogram = NULL;
    SpectrogramData *data = NULL;
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
};

#endif // MFRAMEPCOLORPLOT_H
