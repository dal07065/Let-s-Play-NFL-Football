#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "adminwindow.h"
#include "team.h"
#include <QStyle>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    unicorn::Team::initializeTeams();
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/img/unicorn.png"));
    QFile styleSheet(qApp->applicationDirPath()
                     + QDir::separator()
                     +"style.qss");

    if (!styleSheet.open(QIODevice::ReadWrite)) {
        qWarning("Unable to open :/style.qss");
        return;
    }
    qApp->setStyleSheet(styleSheet.readAll());

    on_actionLogOut_triggered();
    ui->actionLogOut->setVisible(false);



//    Team* ptr = Team::teamsBSTMap.getTreeNodes();
//    Team::teamsBSTMap.display();
//    int max = Team::teamsBSTMap.getBSTSize();

//        for(int i=0;i<max;i++)
//        {


//                   std::cout <<"--------Team start here--------"<<endl;
//                   std::cout<< (*(ptr+i)).getTeamId() << (*(ptr+i)).getTeamName()<<endl;
//                   vector<Distance*> distanceV= (*(ptr+i)).getTeamStadium()->getDistanceFromOthers();
//                           vector<SouvenirType*> souv= (*(ptr+i)).getSouvenirType();


//                          std::cout <<"--------Distances--------"<<endl;
//                          for (auto it2= distanceV.begin(); it2 !=  distanceV.end(); ++it2) {


//                               std::cout << (*it2)->OtherStaduimName
//                                        << (*it2)->OtherStaduimID
//                                        <<  (*it2)->distance<<endl;
//                           }
//                           std::cout <<"--------Souviner--------"<<endl;

//                           for (auto it3= souv.begin(); it3 !=  souv.end(); ++it3) {

//                                std::cout  << (*it3)->SouvenirName
//                                         << (*it3)->souvenirID
//                                         <<  (*it3)->TeamID
//                                         <<  (*it3)->price<<endl;
//                            }
//                    std::cout <<"--------Team end here--------"<<endl<<endl;
//        }


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

void MainWindow::on_show_Stadiums_clicked()
{
    QSqlQuery query;


    query.prepare(QString("SELECT stadiums.StadiumName, teams.TeamName, teams.StadiumID FROM stadiums INNER JOIN TeamName ON teams.StadiumID=stadiums._id"));



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

void MainWindow::on_pushButton_clicked()
{
     CustomVacation *vacWindow = new CustomVacation();
     vacWindow->show();

}
