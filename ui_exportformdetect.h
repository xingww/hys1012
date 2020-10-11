/********************************************************************************
** Form generated from reading UI file 'exportformdetect.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTFORMDETECT_H
#define UI_EXPORTFORMDETECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportFormdetect
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *exportformdisplay;
    QHBoxLayout *lhContainer;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGenerate;
    QPushButton *btnExport;

    void setupUi(QWidget *exportFormdetect)
    {
        if (exportFormdetect->objectName().isEmpty())
            exportFormdetect->setObjectName(QString::fromUtf8("exportFormdetect"));
        exportFormdetect->resize(1012, 581);
        verticalLayout_3 = new QVBoxLayout(exportFormdetect);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        exportformdisplay = new QWidget(exportFormdetect);
        exportformdisplay->setObjectName(QString::fromUtf8("exportformdisplay"));
        lhContainer = new QHBoxLayout(exportformdisplay);
        lhContainer->setObjectName(QString::fromUtf8("lhContainer"));
        groupBox_2 = new QGroupBox(exportformdisplay);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);

        lhContainer->addWidget(groupBox_2);

        groupBox = new QGroupBox(exportformdisplay);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);

        lhContainer->addWidget(groupBox);


        verticalLayout_3->addWidget(exportformdisplay);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeWidget = new QTreeWidget(exportFormdetect);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\344\273\273\345\212\241\344\277\241\346\201\257"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnGenerate = new QPushButton(exportFormdetect);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnGenerate->sizePolicy().hasHeightForWidth());
        btnGenerate->setSizePolicy(sizePolicy2);
        btnGenerate->setMinimumSize(QSize(0, 30));
        btnGenerate->setMaximumSize(QSize(16777215, 30));
        btnGenerate->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(btnGenerate);

        btnExport = new QPushButton(exportFormdetect);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        sizePolicy2.setHeightForWidth(btnExport->sizePolicy().hasHeightForWidth());
        btnExport->setSizePolicy(sizePolicy2);
        btnExport->setMinimumSize(QSize(0, 30));
        btnExport->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnExport);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(exportFormdetect);

        QMetaObject::connectSlotsByName(exportFormdetect);
    } // setupUi

    void retranslateUi(QWidget *exportFormdetect)
    {
        exportFormdetect->setWindowTitle(QCoreApplication::translate("exportFormdetect", "Form", nullptr));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QString());
        btnGenerate->setText(QCoreApplication::translate("exportFormdetect", "\350\246\201\346\212\245\347\224\237\346\210\220", nullptr));
        btnExport->setText(QCoreApplication::translate("exportFormdetect", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exportFormdetect: public Ui_exportFormdetect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTFORMDETECT_H
