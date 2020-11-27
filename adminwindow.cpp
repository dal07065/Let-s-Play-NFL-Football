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
    vector<int> teamID;
    vector<QString> teamNames;
    QSqlQuery query;

    query.prepare(QString("SELECT _id, TeamName FROM teams"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {

            int id = query.value(0).toInt();
            teamID.push_back(id);
            QString teamN = query.value(1).toString();
            ui->comboBox_Team_Selection->addItem(teamN);
            teamNames.push_back(teamN);
        }

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
    }

    for(int i = 0; i < int(teamNames.size()); ++i){
        QPair<int, QString> temp;
        temp.second = teamNames[i];
        temp.first = teamID[i];
        nameAndIndex.push_back(temp);
    }
}

void adminWindow::loadTeamData(int index)
{
    ui->comboBox_SelectSouvenir->clear();
    ui->comboBox_SelectStadium->clear();

    QSqlQuery query;

    /***********************************************************************
    ************** Populates the SelectSouvenir ComboBox *******************
    ***********************************************************************/
    query.prepare(QString("SELECT TeamId, SouvenirName FROM teams_souvenir"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0).toInt() == index)
            {
                QString s = query.value(1).toString();
                ui->comboBox_SelectSouvenir->addItem(s);
            }
        }
    }

    /***********************************************************************
    ************** Populates the SelectStadium ComboBox *******************
    ***********************************************************************/

    query.prepare(QString("SELECT _id, StadiumName FROM stadiums"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0).toInt() == index)
            {
                QString s = query.value(1).toString();
                ui->comboBox_SelectStadium->addItem(s);
            }
        }
    }
}

void adminWindow::on_comboBox_Team_Selection_activated(int index)
{
     loadTeamData(index+1);
}
