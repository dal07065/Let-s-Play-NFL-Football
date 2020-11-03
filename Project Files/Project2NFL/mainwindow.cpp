#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    unicorn::Team::initializeTeams();
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));
    ui->actionLogOut->setVisible(false);


    for (auto it = Team::teams.begin(); it != Team::teams.end(); ++it) {
        qDebug() << it->getTeamId()<< QString::fromStdString( it->getTeamName()) ;
        vector<Distance> distanceV= it->getTeamStadium().getDistanceFromOthers();
         vector<SouvenirType> souv= it->getSouvenirType();


        qDebug() <<"--------Distances--------";
        for (auto it2= distanceV.begin(); it2 !=  distanceV.end(); ++it2) {

             qDebug() << QString::fromStdString(it2->OtherStaduimName)
                      << it2->OtherStaduimID
                      <<  it2->distance;
         }
         qDebug() <<"--------Souviner--------";

         for (auto it3= souv.begin(); it3 !=  souv.end(); ++it3) {

              qDebug() << QString::fromStdString(it3->SouvenirName)
                       << it3->souvenirID
                       <<  it3->TeamID
                       <<  it3->price;
          }

        qDebug() <<"--------END Team--------";
    }
}



void MainWindow::on_show_Teams_clicked()
{



            QSqlQuery query;
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

void MainWindow::on_show_AFC_Teams_clicked()
{



            QSqlQuery query;


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

void MainWindow::on_show_NFC_Teams_clicked()
{


            QSqlQuery query;


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


void MainWindow::on_show_NFCNorth_clicked()
{



            QSqlQuery query;


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

void MainWindow::on_pushButton_clicked()
{
     CustomVacation *vacWindow = new CustomVacation();
     vacWindow->show();

}
