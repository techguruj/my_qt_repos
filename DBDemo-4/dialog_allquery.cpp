#include "dialog_allquery.h"
#include "ui_dialog_allquery.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include "mydatabase.h"

Dialog_allquery::Dialog_allquery(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_allquery)
{
    ui->setupUi(this);

    QSqlDatabase db = MyDatabase::getDatabase();




}

Dialog_allquery::~Dialog_allquery()
{
    delete ui;
}

void Dialog_allquery::on_pushButton_Run_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(ui->textEdit->toPlainText());

    ui->tableView->setModel(model);
    ui->tableView->show();
}




