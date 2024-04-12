#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{

    LabelRed                   =new QLabel      ;
    LabelGreen                 =new QLabel      ;
    LabelBlue                  =new QLabel      ;
    LabelFarbecode             =new QLabel      ;
    LabelPlatzhalter           =new QLabel      ;
    LabelFarbefenster          =new QLabel      ;
    SliderRed                  =new QSlider     ;
    SliderGreen                =new QSlider     ;
    SliderBlue                 =new QSlider     ;
    SpinBoxRed                 =new QSpinBox    ;
    SpinBoxGreen               =new QSpinBox    ;
    SpinBoxBlue                =new QSpinBox    ;
    PushButtonSchreiben        =new QPushButton ;
    PushButtonBeenden          =new QPushButton ;
    PushButtonKopie            =new QPushButton ;
    LineEditFarbefenster       =new QLineEdit   ;
    gridLayoutlinks            =new QGridLayout ;
    hBoxLayouAlles             =new QHBoxLayout ;

    LabelRed            ->setText("Red");
    LabelGreen          ->setText("Green");
    LabelBlue           ->setText("Blue");
    LabelFarbecode      ->setText("Farbecode:");
    LabelPlatzhalter    ->setText(" ");
    LabelFarbefenster   ->setText(" ");

    PushButtonSchreiben ->setText("Schreiben");
    PushButtonBeenden   ->setText("Beenden");
    PushButtonKopie     ->setText("Kopie");

    PushButtonSchreiben ->setFixedWidth(this->width()/6);
    PushButtonBeenden   ->setFixedWidth(this->width()/6);
    PushButtonKopie     ->setFixedWidth(this->width()/6);

    LabelFarbefenster->setFixedSize(this->width()/2,this->height());



    SliderRed                  ->setRange(0,255);
    SliderGreen                ->setRange(0,255);
    SliderBlue                 ->setRange(0,255);
    SpinBoxRed                 ->setRange(0,255);
    SpinBoxGreen               ->setRange(0,255);
    SpinBoxBlue                ->setRange(0,255);

    SliderRed                  ->setValue(100);
    SliderGreen                ->setValue(100);
    SliderBlue                 ->setValue(100);
    SpinBoxRed                 ->setValue(100);
    SpinBoxGreen               ->setValue(100);
    SpinBoxBlue                ->setValue(100);

    SliderRed                  ->setOrientation(Qt::Vertical);
    SliderGreen                ->setOrientation(Qt::Vertical);
    SliderBlue                 ->setOrientation(Qt::Vertical);



    SliderRed                  ->setStyleSheet("QSlider::handle:vertical {background: red;border-radius: 8px;}");
    SliderGreen                ->setStyleSheet("QSlider::handle:vertical {background: green;border-radius: 8px;}");
    SliderBlue                 ->setStyleSheet("QSlider::handle:vertical {background: blue;border-radius: 8px;}");




    SpinBoxRed                 ->setFixedWidth(this->width()/6);
    SpinBoxGreen               ->setFixedWidth(this->width()/6);
    SpinBoxBlue                ->setFixedWidth(this->width()/6);


    gridLayoutlinks->addWidget(LabelRed,            0,0,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(LabelGreen,          0,1,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(LabelBlue,           0,2,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SliderRed,           1,0,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SliderGreen,         1,1,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SliderBlue,          1,2,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SpinBoxRed,          2,0,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SpinBoxGreen,        2,1,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(SpinBoxBlue,         2,2,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(LabelFarbecode,      3,0,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(LineEditFarbefenster,3,1,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(LabelPlatzhalter,    3,2,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(PushButtonKopie,     4,0,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(PushButtonSchreiben, 4,1,Qt::AlignHCenter);
    gridLayoutlinks->addWidget(PushButtonBeenden,   4,2,Qt::AlignHCenter);
    gridLayoutlinks->setColumnStretch(0, 0);
    gridLayoutlinks->setColumnStretch(1, 0);
    gridLayoutlinks->setColumnStretch(2, 0);
    hBoxLayouAlles->addLayout(gridLayoutlinks);
    hBoxLayouAlles->addWidget(LabelFarbefenster);



    setLayout(hBoxLayouAlles);


    connect(SliderRed, SIGNAL(valueChanged(int)), SpinBoxRed, SLOT(setValue(int)));
    connect(SpinBoxRed, SIGNAL(valueChanged(int)), SliderRed, SLOT(setValue(int)));
    connect(SliderGreen, SIGNAL(valueChanged(int)), SpinBoxGreen, SLOT(setValue(int)));
    connect(SpinBoxGreen, SIGNAL(valueChanged(int)), SliderGreen, SLOT(setValue(int)));
    connect(SliderBlue, SIGNAL(valueChanged(int)), SpinBoxBlue, SLOT(setValue(int)));
    connect(SpinBoxBlue, SIGNAL(valueChanged(int)), SliderBlue, SLOT(setValue(int)));
    connect(SliderRed, SIGNAL(valueChanged(int)), this, SLOT(Changecolor(int)));
    connect(SliderGreen, SIGNAL(valueChanged(int)), this, SLOT(Changecolor(int)));
    connect(SliderBlue, SIGNAL(valueChanged(int)), this, SLOT(Changecolor(int)));
    connect(LineEditFarbefenster, SIGNAL(ReturnPressed()), this, SLOT(InputColor()));
    connect(PushButtonKopie, SIGNAL(clicked()), LineEditFarbefenster, SLOT(selectAll()));
    connect(PushButtonSchreiben, SIGNAL(clicked()), this, SLOT(InputColor()));
    connect(PushButtonBeenden, SIGNAL(clicked()), this, SLOT(close()));


    LabelFarbefenster->setStyleSheet("background-color: #646464;");
    LineEditFarbefenster->setText("#646464");


}

void myWidget::Changecolor(int)
{
    QString Farbe;
    Farbe = QString("background-color: #%1%2%3;").arg(SliderRed->value(),2,16,QChar('0')).arg(SliderGreen->value(),2,16,QChar('0')).arg(SliderBlue->value(),2,16,QChar('0'));
    LabelFarbefenster->setStyleSheet(Farbe);
    QString FarbecodeNOPrefix;
    FarbecodeNOPrefix = QString("%1%2%3").arg(SliderRed->value(),2,16,QChar('0')).arg(SliderGreen->value(),2,16,QChar('0')).arg(SliderBlue->value(),2,16,QChar('0'));
    LineEditFarbefenster->setText("#"+FarbecodeNOPrefix.toUpper());

}

void myWidget::InputColor()
{
    QString InputFarbecode=LineEditFarbefenster->text();

//slice 2and3 chars, 4and5 chars, 6and7 chars
    QString Input2_3Chars=InputFarbecode.mid(1,2).toUpper();
    QString Input4_5Chars=InputFarbecode.mid(3,2).toUpper();
    QString Input6_7Chars=InputFarbecode.mid(5,2).toUpper();

    //LabelPlatzhalter->setText("#"+Input2_3Chars+Input4_5Chars+Input6_7Chars);
     int Input2_3CharsInt=Input2_3Chars.toInt(0,16);
     int Input4_5CharsInt=Input4_5Chars.toInt(0,16);
     int Input6_7CharsInt=Input6_7Chars.toInt(0,16);



     SliderRed->setValue(Input2_3CharsInt);
     SliderGreen->setValue(Input4_5CharsInt);
     SliderBlue->setValue(Input6_7CharsInt);



}





myWidget::~myWidget() {}
