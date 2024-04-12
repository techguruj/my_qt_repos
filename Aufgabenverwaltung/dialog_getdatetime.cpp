#include "dialog_getdatetime.h"
#include "ui_dialog_getdatetime.h"

#include <QMessageBox>


Dialog_getDatetime::Dialog_getDatetime(QWidget *parent, QString anweisung)
    : QDialog(parent)
    , ui(new Ui::Dialog_getDatetime)
{
    ui->setupUi(this);
    temp_Datetime = QDateTime();//Constructs a null datetime
    setWindowIcon(QIcon(":/pics/datetime.png"));

    ui->label->setText(anweisung);
    on_pushButton_Jetzt_clicked();

}

Dialog_getDatetime::~Dialog_getDatetime()
{
    delete ui;
}





void Dialog_getDatetime::on_pushButton_Jetzt_clicked()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}


void Dialog_getDatetime::on_pushButton_Uebernehmen_clicked()
{
    if(ui->dateTimeEdit->dateTime()<QDateTime::currentDateTime())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Datumseingabe"), tr("Datum liegt in der Vergangenheit"));
        return;
    }
    temp_Datetime=ui->dateTimeEdit->dateTime();
    this->close();
}

