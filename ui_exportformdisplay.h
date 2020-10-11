/********************************************************************************
** Form generated from reading UI file 'exportformdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTFORMDISPLAY_H
#define UI_EXPORTFORMDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "mpcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_exportformdisplay
{
public:
    QGridLayout *gridLayout;
    MpColorPlot *actfullscreenPlot;
    MpColorPlot *pasfullscreenPlot;

    void setupUi(QWidget *exportformdisplay)
    {
        if (exportformdisplay->objectName().isEmpty())
            exportformdisplay->setObjectName(QString::fromUtf8("exportformdisplay"));
        exportformdisplay->resize(865, 445);
        gridLayout = new QGridLayout(exportformdisplay);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        actfullscreenPlot = new MpColorPlot(exportformdisplay);
        actfullscreenPlot->setObjectName(QString::fromUtf8("actfullscreenPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(actfullscreenPlot->sizePolicy().hasHeightForWidth());
        actfullscreenPlot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(actfullscreenPlot, 0, 0, 1, 1);

        pasfullscreenPlot = new MpColorPlot(exportformdisplay);
        pasfullscreenPlot->setObjectName(QString::fromUtf8("pasfullscreenPlot"));
        sizePolicy.setHeightForWidth(pasfullscreenPlot->sizePolicy().hasHeightForWidth());
        pasfullscreenPlot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pasfullscreenPlot, 0, 1, 1, 1);


        retranslateUi(exportformdisplay);

        QMetaObject::connectSlotsByName(exportformdisplay);
    } // setupUi

    void retranslateUi(QWidget *exportformdisplay)
    {
        exportformdisplay->setWindowTitle(QCoreApplication::translate("exportformdisplay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exportformdisplay: public Ui_exportformdisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTFORMDISPLAY_H
