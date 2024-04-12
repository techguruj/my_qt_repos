#include "form_arbeien.h"
#include "ui_form_arbeien.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include "mydatabase.h"


Form_Arbeien::Form_Arbeien(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_Arbeien)
{
    ui->setupUi(this);
    //qDebug()<<((48&(1<<5 ))!=0);
}

Form_Arbeien::~Form_Arbeien()
{
    delete ui;
}

void Form_Arbeien::on_pushButton_clicked()
{


    QSqlQuery *query2 = new QSqlQuery(MyDatabase::getDatabase());

    qDebug()<<ui->textEdit->toPlainText();

    if(!query2->exec(ui->textEdit->toPlainText()))
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", MyDatabase::getDatabase().lastError().text());
        return;
    }
    query2->first();
    ui->tableWidget_Arbeiten->setRowCount(query2->numRowsAffected());
    ui->tableWidget_Arbeiten->setColumnCount(query2->record().count());

    QStringList header;
    for (int i = 0; i < query2->record().count(); i++)
    {
        header.append(query2->record().fieldName(i));

    }

    ui->tableWidget_Arbeiten->setHorizontalHeaderLabels(header);

    for (int i = 0; i < query2->numRowsAffected(); i++)
    {
        for (int j = 0; j < query2->record().count(); j++)
        {
            ui->tableWidget_Arbeiten->setItem(i, j, new QTableWidgetItem(query2->value(j).toString()));
        }
        query2->next();
    }
}


void Form_Arbeien::on_pushButton_2_clicked()
{
    ui->tableWidget_Arbeiten->clear();

}

