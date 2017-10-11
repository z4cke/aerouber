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
    
    /* FÖRSTA DELEN AV ALGORITMEN (ASSIGNA ALLA PASSAGERARE TILL FLIGHTS)*/
    int flightnumber = 1;
    std::vector<Flight> Flightlist;
    std::vector<Passenger> finishedPassengers;
    while(!Passenger.empty()){
        Passenger tempPassenger = Passengers.back(); 
        Passengers.pop_back()
        std::string origin = tempPassenger.getCurrentLocation();
        std::string destination = tempPassenger.getDestination();
        std::string RTA = tempPassenger.getRTA();
        int i;
        for(i = 0; i < Flightlist.size();i++){ //Checks if the flight already exists.
            std::string forigin = Flightlist[i].departureAirport;
            std::string fdestination = Flightlist[i].arrivalAirport;
            if(forigin == origin && fdestination == destination){
                tempPassenger.setID(Flightlist[i].FlightNumber); //Assignment of Flightnumber for the passenger.
                Flightlist[i].PassengerCount = Flightlist[i].PassengerCount + 1;
                finishedPassengers.push_back(tempPassenger);
            }
        }
        y = i + 1;
        if(y = Flightlist.size()){ //If desired flight doesnt exist yet.

            
            
            Flight newFlight(NULL,NULL,origin,destination,flightnumber,1); //Creation of new flight
                tempPassenger.setID(newFlight.FlightNumber); //Assignment of Flightnumber for the passenger.
                newFlight.PassengerCount = newFlight.PassengerCount + 1;
                finishedPassengers.push_back(tempPassenger);
                flightnumber++;
            
        }
    }
        
    /* ANDRA DELEN AV ALGORITMEN (TILLDELA FLYGPLAN TILL VARJE FLIGHT)*/
    std::vector<Flight> FlightlistSorted;
    int i;
    int flightnumber
    
    while (!Flightlist.empty()){  //DENNA LOOP SÄTTER IN FLIGHTSEN TILL EN NY VEKTOR I STORLEKSORDNING.
        int mostpassengers = 0;
        int flightnumber;
        for(i = 0;i < Flightlist.size(); i++){
            if(Flightlist[i].PassengerCount > mostpassengers){
                mostpassengers = Flightlist[i].PassengerCount;
                flightnumber = Flightlist[i].FlightNumber;
            }
        }
        
        
        FlightlistSorted.push_back(Flightlist[i]);
        Flightlist.erase(Flightlist.begin() + i - 1);
        
        
    }
    
    }
        /* TREDJE DELEN AV ALGORITMEN (TILLDELA DEPARTURETIME OCH ARRIVALTIME) */


        
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
    

    
    time FlightScheduler::stringtotimeconverter(std::string RTA){
                int h;
                int m;
                std::string line = RTA;
                h=std::atoi(line.substr(11,2).c_str());
                m=std::atoi(line.substr(14,2).c_str());
                time timeRTA;
                
                
            
    }
