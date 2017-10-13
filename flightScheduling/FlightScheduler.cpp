/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <cmath>
#include <algorithm>

void FlightScheduler::startScheduleFlights
(std::vector<Passenger> &Passengerlist, std::vector<aircraft> &Aircraft, std::vector<Airport> &Airports){
    
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
            Flight newFlights(0, 0, p.getCurrentLocation(), p.getDestination(), Flightnumber, Airports);
            newFlights.addPassenger(&p);
            scheduledFlights.push_back(newFlights);
            Flightnumber++;
        }
    }
    
    
    std::sort(scheduledFlights.begin(),scheduledFlights.end()); //Sortering av listan.
    
    for(Flight &f : scheduledFlights){
        for(aircraft &a : Aircraft){
            if(a.getCurrentLocation() == f.getdepartureAirportCode()){ //För varje flygplan på platsen.
                if(f.Aircraft == nullptr)
                    if(calculateDistance(f.getdepartureAirport(),f.getarrivalAirport(),a) < (double)a.getFleet().getMaxRange()){
                        f.Aircraft = &a;
                    }
                else{
                    if(f.Aircraft->getSeats() < a.getSeats()){
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
        }   
    } 
} //Funktionens slut



double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, aircraft &Aircraft){
    double A1 = (Origin.getLat() * M_PI)/180;
    double B1 = (Origin.getLon() * M_PI)/180;
    double A2 = (Destination.getLat() * M_PI)/180;
    double B2 = (Destination.getLon() * M_PI)/180;
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



time2 FlightScheduler::calculateTime (double distance, aircraft &Aircraft){ 
    int speed = Aircraft.getFleet().getSpeed();
    distance = distance / 1000; //Conversion to from M to KM
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