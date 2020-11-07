#ifndef souvenirTYPE_H
#define souvenirTYPE_H

#include <stdio.h>
#include <iostream>
//#include<strings.h>
#include<vector>
#include "database.h"
#include <iomanip>
#include <sstream>

#include <map>
#include <deque>

using namespace std;
/**
 * @brief The souvenirType struct represents the souvenir items
 *
 * souvenirType containing the ID, name, price, its team's ID,
 * and the quantity
 */
struct SouvenirType{
    int souvenirID;
    string SouvenirName;
    float price;
    int TeamID;
    int quantity;

};

/**
 * @brief The Distance struct represents the distance from a souviner
 *
 * Distance containing the name, id, and distance to the other souviner
 */
struct Distance{
    int OtherStaduimID;
    string OtherStaduimName;
    int distance;
};

/**
 * @brief The souvenirArr struct represents the souvenir item
 *
 * souvenirArr containing the id, price, and quantity of the souvenir item
 */
struct souvinerArr{
    int souvenirID;
    float Price;
    int Quantity;
    int TeamID;

};






/**
 * @brief The tripInfo_ struct represents the trip information
 * stored for tourist
 *
 * tripInfo_ containing the souvenir items, the list of cities,
 * total distance and total cost for the trip
 */
struct tripInfo_{
    std::deque<SouvenirType> selectedSouvenir;
    int total_distance;
    int Total_cost;
    std::map<int,string> teams;

};

struct TeamType
{
   int teamID;
   string teamName;

};

#endif // souvenirTYPE_H
