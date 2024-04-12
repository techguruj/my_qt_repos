#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

label = new QLabel("Test");
slider = new QSlider(Qt: :Horizontal); //Default: vertical.
spin= new QSpinBox;
hlayout = new QHBoxLayout;

1/-
hlayout->addWidget(Label);|
hlayout->addWidget(slider);
hlayout->addWidget(spin);

setLayout(hlayout);

// --
slider ->setRange(0, 130);
->setRange(0, 130);

spin->setValue(50);
slider->setValue(50);


connect(slider, SIGNAL(valueChanged(int)),spin,     SLOT(setValue(int)));
connect(spin ,  SIGNAL(valueChanged(int)),slider,   SLOT(setValue(int)));
//connect(slider,     SIGNAL(valueChanged(int)),label,SLOT(setText(QString::number(int))));
connect(slider, &QSlider::valueChanged(int), this,[&](int value) {label->setText(QString::number(value));});

}

Widget::~Widget() {}
