#ifndef STADIUM_H
#define STADIUM_H
#include <structures.h>
#include"BSTMap.h"

using namespace std;

namespace unicorn {
class Team;

class Stadium
{


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


public:
    static vector<Stadium*> stadiums;

    /**
     * @brief Default constructor
     */
    Stadium(){
        stadiumID=0;
        stadiumName="";
        capacity=0;
        location="";
        conference="";
        division="";
        surface="";
    }

    /**
     * @brief Destructor
     */
    ~Stadium(){}


/**
 * @brief Function to return Stadium id
 * @return integer stadium id
 */
int getStadiumId();

/**
 * @brief Function to return Stadium id
 * @return string stadium name
 */
string getStadiumName();

/**
 * @brief Function to return Stadium capacity
 * @return integer capacity
 */
int getStadiumCapacity();

/**
 * @brief Function to return address of stadium
 * @return string stadium location
 */
string getStadiumLocation();

/**
 * @brief Function to return stadium conference type
 * @return string stadium conference type
 */
string getStadiumConference();

/**
 * @brief Function to return stadium Division
 * @return string stadium Division
 */
string getStadiumDivision();
/**
 * @brief Function to return stadium surface
 * @return string stadium surface
 */
string getStadiumSurface();

/**
 * @brief Function to return stadium teams
 * @return vector teams in case stadium has more than team
 */
vector<Team*> getTeams(){
    return teams;
}




/**
 * @brief Function to return team name
 * @return team name Qstring
 */
QString getTeamsName();

/**
 * @brief Function to add new team to teams static vector
 * @param team : object of type team
 */
void addTeam(Team* team){teams.push_back(team);}

/**
 * @brief Function to set stadium id
 * @param id : integer
 */
void setStadiumId(int id);

/**
 * @brief Function to set stadium name
 * @param id : integer
 */
void setStadiumName(string name);

/**
 * @brief Function to set stadium capacity
 * @param id : integer
 */
void setStadiumCapacity(int capacity_);

/**
 * @brief Function to set stadium location
 * @param location_ : string location
 */
void setStadiumLocation(string location_);

/**
 * @brief Function to set conference
 * @param conference : string conf
 */
void setStadiumConference(string conf);

/**
 * @brief Function to set division
 * @param division : string division
 */
void setStadiumDivision(string division);

/**
 * @brief Function to set surface
 * @param surface : string surface
 */
void setStadiumSurface(string surface_);

/**
 * @brief Function to get stadium object
 * @param stadiumid : integer stadium id
 */
static Stadium* getStadiumPtrById(int stadiumID);

/**
 * @brief Function to initialize teams vector
 */
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




};}

#endif // STADIUM_H
