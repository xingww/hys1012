/********************************************************************************
** Form generated from reading UI file 'x39scpassiveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X39SCPASSIVEFORM_H
#define UI_X39SCPASSIVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mpcolorplot.h"

QT_BEGIN_NAMESPACE

class Ui_X39ScPassiveForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    MpColorPlot *lofarPlot;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    MpColorPlot *demonPlot;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *echoTxt;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *noTxt;

    void setupUi(QWidget *X39ScPassiveForm)
    {
        if (X39ScPassiveForm->objectName().isEmpty())
            X39ScPassiveForm->setObjectName(QString::fromUtf8("X39ScPassiveForm"));
        X39ScPassiveForm->resize(524, 329);
        X39ScPassiveForm->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout = new QHBoxLayout(X39ScPassiveForm);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(X39ScPassiveForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 24));
        label_3->setMaximumSize(QSize(16777215, 24));
        label_3->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_3->setLineWidth(0);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        lofarPlot = new MpColorPlot(X39ScPassiveForm);
        lofarPlot->setObjectName(QString::fromUtf8("lofarPlot"));

        verticalLayout_4->addWidget(lofarPlot);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(X39ScPassiveForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 24));
        label_4->setMaximumSize(QSize(16777215, 24));
        label_4->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        demonPlot = new MpColorPlot(X39ScPassiveForm);
        demonPlot->setObjectName(QString::fromUtf8("demonPlot"));

        verticalLayout_5->addWidget(demonPlot);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(X39ScPassiveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        echoTxt = new QTextBrowser(X39ScPassiveForm);
        echoTxt->setObjectName(QString::fromUtf8("echoTxt"));
        echoTxt->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(echoTxt);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(X39ScPassiveForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        noTxt = new QTextBrowser(X39ScPassiveForm);
        noTxt->setObjectName(QString::fromUtf8("noTxt"));
        noTxt->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(noTxt);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(X39ScPassiveForm);

        QMetaObject::connectSlotsByName(X39ScPassiveForm);
    } // setupUi

    void retranslateUi(QWidget *X39ScPassiveForm)
    {
        X39ScPassiveForm->setWindowTitle(QCoreApplication::translate("X39ScPassiveForm", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("X39ScPassiveForm", "LOFAR", nullptr));
        label_4->setText(QCoreApplication::translate("X39ScPassiveForm", "DEMON", nullptr));
        label->setText(QCoreApplication::translate("X39ScPassiveForm", "\345\233\236\345\243\260\347\233\256\346\240\207\350\267\237\350\270\252\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("X39ScPassiveForm", "\345\231\252\345\243\260\347\233\256\346\240\207\350\267\237\350\270\252\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X39ScPassiveForm: public Ui_X39ScPassiveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X39SCPASSIVEFORM_H
