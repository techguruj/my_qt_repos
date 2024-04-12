#include "dialog_anyquery.h"
#include "ui_dialog_anyquery.h"

Dialog_anyquery::Dialog_anyquery(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_anyquery)
{
    ui->setupUi(this);
}

Dialog_anyquery::~Dialog_anyquery()
{
    delete ui;
}
