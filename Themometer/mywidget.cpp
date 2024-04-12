#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{

    labelBilder                    =new QLabel          ;
    pixmap                         =new QPixmap         ;
    groupBoxArt                    =new QGroupBox       ;
    radioButtonCelsiustoFahrenheit =new QRadioButton    ;
    radioButtonFahrenheittoCelsius =new QRadioButton    ;
    formLayout                     =new QFormLayout     ;
    checkBox2Nachkommastellen      =new QCheckBox       ;
    vboxLayoutMitte                =new QVBoxLayout     ;
    vboxLayoutRechts               =new QVBoxLayout     ;
    hboxLayoutAlles                =new QHBoxLayout     ;
    lineEditOben                   =new QLineEdit       ;
    lineEditUnten                  =new QLineEdit       ;
    hboxLayoutArt                  =new QHBoxLayout     ;
    pushButtonClear                =new QPushButton     ;
    pushButtonBerechnen            =new QPushButton     ;
    pushButtonSchliessen           =new QPushButton     ;
    icon                           =new QIcon           ;
    celsius                        =0.0                 ;
    fahrenheit                     =32.0                ;
    *toDoubleOK                    =0                   ;

    pixmap->load(":/Screenshot 2024-03-07 144404.png");
    labelBilder->setPixmap(*pixmap);
    labelBilder->setAlignment(Qt::AlignCenter);
    labelBilder->setPixmap (pixmap->scaled( 200, 200, Qt::KeepAspectRatio));


    groupBoxArt                     ->setTitle("Art");
    radioButtonCelsiustoFahrenheit  ->setText("Celsius -> Fahrenheit");
    radioButtonFahrenheittoCelsius  ->setText("Fahrenheit -> Celsius");
    hboxLayoutArt                   ->addWidget(radioButtonCelsiustoFahrenheit);
    hboxLayoutArt                   ->addWidget(radioButtonFahrenheittoCelsius);
    groupBoxArt                     ->setLayout(hboxLayoutArt);
    radioButtonCelsiustoFahrenheit  ->setChecked(true);
    formLayout                      ->addRow("Celcius", lineEditOben);
    formLayout                      ->addRow("Fahrenheit", lineEditUnten);

    checkBox2Nachkommastellen       ->setText("2 Nachkommastellen");
    vboxLayoutMitte                 ->addWidget(groupBoxArt);
    vboxLayoutMitte                 ->addStretch();
    vboxLayoutMitte                 ->addLayout(formLayout);
    vboxLayoutMitte                 ->addWidget(checkBox2Nachkommastellen);

    pushButtonClear     ->setText("Clear");
    pushButtonBerechnen ->setText("Berechnen");
    pushButtonSchliessen->setText("Schliessen");

    icon                ->addFile(":/icons8-exit-96.png");
    pushButtonSchliessen->setIcon(*icon);

    vboxLayoutRechts->addWidget(pushButtonClear);
    vboxLayoutRechts->addWidget(pushButtonBerechnen);
    vboxLayoutRechts->addStretch();
    vboxLayoutRechts->addWidget(pushButtonSchliessen);

    hboxLayoutAlles->addWidget(labelBilder);
    hboxLayoutAlles->addLayout(vboxLayoutMitte);
    hboxLayoutAlles->addLayout(vboxLayoutRechts);

    setLayout(hboxLayoutAlles);

    lineEditUnten->setReadOnly(1);

    connect(pushButtonClear,                &QPushButton::clicked,      this, [&](){lineEditOben->clear(); lineEditUnten->clear();});
    connect(pushButtonSchliessen,           &QPushButton::clicked,      this, &myWidget::close);
    connect(lineEditOben,                   &QLineEdit::returnPressed,  this, &myWidget::celsisuto_Fahrenheit);
    connect(lineEditUnten,                  &QLineEdit::returnPressed,  this, &myWidget::fahrenheitto_Celsius);
    connect(radioButtonCelsiustoFahrenheit, &QRadioButton::clicked,     this, [&](){lineEditUnten->setReadOnly(1);lineEditOben->setReadOnly(0);});
    connect(radioButtonFahrenheittoCelsius, &QRadioButton::clicked,     this, [&](){lineEditUnten->setReadOnly(0);lineEditOben->setReadOnly(1);});
    connect(pushButtonBerechnen,            &QPushButton::clicked,      this, &myWidget::CelOrFahren);



};


myWidget::~myWidget(){}

void myWidget::celsisuto_Fahrenheit()
{
    celsius = lineEditOben->text().toDouble(toDoubleOK);
    if (*toDoubleOK==0)
    {
        QMessageBox::warning(this, "Fehler", "Bitte geben Sie eine Zahl ein");
        return;



    }
    fahrenheit = celsius * 1.8 + 32.0;
    if (checkBox2Nachkommastellen->isChecked())
    {
        lineEditOben->setText(QString::number(celsius, 'f', 2));
        lineEditUnten->setText(QString::number(fahrenheit, 'f', 2));
    }
    else
    {
        lineEditOben->setText(QString::number(celsius, 'g'));
        lineEditUnten->setText(QString::number(fahrenheit, 'g'));
    }

}

void myWidget::fahrenheitto_Celsius()
{
    this->fahrenheit = lineEditUnten->text().toDouble(toDoubleOK);
    if (*toDoubleOK==0)
    {

        QMessageBox::warning(this, "Fehler", "Bitte geben Sie eine Zahl ein");
        return;
    }

    this->celsius = (fahrenheit - 32.0) /1.8;
    if (checkBox2Nachkommastellen->isChecked())
    {
        lineEditOben->setText(QString::number(this->celsius, 'f', 2));
        lineEditUnten->setText(QString::number(this->fahrenheit, 'f', 2));
    }
    else
    {
        lineEditOben->setText(QString::number(this->celsius, 'g'));
        lineEditUnten->setText(QString::number(this->fahrenheit, 'g'));
    }

}

void myWidget::CelOrFahren()
{
    if(radioButtonCelsiustoFahrenheit->isChecked())
        celsisuto_Fahrenheit();
    else
        fahrenheitto_Celsius();
}
