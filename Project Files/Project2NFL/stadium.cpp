#include "stadium.h"

namespace unicorn {

int Stadium::getStadiumId(){
    return stadiumID;

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
}
