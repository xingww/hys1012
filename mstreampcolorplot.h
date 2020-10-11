#ifndef MSTREAMPCOLORPLOT_H
#define MSTREAMPCOLORPLOT_H

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

class MStreampColorPlot: public QwtPlot
{
    Q_OBJECT
public:
    MStreampColorPlot(QWidget * = NULL);
    void setUpdateData(QVector<double> &values);
    void setDimension(int columns, int rows);

    void update();
    void reset();
    bool isDataInit();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QwtPlotSpectrogram *d_spectrogram;
    SpectrogramData *data;
    int columns;
    int rows;

    // 更新数据
    QVector<double> updateValues;
};

#endif // MSTREAMPCOLORPLOT_H
