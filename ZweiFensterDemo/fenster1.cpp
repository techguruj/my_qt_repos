#include "fenster1.h"
#include "ui_fenster1.h"
#include "dlgMitArgumentByValue.h"
#include "dlgmodal.h"
#include "dlgnichtmodal.h"
#include <dlgMitArgumentByValue.h>
#include <dlgmitzeigerargumenten.h>
#include <QMessageBox>

Fenster1::Fenster1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Fenster1)
{
    ui->setupUi(this);
}

Fenster1::~Fenster1()
{
    delete ui;
}

void Fenster1::on_pushButton_2_clicked()    //Modaler Dialog
{
    DlgModal * modal = new DlgModal;
    modal->exec();
}


void Fenster1::on_pushButton_3_clicked()    //Nicht-Modaler Dialog
{
    DlgNichtModal *nichtmodal = new DlgNichtModal;
    nichtmodal->show();
}

void Fenster1::on_pushButton_clicked()      //Dialog mit Argumentüberabe
{
    Dialog *dialog = new Dialog(ui->lineEdit->text(), this);
    dialog->show();
    //dialog.exec();
    //QMessageBox::information(this,"Nach Dialog", "");
}

void Fenster1::on_pushButton_4_clicked()    //Dialog mit Value-Argument und Zeiger-Argument
{
    dlgMitZeigerArgumenten *dialog = new dlgMitZeigerArgumenten(ui->leNachricht->text(), ui->leAntwort);
    dialog->show();
}

