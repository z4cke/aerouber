/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "aircraft.h"
//Default constructor
/*aircraft::aircraft(){
    ID = NULL;
    Model = NULL;
    Seats = NULL;
    CurrentLocation = NULL;
    AircraftModel = NULL;
}*/
    
//Non-default constructor
aircraft::aircraft(int i, std::string m, int s, std::string c, fleet *am){
    ID = i;
    Model = m;
    Seats = s;
    CurrentLocation = c;
    AircraftModel = am;
}
    
//Copy constructor
aircraft::aircraft(const aircraft& other){
        
}
    
//Copy-assignment constructor
aircraft& aircraft::operator=(const aircraft& other){
    return *this;
}
    
//Destructor
aircraft::~aircraft(){
    
}

int aircraft::getID(){return ID;}
std::string aircraft::getModel(){return Model;}
int aircraft::getSeats(){return Seats;}
std::string aircraft::getCurrentLocation(){return CurrentLocation;}
    
fleet& aircraft::getFleet(){}
    
void aircraft::connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet){}
