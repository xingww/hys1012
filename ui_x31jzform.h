/********************************************************************************
** Form generated from reading UI file 'x31jzform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31JZFORM_H
#define UI_X31JZFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mstreampcolorplot.h>

QT_BEGIN_NAMESPACE

class Ui_X31JzForm
{
public:
    QWidget *layoutWidget;
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
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbActive;
    QRadioButton *rbPassive;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *hlvContainer;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    MStreampColorPlot *mbLofarPlot;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_6;
    MStreampColorPlot *pwdPlot;
    MStreampColorPlot *pwdPlot_2;

    void setupUi(QWidget *X31JzForm)
    {
        if (X31JzForm->objectName().isEmpty())
            X31JzForm->setObjectName(QString::fromUtf8("X31JzForm"));
        X31JzForm->resize(645, 403);
        X31JzForm->setAutoFillBackground(true);
        layoutWidget = new QWidget(X31JzForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 621, 72));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbStart = new QLabel(layoutWidget);
        lbStart->setObjectName(QString::fromUtf8("lbStart"));
        lbStart->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_4->addWidget(lbStart);

        lbEnd = new QLabel(layoutWidget);
        lbEnd->setObjectName(QString::fromUtf8("lbEnd"));
        lbEnd->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lbEnd);


        verticalLayout->addLayout(horizontalLayout_4);

        slider = new QSlider(layoutWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setStyleSheet(QString::fromUtf8("border-image:none;"));
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);

        lbRunningTime = new QLabel(layoutWidget);
        lbRunningTime->setObjectName(QString::fromUtf8("lbRunningTime"));
        lbRunningTime->setStyleSheet(QString::fromUtf8("border-image:none;"));

        verticalLayout->addWidget(lbRunningTime);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(25, 25));
        btnStart->setMaximumSize(QSize(25, 25));
        btnStart->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/start.png);\n"
""));

        horizontalLayout_3->addWidget(btnStart);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(20, 20));
        btnStop->setMaximumSize(QSize(20, 20));
        btnStop->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/stop.png);"));

        horizontalLayout_3->addWidget(btnStop);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(X31JzForm);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 122, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rbActive = new QRadioButton(layoutWidget1);
        rbActive->setObjectName(QString::fromUtf8("rbActive"));
        rbActive->setStyleSheet(QString::fromUtf8("border-image:none;"));
        rbActive->setChecked(true);

        horizontalLayout->addWidget(rbActive);

        rbPassive = new QRadioButton(layoutWidget1);
        rbPassive->setObjectName(QString::fromUtf8("rbPassive"));
        rbPassive->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout->addWidget(rbPassive);

        horizontalLayoutWidget = new QWidget(X31JzForm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 120, 281, 271));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        hlvContainer = new QVBoxLayout();
        hlvContainer->setObjectName(QString::fromUtf8("hlvContainer"));
        tabWidget = new QTabWidget(horizontalLayoutWidget);
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
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        mbLofarPlot = new MStreampColorPlot(tab_2);
        mbLofarPlot->setObjectName(QString::fromUtf8("mbLofarPlot"));

        horizontalLayout_7->addWidget(mbLofarPlot);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_6 = new QHBoxLayout(tab);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pwdPlot = new MStreampColorPlot(tab);
        pwdPlot->setObjectName(QString::fromUtf8("pwdPlot"));

        horizontalLayout_6->addWidget(pwdPlot);

        tabWidget->addTab(tab, QString());

        hlvContainer->addWidget(tabWidget);


        horizontalLayout_2->addLayout(hlvContainer);

        pwdPlot_2 = new MStreampColorPlot(X31JzForm);
        pwdPlot_2->setObjectName(QString::fromUtf8("pwdPlot_2"));
        pwdPlot_2->setGeometry(QRect(300, 120, 331, 271));
        QWidget::setTabOrder(btnStart, btnStop);
        QWidget::setTabOrder(btnStop, tabWidget);
        QWidget::setTabOrder(tabWidget, slider);
        QWidget::setTabOrder(slider, rbActive);
        QWidget::setTabOrder(rbActive, rbPassive);

        retranslateUi(X31JzForm);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(X31JzForm);
    } // setupUi

    void retranslateUi(QWidget *X31JzForm)
    {
        X31JzForm->setWindowTitle(QCoreApplication::translate("X31JzForm", "Form", nullptr));
        lbStart->setText(QCoreApplication::translate("X31JzForm", "S:18\357\274\23201\357\274\23213", nullptr));
        lbEnd->setText(QCoreApplication::translate("X31JzForm", "E:18\357\274\23201\357\274\23213", nullptr));
        lbRunningTime->setText(QString());
        btnStart->setText(QString());
        btnStop->setText(QString());
        rbActive->setText(QCoreApplication::translate("X31JzForm", "\344\270\273\345\212\250", nullptr));
        rbPassive->setText(QCoreApplication::translate("X31JzForm", "\350\242\253\345\212\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("X31JzForm", "\350\242\253\345\212\250\347\252\204\345\270\246\345\244\232\346\263\242\346\235\237LOFAR", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("X31JzForm", "\350\242\253\345\212\250\345\256\275\345\270\246\350\255\246\346\210\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31JzForm: public Ui_X31JzForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31JZFORM_H
