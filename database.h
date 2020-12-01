#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QDir>
//#include <strings.h>

#include <QFileInfo>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QtDebug>
#include <QSqlTableModel>


/**
 * @brief The Database class
 * is used to access the database to use in the program
 */
class Database: public QSqlDatabase
{
public:
    /**
     * @brief Function to return the database instance
     * @return the database pointer instance to the project sql database
     */
    static Database* getInstance();

private:
    /**
     * @brief Class constructor
     *
     * Set the path and open the database file for the program
     */
    Database();
    static Database* instance;

};

#endif // DATABASE_H
