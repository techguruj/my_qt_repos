#include "dlgmodal.h"
#include "ui_dlgmodal.h"

DlgModal::DlgModal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgModal)
{
    ui->setupUi(this);
}

DlgModal::~DlgModal()
{
    delete ui;
}
