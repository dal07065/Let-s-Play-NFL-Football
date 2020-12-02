#include "vacationinfo.h"
#include "ui_vacationinfo.h"

VacationInfo::VacationInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VacationInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("Your Trip Information");

    tripInfo_ VacInfo;
    QSqlQuery query,query2;
    userID=2;
   query.exec("SELECT * FROM vacations where IdUser=2 limit 0,1");

    string toHtml = "";

    while(query.next())
    {
        vacationID= query.value("_id").toInt();
        VacInfo.Total_cost = query.value("TotalCost").toFloat();
        VacInfo.total_distance = query.value("TotalDistance").toInt();
        QString sql = "select teams.teamName, vacations_stadiums.IdStadium from vacations_stadiums join teams on teams._id= vacations_stadiums.IdStadium where idVacation= 1 order by TeamName";
        query2.exec(sql);
        while(query2.next())
        {
            //qDebug()<<"city: "<<query2.value("CityName").toString();
            VacInfo.teams.insert(pair<int,string>( query2.value("IdStadium").toInt() , query2.value("TeamName").toString().toStdString()));
        }

        query2.exec("select teams_souvenir._id as souvId, teams_souvenir.SouvenirName as souvName, teams_souvenir.TeamId, teams_souvenir.TeamId, teams_souvenir.Price, vacations_souvenir.Quantity from vacations_souvenir join teams_souvenir on teams_souvenir._id= vacations_souvenir.IdSouvenir where idVacation= 1 order by SouvenirName");
        while(query2.next())
        {
            SouvenirType souvToBeAdded;
            souvToBeAdded.price = query2.value("Price").toFloat();
            souvToBeAdded.TeamID = query2.value("TeamId").toInt();
            souvToBeAdded.quantity = query2.value("Quantity").toInt();
            souvToBeAdded.souvenirID = query2.value("souvId").toInt();
            souvToBeAdded.SouvenirName = query2.value("souvName").toString().toStdString();
            VacInfo.selectedSouvenir.push_back(souvToBeAdded);

            cout<< "xxxxx"<<endl;

        }

    }


    std::map<int, string>::iterator it = VacInfo.teams.begin();
    float totalCity=0;
    float total=0;
    toHtml+="<h3>Vacation Summary ( Total Distance: "+ to_string(VacInfo.total_distance) +" Miles)</h3><table  cellpadding=\"5\" cellspacing=\"1\" width=\"98%\"style=\"border-collapse: collapse;border: 1px solid black;margin-top:5px;\" ><tr><td align=\"center\" style=\"border: 1px solid black;font-weight:bold\" >Souvenir Name</td><td  align=\"center\" style=\"border: 1px solid black;font-weight:bold\" >Quantity</td><td  align=\"right\" style=\"border: 1px solid black;font-weight:bold\">Price</td><td  align=\"right\" style=\"border: 1px solid black;font-weight:bold\">Total</td></tr>";
    for(; it!=VacInfo.teams.end();++it )
    {
        totalCity=0;
        toHtml+= "<tr><td colspan=\"4\" style=\"border-collapse: collapse;border: 1px solid black;color:#92495E\"><b>"+it->second+"</b></tr>";

        std::deque<SouvenirType>::iterator it2 = VacInfo.selectedSouvenir.begin();

            for(; it2!=VacInfo.selectedSouvenir.end();++it2 )
            {
               if(it->first == it2->TeamID )
               {
                   toHtml+= "<tr><td  align=\"left\" style=\"border: 1px solid black;\">"+it2->SouvenirName+"</td> <td  align=\"center\" style=\"border: 1px solid black;\" >"+ to_string( it2->quantity) +"</td> <td  align=\"right\" style=\"border: 1px solid black;\">$" + Team::formateNumbers(it2->price) +"</td>  <td  align=\"right\" style=\"border: 1px solid black;\">$" + Team::formateNumbers(it2->price* it2->quantity) +"</td></tr>";
                   totalCity+= it2->price* it2->quantity;
                   total+= it2->price* it2->quantity;
               }
            }


         toHtml+= "<tr><td colspan=\"3\" style=\"border: 1px solid black;font-weight:bold;text-align:right;color:#92495E\">Total "+it->second+"</td><td align=\"right\" style=\"border: 1px solid black;color:#92495E\"><b> $"+Team::formateNumbers(totalCity)+"</b></td></tr>";



    }
    toHtml+= "<tr><td colspan=\"3\" style=\"border: 1px solid black;font-weight:bold;text-align:right;color:#CF685E\">Grand Total</td><td align=\"right\" style=\"border: 1px solid black;color:#CF685E\"><b> $"+Team::formateNumbers(total)+"</b></td></tr></table>";
    QWidget * container1 = new QWidget;
    QFormLayout *formLayout1 = new QFormLayout();

    QHBoxLayout * hBoxLayout1= new QHBoxLayout;
    QLabel *txtLabel = new QLabel;
    txtLabel->setText(QString::fromStdString( toHtml));
    hBoxLayout1->addWidget(txtLabel);
    formLayout1->addRow(hBoxLayout1);
    ui->scrollArea->setWidget(container1);
    container1->setLayout(formLayout1);



}

VacationInfo::~VacationInfo()
{
    delete ui;
}

void VacationInfo::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("delete from vacations");
    query.exec();

    query.prepare("delete from vacations_stadiums");
    query.exec();

    query.prepare("delete from vacations_souvenir");
    query.exec();

    emit backToCustomVacation();
    this->close();
}
