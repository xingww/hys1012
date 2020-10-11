/********************************************************************************
** Form generated from reading UI file 'basetitlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASETITLEBAR_H
#define UI_BASETITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbIcon;
    QLabel *lbTitle;
    QPushButton *btnClose;

    void setupUi(QWidget *BaseTitleBar)
    {
        if (BaseTitleBar->objectName().isEmpty())
            BaseTitleBar->setObjectName(QString::fromUtf8("BaseTitleBar"));
        BaseTitleBar->resize(831, 40);
        BaseTitleBar->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(BaseTitleBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbIcon = new QLabel(BaseTitleBar);
        lbIcon->setObjectName(QString::fromUtf8("lbIcon"));
        lbIcon->setMinimumSize(QSize(20, 20));
        lbIcon->setMaximumSize(QSize(20, 20));
        lbIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/app.png);"));

        horizontalLayout_2->addWidget(lbIcon);

        lbTitle = new QLabel(BaseTitleBar);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
""));

        horizontalLayout_2->addWidget(lbTitle);


        horizontalLayout->addLayout(horizontalLayout_2);

        btnClose = new QPushButton(BaseTitleBar);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(15, 15));
        btnClose->setMaximumSize(QSize(15, 15));
        btnClose->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/destop/close.png);"));

        horizontalLayout->addWidget(btnClose);


        retranslateUi(BaseTitleBar);

        QMetaObject::connectSlotsByName(BaseTitleBar);
    } // setupUi

    void retranslateUi(QWidget *BaseTitleBar)
    {
        BaseTitleBar->setWindowTitle(QCoreApplication::translate("BaseTitleBar", "Form", nullptr));
        lbIcon->setText(QString());
        lbTitle->setText(QCoreApplication::translate("BaseTitleBar", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\255\350\210\271\351\207\215\345\267\245</span></p></body></html>", nullptr));
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BaseTitleBar: public Ui_BaseTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASETITLEBAR_H
