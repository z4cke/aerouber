/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "aircraft.h"
    
//Non-default constructor
aircraft::aircraft(std::string id, std::string model, int seats, std::string cl){
    ID = id;
    Model = model;
    Seats = seats;
    CurrentLocation = cl;
    AircraftModel = nullptr;
}

std::string aircraft::getID(){return ID;}
std::string aircraft::getModel(){return Model;}
int aircraft::getSeats(){return Seats;}
std::string aircraft::getCurrentLocation(){return CurrentLocation;}
    
fleet& aircraft::getFleet(){
    return *AircraftModel;
}
    
void aircraft::connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleetList){
    for(aircraft& plane : aircrafts){
        for(fleet& planeType : fleetList){
            if(plane.getModel() == planeType.getAircraftModel()){
                plane.AircraftModel = &planeType;
                break;
            }
        }
    }
}
