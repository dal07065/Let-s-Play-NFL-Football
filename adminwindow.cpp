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
    if(ui->doubleSpinBox_SelectSouvenir_Price->value() != 0)
    {
        QString souvenirName = ui->comboBox_SelectSouvenir->currentText();
        QString newPrice = QString::number(ui->doubleSpinBox_SelectSouvenir_Price->value());
        QString teamNum = QString::number(ui->comboBox_Team_Selection->currentIndex());

        QSqlQuery query;
        query.prepare(QString("UPDATE teams_souvenir"
                           " SET Price = " + newPrice +
                           " WHERE SouvenirName = '" +souvenirName+
                           " AND TeamId = " + teamNum));
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        while(query.next())
        {

        }

    }
}

void adminWindow::on_pushButton_SelectSouvenir_Delete_clicked()
{
    if(ui->comboBox_SelectSouvenir->currentText() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to select a souvenir to delete.");
        return;
    }

}

void adminWindow::on_pushButton_SelectStadium_SetCapacity_clicked()
{
    if(ui->comboBox_SelectStadium->currentText() == "")
    {
        QMessageBox::warning(this, "Fail", "You need to select a stadium to change the capacity.");
        return;
    }
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

    QString teamID = QString::number(ui->comboBox_Team_Selection->currentIndex() + 1);
    QString newSouvenirName = ui->lineEdit_NewSouvenir_Name->text();
    QString newSouvenirPrice = QString::number(ui->doubleSpinBox_NewSouvenir_Price->value());

    int idNumber = 0;
    QSqlQuery query;

    query.exec(QString("SELECT _id FROM teams_souvenir"));

    while(query.next())
    {
        if(query.value(0).toInt() > idNumber)
        {
            idNumber = query.value(0).toInt();
        }
    }


    QString _id = QString::number(idNumber);

    // INSERTION INTO THE DATABASE
    query.prepare(QString("INSERT INTO teams_souvenir(_id, SouvenirName, TeamId, Price) VALUES ( 166, 'TEST', 1, 3.50)"));

//    query.bindValue(":_id", idNumber);
//    query.bindValue(":_id", _id);
//    query.bindValue(":SouvenirName", newSouvenirName);
//    query.bindValue(":TeamId", ui->comboBox_Team_Selection->currentIndex() + 1);
//    query.bindValue(":TeamId", teamID);
//    query.bindValue(":Price", ui->doubleSpinBox_NewSouvenir_Price->value());
//    query.bindValue(":Price", newSouvenirPrice);

    query.exec();


//    if (!query.exec())
//    {
//        QMessageBox::warning(this, "Fail", "Query did not execute");
//    }


//    query.exec(QString("INSERT INTO "
//                       "teams_souvenir(_id, SouvenirName, TeamId, Price)"
//                       " VALUES(" +_id + ", '" +newSouvenirName+ "', " +teamID+ ", "
//                          +newSouvenirPrice+ ")"));

    ui->lineEdit_NewSouvenir_Name->clear();
    ui->doubleSpinBox_NewSouvenir_Price->clear();
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
}






