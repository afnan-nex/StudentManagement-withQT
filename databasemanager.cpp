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

    // Students table
    query.exec(
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "age INTEGER,"
        "phone TEXT,"
        "email TEXT"
        ");"
        );

    // Users table
    query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "password TEXT"
        ");"
        );

    qDebug() << "Tables created.";
}

void DatabaseManager::createDefaultAdmin()
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM users");

    if(query.exec())
    {
        query.next();

        if(query.value(0).toInt() == 0)
        {
            QSqlQuery insert;

            insert.prepare(
                "INSERT INTO users(username,password)"
                "VALUES(:username,:password)"
                );

            insert.bindValue(":username", "admin");
            insert.bindValue(":password", "admin123");

            insert.exec();

            qDebug() << "Default admin created.";
        }
    }
}