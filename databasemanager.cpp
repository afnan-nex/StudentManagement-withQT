#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>

DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::connectDatabase()
{
    // Create the database in the same folder as the executable
    QString dbPath = QCoreApplication::applicationDirPath() + "/student.db";

    qDebug() << "Database Path:" << dbPath;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (db.open())
    {
        qDebug() << "Database Connected";
        return true;
    }
    else
    {
        qDebug() << "Database Error:" << db.lastError().text();
        return false;
    }
}

void DatabaseManager::createTables()
{
    QSqlQuery query;

    if(query.exec(
            "CREATE TABLE IF NOT EXISTS students ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT NOT NULL,"
            "age INTEGER,"
            "phone TEXT,"
            "email TEXT"
            ");"))
    {
        qDebug() << "Students table created successfully.";
    }
    else
    {
        qDebug() << "Table Creation Error:" << query.lastError().text();
    }
}