/********************************************************************************
** Form generated from reading UI file 'widgetscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSCREEN_H
#define UI_WIDGETSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <curveplot.h>
#include <mpcolorplot.h>

QT_BEGIN_NAMESPACE

class Ui_widgetScreen
{
public:
    QWidget *widgetScreen_2;
    QGroupBox *groupBox_3;
    MpColorPlot *lofarcvPlot;
    MpColorPlot *lofarcoPlot;
    MpColorPlot *demoncoPlot;
    MpColorPlot *demoncvPlot;
    QTableWidget *echoTxt;
    curvePlot *lofarcvPlotcurve;
    curvePlot *demoncvPlotcurve;
    QGroupBox *groupBox_2;
    MpColorPlot *pasPlot;
    MpColorPlot *cpPlot;
    curvePlot *cpPlotcurve;

    void setupUi(QWidget *widgetScreen)
    {
        if (widgetScreen->objectName().isEmpty())
            widgetScreen->setObjectName(QString::fromUtf8("widgetScreen"));
        widgetScreen->resize(1962, 746);
        widgetScreen_2 = new QWidget(widgetScreen);
        widgetScreen_2->setObjectName(QString::fromUtf8("widgetScreen_2"));
        widgetScreen_2->setGeometry(QRect(0, 0, 1881, 741));
        groupBox_3 = new QGroupBox(widgetScreen_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1240, 0, 641, 741));
        lofarcvPlot = new MpColorPlot(groupBox_3);
        lofarcvPlot->setObjectName(QString::fromUtf8("lofarcvPlot"));
        lofarcvPlot->setGeometry(QRect(10, 200, 631, 16));
        lofarcoPlot = new MpColorPlot(groupBox_3);
        lofarcoPlot->setObjectName(QString::fromUtf8("lofarcoPlot"));
        lofarcoPlot->setGeometry(QRect(10, 300, 631, 161));
        demoncoPlot = new MpColorPlot(groupBox_3);
        demoncoPlot->setObjectName(QString::fromUtf8("demoncoPlot"));
        demoncoPlot->setGeometry(QRect(10, 570, 631, 161));
        demoncvPlot = new MpColorPlot(groupBox_3);
        demoncvPlot->setObjectName(QString::fromUtf8("demoncvPlot"));
        demoncvPlot->setGeometry(QRect(10, 470, 631, 16));
        echoTxt = new QTableWidget(groupBox_3);
        echoTxt->setObjectName(QString::fromUtf8("echoTxt"));
        echoTxt->setGeometry(QRect(10, 0, 631, 192));
        lofarcvPlotcurve = new curvePlot(groupBox_3);
        lofarcvPlotcurve->setObjectName(QString::fromUtf8("lofarcvPlotcurve"));
        lofarcvPlotcurve->setGeometry(QRect(10, 200, 631, 91));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lofarcvPlotcurve->sizePolicy().hasHeightForWidth());
        lofarcvPlotcurve->setSizePolicy(sizePolicy);
        demoncvPlotcurve = new curvePlot(groupBox_3);
        demoncvPlotcurve->setObjectName(QString::fromUtf8("demoncvPlotcurve"));
        demoncvPlotcurve->setGeometry(QRect(10, 490, 631, 91));
        sizePolicy.setHeightForWidth(demoncvPlotcurve->sizePolicy().hasHeightForWidth());
        demoncvPlotcurve->setSizePolicy(sizePolicy);
        groupBox_2 = new QGroupBox(widgetScreen_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1241, 741));
        pasPlot = new MpColorPlot(groupBox_2);
        pasPlot->setObjectName(QString::fromUtf8("pasPlot"));
        pasPlot->setGeometry(QRect(-20, 200, 1261, 541));
        cpPlot = new MpColorPlot(groupBox_2);
        cpPlot->setObjectName(QString::fromUtf8("cpPlot"));
        cpPlot->setGeometry(QRect(-20, 0, 1261, 0));
        cpPlotcurve = new curvePlot(groupBox_2);
        cpPlotcurve->setObjectName(QString::fromUtf8("cpPlotcurve"));
        cpPlotcurve->setGeometry(QRect(0, 0, 1241, 191));
        sizePolicy.setHeightForWidth(cpPlotcurve->sizePolicy().hasHeightForWidth());
        cpPlotcurve->setSizePolicy(sizePolicy);

        retranslateUi(widgetScreen);

        QMetaObject::connectSlotsByName(widgetScreen);
    } // setupUi

    void retranslateUi(QWidget *widgetScreen)
    {
        widgetScreen->setWindowTitle(QCoreApplication::translate("widgetScreen", "Form", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class widgetScreen: public Ui_widgetScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSCREEN_H
