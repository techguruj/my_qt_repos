#include "dialog_abteilung.h"
#include "ui_dialog_abteilung.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QInputDialog>
#include "mydatabase.h"

Dialog_Abteilung::Dialog_Abteilung(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_Abteilung)
{
    ui->setupUi(this);
    QSqlDatabase db = MyDatabase::getDatabase();

    relational_tabelmodel = new QSqlRelationalTableModel(this,db);
    relational_tabelmodel->setTable("abteilung");
    relational_tabelmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    QItemSelectionModel *selectionModel = new QItemSelectionModel(relational_tabelmodel,this);
    ui->tableView->setModel(relational_tabelmodel);
    ui->tableView->setSelectionModel(selectionModel);

    // tabelmodel->setRelation(tabelmodel->fieldIndex("m_abt_nr"),QSqlRelation("abteilung","abt_nr","abt_nr"));
    // ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    relational_tabelmodel->select();
}

Dialog_Abteilung::~Dialog_Abteilung()
{
    delete ui;
}

bool Dialog_Abteilung::on_tableView_doubleClicked(const QModelIndex &index)
{
    origialText = index.data().toString();
    switch (index.column())
    {
    case 0:
    {   QString inputString0 = QInputDialog::getText(this, "Eingabe Dialog", "Zeile: "+ QString::number(index.row()+1)+" Eingabe AbteilungNr.:");
        QRegularExpression muster("^[a-z][0-9]$");
        QRegularExpressionMatch match = muster.match(inputString0);
        if(!match.hasMatch())
        {
            QMessageBox::warning(this, "Fehler", "Abteilungsnummer muss aus einem Kleinbuchstaben und einer Zahl bestehen");

            return 0;
        }
        for (int i = 0; i < relational_tabelmodel->rowCount()-1 ; ++i)
        {
            if(i==index.row())
            {
                continue;
            }
            if(inputString0 == relational_tabelmodel->record(i).value("abt_nr").toString())
            {
                QMessageBox::warning(this, "Fehler", "Abteilungsnummer schon vorhanden");
                return 0;
            }
        }

        ui->tableView->model()->setData(index, inputString0);
        return 1;
    }

    case 1:
    {   QString inputString1 = QInputDialog::getText(this, "Eingabe Dialog", "Zeile: "+ QString::number(index.row()+1)+" Eingabe AbteilungName:");
        QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$");
        QRegularExpressionMatch match = muster.match(inputString1);
        if(!match.hasMatch())
        {
            QMessageBox::warning(this, "Fehler", "Abteilungsname muss mit einem Großbuchstaben beginnen");
            return 0;
        }
        for (int i = 0; i < relational_tabelmodel->rowCount() ; ++i)
        {
            if(i==index.row())
            {
                continue;
            }
            if(inputString1 == relational_tabelmodel->record(i).value("abt_name").toString())
            {
                QMessageBox::warning(this, "Fehler", "Abteilungsname schon vorhanden");
                return 0;
            }
        }
        ui->tableView->model()->setData(index, inputString1);
        return 1;
    }

    case 2:
    {   QString inputString2 = QInputDialog::getText(this, "Eingabe Dialog", "Zeile: "+ QString::number(index.row()+1)+" Eingabe AbteilungStadt:");
        QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$|^$");
        QRegularExpressionMatch match = muster.match(inputString2);
        if(!match.hasMatch())
        {
            QMessageBox::warning(this, "Fehler", "Stadtname muss mit einem Großbuchstaben beginnen");
            return 0;
        }


        ui->tableView->model()->setData(index, inputString2);
        return 1;
    }

    default:
        break;
    }


}

void Dialog_Abteilung::on_pushButton_clicked()
{
    relational_tabelmodel->insertRow(relational_tabelmodel->rowCount());
    bool ok;
    ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,0));
    while (!ok) ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,0));

    ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,1));
    while (!ok) ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,1));

    ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,2));
    while (!ok) ok=on_tableView_doubleClicked(relational_tabelmodel->index(relational_tabelmodel->rowCount()-1,2));
}

void Dialog_Abteilung::on_pushButton_2_clicked()
{
    if(!relational_tabelmodel->submitAll())
    {
        QMessageBox::critical(this, "Fehler", "Daten konnten nicht gespeichert werden");
        qDebug() << "Fehlermeldung: " << relational_tabelmodel->lastError().text();
    }
    else
    {
        QMessageBox::information(this, "Erfolg", "Daten erfolgreich gespeichert");
    }
}

