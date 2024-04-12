#include "dlgmitzeigerargumenten.h"
#include "ui_dlgmitzeigerargumenten.h"

dlgMitZeigerArgumenten::dlgMitZeigerArgumenten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgMitZeigerArgumenten)
{
    ui->setupUi(this);
}

dlgMitZeigerArgumenten::dlgMitZeigerArgumenten(QString nachricht, QLineEdit * leVonFenster1) :
    QDialog(nullptr),
    ui(new Ui::dlgMitZeigerArgumenten)
{
    ui->setupUi(this);

    ui->lblNachricht->setText(nachricht);
    leAntwortVonFenster1 = leVonFenster1;
}

dlgMitZeigerArgumenten::~dlgMitZeigerArgumenten()
{
    delete ui;
}

void dlgMitZeigerArgumenten::on_pushButton_clicked()
{
    leAntwortVonFenster1->setText(ui->leAntwort->text());
    close();
}

