/********************************************************************************
** Form generated from reading UI file 'x39scactiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X39SCACTIVEFORM_H
#define UI_X39SCACTIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mframepcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X39ScActiveForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    MFramepColorPlot *cpPlot;

    void setupUi(QWidget *X39ScActiveForm)
    {
        if (X39ScActiveForm->objectName().isEmpty())
            X39ScActiveForm->setObjectName(QString::fromUtf8("X39ScActiveForm"));
        X39ScActiveForm->resize(536, 352);
        verticalLayout = new QVBoxLayout(X39ScActiveForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(X39ScActiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        cpPlot = new MFramepColorPlot(X39ScActiveForm);
        cpPlot->setObjectName(QString::fromUtf8("cpPlot"));

        verticalLayout->addWidget(cpPlot);


        retranslateUi(X39ScActiveForm);

        QMetaObject::connectSlotsByName(X39ScActiveForm);
    } // setupUi

    void retranslateUi(QWidget *X39ScActiveForm)
    {
        X39ScActiveForm->setWindowTitle(QCoreApplication::translate("X39ScActiveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("X39ScActiveForm", "\344\270\273\345\212\250\345\256\275\345\270\246\350\255\246\346\210\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X39ScActiveForm: public Ui_X39ScActiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X39SCACTIVEFORM_H
