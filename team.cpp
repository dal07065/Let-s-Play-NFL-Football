#include "team.h"
vector<unicorn::Team> unicorn::Team::teams;
BST<unicorn::Team> unicorn::Team::teamsBSTMap;
namespace unicorn {







vector<Team> Team::getTeams(){
    return teams;
}

vector<SouvenirType*> Team::getSouvenirByTeamId(int id)
{
    vector<SouvenirType*> souvV ;

    for (auto it = Team::teams.begin(); it != Team::teams.end(); ++it)
    {
        if(it->getTeamId() ==id)
        {
          souvV = it->getSouvenirType();
        }
    }
    return souvV;
}

string Team::formateNumbers(float number)
{
   stringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}

void Team::initializeTeams(){

if (teams.size()>0) teams.clear();
if(teamsBSTMap.getSize()>0)
{
      teamsBSTMap.~BST();
   Stadium::stadiums.clear();

}

    QSqlQuery query,query2;
    query.exec("SELECT * , teams._id as teamID  FROM teams join stadiums on teams.StadiumID= stadiums._id    ORDER BY TeamName ASC  ");
    int i=0;
    while(query.next())
    {
        Team * team = new Team();
       // Stadium * std = new Stadium();
        QString id;
        string name;

        Stadium * std= new Stadium();

        QString stadiumID;
        string stadiumName;
        QString capacity;
        string location;
        string conference;
        string division;
        string surface;


        id = query.value("_id").toString();
        name= query.value("TeamName").toString().toStdString() ;


        stadiumID = query.value("StadiumID").toString();
        team->setTeamId(id.toInt());
        team->setTeamName(name);

        stadiumName = query.value("StadiumName").toString().toStdString() ;
        capacity = query.value("SeatingCapacity").toString() ;
        location = query.value("Location").toString().toStdString() ;
        conference = query.value("Conference").toString().toStdString() ;
        division = query.value("Division").toString().toStdString() ;
        surface = query.value("SurfaceType").toString().toStdString() ;
        std->setStadiumId(stadiumID.toInt());
        std->setStadiumName(stadiumName);
        std->setStadiumCapacity(capacity.toInt());
        std->setStadiumLocation(location);
        std->setStadiumConference(conference);
        std->setStadiumSurface(surface);
        std->setStadiumDivision(division);


                query2.exec("SELECT *, (select StadiumName from stadiums where _id= stadiums_distances.ToStadiumId) as StadiumName  from stadiums_distances where FromStadiumId="+stadiumID+ "  group by FromStadiumId ,  ToStadiumId  order by distance ASC ");
                while(query2.next())
                {
                    Distance* dist = new Distance;
                      // cout<< "????"<<query2.value("StadiumName").toString().toStdString()<<endl;
                    dist->StadiumID = stadiumID.toInt();
                    dist->OtherStaduimID = query2.value("ToStadiumId").toInt();
                    dist->distance = query2.value("Distance").toInt();
                    dist->OtherStaduimName = query2.value("StadiumName").toString().toStdString();
                    dist->StadiumIDPtr = std;


                    std->addDistance(dist);
                }






         std->addTeam(team);
         team->setTeamStadium(std);




        query2.exec("SELECT * from teams_souvenir where TeamID="+id+ " order by SouvenirName ASC ");
        while(query2.next())
        {
            SouvenirType* souveniritem = new SouvenirType() ;
            souveniritem->souvenirID = query2.value("_id").toInt();
            souveniritem->SouvenirName = query2.value("SouvenirName").toString().toStdString();
            souveniritem->price = query2.value("Price").toFloat();
            souveniritem->TeamID = query2.value("TeamId").toInt();
            team->addSouvenir(souveniritem);
        }

    team->MapKey=i;
    teamsBSTMap.insert(i, *team);
    teams.push_back(*team);

    i++;
    }


    Stadium::initializeStadiums();



}

QString Team::getTeamNameById(int id){
    auto it = Team::teams.begin();
    for (; it != Team::teams.end(); ++it)
    {
        if(it->getTeamId()==id)
        {
            string name = it->getTeamName();
            return QString::fromStdString( name);
            break;
        }
    }
    return 0;
}

Team& Team::getTeamById(int TeamId)
{
    auto it = Team::teams.begin();
    for (; it != Team::teams.end(); ++it)
    {
        if(it->getTeamId()==TeamId)
        {

            break;
        }
    }
    return *it;
}

Team Team::getTeamByIdByValue(int TeamId)
{
    auto it = Team::teams.begin();
    for (; it != Team::teams.end(); ++it)
    {
        if(it->getTeamId()==TeamId)
        {

            break;
        }
    }
    return *it;

}

}
