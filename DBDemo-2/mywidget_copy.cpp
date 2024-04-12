#include "mywidget_copy.h"
#include "ui_mywidget_copy.h"

mywidget_copy::mywidget_copy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mywidget_copy)
{
    ui->setupUi(this);
}

mywidget_copy::~mywidget_copy()
{
    delete ui;
}
