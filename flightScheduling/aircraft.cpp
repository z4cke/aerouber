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
aircraft(int losID, std::string losModelos, int losSeatos, std::string CL, fleet &losAircraftosModelos){
    ID = losID;
    Model = losModelos;
    Seats = losSeatos;
    CurrentLocation = CL;
    AircraftModel = losAircraftosModelos;
}
    
//Copy constructor
aircraft(const aircraft& other){
    
}
    
//Copy-assignment constructor
aircraft& operator=(const aircraft& other){
    return *this;
}
    
//Destructor
~aircraft();

int getID();
std::string getModel();
int getSeats();
std::string getCurrentLocation;
    
fleet& getFleet();
    
void connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet);