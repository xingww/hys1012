/********************************************************************************
** Form generated from reading UI file 'x31jzactiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31JZACTIVEFORM_H
#define UI_X31JZACTIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mstreamframepcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X31JzActiveForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    MStreamFramepColorPlot *cpPlot;

    void setupUi(QWidget *X31JzActiveForm)
    {
        if (X31JzActiveForm->objectName().isEmpty())
            X31JzActiveForm->setObjectName(QString::fromUtf8("X31JzActiveForm"));
        X31JzActiveForm->resize(546, 351);
        verticalLayout = new QVBoxLayout(X31JzActiveForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(X31JzActiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        cpPlot = new MStreamFramepColorPlot(X31JzActiveForm);
        cpPlot->setObjectName(QString::fromUtf8("cpPlot"));

        verticalLayout->addWidget(cpPlot);


        retranslateUi(X31JzActiveForm);

        QMetaObject::connectSlotsByName(X31JzActiveForm);
    } // setupUi

    void retranslateUi(QWidget *X31JzActiveForm)
    {
        X31JzActiveForm->setWindowTitle(QCoreApplication::translate("X31JzActiveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("X31JzActiveForm", "\344\270\273\345\212\250\345\256\275\345\270\246\350\255\246\346\210\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31JzActiveForm: public Ui_X31JzActiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31JZACTIVEFORM_H
