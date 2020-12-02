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

//        QSqlQueryModel *search = new QSqlTableModel;
//        search->setQuery(query);
    }

    for(int i = 0; i < int(teamNames.size()); ++i){
        QPair<int, QString> temp;
        temp.second = teamNames[i];
        temp.first = teamID[i];
        nameAndIndex.push_back(temp);
    }

    unicorn::Team::initializeTeams();
}

void adminWindow::loadTeamData(int index)
{
    ui->comboBox_SelectSouvenir->clear();
    ui->comboBox_SelectStadium->clear();
    ui->doubleSpinBox_SelectSouvenir_Price->clear();
    ui->spinBox_SelectStadium_SetCapacity->clear();

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
    int stadiumId;
    query.prepare(QString("SELECT _id, StadiumID FROM teams"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0) == index)
            {
                stadiumId = query.value(1).toInt();
            }
        }
    }

    query.prepare(QString("SELECT _id, StadiumName, SeatingCapacity FROM stadiums"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0) == stadiumId)
            {
                ui->comboBox_SelectStadium->addItem(query.value(1).toString());
                ui->spinBox_SelectStadium_SetCapacity->setValue(query.value(2).toInt());
            }
        }
    }

        unicorn::Team::initializeTeams();
}

void adminWindow::on_comboBox_Team_Selection_activated(int index)
{
     loadTeamData(index+1);
}


void adminWindow::on_comboBox_SelectSouvenir_activated(const QString &arg1)
{

    QSqlQuery query;
    query.prepare(QString("SELECT SouvenirName, Price FROM teams_souvenir"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0) == arg1)
            {
                ui->doubleSpinBox_SelectSouvenir_Price->setValue(query.value(1).toFloat());
            }
        }
    }
}

void adminWindow::on_pushButton_SelectSouvenir_SetPrice_clicked()
{
    if(ui->doubleSpinBox_SelectSouvenir_Price->value() == 0)
    {
        QMessageBox::warning(this, "Fail", "You need to input a new souvenir price.");
        return;
    }
    if(ui->comboBox_SelectSouvenir->currentText() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to select a souvenir to delete.");
        return;
    }

    QSqlQuery query;
    query.prepare(QString("UPDATE teams_souvenir SET Price = :Price WHERE SouvenirName = :SouvenirName AND TeamId = :TeamId"));
    query.bindValue(":SouvenirName", ui->comboBox_SelectSouvenir->currentText());
    query.bindValue(":TeamId", ui->comboBox_Team_Selection->currentIndex() + 1);
    query.bindValue(":Price", ui->doubleSpinBox_SelectSouvenir_Price->value());

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    ui->comboBox_SelectSouvenir->clear();
    ui->doubleSpinBox_SelectSouvenir_Price->clear();

    unicorn::Team::initializeTeams();
}

void adminWindow::on_pushButton_SelectSouvenir_Delete_clicked()
{
    if(ui->comboBox_SelectSouvenir->currentText() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to select a souvenir to delete.");
        return;
    }

    QSqlQuery query;
    query.prepare(QString("DELETE FROM teams_souvenir WHERE TeamId = :TeamId AND SouvenirName = :SouvenirName"));
    query.bindValue(":TeamId", ui->comboBox_Team_Selection->currentIndex() + 1);
    query.bindValue(":SouvenirName",ui->comboBox_SelectSouvenir->currentText());

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    ui->comboBox_SelectSouvenir->clear();
    ui->doubleSpinBox_SelectSouvenir_Price->clear();

    unicorn::Team::initializeTeams();
}

void adminWindow::on_pushButton_SelectStadium_SetCapacity_clicked()
{
    if(ui->comboBox_SelectStadium->currentText() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to select a stadium to change the capacity of.");
        return;
    }
    if(ui->spinBox_SelectStadium_SetCapacity->value() == 0)
    {
        QMessageBox::warning(this, "Fail", "You need to enter a new stadium capacity.");
        return;
    }

    QSqlQuery query;
    query.prepare(QString("UPDATE stadiums SET SeatingCapacity = :SeatingCapacity WHERE StadiumName = :StadiumName"));
    query.bindValue(":SeatingCapacity", ui->spinBox_SelectStadium_SetCapacity->value());
    query.bindValue(":StadiumName", ui->comboBox_SelectStadium->currentText());

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    ui->comboBox_SelectStadium->clear();
    ui->spinBox_SelectStadium_SetCapacity->clear();

    unicorn::Team::initializeTeams();
}

void adminWindow::on_pushButton_NewSouvenir_Add_clicked()
{
    if(ui->lineEdit_NewSouvenir_Name->text() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to enter a name for the new souvenir.");
        return;
    }
    if(ui->doubleSpinBox_NewSouvenir_Price->value() == 0)
    {
        QMessageBox::warning(this, "Fail", "You need to enter a value for the new souvenir.");
        return;
    }

    QSqlQuery query;

    query.prepare(QString("INSERT INTO teams_souvenir(SouvenirName, TeamId, Price) VALUES (:SouvenirName, :TeamId, :Price)"));

    query.bindValue(":SouvenirName", ui->lineEdit_NewSouvenir_Name->text());
    query.bindValue(":TeamId", ui->comboBox_Team_Selection->currentIndex() + 1);
    query.bindValue(":Price", ui->doubleSpinBox_NewSouvenir_Price->value());


    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }


    ui->lineEdit_NewSouvenir_Name->clear();
    ui->doubleSpinBox_NewSouvenir_Price->clear();

    unicorn::Team::initializeTeams();
}

void adminWindow::on_pushButton_NewStadium_Add_clicked()
{
    if(ui->lineEdit_NewStadium->text() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to enter a name for the new stadium.");
        return;
    }
    if(ui->spinBox_NewStadium_Capacity->value() == 0)
    {
        QMessageBox::warning(this, "Fail", "You need to enter a value for the new stadium capacity.");
        return;
    }



    QSqlQuery query;
    int stadiumID;
    query.prepare(QString("SELECT _id, StadiumID FROM teams"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        while(query.next())
        {
            if(query.value(0) == ui->comboBox_Team_Selection->currentIndex() + 1)
            {
                stadiumID = query.value(1).toInt();
            }
        }
    }

    query.prepare(QString("INSERT INTO stadiums(_id, StadiumName, SeatingCapacity, DateOpened) VALUES (:_id, :StadiumName, :SeatingCapacity, :DateOpened)"));

    query.bindValue(":_id", stadiumID);
    query.bindValue(":StadiumName", ui->lineEdit_NewStadium->text());
    query.bindValue(":SeatingCapacity", ui->spinBox_NewStadium_Capacity->value());
    query.bindValue(":DateOpened", ui->spinBox_NewStadium_Date->value());

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    ui->lineEdit_NewStadium->clear();
    ui->spinBox_NewStadium_Date->clear();
    ui->spinBox_NewStadium_Capacity->clear();
}
