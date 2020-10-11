/********************************************************************************
** Form generated from reading UI file 'analysisform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISFORM_H
#define UI_ANALYSISFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbTitle;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbActpas;
    QHBoxLayout *hlContainer;

    void setupUi(QWidget *AnalysisForm)
    {
        if (AnalysisForm->objectName().isEmpty())
            AnalysisForm->setObjectName(QString::fromUtf8("AnalysisForm"));
        AnalysisForm->resize(796, 559);
        verticalLayout = new QVBoxLayout(AnalysisForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbTitle = new QLabel(AnalysisForm);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_2->addWidget(lbTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(10, -1, 50, -1);
        cbActpas = new QComboBox(AnalysisForm);
        cbActpas->addItem(QString());
        cbActpas->addItem(QString());
        cbActpas->setObjectName(QString::fromUtf8("cbActpas"));
        cbActpas->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbActpas->sizePolicy().hasHeightForWidth());
        cbActpas->setSizePolicy(sizePolicy);
        cbActpas->setMinimumSize(QSize(0, 25));
        cbActpas->setStyleSheet(QString::fromUtf8(":disabled {\n"
"    border-image:none;\n"
"    background-color: #4169E1;\n"
"    color:#778899;\n"
"}"));
        cbActpas->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        cbActpas->setMinimumContentsLength(12);
        cbActpas->setIconSize(QSize(25, 25));
        cbActpas->setFrame(true);

        horizontalLayout->addWidget(cbActpas);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        hlContainer = new QHBoxLayout();
        hlContainer->setSpacing(0);
        hlContainer->setObjectName(QString::fromUtf8("hlContainer"));

        verticalLayout->addLayout(hlContainer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 15);

        retranslateUi(AnalysisForm);

        QMetaObject::connectSlotsByName(AnalysisForm);
    } // setupUi

    void retranslateUi(QWidget *AnalysisForm)
    {
        AnalysisForm->setWindowTitle(QCoreApplication::translate("AnalysisForm", "Form", nullptr));
        lbTitle->setText(QCoreApplication::translate("AnalysisForm", "\344\270\255\345\215\216\344\272\272\346\260\221\345\205\261\345\222\214\345\233\275", nullptr));
        cbActpas->setItemText(0, QCoreApplication::translate("AnalysisForm", "\344\270\273\345\212\250\346\211\253\346\217\217", nullptr));
        cbActpas->setItemText(1, QCoreApplication::translate("AnalysisForm", "\350\242\253\345\212\250\346\216\242\346\265\213", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AnalysisForm: public Ui_AnalysisForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISFORM_H
