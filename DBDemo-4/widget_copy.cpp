#include "widget_copy.h"
#include "ui_widget_copy.h"
#include "mitarbeiter.h"

Widget_copy::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_copy)
{
    ui->setupUi(this);

    //Verbindungsangaben zur Datenbankverbindung in eimen String ablegen
    QString connectionString    =  "Driver={Sql Server};"
                                   "Server=DESKTOP-PGMFK7D\\SQLEXPRESS;"
                                   "Database=EE_projekte3;"
                                   "Trusted_Connection=Yes";

    query = nullptr;            //Wird erst später gebraucht

    db = new QSqlDatabase;      //Datenbankverbindung vorbereiten
    *db = QSqlDatabase::addDatabase("QODBC");

    db->connectOptions();
    db->setDatabaseName(connectionString);
    if(!db->open())             //Datenbank verbinden
    {
        QMessageBox::critical(this, "Fehler bei DB-Verbindung", "Datenbank konnte nicht geöffnet werden\Ist der Name korrekt?");  //Wenn es schief geht...
        qDebug() << "Fehlermeldung der DB: " << db->lastError().text();
        QApplication::beep();
        return;
    }
    qDebug() << "Datenbank geöffnet";
    holeDaten();                //Daten einlesen (von Datenbank)


}

Widget_copy::~Widget_copy()
{
    delete query;                   //Objekte freigeben (Speicher löschen)
    db->close();
    qDebug() << "Datenbank geschlossen";
    delete db;

    delete ui;
}

//----------------------------------------------------------NAVIGATION DURCH DIE DATENSÄTZE; DIE () IM QUERY LIEGEN
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

//----------------------------------------------------------BILDSCHIRMELEMENTE MIT DATEN DES AKTUELLEN DATENSATZES BEFÜLLEN
void Widget::refreshUi()
{
    ui->leMNr       ->setText(query->value("m_nr").toString());
    ui->leMNachname ->setText(query->value("m_name").toString());
    ui->leMVorname  ->setText(query->value("m_vorname").toString());
    ui->leMAbtNr    ->setText(query->value("m_abt_nr").toString());
    ui->comboBox->setCurrentText(query->value("m_abt_nr").toString());

    ui->lblPosition->setText("DS: " +QString::number(_currentrecord) + " / " + QString::number(_numrecords));
    switchButtons(TastenKombi::normal);


}

//----------------------------------------------------------DATENMANIPULATIONEN
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

        mitarbeiter->saveData(db, _modus);  //Weise das Objekt an sich zu speichern
        _modus = Modus::neutral;            //Daten als aktuell setzen
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
    refreshUi();                                //Alles wieder herstellen
    ui->leMNr->setReadOnly(true);
    _modus = Modus::neutral;
    switchButtons(TastenKombi::normal);
}

//----------------------------------------------------------BUTTONS EIN-/AUSSCHALTEN
void Widget::on_leMNachname_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);           //In den Editiermodus wechseln. (Button Speichern und Cancel aktivieren)
}

void Widget::on_leMVorname_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);
}


void Widget::on_leMAbtNr_textChanged(const QString &arg1)
{
    switchButtons(TastenKombi::edit);
}


void Widget::switchButtons(TastenKombi kombi)   //Buttons vom höchsten bis kleinsten Wert (Enum Tasten) durchlaufen,
{                                               //abfragen und ggf. aktivieren
    int k = (int) kombi;
    switchButtonsOff();         //Erst mal alle Buttons deaktivieren
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

void Widget::switchButtonsOff()     //Alle Buttons deaktivieren
{
    ui->btnFirst    ->setEnabled(false);
    ui->btnPrevious ->setEnabled(false);
    ui->btnNext     ->setEnabled(false);
    ui->btnLast     ->setEnabled(false);
    ui->btnNew      ->setEnabled(false);
    ui->btnSave     ->setEnabled(false);
    ui->btnCancel   ->setEnabled(false);
}

//----------------------------------------------------------DATEN VON DATENBANK EINLESEN
void Widget::holeDaten()
{
    QString sqlStatement        = "select * from mitarbeiter";
    //Query mit Datenbank verbinden
    query = new QSqlQuery(*db);     //query erstellen und mit Datenbank verbinden

    //Abfrage an DB senden
    if(!query->exec(sqlStatement))          //SQL-Anweisung ausführen (s. Zeile 235)
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", db->lastError().text());
        return;
    }
    _numrecords = query->numRowsAffected();     //Merke dir, wie viele DS gelesen wurden
    qDebug() << query->numRowsAffected();       //Kontrollausgabe

    QSqlQuery *query2 = new QSqlQuery(*db);
    if(!query2->exec("select * from abteilung"))
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", db->lastError().text());
        return;
    }
    query2->first();
    for (int i = 0; i < query2->numRowsAffected()  ; ++i)
    {
        ui->comboBox->addItem(query2->value("abt_nr").toString());
        query2->next();
    }

    _currentrecord = 0;
    on_btnFirst_clicked();                      //Auf ersten Datensatz positionieren
    ui->leMNr->setReadOnly(true);               //Primärschlüssel schützen


}




void Widget::on_pushButton_zuAbteilung_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

   QSqlQuery *query2 = new QSqlQuery(*db);
   qDebug() << "SELECT * FROM abteilung where abt_nr = '" + ui->leMAbtNr->text() +"'";
    if(!query2->exec("SELECT * FROM abteilung where abt_nr = '" + ui->leMAbtNr->text() +"'" ))
    {
        QMessageBox::warning(this, "Zugriff auf Tabelle fehlgeschlagen", db->lastError().text());
        return;
    }
    query2->first();

    ui->lineEdit_AbteilungNr->setText(query2->value("abt_nr").toString());
    ui->lineEdit_AbteilungName->setText(query2->value("abt_name").toString());
    ui->lineEdit_AbteilungStadt->setText(query2->value("abt_stadt").toString());

    ui->label_AbteilungLastqeury->setText("Last Query:     "+query2->lastQuery());


}


void Widget::on_pushButton_zuMitarbeiter_clicked()
{
     ui->tabWidget->setCurrentIndex(0);
}


void Widget::on_pushButton_ZuFormArbeiten_clicked()
{
//Form_Arbeien *form_arbeiten = new Form_Arbeien(nullptr, db, "select * from arbeiten join projekt on arb_pr_nr=pr_nr");
//form_arbeiten->show();
}


