#include "team.h"
vector<unicorn::Team> unicorn::Team::teams;
namespace unicorn {

int Team::getTotalDistance(vector<Team> &vacTeams)
{
    int total=0;
    for(int i =0; i<=(int)vacTeams.size()-2 ;i++)
    {
       vector<Distance> dist = vacTeams[i].teamStadium.getDistanceFromOthers();
       for(auto it = dist.begin(); it!= dist.end() ;++it)
       {
           if(it->OtherStaduimID == vacTeams[i+1].getTeamId() )
                total+= it->distance;
       }
    }
    return total;

}


void Team::calcDistancRecursively(vector<Team>& vacTeams, int position)
{
   if(position == (int)vacTeams.size() )
   {
       return;
   }
   int min=0;
   int minTeamId=0;
   int minPosition =0;
   for(int i= position;i<(int)vacTeams.size();i++)
   {
      for(auto it = vacTeams[position-1].teamStadium.getDistanceFromOthers().begin(); it!= vacTeams[position-1].teamStadium.getDistanceFromOthers().end() ;++it)
      {
          //qDebug()<< vacTeams[i].teamStadium.getStadiumId() << "---"<<it->OtherStaduimID ;
          if((min ==0 || it->distance < min ) && it->distance !=0 && vacTeams[i].teamStadium.getStadiumId()==it->OtherStaduimID )
          {
              min= it->distance;
              minTeamId= vacTeams[i].getTeamId();
              minPosition=i;
          }

      }

   }

    std::iter_swap(vacTeams.begin()+minPosition,vacTeams.begin()+position);
    calcDistancRecursively(vacTeams, position+1);
}


void Team::orderTeamsByDistance(vector<Team>& vacCities, int idTeamStart)
{
    if(vacCities[0].getTeamId()!= idTeamStart)
    {
        for (auto it =vacCities.begin(); it != vacCities.end(); ++it)
        {
            if(it->getTeamId() == idTeamStart)
            {
                std::iter_swap(it,vacCities.begin());
                break;
            }
        }
    }

    if(vacCities.size()>1)
    {
       calcDistancRecursively(vacCities, 1);
    }
}



vector<Team> Team::getTeams(){
    return teams;
}

vector<SouvenirType> Team::getSouvenirByTeamId(int id)
{
    vector<SouvenirType> foodV ;

    for (auto it = Team::teams.begin(); it != Team::teams.end(); ++it)
    {
        if(it->getTeamId() ==id)
        {
          foodV = it->getSouvenirType();
        }
    }
    return foodV;
}

string Team::formateNumbers(float number)
{
   stringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}

void Team::initializeTeams(){
    teams.clear();
    QSqlQuery query,query2;
    query.exec("SELECT * , teams._id as teamID  FROM teams join stadiums on teams.StadiumID= stadiums._id   ORDER BY TeamName ASC  ");
    while(query.next())
    {
        Team team;
        QString id;
        string name;
        Distance dist;
        SouvenirType souveniritem;

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
        stadiumName = query.value("StadiumName").toString().toStdString() ;
        capacity = query.value("SeatingCapacity").toString() ;
        location = query.value("Location").toString().toStdString() ;
        conference = query.value("Conference").toString().toStdString() ;
        division = query.value("Division").toString().toStdString() ;
        surface = query.value("SurfaceType").toString().toStdString() ;
        team.setTeamId(id.toInt());
        team.setTeamName(name);
        team.teamStadium.setStadiumId(stadiumID.toInt());
        team.teamStadium.setStadiumName(stadiumName);
        team.teamStadium.setStadiumCapacity(capacity.toInt());
        team.teamStadium.setStadiumLocation(location);
        team.teamStadium.setStadiumConference(conference);
        team.teamStadium.setStadiumSurface(surface);
        team.teamStadium.setStadiumDivision(division);




        query2.exec("SELECT *, (select StadiumName from stadiums where _id= stadiums_distances.ToStadiumId) as StadiumName  from stadiums_distances where FromStadiumId="+stadiumID+ " order by distance ASC ");
        while(query2.next())
        {

            dist.OtherStaduimID = query2.value("ToStadiumId").toInt();
            dist.distance = query2.value("Distance").toInt();
            dist.OtherStaduimName = query2.value("StadiumName").toString().toStdString();
            team.teamStadium.addDistance(dist);
        }


        query2.exec("SELECT * from teams_souvenir where TeamID="+id+ " order by SouvenirName ASC ");
        while(query2.next())
        {
            souveniritem.souvenirID = query2.value("_id").toInt();
            souveniritem.SouvenirName = query2.value("SouvenirName").toString().toStdString();
            souveniritem.price = query2.value("Price").toFloat();
            souveniritem.TeamID = query2.value("TeamId").toInt();
            team.addSouvenir(souveniritem);
        }
    teams.push_back(team);
    }


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

}
