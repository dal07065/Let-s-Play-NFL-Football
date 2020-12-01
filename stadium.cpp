#include "stadium.h"
#include "team.h"
vector<unicorn::Stadium*> unicorn::Stadium::stadiums;
//vector <unicorn::Stadium*> stadiumsPtr  ;

namespace unicorn {

int Stadium::getStadiumId(){
    return stadiumID;

 }

QString Stadium::getTeamsName(){
  QString str="";
    for(auto it = teams.begin();it!= teams.end();++it)
    {
        if(str!=""){str+="<br/>";}
        str+= "<b>Team:</b> "+QString::fromStdString( (*it)->getTeamName());
    }

    return str;

}

string Stadium::getStadiumName(){
    return stadiumName;

 }

int Stadium::getStadiumCapacity(){
    return capacity;

 }

string Stadium::getStadiumLocation(){
    return location;

 }

string Stadium::getStadiumConference(){
    return conference;

 }

string Stadium::getStadiumDivision(){
    return division;

 }

string Stadium::getStadiumSurface(){
    return surface;

 }

void Stadium::setStadiumId(int id){
   stadiumID=id;

 }

void Stadium::setStadiumName(string name){
   stadiumName = name;

 }

void Stadium::setStadiumCapacity(int capacity_){
   capacity = capacity_;

 }

void Stadium::setStadiumLocation(string location_){
    location= location_;

 }

void Stadium::setStadiumConference(string conf){
   conference = conf;

 }

void Stadium::setStadiumDivision(string division_){
    division= division_;

 }

void Stadium::setStadiumSurface(string surface_){
   surface=surface_;

 }

void Stadium::initializeStadiums(){


    Team* ptr = Team::teamsBSTMap.getTreeNodes();
    Team::teamsBSTMap.display();
    int max = Team::teamsBSTMap.getBSTSize();
    int * arr = new int[max]();
        for(int i=0;i<max;i++)
        {
            if(arr[(ptr+i)->getTeamStadium()->getStadiumId()]!=1)
            {
                 stadiums.push_back((ptr+i)->getTeamStadium());
                 arr[(ptr+i)->getTeamStadium()->getStadiumId()]=1;
            }
        }
        delete [] arr;



        for(auto i = stadiums.begin(); i != stadiums.end();++i)
        {
            vector<Distance*> dist = (*i)->getDistanceFromOthers();
            for( auto  it= dist.begin() ;it!=dist.end();++it  )
            {
                (*it)->OtherStaduimIDPtr = getStadiumPtrById((*it)->OtherStaduimID);

            }

         }


        for(auto i = stadiums.begin(); i != stadiums.end();++i)
        {
           // cout <<"======" << (*i)->getStadiumName()<<endl;
            vector<Distance*> dist = (*i)->getDistanceFromOthers();
            for( auto  it= dist.begin() ;it!=dist.end();++it  )
            {
               // cout<< (*it)->StadiumID <<",,,"<< (*it)->OtherStaduimID<<endl;

              //  cout<<"self:"<< (*it)->StadiumIDPtr->getStadiumName()<<endl;
            //    cout<<"other"<< (*it)->OtherStaduimIDPtr->getStadiumName()<<endl;
            }

        }









}






}
