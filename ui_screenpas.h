/********************************************************************************
** Form generated from reading UI file 'screenpas.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENPAS_H
#define UI_SCREENPAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Screenpas
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetScreenpas;
    QVBoxLayout *vlscreenpas;
    QGroupBox *groupBoxpas;
    QGroupBox *groupBox;
    QComboBox *navalSelec;
    QLabel *beijingTime;
    QLabel *navalDirection;
    QLabel *navalLat;
    QLabel *navalLt;
    QLabel *navalSpeed;
    QLabel *navalBroad;
    QLabel *navalDepth;
    QLabel *recordTime;
    QLabel *soundSpeed;
    QLabel *navalDir;
    QDoubleSpinBox *navalSpeedvalue;
    QDoubleSpinBox *navalLtvalue;
    QDoubleSpinBox *navalLatvalue;
    QDoubleSpinBox *navalBroadvalue;
    QDoubleSpinBox *navalDirvalue;
    QDoubleSpinBox *soundSpeedvalue;
    QLineEdit *navalDirectionvalue;
    QDoubleSpinBox *navalDepthvalue;
    QLineEdit *recordTimevalue;
    QLineEdit *beijingTimevalue;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbStart;
    QLabel *lbRunningTime;
    QLabel *lbEnd;
    QSlider *slider;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnFastforward;
    QPushButton *btnFastbackward;
    QComboBox *dataSrcsele;
    QVBoxLayout *verticalLayout_3;
    QComboBox *sonarSele;
    QVBoxLayout *verticalLayout_5;
    QComboBox *targetidSrcsele;
    QWidget *widgetScreen;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *Screenpas)
    {
        if (Screenpas->objectName().isEmpty())
            Screenpas->setObjectName(QString::fromUtf8("Screenpas"));
        Screenpas->resize(1876, 864);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Screenpas->sizePolicy().hasHeightForWidth());
        Screenpas->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Screenpas);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetScreenpas = new QWidget(Screenpas);
        widgetScreenpas->setObjectName(QString::fromUtf8("widgetScreenpas"));
        vlscreenpas = new QVBoxLayout(widgetScreenpas);
        vlscreenpas->setSpacing(0);
        vlscreenpas->setObjectName(QString::fromUtf8("vlscreenpas"));
        vlscreenpas->setContentsMargins(0, 0, 0, 0);
        groupBoxpas = new QGroupBox(widgetScreenpas);
        groupBoxpas->setObjectName(QString::fromUtf8("groupBoxpas"));
        sizePolicy.setHeightForWidth(groupBoxpas->sizePolicy().hasHeightForWidth());
        groupBoxpas->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(groupBoxpas);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, 0, 1881, 50));
        navalSelec = new QComboBox(groupBox);
        navalSelec->addItem(QString());
        navalSelec->addItem(QString());
        navalSelec->setObjectName(QString::fromUtf8("navalSelec"));
        navalSelec->setGeometry(QRect(1770, 10, 101, 31));
        navalSelec->setMinimumSize(QSize(0, 30));
        navalSelec->setMaxVisibleItems(2);
        beijingTime = new QLabel(groupBox);
        beijingTime->setObjectName(QString::fromUtf8("beijingTime"));
        beijingTime->setGeometry(QRect(1515, 20, 68, 16));
        navalDirection = new QLabel(groupBox);
        navalDirection->setObjectName(QString::fromUtf8("navalDirection"));
        navalDirection->setGeometry(QRect(180, 16, 71, 16));
        navalLat = new QLabel(groupBox);
        navalLat->setObjectName(QString::fromUtf8("navalLat"));
        navalLat->setGeometry(QRect(684, 20, 38, 16));
        navalLt = new QLabel(groupBox);
        navalLt->setObjectName(QString::fromUtf8("navalLt"));
        navalLt->setGeometry(QRect(540, 18, 38, 16));
        navalSpeed = new QLabel(groupBox);
        navalSpeed->setObjectName(QString::fromUtf8("navalSpeed"));
        navalSpeed->setGeometry(QRect(340, 16, 71, 16));
        navalBroad = new QLabel(groupBox);
        navalBroad->setObjectName(QString::fromUtf8("navalBroad"));
        navalBroad->setGeometry(QRect(830, 20, 38, 16));
        navalDepth = new QLabel(groupBox);
        navalDepth->setObjectName(QString::fromUtf8("navalDepth"));
        navalDepth->setGeometry(QRect(20, 16, 71, 20));
        recordTime = new QLabel(groupBox);
        recordTime->setObjectName(QString::fromUtf8("recordTime"));
        recordTime->setGeometry(QRect(1260, 20, 68, 16));
        soundSpeed = new QLabel(groupBox);
        soundSpeed->setObjectName(QString::fromUtf8("soundSpeed"));
        soundSpeed->setGeometry(QRect(1110, 20, 38, 16));
        navalDir = new QLabel(groupBox);
        navalDir->setObjectName(QString::fromUtf8("navalDir"));
        navalDir->setGeometry(QRect(970, 20, 38, 16));
        navalSpeedvalue = new QDoubleSpinBox(groupBox);
        navalSpeedvalue->setObjectName(QString::fromUtf8("navalSpeedvalue"));
        navalSpeedvalue->setGeometry(QRect(410, 10, 121, 31));
        sizePolicy.setHeightForWidth(navalSpeedvalue->sizePolicy().hasHeightForWidth());
        navalSpeedvalue->setSizePolicy(sizePolicy);
        navalSpeedvalue->setReadOnly(true);
        navalSpeedvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalSpeedvalue->setDecimals(1);
        navalSpeedvalue->setMaximum(1000.000000000000000);
        navalLtvalue = new QDoubleSpinBox(groupBox);
        navalLtvalue->setObjectName(QString::fromUtf8("navalLtvalue"));
        navalLtvalue->setGeometry(QRect(582, 10, 91, 31));
        sizePolicy.setHeightForWidth(navalLtvalue->sizePolicy().hasHeightForWidth());
        navalLtvalue->setSizePolicy(sizePolicy);
        navalLtvalue->setLayoutDirection(Qt::LeftToRight);
        navalLtvalue->setReadOnly(true);
        navalLtvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalLtvalue->setDecimals(1);
        navalLtvalue->setMaximum(1000.000000000000000);
        navalLatvalue = new QDoubleSpinBox(groupBox);
        navalLatvalue->setObjectName(QString::fromUtf8("navalLatvalue"));
        navalLatvalue->setGeometry(QRect(730, 10, 91, 31));
        sizePolicy.setHeightForWidth(navalLatvalue->sizePolicy().hasHeightForWidth());
        navalLatvalue->setSizePolicy(sizePolicy);
        navalLatvalue->setReadOnly(true);
        navalLatvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalLatvalue->setDecimals(1);
        navalLatvalue->setMaximum(1000.000000000000000);
        navalBroadvalue = new QDoubleSpinBox(groupBox);
        navalBroadvalue->setObjectName(QString::fromUtf8("navalBroadvalue"));
        navalBroadvalue->setGeometry(QRect(870, 10, 91, 31));
        sizePolicy.setHeightForWidth(navalBroadvalue->sizePolicy().hasHeightForWidth());
        navalBroadvalue->setSizePolicy(sizePolicy);
        navalBroadvalue->setReadOnly(true);
        navalBroadvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalBroadvalue->setDecimals(1);
        navalBroadvalue->setMaximum(1000.000000000000000);
        navalDirvalue = new QDoubleSpinBox(groupBox);
        navalDirvalue->setObjectName(QString::fromUtf8("navalDirvalue"));
        navalDirvalue->setGeometry(QRect(1010, 10, 91, 31));
        sizePolicy.setHeightForWidth(navalDirvalue->sizePolicy().hasHeightForWidth());
        navalDirvalue->setSizePolicy(sizePolicy);
        navalDirvalue->setReadOnly(true);
        navalDirvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalDirvalue->setDecimals(1);
        navalDirvalue->setMaximum(1000.000000000000000);
        soundSpeedvalue = new QDoubleSpinBox(groupBox);
        soundSpeedvalue->setObjectName(QString::fromUtf8("soundSpeedvalue"));
        soundSpeedvalue->setGeometry(QRect(1150, 10, 101, 31));
        sizePolicy.setHeightForWidth(soundSpeedvalue->sizePolicy().hasHeightForWidth());
        soundSpeedvalue->setSizePolicy(sizePolicy);
        soundSpeedvalue->setReadOnly(true);
        soundSpeedvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        soundSpeedvalue->setDecimals(1);
        soundSpeedvalue->setMaximum(1000.000000000000000);
        navalDirectionvalue = new QLineEdit(groupBox);
        navalDirectionvalue->setObjectName(QString::fromUtf8("navalDirectionvalue"));
        navalDirectionvalue->setGeometry(QRect(250, 10, 81, 31));
        navalDepthvalue = new QDoubleSpinBox(groupBox);
        navalDepthvalue->setObjectName(QString::fromUtf8("navalDepthvalue"));
        navalDepthvalue->setGeometry(QRect(90, 10, 81, 31));
        sizePolicy.setHeightForWidth(navalDepthvalue->sizePolicy().hasHeightForWidth());
        navalDepthvalue->setSizePolicy(sizePolicy);
        navalDepthvalue->setLayoutDirection(Qt::RightToLeft);
        navalDepthvalue->setReadOnly(true);
        navalDepthvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navalDepthvalue->setDecimals(1);
        navalDepthvalue->setMaximum(1000.000000000000000);
        recordTimevalue = new QLineEdit(groupBox);
        recordTimevalue->setObjectName(QString::fromUtf8("recordTimevalue"));
        recordTimevalue->setGeometry(QRect(1330, 10, 171, 31));
        beijingTimevalue = new QLineEdit(groupBox);
        beijingTimevalue->setObjectName(QString::fromUtf8("beijingTimevalue"));
        beijingTimevalue->setGeometry(QRect(1590, 10, 171, 31));
        layoutWidget = new QWidget(groupBoxpas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 810, 1871, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, -1, 10, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbStart = new QLabel(layoutWidget);
        lbStart->setObjectName(QString::fromUtf8("lbStart"));
        lbStart->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_4->addWidget(lbStart);

        lbRunningTime = new QLabel(layoutWidget);
        lbRunningTime->setObjectName(QString::fromUtf8("lbRunningTime"));
        lbRunningTime->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout_4->addWidget(lbRunningTime);

        lbEnd = new QLabel(layoutWidget);
        lbEnd->setObjectName(QString::fromUtf8("lbEnd"));
        lbEnd->setStyleSheet(QString::fromUtf8("border-image:none;"));
        lbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lbEnd);


        verticalLayout->addLayout(horizontalLayout_4);

        slider = new QSlider(layoutWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy1);
        slider->setTabletTracking(false);
        slider->setStyleSheet(QString::fromUtf8("border-image:none;"));
        slider->setMaximum(99);
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, -1, 10, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(10, -1, 20, -1);
        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(25, 25));
        btnStart->setMaximumSize(QSize(25, 25));
        btnStart->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/start.png);\n"
""));

        horizontalLayout->addWidget(btnStart);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(20, 20));
        btnStop->setMaximumSize(QSize(20, 20));
        btnStop->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/stop.png);"));

        horizontalLayout->addWidget(btnStop);

        btnFastforward = new QPushButton(layoutWidget);
        btnFastforward->setObjectName(QString::fromUtf8("btnFastforward"));
        btnFastforward->setMinimumSize(QSize(25, 25));
        btnFastforward->setMaximumSize(QSize(25, 25));
        btnFastforward->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/icons/Fastforward.png);\n"
""));

        horizontalLayout->addWidget(btnFastforward);

        btnFastbackward = new QPushButton(layoutWidget);
        btnFastbackward->setObjectName(QString::fromUtf8("btnFastbackward"));
        btnFastbackward->setMinimumSize(QSize(25, 25));
        btnFastbackward->setMaximumSize(QSize(25, 25));
        btnFastbackward->setStyleSheet(QString::fromUtf8("border-image: url(:/destop/icons/Fastbackward.png);\n"
""));

        horizontalLayout->addWidget(btnFastbackward);


        horizontalLayout_3->addLayout(horizontalLayout);

        dataSrcsele = new QComboBox(layoutWidget);
        dataSrcsele->addItem(QString());
        dataSrcsele->addItem(QString());
        dataSrcsele->setObjectName(QString::fromUtf8("dataSrcsele"));
        dataSrcsele->setMinimumSize(QSize(0, 30));
        dataSrcsele->setBaseSize(QSize(0, 0));
        dataSrcsele->setEditable(false);
        dataSrcsele->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        dataSrcsele->setMinimumContentsLength(10);
        dataSrcsele->setIconSize(QSize(25, 16));

        horizontalLayout_3->addWidget(dataSrcsele);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, -1, 10, -1);
        sonarSele = new QComboBox(layoutWidget);
        sonarSele->addItem(QString());
        sonarSele->addItem(QString());
        sonarSele->addItem(QString());
        sonarSele->setObjectName(QString::fromUtf8("sonarSele"));
        sonarSele->setMinimumSize(QSize(0, 30));
        sonarSele->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        sonarSele->setMinimumContentsLength(6);

        verticalLayout_3->addWidget(sonarSele);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, -1, 10, -1);
        targetidSrcsele = new QComboBox(layoutWidget);
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->addItem(QString());
        targetidSrcsele->setObjectName(QString::fromUtf8("targetidSrcsele"));
        targetidSrcsele->setMinimumSize(QSize(0, 30));
        targetidSrcsele->setBaseSize(QSize(0, 0));
        targetidSrcsele->setEditable(false);
        targetidSrcsele->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        targetidSrcsele->setMinimumContentsLength(10);
        targetidSrcsele->setIconSize(QSize(25, 14));

        verticalLayout_5->addWidget(targetidSrcsele);


        horizontalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        widgetScreen = new QWidget(groupBoxpas);
        widgetScreen->setObjectName(QString::fromUtf8("widgetScreen"));
        widgetScreen->setGeometry(QRect(-10, 60, 1881, 741));
        groupBox_3 = new QGroupBox(widgetScreen);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1240, 0, 641, 741));
        groupBox_2 = new QGroupBox(widgetScreen);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1241, 741));

        vlscreenpas->addWidget(groupBoxpas);


        gridLayout_2->addWidget(widgetScreenpas, 0, 0, 1, 1);


        retranslateUi(Screenpas);

        QMetaObject::connectSlotsByName(Screenpas);
    } // setupUi

    void retranslateUi(QWidget *Screenpas)
    {
        Screenpas->setWindowTitle(QCoreApplication::translate("Screenpas", "Form", nullptr));
        groupBoxpas->setTitle(QString());
        groupBox->setTitle(QString());
        navalSelec->setItemText(0, QCoreApplication::translate("Screenpas", "\346\260\264\344\270\213\350\211\207", nullptr));
        navalSelec->setItemText(1, QCoreApplication::translate("Screenpas", "\346\260\264\351\235\242\350\210\260", nullptr));

        navalSelec->setCurrentText(QCoreApplication::translate("Screenpas", "\346\260\264\344\270\213\350\211\207", nullptr));
        beijingTime->setText(QCoreApplication::translate("Screenpas", "\345\214\227\344\272\254\346\227\266\351\227\264:", nullptr));
        navalDirection->setText(QCoreApplication::translate("Screenpas", "\346\234\254\350\210\260\350\210\252\345\220\221:", nullptr));
        navalLat->setText(QCoreApplication::translate("Screenpas", "\347\272\254\345\272\246:", nullptr));
        navalLt->setText(QCoreApplication::translate("Screenpas", "\347\273\217\345\272\246:", nullptr));
        navalSpeed->setText(QCoreApplication::translate("Screenpas", "\346\234\254\350\210\260\350\210\252\351\200\237:", nullptr));
        navalBroad->setText(QCoreApplication::translate("Screenpas", "\346\250\252\346\221\207:", nullptr));
        navalDepth->setText(QCoreApplication::translate("Screenpas", "\346\234\254\350\211\207\346\275\234\346\267\261:", nullptr));
        recordTime->setText(QCoreApplication::translate("Screenpas", "\350\256\260\345\275\225\346\227\266\351\227\264:", nullptr));
        soundSpeed->setText(QCoreApplication::translate("Screenpas", "\345\243\260\351\200\237:", nullptr));
        navalDir->setText(QCoreApplication::translate("Screenpas", "\347\272\265\346\221\207:", nullptr));
        navalSpeedvalue->setSuffix(QCoreApplication::translate("Screenpas", "\346\265\267\351\207\214/\346\227\266", nullptr));
        navalLtvalue->setSuffix(QCoreApplication::translate("Screenpas", "\345\272\246", nullptr));
        navalLatvalue->setSuffix(QCoreApplication::translate("Screenpas", "\345\272\246", nullptr));
        navalBroadvalue->setSuffix(QCoreApplication::translate("Screenpas", "\345\272\246", nullptr));
        navalDirvalue->setSuffix(QCoreApplication::translate("Screenpas", "\345\272\246", nullptr));
        soundSpeedvalue->setSuffix(QCoreApplication::translate("Screenpas", "\347\261\263/\347\247\222", nullptr));
        navalDepthvalue->setSuffix(QCoreApplication::translate("Screenpas", "\347\261\263", nullptr));
        lbStart->setText(QCoreApplication::translate("Screenpas", "S:18\357\274\23201\357\274\23213", nullptr));
        lbRunningTime->setText(QString());
        lbEnd->setText(QCoreApplication::translate("Screenpas", "E:18\357\274\23201\357\274\23213", nullptr));
        btnStart->setText(QString());
        btnStop->setText(QString());
        btnFastforward->setText(QString());
        btnFastbackward->setText(QString());
        dataSrcsele->setItemText(0, QCoreApplication::translate("Screenpas", "\345\234\272\346\231\257\346\225\260\346\215\256", nullptr));
        dataSrcsele->setItemText(1, QCoreApplication::translate("Screenpas", "\345\237\272\351\230\265\346\225\260\346\215\256", nullptr));

        sonarSele->setItemText(0, QCoreApplication::translate("Screenpas", "3X9", nullptr));
        sonarSele->setItemText(1, QCoreApplication::translate("Screenpas", "3X1", nullptr));
        sonarSele->setItemText(2, QCoreApplication::translate("Screenpas", "2X5", nullptr));

        targetidSrcsele->setItemText(0, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID1", nullptr));
        targetidSrcsele->setItemText(1, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID2", nullptr));
        targetidSrcsele->setItemText(2, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID3", nullptr));
        targetidSrcsele->setItemText(3, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID4", nullptr));
        targetidSrcsele->setItemText(4, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID5", nullptr));
        targetidSrcsele->setItemText(5, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID6", nullptr));
        targetidSrcsele->setItemText(6, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID7", nullptr));
        targetidSrcsele->setItemText(7, QCoreApplication::translate("Screenpas", "\347\233\256\346\240\207ID8", nullptr));

        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Screenpas: public Ui_Screenpas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENPAS_H
