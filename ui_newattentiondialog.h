/********************************************************************************
** Form generated from reading UI file 'newattentiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWATTENTIONDIALOG_H
#define UI_NEWATTENTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "widget/basetitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_NewAttentionDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *inLati;
    QPlainTextEdit *inComment;
    QDateTimeEdit *inCrawlTime;
    QLabel *label_5;
    QLineEdit *inLong;
    QComboBox *inEvent;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QFrame *NewAttentionDialog)
    {
        if (NewAttentionDialog->objectName().isEmpty())
            NewAttentionDialog->setObjectName(QString::fromUtf8("NewAttentionDialog"));
        NewAttentionDialog->resize(609, 400);
        NewAttentionDialog->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);\n"
"color:#EBECFB;"));
        verticalLayout = new QVBoxLayout(NewAttentionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        titleBar = new BaseTitleBar(NewAttentionDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));

        verticalLayout->addWidget(titleBar);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(50, 20, 50, 20);
        label_2 = new QLabel(NewAttentionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        inLati = new QLineEdit(NewAttentionDialog);
        inLati->setObjectName(QString::fromUtf8("inLati"));
        inLati->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(inLati, 3, 1, 1, 1);

        inComment = new QPlainTextEdit(NewAttentionDialog);
        inComment->setObjectName(QString::fromUtf8("inComment"));
        inComment->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(inComment, 4, 1, 1, 1);

        inCrawlTime = new QDateTimeEdit(NewAttentionDialog);
        inCrawlTime->setObjectName(QString::fromUtf8("inCrawlTime"));
        inCrawlTime->setMinimumSize(QSize(0, 30));
        inCrawlTime->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));
        inCrawlTime->setCalendarPopup(true);

        gridLayout->addWidget(inCrawlTime, 1, 1, 1, 1);

        label_5 = new QLabel(NewAttentionDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        inLong = new QLineEdit(NewAttentionDialog);
        inLong->setObjectName(QString::fromUtf8("inLong"));
        inLong->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(inLong, 2, 1, 1, 1);

        inEvent = new QComboBox(NewAttentionDialog);
        inEvent->setObjectName(QString::fromUtf8("inEvent"));
        inEvent->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(inEvent, 0, 1, 1, 1);

        label_4 = new QLabel(NewAttentionDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(NewAttentionDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(NewAttentionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(NewAttentionDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 30));
        btnSave->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(NewAttentionDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 30));
        btnCancel->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(NewAttentionDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewAttentionDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(NewAttentionDialog);
    } // setupUi

    void retranslateUi(QFrame *NewAttentionDialog)
    {
        NewAttentionDialog->setWindowTitle(QCoreApplication::translate("NewAttentionDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("NewAttentionDialog", "\345\217\221\347\224\237\346\227\266\351\227\264\357\274\232", nullptr));
        inCrawlTime->setDisplayFormat(QCoreApplication::translate("NewAttentionDialog", "yyyy-MM-dd hh:mm:ss", nullptr));
        label_5->setText(QCoreApplication::translate("NewAttentionDialog", "\345\244\207\346\263\250\344\277\241\346\201\257\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("NewAttentionDialog", "\347\273\217\345\272\246\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("NewAttentionDialog", "\347\273\264\345\272\246\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("NewAttentionDialog", "\344\272\213\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("NewAttentionDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("NewAttentionDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewAttentionDialog: public Ui_NewAttentionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWATTENTIONDIALOG_H
