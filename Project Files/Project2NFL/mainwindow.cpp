#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "adminwindow.h"

//const QString filePath = "C:\\Users\\jblue\\Documents\\College shit\\CS1D\\NFL\\Project-2-LetsPlayNFLFootball\\Project Files\\Project2NFL\\NFL Information.db";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));
    on_actionLogOut_triggered();
}



void MainWindow::on_show_Teams_clicked()
{

    data.close();
       data.removeDatabase("first");

       QString filePath = QFileInfo(".").absolutePath();
       filePath += "/Project2NFL/nfl.db";

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName(filePath);

       if(database.open())
       {

            QSqlQuery query(database);


            query.prepare(QString("SELECT TeamName FROM teams"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {

                while(query.next())
                {
                    QString teamN = query.value(0).toString();
                    QString stadiumN = query.value(1).toString();
                }

                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);
            }
       }
       else
       {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }

}

void MainWindow::on_show_AFC_Teams_clicked()
{

    data.close();
       data.removeDatabase("first");

       QString filePath = QFileInfo(".").absolutePath();
       filePath += "/Project2NFL/nfl.db";

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName(filePath);

       if(database.open())
       {

            QSqlQuery query(database);


            query.prepare(QString("SELECT StadiumName,SeatingCapacity,Location,Conference,Division,SurfaceType,StadiumRoofType,DateOpened FROM stadiums WHERE Conference LIKE 'American%'"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {

                while(query.next())
                {
                    QString teamN = query.value(0).toString();
                    QString stadiumN = query.value(1).toString();
                }

                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);
            }
       }
       else
       {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }

}

void MainWindow::on_show_NFC_Teams_clicked()
{

    data.close();
       data.removeDatabase("first");

       QString filePath = QFileInfo(".").absolutePath();
       filePath += "/Project2NFL/nfl.db";

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName(filePath);

       if(database.open())
       {

            QSqlQuery query(database);


            query.prepare(QString("SELECT StadiumName,SeatingCapacity,Location,Conference,Division,SurfaceType,StadiumRoofType,DateOpened FROM stadiums WHERE Conference LIKE 'National%'"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {

                while(query.next())
                {
                    QString teamN = query.value(0).toString();
                    QString stadiumN = query.value(1).toString();
                }

                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);
            }
       }
       else
       {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }

}


void MainWindow::on_show_NFCNorth_clicked()
{

    data.close();
       data.removeDatabase("first");

       QString filePath = QFileInfo(".").absolutePath();
       filePath += "/Project2NFL/nfl.db";

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName(filePath);

       if(database.open())
       {

            QSqlQuery query(database);


            query.prepare(QString("SELECT StadiumName,SeatingCapacity,Location,Conference,Division,SurfaceType,StadiumRoofType,DateOpened FROM stadiums WHERE Division LIKE 'NFC  North'"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {

                while(query.next())
                {
                    QString teamN = query.value(0).toString();
                    QString stadiumN = query.value(1).toString();
                }

                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);
            }
       }
       else
       {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAdmin_triggered()
{
    login logWindow;
    connect(&logWindow, &login::userIsAdmin, this, &MainWindow::userIsAdmin);
    logWindow.setModal(true);
    logWindow.exec();
}

void MainWindow::userIsAdmin()
{
    QMessageBox::information(this, "Login", "Username and Password is Correct");

    ui->actionLogOut->setVisible(true);
    ui->actionAdmin_Functions->setVisible(true);
    ui->actionAdmin->setVisible(false);
}

void MainWindow::on_actionLogOut_triggered()
{
    ui->actionAdmin->setVisible(true);
    ui->actionLogOut->setVisible(false);
    ui->actionAdmin_Functions->setVisible(false);
}

void MainWindow::on_actionAdmin_Functions_triggered()
{
    adminWindow aWindow;
    aWindow.setModal(true);
    aWindow.exec();
}
