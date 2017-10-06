/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include "airport.h"
#include <math.h>

void FlightScheduler::startScheduleFlights
(std::vector<passenger>& Passengers, std::vector<aircraft>& Aircraft, std::vector<airport>& Airports){


}

double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, Aircraft &Aircraft){
    double A1 = (Origin->getLat() * M_PI)/180;
    double B1 = (Origin->getLon() * M_PI)/180;;
    double A2 = (Destination->getLat() * M_PI)/180;;
    double B2 = (Destination->getLon() * M_PI)/180;;

    double A1 = (OriginLat * M_PI)/180;
    double B1 = (OriginLon * M_PI)/180;;
    double A2 = (Destinationlat* M_PI)/180;;
    double B2 = (Destinationlon * M_PI)/180;;
    double rad = 637100;
    
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
    double distance = rad * c;
    
    
    return distance; //in meters
}

time FlightScheduler::calculateTime (double distance, Aircraft &Aircraft){
    int speed = Aircraft.fleet.Speed;
    distance = distance / 1000; //Conversion to from M to KM
    double timmar = speed / distance;
    time hoho(timmar); //<-- Constructor
    
    return hoho;
    
}
