#ifndef STADIUM_H
#define STADIUM_H
#include <structures.h>
using namespace std;
namespace unicorn {
class Stadium
{
public:
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
void setStadiumId(int id);
void setStadiumName(string name);
void setStadiumCapacity(int capacity_);
void setStadiumLocation(string location_);
void setStadiumConference(string conf);
void setStadiumDivision(string division);
void setStadiumSurface(string surface_);
/**
 * @brief Function to add a distance object to the vector of distance
 * @param dist: distance object to add into the vector
 */
void addDistance(Distance dist){
    distanceFromOthers.push_back(dist);
}

/**
 * @brief Function to return a vector of distance from other teams to the current team
 * @return: vector of distance to all of the other teams
 */
vector<Distance> getDistanceFromOthers(){
    return distanceFromOthers;
}

private:
    int stadiumID;
    string stadiumName;
    int capacity;
    string location;
    string conference;
    string division;
    string surface;
    vector<TeamType> teams;
    vector<Distance> distanceFromOthers;
};}

#endif // STADIUM_H
