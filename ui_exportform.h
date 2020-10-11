/********************************************************************************
** Form generated from reading UI file 'exportform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTFORM_H
#define UI_EXPORTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbTitle;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *navdetSel;
    QHBoxLayout *lhContainer;

    void setupUi(QWidget *ExportForm)
    {
        if (ExportForm->objectName().isEmpty())
            ExportForm->setObjectName(QString::fromUtf8("ExportForm"));
        ExportForm->resize(955, 542);
        verticalLayout = new QVBoxLayout(ExportForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbTitle = new QLabel(ExportForm);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbTitle->sizePolicy().hasHeightForWidth());
        lbTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbTitle->setScaledContents(false);

        horizontalLayout_2->addWidget(lbTitle);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(10, 5, 50, 5);
        navdetSel = new QComboBox(ExportForm);
        navdetSel->addItem(QString());
        navdetSel->addItem(QString());
        navdetSel->setObjectName(QString::fromUtf8("navdetSel"));
        navdetSel->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(navdetSel->sizePolicy().hasHeightForWidth());
        navdetSel->setSizePolicy(sizePolicy1);
        navdetSel->setMinimumSize(QSize(0, 20));
        navdetSel->setStyleSheet(QString::fromUtf8(":disabled {\n"
"    border-image:none;\n"
"    background-color: #4169E1;\n"
"    color:#778899;\n"
"}"));
        navdetSel->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        navdetSel->setMinimumContentsLength(12);
        navdetSel->setIconSize(QSize(25, 25));
        navdetSel->setFrame(true);

        horizontalLayout_3->addWidget(navdetSel);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        lhContainer = new QHBoxLayout();
        lhContainer->setSpacing(0);
        lhContainer->setObjectName(QString::fromUtf8("lhContainer"));
        lhContainer->setContentsMargins(-1, 0, -1, 0);

        verticalLayout->addLayout(lhContainer);

        verticalLayout->setStretch(1, 15);

        retranslateUi(ExportForm);

        QMetaObject::connectSlotsByName(ExportForm);
    } // setupUi

    void retranslateUi(QWidget *ExportForm)
    {
        ExportForm->setWindowTitle(QCoreApplication::translate("ExportForm", "Form", nullptr));
        lbTitle->setText(QCoreApplication::translate("ExportForm", "\344\270\255\345\215\216\344\272\272\346\260\221\345\205\261\345\222\214\345\233\275", nullptr));
        navdetSel->setItemText(0, QCoreApplication::translate("ExportForm", "\346\265\267\345\233\276\346\230\276\347\244\272", nullptr));
        navdetSel->setItemText(1, QCoreApplication::translate("ExportForm", "\346\216\242\346\265\213\346\230\276\347\244\272", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ExportForm: public Ui_ExportForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTFORM_H
