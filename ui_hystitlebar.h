/********************************************************************************
** Form generated from reading UI file 'hystitlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYSTITLEBAR_H
#define UI_HYSTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HysTitleBar
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbIcon;
    QLabel *lbTitle;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnHome;
    QPushButton *btnMap;
    QPushButton *btnAnaly;
    QPushButton *btnExport;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSetting;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;

    void setupUi(QWidget *HysTitleBar)
    {
        if (HysTitleBar->objectName().isEmpty())
            HysTitleBar->setObjectName(QString::fromUtf8("HysTitleBar"));
        HysTitleBar->resize(839, 56);
        HysTitleBar->setMinimumSize(QSize(0, 35));
        HysTitleBar->setMaximumSize(QSize(16777215, 56));
        HysTitleBar->setAutoFillBackground(false);
        HysTitleBar->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(HysTitleBar);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(12, 0, 15, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbIcon = new QLabel(HysTitleBar);
        lbIcon->setObjectName(QString::fromUtf8("lbIcon"));
        lbIcon->setMinimumSize(QSize(30, 30));
        lbIcon->setMaximumSize(QSize(30, 30));
        lbIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/app.png);"));

        horizontalLayout_3->addWidget(lbIcon);

        lbTitle = new QLabel(HysTitleBar);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setMinimumSize(QSize(30, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"border-image:none;\n"
""));

        horizontalLayout_3->addWidget(lbTitle);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnHome = new QPushButton(HysTitleBar);
        btnHome->setObjectName(QString::fromUtf8("btnHome"));
        btnHome->setMinimumSize(QSize(60, 36));
        btnHome->setMaximumSize(QSize(16777215, 36));
        btnHome->setStyleSheet(QString::fromUtf8("*{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"*:hover {\n"
"color:#4169E1;\n"
"}\n"
"\n"
"*:checked {\n"
"color:#398af1;\n"
"}"));
        btnHome->setCheckable(true);
        btnHome->setChecked(true);
        btnHome->setFlat(true);

        horizontalLayout_2->addWidget(btnHome);

        btnMap = new QPushButton(HysTitleBar);
        btnMap->setObjectName(QString::fromUtf8("btnMap"));
        btnMap->setMinimumSize(QSize(60, 36));
        btnMap->setMaximumSize(QSize(16777215, 36));
        btnMap->setStyleSheet(QString::fromUtf8("*{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"*:hover {\n"
"color:#4169E1;\n"
"}\n"
"\n"
"*:checked {\n"
"color:#398af1;\n"
"}"));
        btnMap->setCheckable(true);
        btnMap->setFlat(true);

        horizontalLayout_2->addWidget(btnMap);

        btnAnaly = new QPushButton(HysTitleBar);
        btnAnaly->setObjectName(QString::fromUtf8("btnAnaly"));
        btnAnaly->setEnabled(true);
        btnAnaly->setMinimumSize(QSize(60, 36));
        btnAnaly->setMaximumSize(QSize(16777215, 36));
        btnAnaly->setStyleSheet(QString::fromUtf8("*{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"*:hover {\n"
"color: #4169E1;\n"
"}\n"
"\n"
"*:checked {\n"
"color:#398af1;\n"
"}"));
        btnAnaly->setCheckable(true);
        btnAnaly->setFlat(true);

        horizontalLayout_2->addWidget(btnAnaly);

        btnExport = new QPushButton(HysTitleBar);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(36);
        sizePolicy.setHeightForWidth(btnExport->sizePolicy().hasHeightForWidth());
        btnExport->setSizePolicy(sizePolicy);
        btnExport->setMinimumSize(QSize(60, 36));
        btnExport->setStyleSheet(QString::fromUtf8("*{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"*:hover {\n"
"color: #4169E1;\n"
"}\n"
"\n"
"*:checked {\n"
"color:#398af1;\n"
"}"));
        btnExport->setCheckable(true);
        btnExport->setFlat(true);

        horizontalLayout_2->addWidget(btnExport);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSetting = new QPushButton(HysTitleBar);
        btnSetting->setObjectName(QString::fromUtf8("btnSetting"));
        btnSetting->setMinimumSize(QSize(15, 15));
        btnSetting->setMaximumSize(QSize(15, 15));
        btnSetting->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/setting.png);\n"
"border:none;"));

        horizontalLayout->addWidget(btnSetting);

        btnMin = new QPushButton(HysTitleBar);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setMinimumSize(QSize(10, 10));
        btnMin->setMaximumSize(QSize(10, 10));
        btnMin->setBaseSize(QSize(10, 10));
        btnMin->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/destop/minux.png);"));
        btnMin->setFlat(true);

        horizontalLayout->addWidget(btnMin);

        btnMax = new QPushButton(HysTitleBar);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        btnMax->setMinimumSize(QSize(15, 15));
        btnMax->setMaximumSize(QSize(15, 15));
        btnMax->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/destop/max.png);"));
        btnMax->setFlat(true);

        horizontalLayout->addWidget(btnMax);

        btnClose = new QPushButton(HysTitleBar);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(15, 15));
        btnClose->setMaximumSize(QSize(15, 15));
        btnClose->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/destop/close.png);"));
        btnClose->setFlat(true);

        horizontalLayout->addWidget(btnClose);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4->setStretch(0, 6);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 3);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 2);

        retranslateUi(HysTitleBar);

        QMetaObject::connectSlotsByName(HysTitleBar);
    } // setupUi

    void retranslateUi(QWidget *HysTitleBar)
    {
        HysTitleBar->setWindowTitle(QCoreApplication::translate("HysTitleBar", "Form", nullptr));
        lbIcon->setText(QString());
        lbTitle->setText(QCoreApplication::translate("HysTitleBar", "\344\270\255\350\210\271\351\207\215\345\267\245\344\270\203\344\270\200\344\272\224\347\240\224\347\251\266\346\211\200", nullptr));
        btnHome->setText(QCoreApplication::translate("HysTitleBar", "\346\225\260\346\215\256\351\207\207\351\233\206", nullptr));
        btnMap->setText(QCoreApplication::translate("HysTitleBar", "\346\200\201\345\212\277\347\224\237\346\210\220", nullptr));
        btnAnaly->setText(QCoreApplication::translate("HysTitleBar", "\345\244\215\347\233\230\345\210\206\346\236\220", nullptr));
        btnExport->setText(QCoreApplication::translate("HysTitleBar", "\346\225\264\347\274\226\345\257\274\345\207\272", nullptr));
        btnSetting->setText(QString());
        btnMin->setText(QString());
        btnMax->setText(QString());
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HysTitleBar: public Ui_HysTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYSTITLEBAR_H
