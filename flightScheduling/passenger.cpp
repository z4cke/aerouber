/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "passenger.h"
#include "Flight.h"

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

void Passenger::addToFlight(Flight* newFlight){
    bookedOnFlight = newFlight;
}
    
void Passenger::removeFromFlight(){
    bookedOnFlight = nullptr;
}

std::string& operator <<(std::string &s, Passenger& passenger ){
    
    s = std::to_string(passenger.getID()) + ":";
    s += "file:";
    if(passenger.bookedOnFlight == nullptr){
        s += ":::";
    }
    else{
    s += passenger.bookedOnFlight->getdepartureAirportCode() + ":";
    
    
    s += passenger.bookedOnFlight->getDepartureTime().getTimeAsString()+":";
    s += passenger.bookedOnFlight->getarrivalAirportCode()+":";
    s += passenger.bookedOnFlight->getArrivalTime().getTimeAsString();
    }
    return s;

}