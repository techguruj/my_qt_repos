#include "mitarbeiter.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
//#include <QException>
#include <QCoreApplication>


//----------------------------------------------------------KONSTRUKTOREN
Mitarbeiter::Mitarbeiter()
{

}

Mitarbeiter::Mitarbeiter(int m_nr, QString nachname, QString vorname, QString abt_nr)
{
    setMNr(m_nr);                           //Daten durch die setter schicken, um diese zuu überprüfen
    setNachname(nachname);
    setVorname(vorname);
    setAbtNr(abt_nr);
}

Mitarbeiter::Mitarbeiter(int m_nr, QString nachname, QString vorname)
    : Mitarbeiter(m_nr, nachname, vorname, "")
{ }

//----------------------------------------------------------SETTER

void Mitarbeiter::setMNr(int value)
{
    if(value > 1000 && value < 30000)
    {
        _m_nr = value;
    }
    else
    {
        throw std::invalid_argument("Mitarbeiternummer ungültig");
    }
}

void    Mitarbeiter::setNachname(QString value)
{
    QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$");
    QRegularExpressionMatch match = muster.match(value);
    if(match.hasMatch())
    {
        _nachname = value;
    }
    else
    {
        throw std::invalid_argument("Nachname Ungültig");
    }
}

void    Mitarbeiter::setVorname(QString value)
{
    QRegularExpression muster("^([A-ZÄÖÜ][a-zäöüß]*|^[A-ZÄÖÜ][a-zäöüß]*[- ]{1}[A-ZÄÖÜ][a-zäöüß]*)$");
    QRegularExpressionMatch match = muster.match(value);
    if(match.hasMatch())
    {
        _vorname = value;
    }
    else
    {
        throw std::invalid_argument("Vorname Ungültig");
    }
}

void    Mitarbeiter::setAbtNr(QString value)
{
    QRegularExpression muster("^[a-z][0-9]$");
    QRegularExpressionMatch match = muster.match(value);
    if(match.hasMatch())
    {
        _abt_nr = value;
    }
    else
    {
        throw std::invalid_argument("Abteilungsnummer Ungültig");
    }
}

void Mitarbeiter::saveData(QSqlDatabase *db, Modus modus) const //Objekt soll sich selbst speichern
{
    QString sqlStatement = "";
    qDebug() << modus;
    if(modus == Modus::neu)                 //SQL-String vorbereiten
    {
        sqlStatement = "insert into mitarbeiter values( ";
        sqlStatement +=         QString::number(_m_nr) + ", ";
        sqlStatement += "'" +   _nachname + "', ";
        sqlStatement += "'" +   _vorname  + "', ";
        sqlStatement += "'" +   _abt_nr    + "');";
    }
    else //if(_modus == Modus::update)
    {
        sqlStatement = "update mitarbeiter set ";
        sqlStatement += "m_name = '"        + _nachname   + "', ";
        sqlStatement += "m_vorname = '"     + _vorname    + "', ";
        sqlStatement += "m_abt_nr = '"      + _abt_nr     + "' ";
        sqlStatement += "where m_nr = "    + QString::number(_m_nr) + ";";
    }
    qDebug() << sqlStatement;

    QSqlQuery *query = new QSqlQuery(*db);      //SQL-String an die DB senden
    if(!query->exec(sqlStatement))
    {
        qDebug() << query->lastError();
        throw std::runtime_error( "Fehler beim Speichern in der Datenbank");
    }
    else
    {

    }
}
