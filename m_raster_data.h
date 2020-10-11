#ifndef M_RASTER_DATA_H
#define M_RASTER_DATA_H

#include <qwt_matrix_raster_data.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_plot.h>

class SpectrogramData: public QwtMatrixRasterData
{
public:
    SpectrogramData(int columns = 480, int rows = 780)
    {
        this->columns = columns;
        this->rows = rows;
        this->capacity = columns * rows;
        this->currentIndex = 0;

        setInterval( Qt::XAxis, QwtInterval( 0, this->columns ) );
        setInterval( Qt::YAxis, QwtInterval( 0, this->rows ) );
        setInterval( Qt::ZAxis, QwtInterval( 0.0, 256 ) );

        this->historyValues.resize(this->capacity);
        setValueMatrix(this->historyValues, this->columns);
    }

    void reset()
    {
        this->currentIndex = 0;
        for (int i=0;i<this->capacity;i++) {
            this->historyValues.replace(i, 0);
        }

        setValueMatrix(this->historyValues, this->columns);
    }

    int getCurrentIndex()
    {
        return this->currentIndex;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    int getColumns()
    {
        return this->columns;
    }

    int getRows()
    {
        return this->rows;
    }

    // 追加模式
    void appendDataValue(const QVector<double> &values)
    {
        int size = values.size();
        if (size == 0) {
            return;
        }

        int capity = this->rows *this->columns;
        QVector<double> resultValues(capity, 0);
        for (int i=size;i<capity;i++) {
            resultValues.replace(i-size, this->historyValues.at(i));
        }
        for (int j=0;j<size;j++){
            resultValues.replace(capity-size+j, values.at(j));
        }

        setValueMatrix(resultValues, this->columns);
        this->historyValues = resultValues;
    }

    // 插入模式
    void prependDataValue(const QVector<double> &values){
        for (int i=0;i<values.size();i++) {
            this->historyValues.replace(this->currentIndex % this->capacity, values.at(i));
            this->currentIndex++;
        }
        setValueMatrix(this->historyValues, this->columns);
    }

private:
    QVector<double> historyValues;   //自动初始化为0
    int columns;
    int rows;
    int capacity;
    int currentIndex;
};

class MFrameSpectrogram : public QwtPlotSpectrogram
{
    void draw(QPainter *painter, const QwtScaleMap &xMap, const QwtScaleMap &yMap, const QRectF &canvasRect) const {
        QwtPlotSpectrogram::draw(painter, xMap, yMap, canvasRect);

        SpectrogramData *data = (SpectrogramData*)this->data();
        if (data == NULL)
            return;

        painter->save();
        painter->setPen(Qt::yellow);


        QwtPlot *plot = static_cast<QwtPlot *>(this->plot());
        const QwtScaleMap ymap = plot->canvasMap(QwtPlot::yLeft);
        const QwtScaleMap xmap = plot->canvasMap(QwtPlot::xBottom);

        double x1 = xmap.transform(0), x2 = xmap.transform(data->getColumns());
        int currentIndex = data->getCurrentIndex();
        int y = (currentIndex % data->getCapacity()) / data->getColumns();

        double y1 = ymap.transform(y);
        painter->drawLine(x1, y1, x2, y1);


        painter->restore();
    }
};

#endif // M_RASTER_DATA_H
