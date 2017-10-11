/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "aircraft.h"
//Default constructor
aircraft::aircraft(){
    ID = NULL;
    Model = NULL;
    Seats = NULL;
    CurrentLocation = NULL;
    AircraftModel = NULL;
}
    
//Non-default constructor
aircarft::aircraft(int i, std::string m, int s, std::string c, fleet &am){
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
aircraft::aircraft& operator=(const aircraft& other){
    return *this;
}
    
//Destructor
~aircraft(){
}

int getID();
std::string getModel();
int getSeats();
std::string getCurrentLocation;
    
fleet& getFleet();
    
void connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet);
