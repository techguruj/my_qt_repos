#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    LabelBild                  =new QLabel      ;
    FormlayoutUsernamePassword =new QFormLayout ;
    Lineeditusername           =new QLineEdit   ;
    Lineeditpassword           =new QLineEdit   ;
    PushbuttonOk               =new QPushButton ;
    PushbuttonAbort            =new QPushButton ;
    GridlayoutAlles            =new QGridLayout ;
    logincount                 =0               ;

    QPixmap pix(":/new/prefix1/Screenshot 2024-03-07 113616.png");

    LabelBild->setPixmap(pix);
    LabelBild->setPixmap(pix.scaled(100,100, Qt::KeepAspectRatio));
    LabelBild->setStyleSheet("QLabel { border: 3px solid gray; border-radius: 10px;}");


    Lineeditusername           ->setText("Username") ;
    Lineeditpassword           ->setText("Password") ;
    Lineeditpassword           ->setEchoMode(QLineEdit::Password);

    PushbuttonOk               ->setText("OK") ;
    PushbuttonAbort            ->setText("Abort") ;

    PushbuttonOk               ->setFixedWidth(this->width()/2);
    PushbuttonAbort            ->setFixedWidth(this->width()/2);

    FormlayoutUsernamePassword ->addRow("Username", Lineeditusername) ;
    FormlayoutUsernamePassword ->addRow("Password", Lineeditpassword) ;

    GridlayoutAlles            ->addWidget(LabelBild, 0, 0,                 Qt::AlignmentFlag::AlignCenter) ;
    GridlayoutAlles            ->addLayout(FormlayoutUsernamePassword, 0, 1,Qt::AlignmentFlag::AlignCenter) ;
    GridlayoutAlles            ->addWidget(PushbuttonOk, 1, 0,              Qt::AlignmentFlag::AlignCenter) ;
    GridlayoutAlles            ->addWidget(PushbuttonAbort, 1, 1,           Qt::AlignmentFlag::AlignCenter) ;

    setLayout(GridlayoutAlles) ;

    connect(PushbuttonAbort, &QPushButton::clicked, this, &myWidget::close);
    connect(PushbuttonOk, SIGNAL(clicked()), this, SLOT(loginfunction()));

}

myWidget::~myWidget() {}

void myWidget::loginfunction()
{
    logincount++;
    if(logincount>3)
    {
        QMessageBox::critical(this, "Fehler", "Darf nicht mehr als 3 mal versuchen!");
        close();
    }
    else
    {
        if(Lineeditusername->text()=="admin" && Lineeditpassword->text()=="123")
        {
            QMessageBox::information(this, "eingelogt", "Login erfolgreich");
            close();
        }
        else
        {
            QMessageBox::warning(this, "Fehler", "Username oder Password ist falsch!");
        }
    }
}
