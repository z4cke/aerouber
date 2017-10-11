/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "passenger.h"

int Passenger::getID(){
    return Passenger.ID;   
}

int Passenger::getDestination(){
    return Passenger.Destination;   
}

int Passenger::getCurrentLocation(){
    return Passenger.currentLocation;   
}

std::string Passenger::getRTA(){
    return Passenger.RTA;   
}

void Passenger::setID(int flightID){
    Passenger.ID = flightID;
    
}