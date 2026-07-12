#include "loginwindow.h"
#include "DatabaseManager.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager db;

    if(!db.connectDatabase())
    {
        return -1;
    }

    db.createTables();
    db.createDefaultAdmin();

    LoginWindow w;
    w.show();

    return a.exec();
}