#include "widget_edit.h"
#include "ui_widget_edit.h"
#include "database_scheduler.h"
#include "dialog_getdatetime.h"

#include <QMessageBox>
#include <QDateTimeEdit>
#include <QInputDialog>

Widget_Edit::Widget_Edit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_Edit)
{
    ui->setupUi(this);

    relationalmodel = new QSqlRelationalTableModel(this, Database_Scheduler::getDatabase());
    relationalmodel->setTable("aufgaben");
    relationalmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    selectionModel = new QItemSelectionModel(relationalmodel,this);
    ui->tableView->setModel(relationalmodel);
    ui->tableView->setSelectionModel(selectionModel);



    relationalmodel->setRelation(relationalmodel->fieldIndex("stat"), QSqlRelation("status", "status_id", "status_name"));
    relationalmodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    relationalmodel->setHeaderData(1, Qt::Horizontal, tr("Projektname"));
    relationalmodel->setHeaderData(2, Qt::Horizontal, tr("Dauer"));
    relationalmodel->setHeaderData(3, Qt::Horizontal, tr("Startdatum"));
    relationalmodel->setHeaderData(4, Qt::Horizontal, tr("Enddatum"));
    relationalmodel->setHeaderData(5, Qt::Horizontal, tr("Status"));
    relationalmodel->setHeaderData(6, Qt::Horizontal, tr("Bemerkung"));


    relationalmodel->select();

    ui->tableView->setColumnHidden(2,true);  //hidden Spalt stat
    ui->tableView->setColumnHidden(4,true);  //hidden Spalt EndeDatum
    for (int i = 0; i < ui->tableView->model()->rowCount() ; ++i)
    {
        if(ui->tableView->model()->data(ui->tableView->model()->index(i,5))=="erledigt")
        {
            ui->tableView->setRowHidden(i,true);
        }

    }
}

Widget_Edit::~Widget_Edit()
{
    delete ui;
}

void Widget_Edit::on_pushButton_Hochladen_clicked()
{
    if(!relationalmodel->isDirty())
    {
        QMessageBox::information(this, tr("Keine Änderungen"), tr("Keine Änderungen zum Hochladen"));
        return;
    }

    if (relationalmodel->submitAll())
    {
        QMessageBox::information(this, tr("Erfolgreich"), tr("Änderungen wurden gespeichert"));
    }
    else
    {
        QMessageBox::critical(this, tr("Fehler"), tr("Änderungen konnten nicht gespeichert werden"));
    }

}




void Widget_Edit::on_pushButton_UndoAll_clicked()
{
    relationalmodel->revertAll();
}


void Widget_Edit::on_tableView_doubleClicked(const QModelIndex &index)
{
    switch (index.column())
    {
    case 0:
    {
        QMessageBox::information(this, tr("ID"), tr("ID kann nicht geändert werden"));
        return;
    }

    case 1:
    {
        QString inputString1 = QInputDialog::getText(this, "Eingabe Dialog", "Zeile: "+ QString::number(index.row()+1)+",  Eingabe Projekt Name:");

        if(inputString1.isEmpty()& (!ui->tableView->model()->data(index).toString().isEmpty())) return;

        QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$");
        QRegularExpressionMatch match = muster.match(inputString1);
        if(!match.hasMatch())
        {
            QMessageBox::warning(this, "Fehler", "Projekt Name muss mit einem Großbuchstaben beginnen");
            return ;
        }
        ui->tableView->model()->setData(index, inputString1);

        return;
    }

    case 3:
    {

        if(ui->tableView->model()->data(index).toDateTime().isNull())
        {
            QMessageBox::information(this, tr("Fehler"), tr("Projekt kann nur durch Haupt Menü initialisiert werden"));
            return;
        }


            Dialog_getDatetime *w=new Dialog_getDatetime(this,"Bitte ändern Sie das Startdatum ab");
            w->exec();
            if(w->temp_Datetime.isNull()) return;

            ui->tableView->model()->setData(index, w->temp_Datetime);

            delete w;
            return;
    }

    case 5:
        QMessageBox::information(this, tr("Status"), tr("Status kann nicht geändert werden"));
        return;

    case 6:
    {
        QString inputString6 = QInputDialog::getText(this, "Eingabe Dialog", "Zeile: "+ QString::number(index.row()+1)+", Eingabe Bemerkung:");
        if(inputString6.isEmpty()& (!ui->tableView->model()->data(index).toString().isEmpty())) return;
        ui->tableView->model()->setData(index, inputString6);
        return;
    }

    default:
        return;
    }
}


void Widget_Edit::on_pushButton_Beenden_clicked()
{
    this->close();

}

