/********************************************************************************
** Form generated from reading UI file 'mywidget_copy2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_COPY2_H
#define UI_MYWIDGET_COPY2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywidget_copy2
{
public:

    void setupUi(QWidget *mywidget_copy2)
    {
        if (mywidget_copy2->objectName().isEmpty())
            mywidget_copy2->setObjectName("mywidget_copy2");
        mywidget_copy2->resize(400, 300);

        retranslateUi(mywidget_copy2);

        QMetaObject::connectSlotsByName(mywidget_copy2);
    } // setupUi

    void retranslateUi(QWidget *mywidget_copy2)
    {
        mywidget_copy2->setWindowTitle(QCoreApplication::translate("mywidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywidget_copy2 : public Ui_mywidget_copy2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_COPY2_H
