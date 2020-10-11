/********************************************************************************
** Form generated from reading UI file 'newtargetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTARGETDIALOG_H
#define UI_NEWTARGETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "widget/basetitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_NewTargetDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *lbTaskTitle;
    QLabel *label_2;
    QLineEdit *inTargetName;
    QLabel *label_3;
    QLineEdit *inShipType;
    QLabel *label_4;
    QComboBox *cbSonarType;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *NewTargetDialog)
    {
        if (NewTargetDialog->objectName().isEmpty())
            NewTargetDialog->setObjectName(QString::fromUtf8("NewTargetDialog"));
        NewTargetDialog->resize(637, 399);
        NewTargetDialog->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);\n"
"color:#EBECFB;"));
        verticalLayout = new QVBoxLayout(NewTargetDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new BaseTitleBar(NewTargetDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));

        verticalLayout->addWidget(titleBar);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(16);
        gridLayout->setContentsMargins(50, 50, 50, 50);
        label = new QLabel(NewTargetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lbTaskTitle = new QLabel(NewTargetDialog);
        lbTaskTitle->setObjectName(QString::fromUtf8("lbTaskTitle"));
        lbTaskTitle->setMinimumSize(QSize(0, 30));
        lbTaskTitle->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(lbTaskTitle, 0, 1, 1, 1);

        label_2 = new QLabel(NewTargetDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        inTargetName = new QLineEdit(NewTargetDialog);
        inTargetName->setObjectName(QString::fromUtf8("inTargetName"));
        inTargetName->setMinimumSize(QSize(0, 30));
        inTargetName->setMaximumSize(QSize(16777215, 30));
        inTargetName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(inTargetName, 1, 1, 1, 1);

        label_3 = new QLabel(NewTargetDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        inShipType = new QLineEdit(NewTargetDialog);
        inShipType->setObjectName(QString::fromUtf8("inShipType"));
        inShipType->setMinimumSize(QSize(0, 30));
        inShipType->setMaximumSize(QSize(16777215, 30));
        inShipType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(inShipType, 2, 1, 1, 1);

        label_4 = new QLabel(NewTargetDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cbSonarType = new QComboBox(NewTargetDialog);
        cbSonarType->setObjectName(QString::fromUtf8("cbSonarType"));
        cbSonarType->setMinimumSize(QSize(0, 30));
        cbSonarType->setMaximumSize(QSize(16777215, 30));
        cbSonarType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cbSonarType, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(NewTargetDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 30));
        btnSave->setMaximumSize(QSize(16777215, 30));
        btnSave->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(NewTargetDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 30));
        btnCancel->setMaximumSize(QSize(16777215, 30));
        btnCancel->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 1);

        retranslateUi(NewTargetDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewTargetDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(NewTargetDialog);
    } // setupUi

    void retranslateUi(QFrame *NewTargetDialog)
    {
        NewTargetDialog->setWindowTitle(QCoreApplication::translate("NewTargetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewTargetDialog", "\344\273\273\345\212\241\345\220\215\347\247\260:", nullptr));
        lbTaskTitle->setText(QCoreApplication::translate("NewTargetDialog", "\344\270\255\345\215\216\344\272\272\346\260\221\345\205\261\345\222\214\345\233\275", nullptr));
        label_2->setText(QCoreApplication::translate("NewTargetDialog", "\347\233\256\346\240\207\345\220\215\347\247\260:", nullptr));
        inTargetName->setPlaceholderText(QCoreApplication::translate("NewTargetDialog", "\345\277\205\345\241\253", nullptr));
        label_3->setText(QCoreApplication::translate("NewTargetDialog", "\350\210\260\350\210\271\347\261\273\345\236\213:", nullptr));
        inShipType->setPlaceholderText(QCoreApplication::translate("NewTargetDialog", "\345\246\202052/053\347\255\211", nullptr));
        label_4->setText(QCoreApplication::translate("NewTargetDialog", "\345\243\260\345\221\220\347\261\273\345\236\213:", nullptr));
        btnSave->setText(QCoreApplication::translate("NewTargetDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("NewTargetDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTargetDialog: public Ui_NewTargetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTARGETDIALOG_H
