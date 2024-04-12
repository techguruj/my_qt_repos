#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>

//Singleton Pattern

class MyDatabase
{
public:
    MyDatabase();
    ~MyDatabase();
    static QSqlDatabase& getDatabase();
};

#endif // MYDATABASE_H
