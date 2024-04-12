#include "dlgoptionen.h"
#include "ui_dlgoptionen.h"
#include <QSettings>
#include <QMessageBox>
#include <QDebug>

DlgOptionen::DlgOptionen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgOptionen)
{
    ui->setupUi(this);
    registry = new QSettings("HKEY_CURRENT_USER/Software/Graf_Editor", QSettings::IniFormat);
    QString lang = registry->value("lang").toString();
    qDebug() << lang;
    if(lang == "de")
        ui->rdDeutsch->setChecked(true);
    else if(lang == "en")
        ui->rdEnglisch->setChecked(true);
}

DlgOptionen::~DlgOptionen()
{
    delete ui;
}

void DlgOptionen::on_rdDeutsch_clicked()
{
    registry->setValue("lang","de");
    QMessageBox::information(this, tr("Sprache umgestellt"), tr("Damit die Einstellung wirkt, starten Sie die Anwendung neu"));
}


void DlgOptionen::on_rdEnglisch_clicked()
{
    registry->setValue("lang","en");
    QMessageBox::information(this, tr("Sprache umgestellt"), tr("Damit die Einstellung wirkt, starten Sie die Anwendung neu"));
}

