/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>

#define EARTH_RADIUS 6371.0

void FlightScheduler::startScheduleFlights
(std::vector<Passenger> &Passengerlist, std::vector<aircraft> &aircraftList, std::vector<Airport> &Airports){
    
    int Flightnumber = 1;
    
    for(Passenger& p : Passengerlist){
        bool flightexist = false;
        if(scheduledFlights.size() > 0)
            for(Flight& f : scheduledFlights){ //Kollar om flight redan finns.
                if(p.getCurrentLocation() == f.getdepartureAirportCode()){
                    if(p.getDestination() == f.getarrivalAirportCode()){
                        flightexist = true;
                        f.addPassenger(&p);  
                        break;
                    }
                }
            }
        
        if(!flightexist){ //Om flight inte finns.
            scheduledFlights.emplace_back(0, 0, p.getCurrentLocation(), p.getDestination(), Flightnumber, Airports);
            scheduledFlights[scheduledFlights.size() - 1].addPassenger(&p);
            Flightnumber++;
        }
    }
    
    
    std::sort(scheduledFlights.begin(),scheduledFlights.end()); //Sortering av listan.
    
    for(Flight& f : scheduledFlights){
        for(aircraft &a : aircraftList){
            
            if(a.getCurrentLocation() == f.getdepartureAirportCode()){ 
                std::cout <<"ID: " <<f.getPassengerlist()[0]->getID() << std::endl;
                if(f.Aircraft == nullptr){
                    if(calculateDistance(f.getdepartureAirport(),f.getarrivalAirport(),a) < (double)a.getFleet().getMaxRange()){
                        f.Aircraft = &a;
                    }
                }else{
                    if(f.Aircraft->getSeats() <= a.getSeats()){
                        if(calculateDistance(f.getdepartureAirport(),f.getarrivalAirport(),a) < (double)a.getFleet().getMaxRange()){
                            f.Aircraft = &a;  
                        }
                    }
                }    
            }
        }
    }
    
    
    for(Flight &f : scheduledFlights){ //uträkning av tid;
        if(f.Aircraft != nullptr){
            f.removeExcessPassenger();//checks to see that there is enough seats for each passenger, else it removes passengers from the flight until it is.
            time2 EarliestRTA = stringtotimeconverter(Passengerlist[0].getRTA());
            for(Passenger *p : f.getPassengerlist()){
                time2 RTA = stringtotimeconverter(p->getRTA());
                if(RTA>EarliestRTA){
                    EarliestRTA = RTA;
                }
            }
            f.setArrivalTime(EarliestRTA);
            time2 Flighttime = calculateTime(calculateDistance(f.getdepartureAirport(),f.getarrivalAirport(),*f.Aircraft),*f.Aircraft);
            f.setDepartureTime(EarliestRTA - Flighttime);
            f.confirmFlight();
        }
        else{
            f.cancelFlight();
        }
    } 
} //Funktionens slut

double hav(double radians){
    double sine = std::sin(radians/2);
    return sine*sine;
}

double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, aircraft &currAircraft){
    if(&Origin == nullptr || &Destination == nullptr || &currAircraft == nullptr)
        return std::numeric_limits<double>::max();
    double originLat = Origin.getLat();
    double originLon = Origin.getLon();
    double destLat = Destination.getLat();
    double destLon = Destination.getLon();
    
    double A1 = (originLat * M_PI)/180.0;
    double B1 = (originLon * M_PI)/180.0;
    double A2 = (destLat * M_PI)/180.0;
    double B2 = (destLon * M_PI)/180.0;
    
    double cruiseHeight = (double)currAircraft.getFleet().getHeight();
    double rad = EARTH_RADIUS + cruiseHeight;
    
    double deltaA = (A1 - A2);
    double deltaB = (B1 - B2);
    
    double a = hav(deltaA) + std::cos(A1) * std::cos(A2) * hav(deltaB);
    double distance = 2 * rad * std::asin(std::sqrt(a));
    
    return distance; //in kilometers
}





time2 FlightScheduler::calculateTime (double distance, aircraft &Aircraft){ 
    int speed = Aircraft.getFleet().getSpeed();
    double timmar = speed / distance;
    double sekunder = timmar*3600;
    time2 hoho(sekunder); //<-- Constructor
    
    return hoho;
}
    

    
    time2 FlightScheduler::stringtotimeconverter(std::string RTA){
                int h;
                int m;
                std::string line = RTA;
                h=std::atoi(line.substr(11,2).c_str());
                m=std::atoi(line.substr(14,2).c_str());
                time2 timeRTA;
                timeRTA.setHour(h);
                timeRTA.setMin(m);
                
                return timeRTA;
                
            
    }