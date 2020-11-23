#include "team.h"
vector<unicorn::Team> unicorn::Team::teams;
BST<unicorn::Team> unicorn::Team::teamsBSTMap;
namespace unicorn {

int Team::getTotalDistance(vector<Team> &vacTeams)
{
//    int total=0;
//    for(int i =0; i<=(int)vacTeams.size()-2 ;i++)
//    {
//       vector<Distance*> dist = vacTeams[i].teamStadium->getDistanceFromOthers();
//       for(auto it = dist.begin(); it!= dist.end() ;++it)
//       {
//           if((*it)->OtherStaduimID == vacTeams[i+1].getTeamId() )
//                total+= (*it)->distance;
//       }
//    }
//    return total;

    return 0;
}


void Team::calcDistancRecursively(vector<Team>& vacTeams, int position)
{
//   if(position == (int)vacTeams.size() )
//   {
//       return;
//   }
//   int min=0;
//   int minTeamId=0;
//   int minPosition =0;
//   for(int i= position;i<(int)vacTeams.size();i++)
//   {
//      for(auto it = vacTeams[position-1].teamStadium->getDistanceFromOthers().begin(); it!= vacTeams[position-1].teamStadium->getDistanceFromOthers().end() ;++it)
//      {
//          //qDebug()<< vacTeams[i].teamStadium.getStadiumId() << "---"<<it->OtherStaduimID ;
//          if((min ==0 || (*it)->distance < min ) && (*it)->distance !=0 && vacTeams[i].teamStadium->getStadiumId()==(*it)->OtherStaduimID )
//          {
//              min= (*it)->distance;
//              minTeamId= vacTeams[i].getTeamId();
//              minPosition=i;
//          }

//      }

//   }

//    std::iter_swap(vacTeams.begin()+minPosition,vacTeams.begin()+position);
//    calcDistancRecursively(vacTeams, position+1);
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


Stadium *stad[50] = {NULL};
     teamsBSTMap.destroyTree();
    //teamsBSTMap.~BST();
    Stadium::stadiums.clear();
    QSqlQuery query,query2;
    query.exec("SELECT * , teams._id as teamID  FROM teams join stadiums on teams.StadiumID= stadiums._id   ORDER BY TeamName ASC  ");
    int i=0;
    while(query.next())
    {
        Team * team = new Team();
       // Stadium * std = new Stadium();
        QString id;
        string name;

        Stadium * std= new Stadium;

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

        if(stad[stadiumID.toInt()] ==NULL)
        {
         stad[stadiumID.toInt()] = new Stadium;
        stad[stadiumID.toInt()] = std;
        stadiumName = query.value("StadiumName").toString().toStdString() ;
        capacity = query.value("SeatingCapacity").toString() ;
        location = query.value("Location").toString().toStdString() ;
        conference = query.value("Conference").toString().toStdString() ;
        division = query.value("Division").toString().toStdString() ;
        surface = query.value("SurfaceType").toString().toStdString() ;

        //stad[stadiumID.toInt()]= std;
        stad[stadiumID.toInt()]->setStadiumId(stadiumID.toInt());
        stad[stadiumID.toInt()]->setStadiumName(stadiumName);
        stad[stadiumID.toInt()]->setStadiumCapacity(capacity.toInt());
        stad[stadiumID.toInt()]->setStadiumLocation(location);
        stad[stadiumID.toInt()]->setStadiumConference(conference);
        stad[stadiumID.toInt()]->setStadiumSurface(surface);
        stad[stadiumID.toInt()]->setStadiumDivision(division);



//cout<<stadiumName<<endl;
                query2.exec("SELECT *, (select StadiumName from stadiums where _id= stadiums_distances.ToStadiumId) as StadiumName  from stadiums_distances where FromStadiumId="+stadiumID+ "  group by FromStadiumId ,  ToStadiumId  order by distance ASC ");
                while(query2.next())
                {
                    Distance* dist = new Distance;
                      // cout<< "????"<<query2.value("StadiumName").toString().toStdString()<<endl;
                    dist->StadiumID = stadiumID.toInt();
                    dist->OtherStaduimID = query2.value("ToStadiumId").toInt();
                    dist->distance = query2.value("Distance").toInt();
                    dist->OtherStaduimName = query2.value("StadiumName").toString().toStdString();
                    dist->StadiumIDPtr = stad[stadiumID.toInt()];


                    stad[stadiumID.toInt()]->addDistance(dist);
                }




//cout<<"kkkkk"<<stadiumID.toInt()<<endl;

        }
 stad[stadiumID.toInt()]->addTeam(team);

        team->setTeamStadium(stad[stadiumID.toInt()]);





       // team->setTeamStadium(std);

//            std::vector<Team*>::iterator itr = std::find_if(
//               std->getTeams().begin(), std->getTeams().end(),
//               [&id](const Team* x) { return x->TeamID == id.toInt();});
//            if(itr== std->getTeams().end() ){
//               std->addTeam(team);
//            }



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
