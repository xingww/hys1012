/********************************************************************************
** Form generated from reading UI file 'viewattentiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWATTENTIONDIALOG_H
#define UI_VIEWATTENTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include "widget/basetitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_ViewAttentionDialog
{
public:
    QVBoxLayout *verticalLayout;
    BaseTitleBar *titleBar;
    QHBoxLayout *horizontalLayout;
    QTableView *tableAttention;

    void setupUi(QFrame *ViewAttentionDialog)
    {
        if (ViewAttentionDialog->objectName().isEmpty())
            ViewAttentionDialog->setObjectName(QString::fromUtf8("ViewAttentionDialog"));
        ViewAttentionDialog->resize(633, 350);
        verticalLayout = new QVBoxLayout(ViewAttentionDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new BaseTitleBar(ViewAttentionDialog);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setMinimumSize(QSize(0, 36));
        titleBar->setMaximumSize(QSize(16777215, 36));
        titleBar->setStyleSheet(QString::fromUtf8("border-image:none;"));

        verticalLayout->addWidget(titleBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 9, 9, 9);
        tableAttention = new QTableView(ViewAttentionDialog);
        tableAttention->setObjectName(QString::fromUtf8("tableAttention"));
        tableAttention->setStyleSheet(QString::fromUtf8(""));
        tableAttention->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tableAttention);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ViewAttentionDialog);

        QMetaObject::connectSlotsByName(ViewAttentionDialog);
    } // setupUi

    void retranslateUi(QFrame *ViewAttentionDialog)
    {
        ViewAttentionDialog->setWindowTitle(QCoreApplication::translate("ViewAttentionDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewAttentionDialog: public Ui_ViewAttentionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWATTENTIONDIALOG_H
