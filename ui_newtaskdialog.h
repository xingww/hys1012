/********************************************************************************
** Form generated from reading UI file 'newtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKDIALOG_H
#define UI_NEWTASKDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_NewTaskDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *inAbbr;
    QLabel *label_8;
    QLineEdit *inArea;
    QLabel *label_12;
    QDateEdit *inDate;
    QLabel *label_9;
    QLineEdit *inShipName;
    QLabel *label_14;
    QLineEdit *inShipType;
    QLabel *label_15;
    QComboBox *cbSonarType;
    QLabel *label_10;
    QLineEdit *inActor;
    QLabel *label_11;
    QLineEdit *inAuthor;
    QLabel *label_13;
    QPlainTextEdit *inComment;
    QLineEdit *inTitle;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *NewTaskDialog)
    {
        if (NewTaskDialog->objectName().isEmpty())
            NewTaskDialog->setObjectName(QString::fromUtf8("NewTaskDialog"));
        NewTaskDialog->resize(657, 486);
        NewTaskDialog->setStyleSheet(QString::fromUtf8("color:#EBECFB;\n"
"border-image: url(:/destop/background.png);"));
        verticalLayout = new QVBoxLayout(NewTaskDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new BaseTitleBar(NewTaskDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));
        titleBar->setBaseSize(QSize(0, 30));

        verticalLayout->addWidget(titleBar);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 10, 20, 10);
        label_6 = new QLabel(NewTaskDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QPalette palette;
        QBrush brush(QColor(235, 236, 251, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(235, 236, 251, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(235, 236, 251, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(235, 236, 251, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_6->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(NewTaskDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(235, 236, 251, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush6(QColor(235, 236, 251, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush7(QColor(235, 236, 251, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        label_7->setPalette(palette1);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        inAbbr = new QLineEdit(NewTaskDialog);
        inAbbr->setObjectName(QString::fromUtf8("inAbbr"));
        inAbbr->setMinimumSize(QSize(0, 36));
        QFont font1;
        font1.setPointSize(9);
        inAbbr->setFont(font1);
        inAbbr->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inAbbr, 1, 1, 1, 1);

        label_8 = new QLabel(NewTaskDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush8(QColor(235, 236, 251, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush9(QColor(235, 236, 251, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush10(QColor(235, 236, 251, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        label_8->setPalette(palette2);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        inArea = new QLineEdit(NewTaskDialog);
        inArea->setObjectName(QString::fromUtf8("inArea"));
        inArea->setMinimumSize(QSize(0, 36));
        inArea->setFont(font1);
        inArea->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inArea, 1, 3, 1, 1);

        label_12 = new QLabel(NewTaskDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush11(QColor(235, 236, 251, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush12(QColor(235, 236, 251, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush13(QColor(235, 236, 251, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        label_12->setPalette(palette3);
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        inDate = new QDateEdit(NewTaskDialog);
        inDate->setObjectName(QString::fromUtf8("inDate"));
        inDate->setMinimumSize(QSize(0, 36));
        inDate->setStyleSheet(QString::fromUtf8(""));
        inDate->setCalendarPopup(true);
        inDate->setDate(QDate(2020, 1, 1));

        gridLayout->addWidget(inDate, 2, 1, 1, 1);

        label_9 = new QLabel(NewTaskDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush14(QColor(235, 236, 251, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush15(QColor(235, 236, 251, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush15);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush16(QColor(235, 236, 251, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        label_9->setPalette(palette4);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        inShipName = new QLineEdit(NewTaskDialog);
        inShipName->setObjectName(QString::fromUtf8("inShipName"));
        inShipName->setMinimumSize(QSize(0, 36));
        inShipName->setFont(font1);
        inShipName->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inShipName, 2, 3, 1, 1);

        label_14 = new QLabel(NewTaskDialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush17(QColor(235, 236, 251, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush17);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush18(QColor(235, 236, 251, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush18);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush19(QColor(235, 236, 251, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        label_14->setPalette(palette5);
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 3, 0, 1, 1);

        inShipType = new QLineEdit(NewTaskDialog);
        inShipType->setObjectName(QString::fromUtf8("inShipType"));
        inShipType->setMinimumSize(QSize(0, 36));
        inShipType->setFont(font1);
        inShipType->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inShipType, 3, 1, 1, 1);

        label_15 = new QLabel(NewTaskDialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush20(QColor(235, 236, 251, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush20);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush21(QColor(235, 236, 251, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush22(QColor(235, 236, 251, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush22);
#endif
        label_15->setPalette(palette6);
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 3, 2, 1, 1);

        cbSonarType = new QComboBox(NewTaskDialog);
        cbSonarType->setObjectName(QString::fromUtf8("cbSonarType"));
        cbSonarType->setMinimumSize(QSize(0, 30));
        cbSonarType->setMaximumSize(QSize(16777215, 30));
        cbSonarType->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbSonarType, 3, 3, 1, 1);

        label_10 = new QLabel(NewTaskDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush23(QColor(235, 236, 251, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush23);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush24(QColor(235, 236, 251, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush24);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush25(QColor(235, 236, 251, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush25);
#endif
        label_10->setPalette(palette7);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        inActor = new QLineEdit(NewTaskDialog);
        inActor->setObjectName(QString::fromUtf8("inActor"));
        inActor->setMinimumSize(QSize(0, 36));
        inActor->setFont(font1);
        inActor->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inActor, 4, 1, 1, 1);

        label_11 = new QLabel(NewTaskDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush26(QColor(235, 236, 251, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush26);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush27(QColor(235, 236, 251, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush27);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush28(QColor(235, 236, 251, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush28);
#endif
        label_11->setPalette(palette8);
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        inAuthor = new QLineEdit(NewTaskDialog);
        inAuthor->setObjectName(QString::fromUtf8("inAuthor"));
        inAuthor->setMinimumSize(QSize(0, 36));
        inAuthor->setFont(font1);
        inAuthor->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inAuthor, 4, 3, 1, 1);

        label_13 = new QLabel(NewTaskDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush29(QColor(235, 236, 251, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush29);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush30(QColor(235, 236, 251, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush30);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush31(QColor(235, 236, 251, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush31);
#endif
        label_13->setPalette(palette9);
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("border-image:none;"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 5, 0, 1, 1);

        inComment = new QPlainTextEdit(NewTaskDialog);
        inComment->setObjectName(QString::fromUtf8("inComment"));
        inComment->setMinimumSize(QSize(0, 0));
        inComment->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inComment, 5, 1, 1, 3);

        inTitle = new QLineEdit(NewTaskDialog);
        inTitle->setObjectName(QString::fromUtf8("inTitle"));
        inTitle->setMinimumSize(QSize(0, 36));
        inTitle->setFont(font1);
        inTitle->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(inTitle, 0, 1, 1, 3);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnSave = new QPushButton(NewTaskDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 30));
        btnSave->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_3->addWidget(btnSave);

        btnCancel = new QPushButton(NewTaskDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 30));
        btnCancel->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 1);

        retranslateUi(NewTaskDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewTaskDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(NewTaskDialog);
    } // setupUi

    void retranslateUi(QFrame *NewTaskDialog)
    {
        NewTaskDialog->setWindowTitle(QCoreApplication::translate("NewTaskDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("NewTaskDialog", "\346\225\260\346\215\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("NewTaskDialog", "\344\273\273\345\212\241\347\256\200\347\247\260\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("NewTaskDialog", "\344\273\273\345\212\241\346\265\267\345\214\272\357\274\232", nullptr));
        inArea->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\345\277\205\345\241\253", nullptr));
        label_12->setText(QCoreApplication::translate("NewTaskDialog", "\344\273\273\345\212\241\346\227\266\351\227\264\357\274\232", nullptr));
        inDate->setDisplayFormat(QCoreApplication::translate("NewTaskDialog", "yyyy-MM-dd", nullptr));
        label_9->setText(QCoreApplication::translate("NewTaskDialog", "\346\234\254\350\210\260\345\220\215\347\247\260\357\274\232", nullptr));
        inShipName->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\345\277\205\345\241\253", nullptr));
        label_14->setText(QCoreApplication::translate("NewTaskDialog", "\346\234\254\350\210\260\347\261\273\345\236\213\357\274\232", nullptr));
        inShipType->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\350\210\260\350\211\207\347\261\273\345\236\213\357\274\214\345\246\202052/053\347\255\211", nullptr));
        label_15->setText(QCoreApplication::translate("NewTaskDialog", "\345\243\260\345\221\220\347\261\273\345\236\213\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("NewTaskDialog", "\345\200\274\346\233\264\351\225\277\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("NewTaskDialog", "\346\225\264\347\274\226\344\272\272\357\274\232", nullptr));
        inAuthor->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\345\277\205\345\241\253", nullptr));
        label_13->setText(QCoreApplication::translate("NewTaskDialog", "\345\244\207\346\263\250\344\277\241\346\201\257\357\274\232", nullptr));
        inComment->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\350\257\267\350\276\223\345\205\245\345\205\266\344\273\226\347\233\270\345\205\263\344\277\241\346\201\257", nullptr));
        inTitle->setPlaceholderText(QCoreApplication::translate("NewTaskDialog", "\345\277\205\345\241\253", nullptr));
        btnSave->setText(QCoreApplication::translate("NewTaskDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("NewTaskDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTaskDialog: public Ui_NewTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKDIALOG_H
