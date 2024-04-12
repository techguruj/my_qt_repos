#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->lineEdit->setText("5");

}


void Widget::on_pushButton_2_clicked()
{
     ui->lineEdit->setText("10");
}


void Widget::on_lineEdit_editingFinished()
{
    if (ui->lineEdit->text()!="123") ui->lineEdit->undo();
}

