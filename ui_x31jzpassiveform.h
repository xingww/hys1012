/********************************************************************************
** Form generated from reading UI file 'x31jzpassiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31JZPASSIVEFORM_H
#define UI_X31JZPASSIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mstreampcolorplot.h>

QT_BEGIN_NAMESPACE

class Ui_X31JzPassiveForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    MStreampColorPlot *lofarPlot;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    MStreampColorPlot *demonPlot;

    void setupUi(QWidget *X31JzPassiveForm)
    {
        if (X31JzPassiveForm->objectName().isEmpty())
            X31JzPassiveForm->setObjectName(QString::fromUtf8("X31JzPassiveForm"));
        X31JzPassiveForm->resize(451, 381);
        X31JzPassiveForm->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout_3 = new QVBoxLayout(X31JzPassiveForm);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(X31JzPassiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lofarPlot = new MStreampColorPlot(X31JzPassiveForm);
        lofarPlot->setObjectName(QString::fromUtf8("lofarPlot"));
        lofarPlot->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(lofarPlot);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(X31JzPassiveForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        demonPlot = new MStreampColorPlot(X31JzPassiveForm);
        demonPlot->setObjectName(QString::fromUtf8("demonPlot"));

        verticalLayout_2->addWidget(demonPlot);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(X31JzPassiveForm);

        QMetaObject::connectSlotsByName(X31JzPassiveForm);
    } // setupUi

    void retranslateUi(QWidget *X31JzPassiveForm)
    {
        X31JzPassiveForm->setWindowTitle(QCoreApplication::translate("X31JzPassiveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("X31JzPassiveForm", "LOFAR", nullptr));
        label_2->setText(QCoreApplication::translate("X31JzPassiveForm", "DEMON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31JzPassiveForm: public Ui_X31JzPassiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31JZPASSIVEFORM_H
