#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::on_show_Data_clicked()
{

    data.close();
       data.removeDatabase("first");

       QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "first");
       database.setDatabaseName("/Users/jblue/Documents/College shit/CS1D/NFL/Project-2-LetsPlayNFLFootball/Project Files/Project2NFL/NFL Information.db");

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


