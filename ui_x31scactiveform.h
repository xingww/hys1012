/********************************************************************************
** Form generated from reading UI file 'x31scactiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31SCACTIVEFORM_H
#define UI_X31SCACTIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mframepcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X31ScActiveForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    MFramepColorPlot *activePlot;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *tbAcSearch;

    void setupUi(QWidget *X31ScActiveForm)
    {
        if (X31ScActiveForm->objectName().isEmpty())
            X31ScActiveForm->setObjectName(QString::fromUtf8("X31ScActiveForm"));
        X31ScActiveForm->resize(594, 439);
        horizontalLayout = new QHBoxLayout(X31ScActiveForm);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(X31ScActiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        activePlot = new MFramepColorPlot(X31ScActiveForm);
        activePlot->setObjectName(QString::fromUtf8("activePlot"));

        verticalLayout->addWidget(activePlot);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(X31ScActiveForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tbAcSearch = new QTextBrowser(X31ScActiveForm);
        tbAcSearch->setObjectName(QString::fromUtf8("tbAcSearch"));

        verticalLayout_2->addWidget(tbAcSearch);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(X31ScActiveForm);

        QMetaObject::connectSlotsByName(X31ScActiveForm);
    } // setupUi

    void retranslateUi(QWidget *X31ScActiveForm)
    {
        X31ScActiveForm->setWindowTitle(QCoreApplication::translate("X31ScActiveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("X31ScActiveForm", "\344\270\273\345\212\250\345\256\275\345\270\246\350\255\246\346\210\222", nullptr));
        label_2->setText(QCoreApplication::translate("X31ScActiveForm", "\344\270\273\345\212\250\346\220\234\347\264\242\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31ScActiveForm: public Ui_X31ScActiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31SCACTIVEFORM_H
