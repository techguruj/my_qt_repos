#include "dlgnichtmodal.h"
#include "ui_dlgnichtmodal.h"

DlgNichtModal::DlgNichtModal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNichtModal)
{
    ui->setupUi(this);
}

DlgNichtModal::~DlgNichtModal()
{
    delete ui;
}
