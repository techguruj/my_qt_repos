#ifndef MITARBEITER_H
#define MITARBEITER_H

#include <QString>
#include "enums.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include "widget.h"

class Mitarbeiter
{
    int     _m_nr;
    QString _nachname;
    QString _vorname;
    QString _abt_nr;
public:
    Mitarbeiter();
    Mitarbeiter(int m_nr, QString nachname, QString vorname, QString abt_nr);
    Mitarbeiter(int m_nr, QString nachname, QString vorname);

    void    setMNr(int value);
    void    setNachname(QString value);
    void    setVorname(QString value);
    void    setAbtNr(QString value);

    int     getMNr()        const { return _m_nr;     }
    QString getNachname()   const { return _nachname; }
    QString getVorname()    const { return _vorname;  }
    QString getAbt_Nr()     const { return _abt_nr;   }

    void    saveData(QSqlDatabase *db, Modus modus)      const;

};

#endif // MITARBEITER_H
