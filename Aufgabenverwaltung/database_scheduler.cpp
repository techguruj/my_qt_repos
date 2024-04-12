#include "database_scheduler.h"
#include <QMessageBox>
#include <QTranslator>
Database_Scheduler::Database_Scheduler() {}

QSqlDatabase &Database_Scheduler::getDatabase()
{
    static QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Sql Server};Server=DESKTOP-PGMFK7D\\SQLEXPRESS;Database=scheduler_jinwen;Trusted_Connection=Yes");
    if(!db.open())
    {
        QMessageBox::critical(nullptr, QObject::tr("Fehler bei DB-Verbindung"), QObject::tr("Datenbank konnte nicht geöffnet werden"));
        exit(0);
    }

    return db;
}
