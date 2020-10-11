#ifndef M_COLORMAP_H
#define M_COLORMAP_H

#include <qwt_color_map.h>

class TLinearColorMapRGB: public QwtLinearColorMap
{
public:
    enum CMode
    {
        JETRGB,
        GRAYRGB
    };

public:
    TLinearColorMapRGB(CMode mode = CMode::JETRGB): QwtLinearColorMap()
    {
        const double ratio = 1.0 / 63;
        if (mode == CMode::GRAYRGB) {
            for(int i=0;i<64;i++){
                addColorStop( i * ratio, QColor(i * ratio * 255, i * ratio * 255, i * ratio * 255) );
            }
        } else {
            addColorStop( 0, QColor(0, 0, 144) );
            addColorStop( ratio, QColor(0, 0, 160) );
            addColorStop( 2.0*ratio, QColor(0, 0, 176) );
            addColorStop( 3.0*ratio, QColor(0, 0, 192) );
            addColorStop( 4.0*ratio, QColor(0, 0, 208) );
            addColorStop( 5.0*ratio, QColor(0, 0, 224) );
            addColorStop( 6.0*ratio, QColor(0, 0, 240) );
            addColorStop( 7.0*ratio, QColor(0, 0, 255) );
            addColorStop( 8.0*ratio, QColor(0, 16, 255) );
            addColorStop( 9.0*ratio, QColor(0, 32, 255) );
            addColorStop( 10.0*ratio, QColor(0, 48, 255) );
            addColorStop( 11.0*ratio, QColor(0, 64, 255) );
            addColorStop( 12.0*ratio, QColor(0, 80, 255) );
            addColorStop( 13*ratio, QColor(0, 96, 255) );
            addColorStop( 14*ratio, QColor(0, 112, 255) );
            addColorStop( 15*ratio, QColor(0, 128, 255) );
            addColorStop( 16*ratio, QColor(0, 144, 255) );
            addColorStop( 17*ratio, QColor(0, 160, 255) );
            addColorStop( 18*ratio, QColor(0, 176, 255) );
            addColorStop( 19*ratio, QColor(0, 192, 255) );
            addColorStop( 20*ratio, QColor(0, 208, 255) );
            addColorStop( 21*ratio, QColor(0, 224, 255) );
            addColorStop( 22*ratio, QColor(0, 240, 255) );
            addColorStop( 23*ratio, QColor(0, 255, 255) );
            addColorStop( 24*ratio, QColor(16, 255, 240) );
            addColorStop( 25*ratio, QColor(32, 255, 224) );
            addColorStop( 26*ratio, QColor(48, 255, 208) );
            addColorStop( 27*ratio, QColor(64, 255, 192) );
            addColorStop( 28*ratio, QColor(80, 255, 176) );
            addColorStop( 29*ratio, QColor(96, 255, 160) );
            addColorStop( 30*ratio, QColor(112, 255, 144) );
            addColorStop( 31*ratio, QColor(128, 255, 128) );
            addColorStop( 32*ratio, QColor(144, 255, 112) );
            addColorStop( 33*ratio, QColor(160, 255, 96) );
            addColorStop( 34*ratio, QColor(176, 255, 80) );
            addColorStop( 35*ratio, QColor(192, 255, 64) );
            addColorStop( 36*ratio, QColor(208, 255, 48) );
            addColorStop( 37*ratio, QColor(224, 255, 32) );
            addColorStop( 38*ratio, QColor(240, 255, 16) );
            addColorStop( 39*ratio, QColor(255, 255, 0) );
            addColorStop( 40*ratio, QColor(255, 240, 0) );
            addColorStop( 41*ratio, QColor(255, 224, 0) );
            addColorStop( 42*ratio, QColor(255, 208, 0) );
            addColorStop( 43*ratio, QColor(255, 192, 0) );
            addColorStop( 44*ratio, QColor(255, 176, 0) );
            addColorStop( 45*ratio, QColor(255, 160, 0) );
            addColorStop( 46*ratio, QColor(255, 144, 0) );
            addColorStop( 47*ratio, QColor(255, 128, 0) );
            addColorStop( 48*ratio, QColor(255, 112, 0) );
            addColorStop( 49*ratio, QColor(255, 96, 0) );
            addColorStop( 50*ratio, QColor(255, 80, 0) );
            addColorStop( 51*ratio, QColor(255, 64, 0) );
            addColorStop( 52*ratio, QColor(255, 48, 0) );
            addColorStop( 53*ratio, QColor(255, 32, 0) );
            addColorStop( 54*ratio, QColor(255, 16, 0) );
            addColorStop( 55*ratio, QColor(255, 0, 0) );
            addColorStop( 56*ratio, QColor(240, 0, 0) );
            addColorStop( 57*ratio, QColor(224, 0, 0) );
            addColorStop( 58*ratio, QColor(208, 0, 0) );
            addColorStop( 59*ratio, QColor(192, 0, 0) );
            addColorStop( 60*ratio, QColor(176, 0, 0) );
            addColorStop( 61*ratio, QColor(160, 0, 0) );
            addColorStop( 62*ratio, QColor(144, 0, 0) );
            addColorStop( 63*ratio, QColor(128, 0, 0) );
        }
    }
};

#endif // M_COLORMAP_H
