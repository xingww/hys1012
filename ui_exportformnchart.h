/********************************************************************************
** Form generated from reading UI file 'exportformnchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTFORMNCHART_H
#define UI_EXPORTFORMNCHART_H

#include <EncMapWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportFormnchart
{
public:
    QGridLayout *gridLayout;
    EncMapWidget *mapWidget;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGenerate;
    QPushButton *btnExport;

    void setupUi(QWidget *exportFormnchart)
    {
        if (exportFormnchart->objectName().isEmpty())
            exportFormnchart->setObjectName(QString::fromUtf8("exportFormnchart"));
        exportFormnchart->resize(1015, 569);
        gridLayout = new QGridLayout(exportFormnchart);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mapWidget = new EncMapWidget(exportFormnchart);
        mapWidget->setObjectName(QString::fromUtf8("mapWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(mapWidget->sizePolicy().hasHeightForWidth());
        mapWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mapWidget, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeWidget = new QTreeWidget(exportFormnchart);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout_2->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnGenerate = new QPushButton(exportFormnchart);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnGenerate->sizePolicy().hasHeightForWidth());
        btnGenerate->setSizePolicy(sizePolicy1);
        btnGenerate->setMinimumSize(QSize(0, 30));
        btnGenerate->setMaximumSize(QSize(16777215, 30));
        btnGenerate->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(btnGenerate);

        btnExport = new QPushButton(exportFormnchart);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        sizePolicy1.setHeightForWidth(btnExport->sizePolicy().hasHeightForWidth());
        btnExport->setSizePolicy(sizePolicy1);
        btnExport->setMinimumSize(QSize(0, 30));
        btnExport->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnExport);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);


        retranslateUi(exportFormnchart);

        QMetaObject::connectSlotsByName(exportFormnchart);
    } // setupUi

    void retranslateUi(QWidget *exportFormnchart)
    {
        exportFormnchart->setWindowTitle(QCoreApplication::translate("exportFormnchart", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("exportFormnchart", "\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        btnGenerate->setText(QCoreApplication::translate("exportFormnchart", "\350\246\201\346\212\245\347\224\237\346\210\220", nullptr));
        btnExport->setText(QCoreApplication::translate("exportFormnchart", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exportFormnchart: public Ui_exportFormnchart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTFORMNCHART_H
