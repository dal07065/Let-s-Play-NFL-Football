#include "adminwindow.h"
#include "ui_adminwindow.h"


adminWindow::adminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Unicorn Admin Functions");
    this->setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));

    loadTeams();
}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::loadTeams()
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
                    ui->comboBox_Team_Selection->addItem(teamN);
                }
            }
       }
       else
       {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }

}
