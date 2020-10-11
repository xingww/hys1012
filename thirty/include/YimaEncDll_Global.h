#ifndef YIMAENCDLL_GLOBAL_H
#define YIMAENCDLL_GLOBAL_H

#include <QtCore/qglobal.h>
#include <qpixmap.h>

#if defined(YIMAENCDLL_LIBRARY)
#  define YIMAENCDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define YIMAENCDLLSHARED_IMPORT Q_DECL_IMPORT
#endif

#endif // YIMAENCDLL_GLOBAL_H
