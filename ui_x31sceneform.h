/********************************************************************************
** Form generated from reading UI file 'x31sceneform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31SCENEFORM_H
#define UI_X31SCENEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mpcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X31SceneForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbStart;
    QLabel *lbEnd;
    QSlider *slider;
    QLabel *lbRunningTime;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbActive;
    QRadioButton *rbPassive;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_6;
    MpColorPlot *fullPlot;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    MpColorPlot *zdLofarPlot;
    QVBoxLayout *vlContainer;

    void setupUi(QWidget *X31SceneForm)
    {
        if (X31SceneForm->objectName().isEmpty())
            X31SceneForm->setObjectName(QString::fromUtf8("X31SceneForm"));
        X31SceneForm->resize(674, 507);
        verticalLayout_3 = new QVBoxLayout(X31SceneForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbStart = new QLabel(X31SceneForm);
        lbStart->setObjectName(QString::fromUtf8("lbStart"));
        lbStart->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_4->addWidget(lbStart);

        lbEnd = new QLabel(X31SceneForm);
        lbEnd->setObjectName(QString::fromUtf8("lbEnd"));
        lbEnd->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lbEnd);


        verticalLayout->addLayout(horizontalLayout_4);

        slider = new QSlider(X31SceneForm);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setStyleSheet(QString::fromUtf8("border-image:none;"));
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);

        lbRunningTime = new QLabel(X31SceneForm);
        lbRunningTime->setObjectName(QString::fromUtf8("lbRunningTime"));
        lbRunningTime->setStyleSheet(QString::fromUtf8("border-image:none;"));

        verticalLayout->addWidget(lbRunningTime);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnStart = new QPushButton(X31SceneForm);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(25, 25));
        btnStart->setMaximumSize(QSize(25, 25));
        btnStart->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/start.png);\n"
""));

        horizontalLayout_3->addWidget(btnStart);

        btnStop = new QPushButton(X31SceneForm);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(20, 20));
        btnStop->setMaximumSize(QSize(20, 20));
        btnStop->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/stop.png);"));

        horizontalLayout_3->addWidget(btnStop);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbActive = new QRadioButton(X31SceneForm);
        rbActive->setObjectName(QString::fromUtf8("rbActive"));
        rbActive->setStyleSheet(QString::fromUtf8("border-image:none;"));
        rbActive->setChecked(true);

        horizontalLayout->addWidget(rbActive);

        rbPassive = new QRadioButton(X31SceneForm);
        rbPassive->setObjectName(QString::fromUtf8("rbPassive"));
        rbPassive->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout->addWidget(rbPassive);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(X31SceneForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    border-image:url(:/destop/background.png);\n"
"    color:#EBECFB;\n"
"    padding-right:10px;\n"
"    padding-top:5px;\n"
"    padding-bottom:5px;\n"
"    padding-left:5px;\n"
"    border:1px solid #F2F2F2;\n"
"}\n"
"QTabBar::tab:hover {\n"
"    color:#4169E1;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    color:#398AF1;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_6 = new QHBoxLayout(tab);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        fullPlot = new MpColorPlot(tab);
        fullPlot->setObjectName(QString::fromUtf8("fullPlot"));

        horizontalLayout_6->addWidget(fullPlot);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        zdLofarPlot = new MpColorPlot(tab_2);
        zdLofarPlot->setObjectName(QString::fromUtf8("zdLofarPlot"));
        zdLofarPlot->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(zdLofarPlot);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);

        vlContainer = new QVBoxLayout();
        vlContainer->setObjectName(QString::fromUtf8("vlContainer"));
        vlContainer->setContentsMargins(-1, 0, -1, -1);

        horizontalLayout_2->addLayout(vlContainer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(X31SceneForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(X31SceneForm);
    } // setupUi

    void retranslateUi(QWidget *X31SceneForm)
    {
        X31SceneForm->setWindowTitle(QCoreApplication::translate("X31SceneForm", "Form", nullptr));
        lbStart->setText(QCoreApplication::translate("X31SceneForm", "S:18\357\274\23201\357\274\23213", nullptr));
        lbEnd->setText(QCoreApplication::translate("X31SceneForm", "E:18\357\274\23201\357\274\23213", nullptr));
        lbRunningTime->setText(QString());
        btnStart->setText(QString());
        btnStop->setText(QString());
        rbActive->setText(QCoreApplication::translate("X31SceneForm", "\344\270\273\345\212\250", nullptr));
        rbPassive->setText(QCoreApplication::translate("X31SceneForm", "\350\242\253\345\212\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("X31SceneForm", "\350\242\253\345\212\250\345\205\250\346\226\271\344\275\215\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("X31SceneForm", "\350\242\253\345\212\250\347\252\204\345\270\246LOFAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31SceneForm: public Ui_X31SceneForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31SCENEFORM_H
