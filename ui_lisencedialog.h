/********************************************************************************
** Form generated from reading UI file 'lisencedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISENCEDIALOG_H
#define UI_LISENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget/basetitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_LisenceDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QLineEdit *inLisenceNo;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LisenceDialog)
    {
        if (LisenceDialog->objectName().isEmpty())
            LisenceDialog->setObjectName(QString::fromUtf8("LisenceDialog"));
        LisenceDialog->resize(500, 332);
        LisenceDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(LisenceDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        titleBar = new BaseTitleBar(LisenceDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));

        verticalLayout->addWidget(titleBar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(LisenceDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_2->setMargin(0);
        label_2->setIndent(20);

        verticalLayout->addWidget(label_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setContentsMargins(20, 0, 20, -1);
        inLisenceNo = new QLineEdit(LisenceDialog);
        inLisenceNo->setObjectName(QString::fromUtf8("inLisenceNo"));
        inLisenceNo->setMinimumSize(QSize(0, 30));
        inLisenceNo->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        inLisenceNo->setFont(font);

        gridLayout->addWidget(inLisenceNo, 1, 1, 1, 1);

        label = new QLabel(LisenceDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 50, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(LisenceDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 30));
        btnSave->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(LisenceDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 30));
        btnCancel->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(LisenceDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), LisenceDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LisenceDialog);
    } // setupUi

    void retranslateUi(QWidget *LisenceDialog)
    {
        LisenceDialog->setWindowTitle(QCoreApplication::translate("LisenceDialog", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LisenceDialog", "\350\257\267\350\276\223\345\205\245\346\216\210\346\235\203\345\272\217\345\210\227\345\217\267\357\274\214\345\220\246\345\210\231\346\227\240\346\263\225\344\275\277\347\224\250!", nullptr));
        inLisenceNo->setPlaceholderText(QCoreApplication::translate("LisenceDialog", "xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxx", nullptr));
        label->setText(QCoreApplication::translate("LisenceDialog", "\345\272\217\345\210\227\345\217\267:", nullptr));
        btnSave->setText(QCoreApplication::translate("LisenceDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("LisenceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LisenceDialog: public Ui_LisenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISENCEDIALOG_H
