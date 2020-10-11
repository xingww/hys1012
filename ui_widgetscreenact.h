/********************************************************************************
** Form generated from reading UI file 'widgetscreenact.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSCREENACT_H
#define UI_WIDGETSCREENACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <curveplot.h>
#include <mpcolorplot.h>

QT_BEGIN_NAMESPACE

class Ui_widgetscreenact
{
public:
    QWidget *Screenact;
    QGroupBox *groupBox_3;
    MpColorPlot *mfPlot;
    MpColorPlot *mfaPlot;
    MpColorPlot *sftPlot;
    MpColorPlot *wavPlot;
    QTableWidget *echoactTxt;
    curvePlot *wavPlotcurve;
    curvePlot *mfPlotcurve;
    QGroupBox *groupBox_2;
    MpColorPlot *actPlot;

    void setupUi(QWidget *widgetscreenact)
    {
        if (widgetscreenact->objectName().isEmpty())
            widgetscreenact->setObjectName(QString::fromUtf8("widgetscreenact"));
        widgetscreenact->resize(1884, 743);
        Screenact = new QWidget(widgetscreenact);
        Screenact->setObjectName(QString::fromUtf8("Screenact"));
        Screenact->setGeometry(QRect(0, 0, 1881, 741));
        groupBox_3 = new QGroupBox(Screenact);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1240, 0, 641, 741));
        mfPlot = new MpColorPlot(groupBox_3);
        mfPlot->setObjectName(QString::fromUtf8("mfPlot"));
        mfPlot->setGeometry(QRect(10, 200, 641, 16));
        mfaPlot = new MpColorPlot(groupBox_3);
        mfaPlot->setObjectName(QString::fromUtf8("mfaPlot"));
        mfaPlot->setGeometry(QRect(10, 300, 641, 161));
        sftPlot = new MpColorPlot(groupBox_3);
        sftPlot->setObjectName(QString::fromUtf8("sftPlot"));
        sftPlot->setGeometry(QRect(10, 570, 641, 171));
        wavPlot = new MpColorPlot(groupBox_3);
        wavPlot->setObjectName(QString::fromUtf8("wavPlot"));
        wavPlot->setGeometry(QRect(10, 470, 641, 16));
        echoactTxt = new QTableWidget(groupBox_3);
        echoactTxt->setObjectName(QString::fromUtf8("echoactTxt"));
        echoactTxt->setGeometry(QRect(10, 0, 631, 192));
        wavPlotcurve = new curvePlot(groupBox_3);
        wavPlotcurve->setObjectName(QString::fromUtf8("wavPlotcurve"));
        wavPlotcurve->setGeometry(QRect(10, 470, 631, 101));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wavPlotcurve->sizePolicy().hasHeightForWidth());
        wavPlotcurve->setSizePolicy(sizePolicy);
        mfPlotcurve = new curvePlot(groupBox_3);
        mfPlotcurve->setObjectName(QString::fromUtf8("mfPlotcurve"));
        mfPlotcurve->setGeometry(QRect(10, 200, 631, 91));
        sizePolicy.setHeightForWidth(mfPlotcurve->sizePolicy().hasHeightForWidth());
        mfPlotcurve->setSizePolicy(sizePolicy);
        groupBox_2 = new QGroupBox(Screenact);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1241, 741));
        actPlot = new MpColorPlot(groupBox_2);
        actPlot->setObjectName(QString::fromUtf8("actPlot"));
        actPlot->setGeometry(QRect(-20, 0, 1261, 741));

        retranslateUi(widgetscreenact);

        QMetaObject::connectSlotsByName(widgetscreenact);
    } // setupUi

    void retranslateUi(QWidget *widgetscreenact)
    {
        widgetscreenact->setWindowTitle(QCoreApplication::translate("widgetscreenact", "Form", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class widgetscreenact: public Ui_widgetscreenact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSCREENACT_H
