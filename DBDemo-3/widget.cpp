#include "widget.h"
#include "ui_widget.h"
#include "mitarbeiter.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString connectionString    =  "Driver={Sql Server};"
                                   "Server=DESKTOP-PGMFK7D\\SQLEXPRESS;"
                                   "Database=EE_projekte3;"
                                   "Trusted_Connection=Yes";

    query = nullptr;

    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QODBC");

    db->connectOptions();
    db->setDatabaseName(connectionString);
    if(!db->open())
    {
        QMessageBox::critical(this, "Fehler bei DB-Verbindung", db->lastError().text());
        QApplication::beep();
        return;
    }
    qDebug() << "Datenbank geöffnet";
    holeDaten();

    ui->
}

Widget::~Widget()
{
    delete query;
    db->close();
    qDebug() << "Datenbank geschlossen";
    delete db;

    delete ui;
}


void Widget::on_btnFirst_clicked()
{
    _currentrecord = 1;
    query->first();
    refreshUi();
}


void Widget::on_btnPrevious_clicked()
{
    query->previous();
    _currentrecord--;
    if(_currentrecord <= 0)
    {
        QMessageBox::information(this, "Navigation nicht möglich", "Cursor befindet sich bereits auf dem ersten Datensatz");
        QApplication::beep();
        _currentrecord++;
        query->first();
        return;
    }
    refreshUi();
}


void Widget::on_btnNext_clicked()
{
    query->next();
    _currentrecord++;
    if(_currentrecord > _numrecords)
    {
        QMessageBox::information(this, "Navigation nicht möglich", "Cursor befindet sich bereits auf dem letzten Datensatz");
        QApplication::beep();
        _currentrecord--;
        query->last();
        return;
    }
    refreshUi();
}


void Widget::on_btnLast_clicked()
{
    query->last();
    _currentrecord = _numrecords;
    refreshUi();
}

void Widget::refreshUi()
{
    ui->leMNr       ->setText(query->value("m_nr").toString());
    ui->leMNachname ->setText(query->value("m_name").toString());
    ui->leMVorname  ->setText(query->value("m_vorname").toString());
    ui->leMAbtNr    ->setText(query->value("m_abt_nr").toString());

    ui->lblPosition->setText("DS: " +QString::number(_currentrecord) + " / " + QString::number(_numrecords));
    switchButtons(TastenKombi::normal);


}

void Widget::on_btnNew_clicked()
{
    ui->leMNr       ->clear();
    ui->leMNachname ->clear();
    ui->leMVorname  ->clear();
    ui->leMAbtNr    ->clear();
    ui->leMNr       ->setFocus();
    ui->leMNr       ->setReadOnly(false);
    _modus = Modus::neu;
    switchButtons(TastenKombi::edit);
}


void Widget::on_btnSave_clicked()
{
    Mitarbeiter *mitarbeiter;
    try
    {
        //Erstelle ein Mitarbeiter-Objekt und übergebe die Bildschirmfeld-Daten an den Konstruktor
        mitarbeiter = new Mitarbeiter(      ui->leMNr->text().toInt(),
                                            ui->leMNachname->text(),
                                            ui->leMVorname->text(),
                                            ui->leMAbtNr->text());
        //Weise das Objekt an sich zu speichern
        mitarbeiter->saveData(db, _modus);
        _modus = Modus::neutral;
        //Erfolgsausgabe???
        holeDaten();                            //Was, wenn hier beim Speichern etwas schief geht?
        switchButtons(TastenKombi::normal);
    }
    catch (std::invalid_argument ex)
    {
        QMessageBox::warning(this, "Eingabefehler", ex.what() );
        QApplication::beep();
    }
    catch(std::runtime_error ex)
    {
        QMessageBox::warning(this, "Fehler beim Speichern", ex.what() );
        QApplication::beep();
    }
    catch(...)
    {
        //Evtl. DB-Fehler auffangen
        QMessageBox::warning(this, "Fehler in Datenbank", "Datenbank hat einen Fehler gemeldet\nBitte wenden Sie sich an Ihren Administrator");
        QApplication::beep();
    }
}

void Widget::on_btnCancel_clicked()
{
    refreshUi();
    ui->leMNr->setReadOnly(true);
    _modus = Modus::neutral;
    switchButtons(TastenKombi::normal);
}

void Widget::on_leMNachname_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);
}

void Widget::on_leMVorname_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);
}


void Widget::on_leMAbtNr_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);
}

void Widget::holeDaten()
{
    QString sqlStatement        = "select * from mitarbeiter";
    //Query mit Datenbank verbinden
    query = new QSqlQuery(*db);

    //Abfrage an DB senden
    if(!query->exec(sqlStatement))
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", db->lastError().text());
        return;
    }
    _numrecords = query->numRowsAffected();     //Merke dir, wie viele DS gelesen wurden
    qDebug() << query->numRowsAffected();

    _currentrecord = 0;
    on_btnFirst_clicked();
    ui->leMNr->setReadOnly(true);

}

void Widget::switchButtons(TastenKombi kombi)
{
    int k = (int) kombi;
    switchButtonsOff();
    if(k >= Tasten::e_cancel)
    {
        ui->btnCancel->setEnabled(true);
        k -= Tasten::e_cancel;
    }
    if(k >= Tasten::e_save)
    {
        ui->btnSave->setEnabled(true);
        k -= Tasten::e_save;
    }
    if(k >= Tasten::e_new)
    {
        ui->btnNew->setEnabled(true);
        k -= Tasten::e_new;
    }
    if(k >= Tasten::e_last)
    {
        ui->btnLast->setEnabled(true);
        k -= Tasten::e_last;
    }
    if(k >= Tasten::e_next)
    {
        ui->btnNext->setEnabled(true);
        k -= Tasten::e_next;
    }
    if(k >= Tasten::e_prevoius)
    {
        ui->btnPrevious->setEnabled(true);
        k -= Tasten::e_prevoius;
    }
    if(k >= Tasten::e_first)
    {
        ui->btnFirst->setEnabled(true);
        k -= Tasten::e_first;
    }
}

void Widget::switchButtonsOff()
{
    ui->btnFirst    ->setEnabled(false);
    ui->btnPrevious ->setEnabled(false);
    ui->btnNext     ->setEnabled(false);
    ui->btnLast     ->setEnabled(false);
    ui->btnNew      ->setEnabled(false);
    ui->btnSave     ->setEnabled(false);
    ui->btnCancel   ->setEnabled(false);
}






