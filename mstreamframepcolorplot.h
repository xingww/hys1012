#ifndef MSTREAMFRAMEPCOLORPLOT_H
#define MSTREAMFRAMEPCOLORPLOT_H

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

class MStreamFramepColorPlot: public QwtPlot
{
    Q_OBJECT
public:
    MStreamFramepColorPlot(QWidget * = NULL);
    void setUpdateData(QVector<double> &values);
    void setDimension(int columns, int rows);

    void update();
    void reset();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    MFrameSpectrogram *d_spectrogram;
    SpectrogramData *data;
    int columns;
    int rows;

    // 更新数据
    QVector<double> updateValues;
};

#endif // MSTREAMFRAMEPCOLORPLOT_H
