#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

//const QString filePath = "C:\\Users\\jblue\\Documents\\College shit\\CS1D\\NFL\\Project-2-LetsPlayNFLFootball\\Project Files\\Project2NFL\\NFL Information.db";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));
    ui->actionLogOut->setVisible(false);
}

void MainWindow::on_show_Data_clicked()
{

    data.close();
       data.removeDatabase("first");

       QString filePath = QFileInfo(".").absolutePath();
       filePath += "/Project2NFL/NFL Information.db";

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName(filePath);

       if(database.open())
       {

            QSqlQuery query(database);


            query.prepare(QString("SELECT * FROM Information"));


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
    ui->actionAdmin->setVisible(false);
}

void MainWindow::on_actionLogOut_triggered()
{
    ui->actionAdmin->setVisible(true);
    ui->actionLogOut->setVisible(false);
}
