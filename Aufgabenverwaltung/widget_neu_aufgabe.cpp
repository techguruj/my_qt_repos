#include "widget_neu_aufgabe.h"
#include "ui_widget_neu_aufgabe.h"
#include "widget_neu_aufgabe.h"
#include "database_scheduler.h"
#include <QMessageBox>
#include <QSqlQuery>
Widget_Neu_Aufgabe::Widget_Neu_Aufgabe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_Neu_Aufgabe)
{
    ui->setupUi(this);
    holenNextID();


}

int Widget_Neu_Aufgabe::holenNextID()
{
    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query->exec("SELECT id,aufgabenbezeichnung FROM aufgaben"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query alle Projekte ID konnte nicht ausgeführt werden"));

    }

    query->last();
    ui->spinBox->setValue(query->value(0).toInt()+1);
    return query->value(0).toInt()+1;
    delete query;
}

Widget_Neu_Aufgabe::~Widget_Neu_Aufgabe()
{

    delete ui;
}

void Widget_Neu_Aufgabe::on_spinBox_valueChanged(int arg1)
{
    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query->exec("SELECT id,aufgabenbezeichnung FROM aufgaben"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query alle Projekte ID konnte nicht ausgeführt werden"));
        return;
    }

    query->first();
    for (int i=0;i<query->numRowsAffected();i++)
    {
        if(query->value(0).toInt()==arg1)
        {
            QMessageBox::information(nullptr, tr("Fehler bei ID Eingabe"), tr("ID schon vergeben"));
            holenNextID();
            break;
        }
        query->next();
    }


}




void Widget_Neu_Aufgabe::on_pushButton_Speichern_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte geben Sie eine Aufgabenbezeichnung ein");
        return;
    }
    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query->exec("INSERT INTO aufgaben (id,aufgabenbezeichnung,Stat) VALUES ("+QString::number(ui->spinBox->value())+",'"+ui->lineEdit->text()+"',0)"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query Speichern konnte nicht ausgeführt werden"));
        return;
    }
    else
    {
        QMessageBox::information(nullptr, tr("Erfolg"), tr("Aufgabe erfolgreich gespeichert"));
        holenNextID();
        ui->lineEdit->clear();
    }


}


void Widget_Neu_Aufgabe::on_lineEdit_editingFinished()
{
    QString inputString = ui->lineEdit->text();
    QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$");
    QRegularExpressionMatch match = muster.match(inputString);
    if(!match.hasMatch())
    {
        QMessageBox::warning(this, "Fehler", "Bezeichnung muss aus einem Kleinbuchstabenbestehen");

        return ;
    }
}


