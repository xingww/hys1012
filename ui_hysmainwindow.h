/********************************************************************************
** Form generated from reading UI file 'hysmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYSMAINWINDOW_H
#define UI_HYSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget/hystitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_HysMainWindow
{
public:
    QVBoxLayout *verticalLayout;
    HysTitleBar *titleBar;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *HysMainWindow)
    {
        if (HysMainWindow->objectName().isEmpty())
            HysMainWindow->setObjectName(QString::fromUtf8("HysMainWindow"));
        HysMainWindow->resize(900, 516);
        HysMainWindow->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);\n"
"color:#EBECFB;"));
        verticalLayout = new QVBoxLayout(HysMainWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        titleBar = new HysTitleBar(HysMainWindow);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setEnabled(true);
        titleBar->setMinimumSize(QSize(0, 56));
        titleBar->setMaximumSize(QSize(16777215, 56));
        titleBar->setAutoFillBackground(false);
        titleBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(titleBar);

        stackedWidget = new QStackedWidget(HysMainWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(HysMainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(HysMainWindow);
    } // setupUi

    void retranslateUi(QWidget *HysMainWindow)
    {
        HysMainWindow->setWindowTitle(QCoreApplication::translate("HysMainWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HysMainWindow: public Ui_HysMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYSMAINWINDOW_H
