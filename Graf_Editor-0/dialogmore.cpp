#include "dialogmore.h"
#include "ui_dialogmore.h"

Dialogmore::Dialogmore(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogmore)
{
    ui->setupUi(this);
}

Dialogmore::~Dialogmore()
{
    delete ui;
}
