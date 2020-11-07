#include "database.h"

Database* Database::instance = nullptr;

Database::Database() : QSqlDatabase(addDatabase("QSQLITE"))
{
    this->setDatabaseName(qApp->applicationDirPath()
                          + QDir::separator()
                          + "nfl.db");
    QFileInfo databaseInfo(qApp->applicationDirPath()
                          + QDir::separator()
                          + "nfl.db");
    qDebug() << "database path:" << qApp->applicationDirPath()
                              + QDir::separator()
                              + "nfl.db";
   if (databaseInfo.exists())
   {
        qDebug() << "Database file is open.\n";
        this->open();
        QSqlQuery query;
        query.prepare("PRAGMA foreign_keys = ON");
        query.exec();
    }
    else
    {
        qDebug() << "Database file is not open.\n";
    }
}

Database* Database::getInstance()
{
    if(instance == nullptr)
        instance = new Database;
     return instance;
}
