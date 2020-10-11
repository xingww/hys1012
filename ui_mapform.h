/********************************************************************************
** Form generated from reading UI file 'mapform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPFORM_H
#define UI_MAPFORM_H

#include <EncMapWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapForm
{
public:
    QHBoxLayout *horizontalLayout;
    EncMapWidget *mapWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbTaskTitle;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbStart;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbEnd;
    QSlider *slider;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnFastforward;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MapForm)
    {
        if (MapForm->objectName().isEmpty())
            MapForm->setObjectName(QString::fromUtf8("MapForm"));
        MapForm->resize(580, 398);
        horizontalLayout = new QHBoxLayout(MapForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mapWidget = new EncMapWidget(MapForm);
        mapWidget->setObjectName(QString::fromUtf8("mapWidget"));
        verticalLayout_2 = new QVBoxLayout(mapWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(mapWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("*{\n"
"	border-image: url(:/destop/dia_bg.png);\n"
"    border-radius: 5px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbTaskTitle = new QLabel(widget);
        lbTaskTitle->setObjectName(QString::fromUtf8("lbTaskTitle"));
        QFont font;
        font.setPointSize(12);
        lbTaskTitle->setFont(font);
        lbTaskTitle->setStyleSheet(QString::fromUtf8("*{\n"
"border-image:none;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(lbTaskTitle);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbStart = new QLabel(widget);
        lbStart->setObjectName(QString::fromUtf8("lbStart"));
        lbStart->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_3->addWidget(lbStart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lbEnd = new QLabel(widget);
        lbEnd->setObjectName(QString::fromUtf8("lbEnd"));
        lbEnd->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lbEnd);


        verticalLayout->addLayout(horizontalLayout_3);

        slider = new QSlider(widget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setStyleSheet(QString::fromUtf8("border-image:none;"));
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, -1, 6, -1);
        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(25, 25));
        btnStart->setMaximumSize(QSize(25, 25));
        btnStart->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/start.png);"));

        horizontalLayout_2->addWidget(btnStart);

        btnStop = new QPushButton(widget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(20, 20));
        btnStop->setMaximumSize(QSize(20, 20));
        btnStop->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/destop/stop.png);"));

        horizontalLayout_2->addWidget(btnStop);

        btnFastforward = new QPushButton(widget);
        btnFastforward->setObjectName(QString::fromUtf8("btnFastforward"));
        btnFastforward->setMinimumSize(QSize(25, 25));
        btnFastforward->setMaximumSize(QSize(25, 25));
        btnFastforward->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/icons/Fastforward.png);\n"
""));

        horizontalLayout_2->addWidget(btnFastforward);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(mapWidget);


        retranslateUi(MapForm);

        QMetaObject::connectSlotsByName(MapForm);
    } // setupUi

    void retranslateUi(QWidget *MapForm)
    {
        MapForm->setWindowTitle(QCoreApplication::translate("MapForm", "Form", nullptr));
        lbTaskTitle->setText(QCoreApplication::translate("MapForm", "\344\270\255\345\215\216\344\272\272\346\260\221\345\205\261\345\222\214\345\233\275", nullptr));
        lbStart->setText(QCoreApplication::translate("MapForm", "17:09:32", nullptr));
        lbEnd->setText(QCoreApplication::translate("MapForm", "20.45:31", nullptr));
        btnStart->setText(QString());
        btnStop->setText(QString());
        btnFastforward->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapForm: public Ui_MapForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPFORM_H
