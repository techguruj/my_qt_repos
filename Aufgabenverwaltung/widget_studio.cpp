#include "widget_studio.h"
#include "ui_widget_studio.h"
#include "database_scheduler.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlRecord>

Widget_Studio::Widget_Studio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_Studio)
{
    ui->setupUi(this);
    setWindowIcon(QIcon (":/pics/mainIconAufgabe.png") );


}

Widget_Studio::~Widget_Studio()
{
    delete ui;
}


void Widget_Studio::on_pushButton_Laden_clicked()
{
    on_pushButton_Leeren_clicked();

    QString tempSql = ui->textEdit->toPlainText();

    if(tempSql.isEmpty())
    {
        QMessageBox::warning(this, "SQL-Abfrage fehlt", "Bitte geben Sie eine SQL-Abfrage ein");
        return;
    }

    if(!tempSql.contains("SELECT", Qt::CaseInsensitive))
    {
        QMessageBox::warning(this, "Fehlerhafte SQL-Abfrage", "Es muss sich um eine SELECT-Abfrage handeln");
        return;
    }

    QSqlQuery *query = new QSqlQuery(Database_Scheduler::getDatabase());

    if(!query->exec(tempSql))
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", "Die Tabelle konnte nicht abgerufen werden");
        return;
    }
    query->first();
    ui->tableWidget->setRowCount(query->numRowsAffected());
    ui->tableWidget->setColumnCount(query->record().count());

    QStringList header;
    for (int i = 0; i < query->record().count(); i++)
    {
        header.append(query->record().fieldName(i));

    }

    ui->tableWidget->setHorizontalHeaderLabels(header);

    for (int i = 0; i < query->numRowsAffected(); i++)
    {
        for (int j = 0; j < query->record().count(); j++)
        {
            if(query->value(j).isNull() )
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(""));
            }
            else if(query->value(j).type() == QVariant::DateTime)
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(query->value(j).toDateTime().toString("dd.MM.yyyy hh:mm:ss")));
            }
            else
            {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(query->value(j).toString()));
            }

        }
        query->next();
    }

    delete query;
}


void Widget_Studio::on_pushButton_Leeren_clicked()
{
    ui->tableWidget->clear();
}

