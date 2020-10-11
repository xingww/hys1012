/********************************************************************************
** Form generated from reading UI file 'x39sceneform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X39SCENEFORM_H
#define UI_X39SCENEFORM_H

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

class Ui_X39SceneForm
{
public:
    QVBoxLayout *verticalLayout_6;
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
    QVBoxLayout *verticalLayout_3;
    MpColorPlot *edPlot;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    MpColorPlot *noiseLPlot;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    MpColorPlot *noiseSPlot;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    MpColorPlot *fsdPlot;
    QVBoxLayout *vlContainer;

    void setupUi(QWidget *X39SceneForm)
    {
        if (X39SceneForm->objectName().isEmpty())
            X39SceneForm->setObjectName(QString::fromUtf8("X39SceneForm"));
        X39SceneForm->resize(731, 399);
        verticalLayout_6 = new QVBoxLayout(X39SceneForm);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbStart = new QLabel(X39SceneForm);
        lbStart->setObjectName(QString::fromUtf8("lbStart"));
        lbStart->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_4->addWidget(lbStart);

        lbEnd = new QLabel(X39SceneForm);
        lbEnd->setObjectName(QString::fromUtf8("lbEnd"));
        lbEnd->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lbEnd);


        verticalLayout->addLayout(horizontalLayout_4);

        slider = new QSlider(X39SceneForm);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setStyleSheet(QString::fromUtf8("border-image:none;"));
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);

        lbRunningTime = new QLabel(X39SceneForm);
        lbRunningTime->setObjectName(QString::fromUtf8("lbRunningTime"));
        lbRunningTime->setStyleSheet(QString::fromUtf8("border-image:none;"));

        verticalLayout->addWidget(lbRunningTime);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnStart = new QPushButton(X39SceneForm);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(25, 25));
        btnStart->setMaximumSize(QSize(25, 25));
        btnStart->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/start.png);\n"
""));
        btnStart->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btnStart);

        btnStop = new QPushButton(X39SceneForm);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(20, 20));
        btnStop->setMaximumSize(QSize(20, 20));
        btnStop->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/stop.png);"));

        horizontalLayout_3->addWidget(btnStop);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbActive = new QRadioButton(X39SceneForm);
        rbActive->setObjectName(QString::fromUtf8("rbActive"));
        rbActive->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout->addWidget(rbActive);

        rbPassive = new QRadioButton(X39SceneForm);
        rbPassive->setObjectName(QString::fromUtf8("rbPassive"));
        rbPassive->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout->addWidget(rbPassive);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(X39SceneForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
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
        tabWidget->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        edPlot = new MpColorPlot(tab);
        edPlot->setObjectName(QString::fromUtf8("edPlot"));
        edPlot->setStyleSheet(QString::fromUtf8("border:none;"));

        verticalLayout_3->addWidget(edPlot);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        noiseLPlot = new MpColorPlot(tab_2);
        noiseLPlot->setObjectName(QString::fromUtf8("noiseLPlot"));

        verticalLayout_4->addWidget(noiseLPlot);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        noiseSPlot = new MpColorPlot(tab_3);
        noiseSPlot->setObjectName(QString::fromUtf8("noiseSPlot"));

        verticalLayout_2->addWidget(noiseSPlot);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        fsdPlot = new MpColorPlot(tab_4);
        fsdPlot->setObjectName(QString::fromUtf8("fsdPlot"));

        verticalLayout_5->addWidget(fsdPlot);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_2->addWidget(tabWidget);

        vlContainer = new QVBoxLayout();
        vlContainer->setObjectName(QString::fromUtf8("vlContainer"));
        vlContainer->setContentsMargins(-1, 0, -1, -1);

        horizontalLayout_2->addLayout(vlContainer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_2);


        retranslateUi(X39SceneForm);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(X39SceneForm);
    } // setupUi

    void retranslateUi(QWidget *X39SceneForm)
    {
        X39SceneForm->setWindowTitle(QCoreApplication::translate("X39SceneForm", "Form", nullptr));
        lbStart->setText(QCoreApplication::translate("X39SceneForm", "S:18\357\274\23201\357\274\23213", nullptr));
        lbEnd->setText(QCoreApplication::translate("X39SceneForm", "E:18\357\274\23201\357\274\23213", nullptr));
        lbRunningTime->setText(QString());
        btnStart->setText(QString());
        btnStop->setText(QString());
        rbActive->setText(QCoreApplication::translate("X39SceneForm", "\344\270\273\345\212\250", nullptr));
        rbPassive->setText(QCoreApplication::translate("X39SceneForm", "\350\242\253\345\212\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("X39SceneForm", "\347\252\204\345\270\246\350\255\246\346\210\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("X39SceneForm", "\345\231\252\345\243\260\345\216\206\347\250\213(\351\225\277)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("X39SceneForm", "\345\231\252\345\243\260\345\216\206\347\250\213(\347\237\255)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("X39SceneForm", "\345\244\232\346\231\256\345\213\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X39SceneForm: public Ui_X39SceneForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X39SCENEFORM_H
