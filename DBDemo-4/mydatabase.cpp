#include "mydatabase.h"

#include <QMessageBox>

MyDatabase::MyDatabase() {}

QSqlDatabase& MyDatabase::getDatabase()
{
    static QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Sql Server};Server=DESKTOP-PGMFK7D\\SQLEXPRESS;Database=EE_projekte3;Trusted_Connection=Yes");
    if(!db.open())
    {
        QMessageBox::critical(nullptr, "Fehler bei DB-Verbindung", "Datenbank konnte nicht geöffnet werden");
        exit(0);
    }

    return db;
}


