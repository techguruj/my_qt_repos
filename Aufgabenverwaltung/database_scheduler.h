#ifndef DATABASE_SCHEDULER_H
#define DATABASE_SCHEDULER_H
#include <QDatetime>
#include <QSqlDatabase>

class Database_Scheduler
{
public:
    Database_Scheduler();
    static QSqlDatabase& getDatabase();

};

#endif // DATABASE_SCHEDULER_H
