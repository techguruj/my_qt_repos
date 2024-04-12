#include "widget.h"

//C:/Users/q/Pictures/Screenshots/Screenshot 2024-03-06 111728.png
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    lblImage = new QLabel(this);

    QPixmap pix("C:/Users/q/Pictures/Screenshots/Screenshot 2024-03-06 111728.png");

    lblImage->setPixmap(pix);


}

Widget::~Widget() {}
