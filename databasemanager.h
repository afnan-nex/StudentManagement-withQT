#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager();

    bool connectDatabase();
    void createTables();

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H