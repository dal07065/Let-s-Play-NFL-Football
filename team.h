#ifndef CITY_H
#define CITY_H

#include"structures.h"
#include"stadium.h"


using namespace std;

namespace unicorn  {
/**
 * @brief The Team class
 * contains functions to easily access the teams information,
 *  order teams by distance, and formatting
 */
class Team
{

public:
    /**
     * @brief Default constructor
     */
    Team() {
        TeamID=0;
        TeamName="";
        vector<Distance> distanceFromOthers;
        vector <SouvenirType>souvenir;
        teamStadium = new Stadium;

    }
    /**
     * @brief Parameter constructor
     * @param team_id: id of the team
     * @param team_name: name of team
     * @param country_iso: the iso code of the team
     */
    Team(int team_id, string team_name):
       TeamID{team_id}, TeamName{team_name}{}

    /**
     * @brief Static vector containing all the team information
     */
    static vector<Team> teams;

    static BST<Team> teamsBSTMap;

    /**
     * @brief Function to return a static vector containing all the teams information
     *
     * The teams information will be saved into the vector from database for easier access
     */
    static vector<Team> getTeams();

    /**
     * @brief Function to initialize the static team vector with the current information in database
     *
     * The teams static vector will be updated with the newest information
     */
    static void initializeTeams();

    /**
     * @brief Function to return a food static vector from a specific team
     * @param id: team id
     * @return: the static vector of SouvenirType from the specific team
     */
    static vector<SouvenirType*> getSouvenirByTeamId(int id);


    /**
     * @brief Function to return team name using team id
     * @param id: team id
     * @return the team name string
     */
    static QString getTeamNameById(int id);

    /**
     * @brief Function to format a float number with 2 decimal places
     * @param number: number that needs to be formatted
     * @return the formatted number as a string
     */
    static string formateNumbers(float number);

    /**
     * @brief Function to put the list of teams in the order of shortest distance
     * @param vacTeams: list of teams to be ordered
     * @param idTeamStart: id of the starting team
     *
     */

    static Team& getTeamById(int TeamId);

    static Team getTeamByIdByValue(int TeamId);



    /**
     * @brief Function to get the vector containing all the food
     * @return: vector of foodType
     */
    vector<SouvenirType*> getSouvenirType(){
        return souvenir;
    }

    /**
     * @brief Destructor
     */
    ~Team(){

    }



    /**
     * @brief Function to add the food into the food vector
     * @param food: SouvenirType object to add into food vector
     */
    void addSouvenir(SouvenirType* souv){
        souvenir.push_back(souv);

    }

    /**
     * @brief Function to set the team id
     * @param id: team id
     */
    void setTeamId(int id){TeamID =id;}

    /**
     * @brief Function to return the id of the team
     * @return TeamId
     */
    int getTeamId(){ return TeamID;}

    /**
     * @brief Function to set the team name
     * @param name: team name
     */
    void setTeamName(string name){TeamName =name;}

    /**
     * @brief Function to return the team name
     * @return team name
     */
    string getTeamName(){ return TeamName;}

    /**
     * @brief Function to return the team name
     * @return team name
     */
    Stadium* getTeamStadium(){ return teamStadium;}

    void setTeamStadium(Stadium * std){
        teamStadium = std;
    }

    static int getStadiumByTeamId(int id)
    {
        Team* ptr = Team::teamsBSTMap.getTreeNodes();
        Team::teamsBSTMap.display();
        int max = Team::teamsBSTMap.getBSTSize();
        int stadium=0;
            for(int i=0;i<max;i++)
            {
                if((ptr+i)->getTeamId() == id)
                {
                   stadium =  (ptr+i)->getTeamStadium()->getStadiumId();
                    break;
                }
            }
            return stadium;
    }



private:
   int TeamID;
   string TeamName;
   vector <SouvenirType*>souvenir;
   Stadium * teamStadium;
   int MapKey;


};



}

#endif // CITY_H
