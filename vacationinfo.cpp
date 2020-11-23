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
   query.exec("SELECT * FROM vacations where IdUser="+QString::number(userID)+" limit 0,1");

    string toHtml = "";

    while(query.next())
    {
        vacationID= query.value("_id").toInt();
        VacInfo.Total_cost = query.value("TotalCost").toFloat();
        VacInfo.total_distance = query.value("TotalDistance").toInt();
        QString sql = "select cities.CityName, vacations_cities.IdCity from vacations_cities join cities on cities._id= vacations_cities.IdCity where idVacation= "+query.value("_id").toString()+" order by CityName";
        query2.exec(sql);
        while(query2.next())
        {
           // qDebug()<<"city: "<<query2.value("CityName").toString();
            VacInfo.teams.insert(pair<int,string>( query2.value("IdCity").toInt() , query2.value("CityName").toString().toStdString()));
        }

        query2.exec("select cities_foods.FoodName, cities_foods.IdCity , vacations_foods.IdFood, vacations_foods.foodPrice, vacations_foods.Quantity from vacations_foods join cities_foods on cities_foods._id= vacations_foods.IdFood where idVacation= "+query.value("_id").toString()+" order by FoodName");
        while(query2.next())
        {
            //qDebug()<<"food: "<<query2.value("FoodName").toString();
            SouvenirType souvToBeAdded;
            souvToBeAdded.price = query2.value("foodPrice").toFloat();
            souvToBeAdded.TeamID = query2.value("IdCity").toInt();
            souvToBeAdded.quantity = query2.value("Quantity").toInt();
            souvToBeAdded.TeamID = query2.value("IdFood").toInt();
            souvToBeAdded.SouvenirName = query2.value("FoodName").toString().toStdString();
            VacInfo.selectedSouvenir.push_back(souvToBeAdded);

        }

    }


    std::map<int, string>::iterator it = VacInfo.teams.begin();
    float totalCity=0;
    float total=0;
    toHtml+="<h3>Vacation Summary ( Total Distance: "+ to_string(VacInfo.total_distance) +" KM)</h3><table  cellpadding=\"5\" cellspacing=\"1\" width=\"98%\"style=\"border-collapse: collapse;border: 1px solid black;margin-top:5px;\" ><tr><td align=\"center\" style=\"border: 1px solid black;font-weight:bold\" >Food Name</td><td  align=\"center\" style=\"border: 1px solid black;font-weight:bold\" >Quantity</td><td  align=\"right\" style=\"border: 1px solid black;font-weight:bold\">Price</td><td  align=\"right\" style=\"border: 1px solid black;font-weight:bold\">Total</td></tr>";
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
    query.prepare("delete from vacations where IdUser =2");
    query.exec();

    query.prepare("delete from vacations_teams where IdVacation =1");
    query.exec();

    query.prepare("delete from vacations_souvenir where IdVacation =1");
    query.exec();

    emit backToCustomVacation();
    this->close();
}
