/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <math.h>

void FlightScheduler::startScheduleFlights
(std::vector<passenger>& Passengers, std::vector<aircraft>& Aircraft, std::vector<airport>& Airports){


}

double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, Aircraft &Aircraft){
    double φ1 = (Origin.latitide * M_PI)/180;
    double λ1 = (Origin.longitude * M_PI)/180;;
    double φ2 = (Destination.latitude * M_PI)/180;;
    double λ2 = (Destination.longitute * M_PI)/180;;
    double rad = 6371000 + Aircraft.fleet.CruisingHeight*1000;
    
    double Δφ = φ1 - φ2;
    double Δλ = λ1 - λ2;
    
    if (Δφ < 0){
        Δφ = -Δφ;
    }
    if (Δλ < 0){
        Δλ = -Δλ;
    }
    
    double a = sin(Δφ/2)^2 * cos(φ1) * cos(φ2) * sin(Δλ/2)^2;
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double distance = rad * c;
    
    
    return distance; //in meters
}

Time FlightScheduler::calculateTime (double distance, Aircraft Aircraft){
    int speed = Aircraft.fleet.Speed;
    distance = distance / 1000; //Conversion to from M to KM
    double time = speed / distance;
    Time hoho(Time); //<-- CONVERSION
    
    return hoho;
    
}
