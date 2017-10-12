/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "passenger.h"

int Passenger::getID(){
    return ID;   
}

std::string Passenger::getDestination(){
    return Destination;   
}

std::string Passenger::getCurrentLocation(){
    return currentLocation;   
}

std::string Passenger::getRTA(){
    return RTA;   
}

void Passenger::setID(int flightID){
    ID = flightID;
    
}