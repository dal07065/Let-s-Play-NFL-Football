#ifndef STADIUM_H
#define STADIUM_H
#include <structures.h>
#include"BSTMap.h"

using namespace std;

namespace unicorn {
class Team;

class Stadium
{
public:
    static vector<Stadium*> stadiums;
    Stadium(){
        stadiumID=0;
        stadiumName="";
        capacity=0;
        location="";
        conference="";
        division="";
        surface="";
    }

int getStadiumId();
string getStadiumName();
int getStadiumCapacity();
string getStadiumLocation();
string getStadiumConference();
string getStadiumDivision();
string getStadiumSurface();
vector<Team*> getTeams(){
    return teams;
}

QString getTeamsName();

void addTeam(Team* team){teams.push_back(team);}
void setStadiumId(int id);
void setStadiumName(string name);
void setStadiumCapacity(int capacity_);
void setStadiumLocation(string location_);
void setStadiumConference(string conf);
void setStadiumDivision(string division);
void setStadiumSurface(string surface_);

static Stadium* getStadiumPtrById(int stadiumID){

            for(auto i = stadiums.begin(); i != stadiums.end();++i)
            {
                if(stadiumID == (*i)->getStadiumId())
                {
                    return *i;
                }
            }
            return 0;
}


static void initializeStadiums();

/**
 * @brief Function to add a distance object to the vector of distance
 * @param dist: distance object to add into the vector
 */
void addDistance(Distance* dist){
    distanceFromOthers.push_back(dist);
}

/**
 * @brief Function to return a vector of distance from other teams to the current team
 * @return: vector of distance to all of the other teams
 */
vector<Distance*> getDistanceFromOthers(){
    return distanceFromOthers;
}

//Stadium* getStadiums(){
//    //return stadiumsPtr;
//}

private:
    int stadiumID;
    string stadiumName;
    int capacity;
    string location;
    string conference;
    string division;
    string surface;
    vector<Team*> teams;
    vector<Distance*> distanceFromOthers;
};}

#endif // STADIUM_H
