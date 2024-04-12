#include "mywidget.h"
#include "ui_mywidget.h"
#include "ui_mywidget_copy2.h"
#include "mywidget_copy2.h"

mywidget_copy2::mywidget_copy2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mywidget_copy2)
{
    ui->setupUi(this);
}

mywidget_copy2::~mywidget_copy2()
{
    delete ui;
}
