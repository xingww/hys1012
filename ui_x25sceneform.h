/********************************************************************************
** Form generated from reading UI file 'x25sceneform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_X25SCENEFORM_H
#define UI_X25SCENEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_X25SceneForm
{
public:

    void setupUi(QWidget *X25SceneForm)
    {
        if (X25SceneForm->objectName().isEmpty())
            X25SceneForm->setObjectName(QString::fromUtf8("X25SceneForm"));
        X25SceneForm->resize(597, 443);

        retranslateUi(X25SceneForm);

        QMetaObject::connectSlotsByName(X25SceneForm);
    } // setupUi

    void retranslateUi(QWidget *X25SceneForm)
    {
        X25SceneForm->setWindowTitle(QCoreApplication::translate("X25SceneForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class X25SceneForm: public Ui_X25SceneForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_X25SCENEFORM_H
