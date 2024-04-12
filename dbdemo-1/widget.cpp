#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


    ui->setupUi(this);

    QString connectionString = "Driver={Sql Server};"
                               "Server=DESKTOP-PGMFK7D\\SQLEXPRESS;"
                               "Database=EE_projekte3;"
                               "Trusted_Connection=YES";

    QString sqlStatement= "select * from mitarbeiter";
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QODBC");
    //db->connectOptions();
    db->setDatabaseName(connectionString);
    if(!db->open())
    {

        QMessageBox :: critical(this, "Fehler bei DB-Verbindung", db->lastError().text());
        return;
    }
        qDebug() << "Datenbank geöffnet";


query=new  QSqlQuery(*db);

if(!query->exec(sqlStatement))
{
    QMessageBox :: critical(this, "Fehler bei DB-Verbindung", query->lastError().text());
    return;
}

on_pushButton_First_clicked();
on_pushButton_Viewmode_clicked();

ui->label_lastquery->setText("last query:    "+query->executedQuery());



}
//---------------------------------------------------------------End
Widget::~Widget()
{
    db->close();
    qDebug() << "Datenbank geschliessen";
    delete query;
    delete db;
    delete ui;
}

void Widget::refreshui(int index)
{
query->first();
for(int i=0; i<index; i++)
{
    query->next();
}
refreshui();
}

void Widget::refreshui()
{
    ui->lineEdit_MitarbeiterNr->setText(query->value("m_nr").toString());
    ui->lineEdit_Nachname->setText(query->value("m_name").toString());
    ui->lineEdit_Vorname->setText(query->value("m_vorname").toString());
    ui->lineEdit_AbteilungNr->setText(query->value("m_abt_nr").toString());
}

void Widget::rowlabelupdate()
{
    ui->label_Status->setText("Row: "+QString::number(query->at()+1)+"/"+QString::number(query->numRowsAffected()));
    ui->label_Slider->setText("/"+QString::number(query->numRowsAffected()));
    ui->horizontalSlider->setMaximum(query->numRowsAffected());
    ui->horizontalSlider->setValue(query->at()+1);
    ui->horizontalSlider->setMinimum(1);

    ui->spinBox->setMaximum(query->numRowsAffected());
    ui->spinBox->setMinimum(1);
    ui->spinBox->setValue(query->at()+1);
}

void Widget::on_pushButton_First_clicked()
{
    query->first();
    refreshui();

}


void Widget::on_pushButton_Previous_clicked()
{
    query->previous();
    if(query->at()==-1)
    {
        query->last();
    }
    refreshui();
}



void Widget::on_pushButton_Next_clicked()
{
    query->next();
    if(query->at()==-2)
    {
        query->first();
    }
    refreshui();
}





void Widget::on_pushButton_4_clicked()
{
    query->last();
    refreshui();
}


void Widget::on_pushButton_Abbrechen_clicked()
{
    refreshui();
   on_pushButton_Viewmode_clicked();
}


void Widget::on_pushButton_Viewmode_clicked()
{
    ui->pushButton_Viewmode->setChecked(true);
    ui->pushButton_Neu->setEnabled(false);
    ui->pushButton_Neu->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Speichern->setEnabled(false);
    ui->pushButton_Speichern->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Abbrechen->setEnabled(false);
    ui->pushButton_Abbrechen->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));

    ui->lineEdit_MitarbeiterNr  ->setReadOnly(true);
    ui->lineEdit_Nachname       ->setReadOnly(true);
    ui->lineEdit_Vorname        ->setReadOnly(true);
    ui->lineEdit_AbteilungNr    ->setReadOnly(true);

    ui->pushButton_First->setEnabled(true);
    ui->pushButton_Previous->setEnabled(true);
    ui->pushButton_Next->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

    ui->horizontalSlider->setEnabled(true);
    ui->spinBox         ->setEnabled(true);
    ui->label_Slider    ->setEnabled(true);
}


void Widget::on_pushButton_neumode_clicked()
{
    ui->lineEdit_MitarbeiterNr  ->setReadOnly(false);
    ui->lineEdit_Nachname       ->setReadOnly(false);
    ui->lineEdit_Vorname        ->setReadOnly(false);
    ui->lineEdit_AbteilungNr    ->setReadOnly(false);
    ui->pushButton_Neu->setEnabled(true);
    ui->pushButton_Neu->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Speichern->setEnabled(true);
    ui->pushButton_Speichern->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Abbrechen->setEnabled(true);
    ui->pushButton_Abbrechen->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));

    ui->horizontalSlider->setEnabled(false);
    ui->spinBox         ->setEnabled(false);
    ui->label_Slider    ->setEnabled(false);


    ui->label_Status->setText("");
    ui->pushButton_First->setEnabled(false);
    ui->pushButton_First->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Previous->setEnabled(false);
    ui->pushButton_Previous->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Next->setEnabled(false);
    ui->pushButton_Next->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
}


void Widget::on_pushButton_updatemode_clicked()
{
    ui->lineEdit_MitarbeiterNr  ->setReadOnly(false);
    ui->lineEdit_Nachname       ->setReadOnly(false);
    ui->lineEdit_Vorname        ->setReadOnly(false);
    ui->lineEdit_AbteilungNr    ->setReadOnly(false);
    ui->pushButton_Neu->setEnabled(false);
    ui->pushButton_Neu->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Speichern->setEnabled(false);
    ui->pushButton_Speichern->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton->setEnabled(true);
    ui->pushButton->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));
    ui->pushButton_Abbrechen->setEnabled(true);
    ui->pushButton_Abbrechen->setStyleSheet(QString::fromUtf8("QPushButton:disabled { color: gray }" ));

    ui->horizontalSlider->setEnabled(true);
    ui->spinBox         ->setEnabled(true);
    ui->label_Slider    ->setEnabled(true);

    ui->lineEdit_MitarbeiterNr  ->setReadOnly(true);
    ui->lineEdit_Nachname       ->setReadOnly(true);
    ui->lineEdit_Vorname        ->setReadOnly(true);
    ui->lineEdit_AbteilungNr    ->setReadOnly(true);
}


void Widget::on_lineEdit_MitarbeiterNr_textChanged(const QString &arg1)
{
    rowlabelupdate();
}


void Widget::on_pushButton_Neu_clicked()
{
    ui->lineEdit_MitarbeiterNr->clear();
    ui->lineEdit_Nachname->clear();
    ui->lineEdit_Vorname->clear();
    ui->lineEdit_AbteilungNr->clear();
    ui->lineEdit_MitarbeiterNr->setFocus();


}


void Widget::on_pushButton_Speichern_clicked()
{
    if(ui->lineEdit_MitarbeiterNr->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "MitarbeiterNr darf nicht leer sein");
        return;
    }
    if(ui->lineEdit_Nachname->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "Nachname darf nicht leer sein");
        return;
    }
    if(ui->lineEdit_Vorname->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "Vorname darf nicht leer sein");
        return;
    }
    if(ui->lineEdit_AbteilungNr->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "AbteilungNr darf nicht leer sein");
        return;
    }

    QString sqlStatement;

    sqlStatement="insert into mitarbeiter (m_nr, m_name, m_vorname, m_abt_nr) values ("
                +ui->lineEdit_MitarbeiterNr->text()+", '"
                +ui->lineEdit_Nachname->text()+"', '"
                +ui->lineEdit_Vorname->text()+"', '"
                +ui->lineEdit_AbteilungNr->text()+"')";
qDebug() << sqlStatement;
    if(!query->exec(sqlStatement))
    {
        QMessageBox::critical(this, "Fehler", query->lastError().text());
        return;
    }


    ui->label_lastquery->setText("last query:    "+query->executedQuery());
    delete query;
    query=new  QSqlQuery(*db);
    query->exec("select * from mitarbeiter ");
    on_pushButton_First_clicked();


}

void Widget::on_pushButton_clicked()
{

    if(ui->lineEdit_Nachname->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "Nachname darf nicht leer sein");
        return;
    }
    if(ui->lineEdit_Vorname->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "Vorname darf nicht leer sein");
        return;
    }
    if(ui->lineEdit_AbteilungNr->text().isEmpty())
    {
        QMessageBox::critical(this, "Fehler", "AbteilungNr darf nicht leer sein");
        return;
    }
    QString sqlStatement;

   sqlStatement="update mitarbeiter set m_name='"
                       +ui->lineEdit_Nachname->text()+"', m_vorname='"
                       +ui->lineEdit_Vorname->text()+"', m_abt_nr='"
                       +ui->lineEdit_AbteilungNr->text()+"' where m_nr="
                       +ui->lineEdit_MitarbeiterNr->text();
    qDebug() << sqlStatement;
   if (!query->exec(sqlStatement))
   {
       QMessageBox::critical(this, "Fehler", query->lastError().text());
       return;
   }

   ui->label_lastquery->setText("last query:    "+query->executedQuery());
   query->exec("select * from mitarbeiter ");

}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    refreshui(value-1);
}

