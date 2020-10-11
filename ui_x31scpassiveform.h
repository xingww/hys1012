/********************************************************************************
** Form generated from reading UI file 'x31scpassiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X31SCPASSIVEFORM_H
#define UI_X31SCPASSIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mpcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X31ScPassiveForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    MpColorPlot *lofarPlot;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    MpColorPlot *demonPlot;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextBrowser *tbPaSearch;

    void setupUi(QWidget *X31ScPassiveForm)
    {
        if (X31ScPassiveForm->objectName().isEmpty())
            X31ScPassiveForm->setObjectName(QString::fromUtf8("X31ScPassiveForm"));
        X31ScPassiveForm->resize(644, 515);
        horizontalLayout = new QHBoxLayout(X31ScPassiveForm);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(X31ScPassiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        lofarPlot = new MpColorPlot(X31ScPassiveForm);
        lofarPlot->setObjectName(QString::fromUtf8("lofarPlot"));

        verticalLayout_2->addWidget(lofarPlot);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(X31ScPassiveForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        demonPlot = new MpColorPlot(X31ScPassiveForm);
        demonPlot->setObjectName(QString::fromUtf8("demonPlot"));

        verticalLayout_3->addWidget(demonPlot);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(X31ScPassiveForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 24));
        label_3->setMaximumSize(QSize(16777215, 24));
        label_3->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        tbPaSearch = new QTextBrowser(X31ScPassiveForm);
        tbPaSearch->setObjectName(QString::fromUtf8("tbPaSearch"));

        verticalLayout->addWidget(tbPaSearch);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(X31ScPassiveForm);

        QMetaObject::connectSlotsByName(X31ScPassiveForm);
    } // setupUi

    void retranslateUi(QWidget *X31ScPassiveForm)
    {
        X31ScPassiveForm->setWindowTitle(QCoreApplication::translate("X31ScPassiveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("X31ScPassiveForm", "LOFAR", nullptr));
        label_2->setText(QCoreApplication::translate("X31ScPassiveForm", "DEMON", nullptr));
        label_3->setText(QCoreApplication::translate("X31ScPassiveForm", "\350\242\253\345\212\250\346\220\234\347\264\242\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X31ScPassiveForm: public Ui_X31ScPassiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X31SCPASSIVEFORM_H
