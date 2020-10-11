/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_SettingDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *inHost;
    QLabel *label_7;
    QLineEdit *inPort;
    QLabel *label_8;
    QLineEdit *inUser;
    QLabel *label_5;
    QLineEdit *inPwd;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnTest;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnModified;
    QSpacerItem *horizontalSpacer_12;

    void setupUi(QFrame *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(545, 306);
        SettingDialog->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);\n"
"color:#EBECFB;"));
        verticalLayout = new QVBoxLayout(SettingDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new BaseTitleBar(SettingDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));

        verticalLayout->addWidget(titleBar);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(SettingDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"color:#EBECFB;"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        inHost = new QLineEdit(SettingDialog);
        inHost->setObjectName(QString::fromUtf8("inHost"));
        inHost->setMinimumSize(QSize(0, 30));
        inHost->setMaximumSize(QSize(16777215, 30));
        inHost->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(inHost, 0, 1, 1, 1);

        label_7 = new QLabel(SettingDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"color:#EBECFB;"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        inPort = new QLineEdit(SettingDialog);
        inPort->setObjectName(QString::fromUtf8("inPort"));
        inPort->setMinimumSize(QSize(0, 30));
        inPort->setMaximumSize(QSize(16777215, 30));
        inPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(inPort, 1, 1, 1, 1);

        label_8 = new QLabel(SettingDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"color:#EBECFB;"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        inUser = new QLineEdit(SettingDialog);
        inUser->setObjectName(QString::fromUtf8("inUser"));
        inUser->setMinimumSize(QSize(0, 30));
        inUser->setMaximumSize(QSize(16777215, 30));
        inUser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(inUser, 2, 1, 1, 1);

        label_5 = new QLabel(SettingDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"color:#EBECFB;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        inPwd = new QLineEdit(SettingDialog);
        inPwd->setObjectName(QString::fromUtf8("inPwd"));
        inPwd->setMinimumSize(QSize(0, 30));
        inPwd->setMaximumSize(QSize(16777215, 30));
        inPwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        inPwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(inPwd, 3, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 30, -1, 30);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        btnTest = new QPushButton(SettingDialog);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setMinimumSize(QSize(0, 30));
        btnTest->setMaximumSize(QSize(16777215, 30));
        btnTest->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_2->addWidget(btnTest);

        horizontalSpacer_10 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSave = new QPushButton(SettingDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 30));
        btnSave->setMaximumSize(QSize(16777215, 30));
        btnSave->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(SettingDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 30));
        btnCancel->setMaximumSize(QSize(16777215, 30));
        btnCancel->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnCancel);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        btnModified = new QPushButton(SettingDialog);
        btnModified->setObjectName(QString::fromUtf8("btnModified"));
        btnModified->setMinimumSize(QSize(0, 30));
        btnModified->setMaximumSize(QSize(16777215, 30));
        btnModified->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_2->addWidget(btnModified);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SettingDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), SettingDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QFrame *SettingDialog)
    {
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("SettingDialog", "\344\270\273\346\234\272\345\234\260\345\235\200:", nullptr));
        inHost->setPlaceholderText(QCoreApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\345\272\223IP\345\234\260\345\235\200,\345\246\202192.168.1.100", nullptr));
        label_7->setText(QCoreApplication::translate("SettingDialog", "\347\253\257\345\217\243:", nullptr));
        inPort->setText(QCoreApplication::translate("SettingDialog", "3306", nullptr));
        label_8->setText(QCoreApplication::translate("SettingDialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        inUser->setPlaceholderText(QCoreApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("SettingDialog", "\345\257\206\347\240\201:", nullptr));
        inPwd->setText(QString());
        inPwd->setPlaceholderText(QCoreApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201", nullptr));
        btnTest->setText(QCoreApplication::translate("SettingDialog", "\346\265\213\350\257\225\350\277\236\346\216\245", nullptr));
        btnSave->setText(QCoreApplication::translate("SettingDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("SettingDialog", "\345\217\226\346\266\210", nullptr));
        btnModified->setText(QCoreApplication::translate("SettingDialog", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
