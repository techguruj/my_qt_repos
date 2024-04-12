/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leMNr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leMNachname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *leMVorname;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *leMAbtNr;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblPosition;
    QPushButton *btnFirst;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QPushButton *btnLast;
    QPushButton *btnNew;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 520);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(180, 90, 331, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(150, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setMargin(20);

        horizontalLayout->addWidget(label);

        leMNr = new QLineEdit(layoutWidget);
        leMNr->setObjectName("leMNr");

        horizontalLayout->addWidget(leMNr);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setMargin(20);

        horizontalLayout_2->addWidget(label_2);

        leMNachname = new QLineEdit(layoutWidget);
        leMNachname->setObjectName("leMNachname");

        horizontalLayout_2->addWidget(leMNachname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setMargin(20);

        horizontalLayout_3->addWidget(label_3);

        leMVorname = new QLineEdit(layoutWidget);
        leMVorname->setObjectName("leMVorname");

        horizontalLayout_3->addWidget(leMVorname);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(150, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setMargin(20);

        horizontalLayout_4->addWidget(label_4);

        leMAbtNr = new QLineEdit(layoutWidget);
        leMAbtNr->setObjectName("leMAbtNr");

        horizontalLayout_4->addWidget(leMAbtNr);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(590, 10, 82, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblPosition = new QLabel(layoutWidget1);
        lblPosition->setObjectName("lblPosition");
        lblPosition->setMaximumSize(QSize(16777215, 20));
        lblPosition->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblPosition);

        btnFirst = new QPushButton(layoutWidget1);
        btnFirst->setObjectName("btnFirst");

        verticalLayout_2->addWidget(btnFirst);

        btnPrevious = new QPushButton(layoutWidget1);
        btnPrevious->setObjectName("btnPrevious");

        verticalLayout_2->addWidget(btnPrevious);

        btnNext = new QPushButton(layoutWidget1);
        btnNext->setObjectName("btnNext");

        verticalLayout_2->addWidget(btnNext);

        btnLast = new QPushButton(layoutWidget1);
        btnLast->setObjectName("btnLast");

        verticalLayout_2->addWidget(btnLast);

        btnNew = new QPushButton(Widget);
        btnNew->setObjectName("btnNew");
        btnNew->setGeometry(QRect(180, 390, 80, 24));
        btnCancel = new QPushButton(Widget);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(180, 430, 80, 24));
        btnSave = new QPushButton(Widget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(280, 390, 80, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Mitarbeiter-Nr", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Nachname", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Vorname", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Abteilungs-Nr", nullptr));
        lblPosition->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        btnFirst->setText(QCoreApplication::translate("Widget", "First", nullptr));
        btnPrevious->setText(QCoreApplication::translate("Widget", "Previous", nullptr));
        btnNext->setText(QCoreApplication::translate("Widget", "Next", nullptr));
        btnLast->setText(QCoreApplication::translate("Widget", "Last", nullptr));
        btnNew->setText(QCoreApplication::translate("Widget", "Neu", nullptr));
        btnCancel->setText(QCoreApplication::translate("Widget", "Abbrechen", nullptr));
        btnSave->setText(QCoreApplication::translate("Widget", "Speichern", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
