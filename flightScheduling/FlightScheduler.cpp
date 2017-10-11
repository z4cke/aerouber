/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <math.h>
#include <vector>

void FlightScheduler::startScheduleFlights
(std::vector<Passenger> Passengers, std::vector<aircraft> Aircraft, std::vector<Airport> Airports){
    int flightnumber = 1;
    std::vector<Flight> Flightlist;
    std::vector<Passenger> finishedP
    while(!Passenger.empty()){
        Passenger tempPassenger = Passengers.back(); 
        Passengers.pop_back();
        std::string origin = tempPassenger.getCurrentLocation();
        std::string destination = tempPassenger.getDestination();
        int RTA = tempPassenger.getRTA();
        
        for(int i = 0; i < Flightlist.size();i++){
            std::string forigin = Flightlist[i].departureAirport;
            std::string fdestination = Flightlist[i].arrivalAirport;
            if(forigin == origin && fdestination == destination){
                tempPassenger.setID(Flightlist[i].FlightNumber);
            }
        }
        if((i + 1) = Flightlist.size()){
        }
        
        
    }
}

double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, aircraft &Aircraft){
    double A1 = (Origin->getLat() * M_PI)/180;
    double B1 = (Origin->getLon() * M_PI)/180;
    double A2 = (Destination->getLat() * M_PI)/180;
    double B2 = (Destination->getLon() * M_PI)/180;
       double rad = 637100 + Aircraft.getFleet().getHeight();
    
    double deltaA = A1 - A2;
    double deltaB = B1 - B2;
    
    if (deltaA < 0){
        deltaA = -deltaA;
    }
    if (deltaB < 0){
        deltaB = -deltaB;
    }
    
    double a = sin(deltaA/2) * sin(deltaA/2) * cos(A1) * cos(A2) * sin(deltaB/2) * sin(deltaB/2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double distance = rad * c/1000;
    
    
    return distance; //in kilometers
}

time FlightScheduler::calculateTime (double distance, aircraft &Aircraft){ 
    int speed = Aircraft.getFleet().getSpeed();
    distance = distance / 1000; //Conversion to from M to KM
    double timmar = speed / distance;
    double sekunder = timmar*3600;
    time hoho(sekunder); //<-- Constructor
    
    return hoho;
    
}
