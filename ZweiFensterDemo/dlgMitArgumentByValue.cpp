#include "dlgMitArgumentByValue.h"
#include "ui_dlgMitArgumentByValue.h"

Dialog::Dialog(QString msg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lblMessage->setText(msg);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    close();
}

