/********************************************************************************
** Form generated from reading UI file 'homeform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEFORM_H
#define UI_HOMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *inKeyword;
    QWidget *wtAdvSearch;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *lbAuthor;
    QLineEdit *inActor;
    QLabel *lbAbbr;
    QLineEdit *inAbbr;
    QLineEdit *inShipName;
    QLabel *lbArea;
    QLineEdit *inAuthor;
    QLabel *lbTitle;
    QLabel *lbShipName;
    QLabel *lbActor;
    QLineEdit *inTitle;
    QLineEdit *inArea;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnSearchType;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReset;
    QPushButton *btnSearch;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnRefresh;
    QPushButton *btnCreate;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableTask;
    QVBoxLayout *verticalLayout_5;
    QTreeWidget *taskInfoTree;
    QLabel *label_14;
    QTextBrowser *txtComment;

    void setupUi(QWidget *HomeForm)
    {
        if (HomeForm->objectName().isEmpty())
            HomeForm->setObjectName(QString::fromUtf8("HomeForm"));
        HomeForm->resize(760, 750);
        horizontalLayout = new QHBoxLayout(HomeForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 10);
        inKeyword = new QLineEdit(HomeForm);
        inKeyword->setObjectName(QString::fromUtf8("inKeyword"));
        inKeyword->setMinimumSize(QSize(0, 36));
        inKeyword->setMaximumSize(QSize(16777215, 36));
        inKeyword->setStyleSheet(QString::fromUtf8("padding-left:10px;\n"
"margin:0 10px;"));

        verticalLayout->addWidget(inKeyword);

        wtAdvSearch = new QWidget(HomeForm);
        wtAdvSearch->setObjectName(QString::fromUtf8("wtAdvSearch"));
        wtAdvSearch->setEnabled(true);
        wtAdvSearch->setMinimumSize(QSize(0, 90));
        wtAdvSearch->setMaximumSize(QSize(16777215, 90));
        wtAdvSearch->setStyleSheet(QString::fromUtf8("border-image:none;"));
        horizontalLayout_2 = new QHBoxLayout(wtAdvSearch);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setVerticalSpacing(10);
        lbAuthor = new QLabel(wtAdvSearch);
        lbAuthor->setObjectName(QString::fromUtf8("lbAuthor"));
        QFont font;
        font.setPointSize(10);
        lbAuthor->setFont(font);
        lbAuthor->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbAuthor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lbAuthor, 1, 4, 1, 1);

        inActor = new QLineEdit(wtAdvSearch);
        inActor->setObjectName(QString::fromUtf8("inActor"));
        inActor->setMinimumSize(QSize(0, 36));
        inActor->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inActor, 1, 3, 1, 1);

        lbAbbr = new QLabel(wtAdvSearch);
        lbAbbr->setObjectName(QString::fromUtf8("lbAbbr"));
        lbAbbr->setFont(font);
        lbAbbr->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout_2->addWidget(lbAbbr, 0, 2, 1, 1);

        inAbbr = new QLineEdit(wtAdvSearch);
        inAbbr->setObjectName(QString::fromUtf8("inAbbr"));
        inAbbr->setMinimumSize(QSize(0, 36));
        inAbbr->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inAbbr, 0, 3, 1, 1);

        inShipName = new QLineEdit(wtAdvSearch);
        inShipName->setObjectName(QString::fromUtf8("inShipName"));
        inShipName->setMinimumSize(QSize(0, 36));
        inShipName->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inShipName, 1, 1, 1, 1);

        lbArea = new QLabel(wtAdvSearch);
        lbArea->setObjectName(QString::fromUtf8("lbArea"));
        lbArea->setFont(font);
        lbArea->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout_2->addWidget(lbArea, 0, 4, 1, 1);

        inAuthor = new QLineEdit(wtAdvSearch);
        inAuthor->setObjectName(QString::fromUtf8("inAuthor"));
        inAuthor->setMinimumSize(QSize(0, 36));
        inAuthor->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inAuthor, 1, 5, 1, 1);

        lbTitle = new QLabel(wtAdvSearch);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lbTitle, 0, 0, 1, 1);

        lbShipName = new QLabel(wtAdvSearch);
        lbShipName->setObjectName(QString::fromUtf8("lbShipName"));
        lbShipName->setFont(font);
        lbShipName->setStyleSheet(QString::fromUtf8("border-image:none;"));

        gridLayout_2->addWidget(lbShipName, 1, 0, 1, 1);

        lbActor = new QLabel(wtAdvSearch);
        lbActor->setObjectName(QString::fromUtf8("lbActor"));
        lbActor->setFont(font);
        lbActor->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbActor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lbActor, 1, 2, 1, 1);

        inTitle = new QLineEdit(wtAdvSearch);
        inTitle->setObjectName(QString::fromUtf8("inTitle"));
        inTitle->setMinimumSize(QSize(0, 36));
        inTitle->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inTitle, 0, 1, 1, 1);

        inArea = new QLineEdit(wtAdvSearch);
        inArea->setObjectName(QString::fromUtf8("inArea"));
        inArea->setMinimumSize(QSize(0, 36));
        inArea->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/background.png);"));

        gridLayout_2->addWidget(inArea, 0, 5, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addWidget(wtAdvSearch);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, -1, 10, -1);
        btnSearchType = new QPushButton(HomeForm);
        btnSearchType->setObjectName(QString::fromUtf8("btnSearchType"));
        btnSearchType->setStyleSheet(QString::fromUtf8("*{\n"
"border:none;\n"
"color:#D3D3D3;\n"
"}\n"
"*:hover {\n"
"    color:#4169E1;\n"
"}"));

        horizontalLayout_8->addWidget(btnSearchType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        btnReset = new QPushButton(HomeForm);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setMinimumSize(QSize(0, 30));
        btnReset->setMaximumSize(QSize(75, 16777215));
        btnReset->setFocusPolicy(Qt::ClickFocus);
        btnReset->setAutoFillBackground(false);
        btnReset->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));
        btnReset->setFlat(false);

        horizontalLayout_8->addWidget(btnReset);

        btnSearch = new QPushButton(HomeForm);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setMinimumSize(QSize(0, 30));
        btnSearch->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_8->addWidget(btnSearch);

        horizontalLayout_8->setStretch(1, 10);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(HomeForm);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 1));
        line_2->setMaximumSize(QSize(16777215, 0));
        line_2->setStyleSheet(QString::fromUtf8("border-color: rgb(232, 232, 232);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btnRefresh = new QPushButton(HomeForm);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMinimumSize(QSize(0, 30));
        btnRefresh->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_9->addWidget(btnRefresh);

        btnCreate = new QPushButton(HomeForm);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setMinimumSize(QSize(0, 30));
        btnCreate->setStyleSheet(QString::fromUtf8("*:hover {\n"
"color: rgb(57, 138, 241);\n"
"}"));

        horizontalLayout_9->addWidget(btnCreate);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_9);

        tableTask = new QTableView(HomeForm);
        tableTask->setObjectName(QString::fromUtf8("tableTask"));
        tableTask->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(242, 242, 242);"));
        tableTask->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableTask->horizontalHeader()->setCascadingSectionResizes(true);
        tableTask->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableTask);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        taskInfoTree = new QTreeWidget(HomeForm);
        taskInfoTree->setObjectName(QString::fromUtf8("taskInfoTree"));
        taskInfoTree->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(242, 242, 242);"));

        verticalLayout_5->addWidget(taskInfoTree);

        label_14 = new QLabel(HomeForm);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font:bold 9pt;"));

        verticalLayout_5->addWidget(label_14);

        txtComment = new QTextBrowser(HomeForm);
        txtComment->setObjectName(QString::fromUtf8("txtComment"));
        txtComment->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(txtComment);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(2, 2);

        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(HomeForm);

        QMetaObject::connectSlotsByName(HomeForm);
    } // setupUi

    void retranslateUi(QWidget *HomeForm)
    {
        HomeForm->setWindowTitle(QCoreApplication::translate("HomeForm", "Form", nullptr));
        inKeyword->setPlaceholderText(QCoreApplication::translate("HomeForm", "\350\257\267\350\276\223\345\205\245\346\220\234\347\264\242\345\205\263\351\224\256\350\257\215", nullptr));
        lbAuthor->setText(QCoreApplication::translate("HomeForm", "\346\225\264\347\274\226\344\272\272:", nullptr));
        lbAbbr->setText(QCoreApplication::translate("HomeForm", "\344\273\273\345\212\241\347\256\200\347\247\260:", nullptr));
        lbArea->setText(QCoreApplication::translate("HomeForm", "\344\273\273\345\212\241\346\265\267\345\214\272:", nullptr));
        lbTitle->setText(QCoreApplication::translate("HomeForm", "\346\225\260\346\215\256\345\220\215\347\247\260:", nullptr));
        lbShipName->setText(QCoreApplication::translate("HomeForm", "\346\234\254\350\210\260\345\220\215\347\247\260:", nullptr));
        lbActor->setText(QCoreApplication::translate("HomeForm", "\345\200\274\346\233\264\351\225\277:", nullptr));
        inArea->setPlaceholderText(QString());
        btnSearchType->setText(QCoreApplication::translate("HomeForm", ">>\351\253\230\347\272\247\346\220\234\347\264\242", nullptr));
        btnReset->setText(QCoreApplication::translate("HomeForm", "\351\207\215\347\275\256", nullptr));
        btnSearch->setText(QCoreApplication::translate("HomeForm", "\346\220\234\347\264\242", nullptr));
        btnRefresh->setText(QCoreApplication::translate("HomeForm", "\345\210\267\346\226\260", nullptr));
        btnCreate->setText(QCoreApplication::translate("HomeForm", "\346\226\260\345\273\272\344\273\273\345\212\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = taskInfoTree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("HomeForm", "\344\273\273\345\212\241\350\257\246\346\203\205", nullptr));
        label_14->setText(QCoreApplication::translate("HomeForm", "\345\244\207\346\263\250\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeForm: public Ui_HomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEFORM_H
