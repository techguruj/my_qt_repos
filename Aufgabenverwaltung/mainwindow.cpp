#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSettings>
#include "database_scheduler.h"
#include <QTranslator>
#include <QDateTime>
#include <widget_neu_aufgabe.h>
#include "dialog_getdatetime.h"
#include "widget_edit.h"
#include "widget_studio.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->pushButton_1->setIcon(QIcon(":/pics/right.png"));
    ui->pushButton_2->setIcon(QIcon(":/pics/left.png"));
    ui->pushButton_3->setIcon(QIcon(":/pics/right.png"));
    ui->pushButton_4->setIcon(QIcon(":/pics/left.png"));
    MainWindow::setWindowIcon(QIcon(":/pics/mainIconAufgabe.png"));
    ui->actionDE->setIcon(QIcon(":/pics/DE2.png"));
    ui->actionUS->setIcon(QIcon(":/pics/EN2.png"));
    ui->actionStudio->setIcon(QIcon(":/pics/SQL4.png"));

    languageActionGroup = new QActionGroup(this);
    languageActionGroup->addAction(ui->actionDE);
    languageActionGroup->addAction(ui->actionUS);
    languageActionGroup->setExclusive(true);


    refreschUI();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreschUI()
{
    ui->listWidget_Unerledigt->clear();
    ui->listWidget_InArbeit->clear();
    ui->listWidget_Erledigt->clear();

    //------------------------------Query unerledigte Projekte---------------------------
    QSqlQuery *query_Unerledigt=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query_Unerledigt->exec("SELECT id,aufgabenbezeichnung FROM aufgaben WHERE Stat=0"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query unerledigte Projekte konnte nicht ausgeführt werden"));
        return;
    }

    query_Unerledigt->first();
    for (int i=0;i<query_Unerledigt->numRowsAffected();i++)
    {
        ui->listWidget_Unerledigt->addItem(query_Unerledigt->value(0).toString()+": "+query_Unerledigt->value(1).toString());
        query_Unerledigt->next();
    }

    //------------------------------Query Projekte in Arbeit-----------------------------
    QSqlQuery *query_In_Arbeit=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query_In_Arbeit->exec("SELECT id,aufgabenbezeichnung FROM aufgaben WHERE Stat=1"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query Projekte in Arbeit konnte nicht ausgeführt werden"));
        return;
    }
    query_In_Arbeit->first();
    for (int i=0;i<query_In_Arbeit->numRowsAffected();i++)
    {
        ui->listWidget_InArbeit->addItem(query_In_Arbeit->value(0).toString()+": "+query_In_Arbeit->value(1).toString());
        query_In_Arbeit->next();
    }

    //------------------------------Query erledigte Projekte-----------------------------
    QSqlQuery *query_Erledigt=new QSqlQuery(Database_Scheduler::getDatabase());
    if (!query_Erledigt->exec("SELECT id,aufgabenbezeichnung FROM aufgaben WHERE Stat=2"))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei DB-Verbindung"), tr("Query erledigte Projekte konnte nicht ausgeführt werden"));
        return;
    }
    query_Erledigt->first();
    for (int i=0;i<query_Erledigt->numRowsAffected();i++)
    {
        ui->listWidget_Erledigt->addItem(query_Erledigt->value(0).toString()+": "+query_Erledigt->value(1).toString());
        query_Erledigt->next();
    }
    delete query_Unerledigt;
    delete query_In_Arbeit;
    delete query_Erledigt;
}

void MainWindow::on_pushButton_1_clicked()
{

    if(ui->listWidget_Unerledigt ->selectedItems().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("Bitte wählen Sie eine Aufgabe aus"));
        return;
    }


    Dialog_getDatetime *w=new Dialog_getDatetime(this,"Bitte geben Sie das Startdatum ein");
    w->exec();
    if(w->temp_Datetime.isNull())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("kein Datetime ausgewählt"));
        return;
    }

    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());


    query->prepare("UPDATE aufgaben SET stat=1,beginn=:beginn WHERE id=:id");
    query->bindValue(":beginn", w->temp_Datetime);
    query->bindValue(":id", ui->listWidget_Unerledigt->currentItem()->text().split(":").at(0));


    if (!query->exec())
    {
        QMessageBox::critical(nullptr, tr("Fehler bei sql Syntax"), tr("Update Unerledgit konnte nicht ausgeführt werden"));
        return;
    }

    refreschUI();
    delete query;
    delete w;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->listWidget_InArbeit ->selectedItems().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("Bitte wählen Sie eine Aufgabe aus"));
        return;
    }

    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());
    QString temptext="UPDATE aufgaben SET stat=0,beginn=NULL WHERE id="+ui->listWidget_InArbeit->currentItem()->text().split(":").at(0);
    if (!query->exec(temptext))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei sql Syntax"), tr("Update In Arbeit konnte nicht ausgeführt werden"));
        return;
    }

    refreschUI();
    delete query;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->listWidget_InArbeit ->selectedItems().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("Bitte wählen Sie eine Aufgabe aus"));
        return;
    }

    QSqlQuery *query1=new QSqlQuery(Database_Scheduler::getDatabase());
    QString temptext1="SELECT beginn FROM aufgaben WHERE id="+ui->listWidget_InArbeit->currentItem()->text().split(":").at(0);

    if (!query1->exec(temptext1))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei sql Syntax"), tr("Select beginn konnte nicht ausgeführt werden"));
        return;
    }
    query1->first();

    Dialog_getDatetime *w=new Dialog_getDatetime(this,"Bitte geben Sie das Endedatum ein");
    w->exec();
    if(w->temp_Datetime.isNull())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("kein Datetime ausgewählt"));
    }

    if(w->temp_Datetime<query1->value(0).toDateTime())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Datumseingabe"), tr("Endedatum liegt vor dem Startdatum"));
        return;
    }

    int dauerTage=(w->temp_Datetime.toSecsSinceEpoch()-query1->value(0).toDateTime().toSecsSinceEpoch())/(60 * 60 * 24);

    if(w->temp_Datetime<query1->value(0).toDateTime())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Datumseingabe"), tr("Datum liegt vor dem Startdatum"));
        return;
    }

    QSqlQuery *query2=new QSqlQuery(Database_Scheduler::getDatabase());

    query2->prepare("UPDATE aufgaben SET stat=2,ende=:ende ,dauer=:dauer WHERE id=:id");
    query2->bindValue(":ende", w->temp_Datetime);
    query2->bindValue(":dauer", dauerTage);
    query2->bindValue(":id", ui->listWidget_InArbeit->currentItem()->text().split(":").at(0));

    if (!query2->exec())
    {
        QMessageBox::critical(nullptr, tr("Fehler bei sql Syntax"), tr("Update Erledigt konnte nicht ausgeführt werden"));
        return;
    }

    refreschUI();
    delete query1;
    delete query2;
    delete w;
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->listWidget_Erledigt ->selectedItems().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Fehler bei Auswahl"), tr("Bitte wählen Sie eine Aufgabe aus"));
        return;
    }
    QSqlQuery *query=new QSqlQuery(Database_Scheduler::getDatabase());
    QString temptext="UPDATE aufgaben SET stat=1,ende=NULL, dauer=NULL WHERE id="+ui->listWidget_Erledigt->currentItem()->text().split(":").at(0);
    if (!query->exec(temptext))
    {
        QMessageBox::critical(nullptr, tr("Fehler bei sql Syntax"), tr("Update Erledigt konnte nicht ausgeführt werden"));
        return;
    }

    refreschUI();
    delete query;

}

void MainWindow::on_actionNeu_Aufgabe_triggered()
{
    Widget_Neu_Aufgabe *w=new Widget_Neu_Aufgabe();
    w->show();
}


void MainWindow::on_actionProjekteninfo_triggered()
{
   Widget_Edit *w=new Widget_Edit();
   w->show();
}


void MainWindow::on_actionStudio_triggered()
{
    Widget_Studio *w=new Widget_Studio();
    w->show();
}




void MainWindow::on_actionAktualisierung_triggered()
{
    refreschUI();
    QMessageBox::information(nullptr, tr("Erfolgreich"), tr("Aktualisierung erfolgreich"));
}


void MainWindow::on_actionDE_triggered()
{
    if(translator.load(":/q_de.qm"))
    {
        ui->actionDE->setChecked(true);
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        QSettings *myregistry1 = new QSettings("HKEY_CURRENT_USER\\Software\\QtApp", QSettings::NativeFormat);
        myregistry1->setValue("lang", "de");

    }
}



void MainWindow::on_actionUS_triggered()
{
    if(translator.load(":/q_us.qm"))//
    {
        ui->actionUS->setChecked(true);
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        QSettings *myregistry2 = new QSettings("HKEY_CURRENT_USER\\Software\\QtApp", QSettings::NativeFormat);
        myregistry2->setValue("lang", "us");
    }
}

