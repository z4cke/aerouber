/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <math.h>
#include <vector>
#include <string>

void FlightScheduler::startScheduleFlights
(std::vector<Passenger> Passengers, std::vector<aircraft> Aircraft, std::vector<Airport> Airports){
    
    /* FÖRSTA DELEN AV ALGORITMEN (ASSIGNA ALLA PASSAGERARE TILL FLIGHTS)*/
    int flightnumber = 1;
    std::vector<Flight> Flightlist;
    std::vector<Passenger> finishedPassengers; //Lista för passagerare som fått ett flyg tilldelat till sig.
    while(!Passenger.empty()){
        Passenger tempPassenger = Passengers.back();  //Ta ut passagerare ur vektorn..
        Passengers.pop_back()
        std::string origin = tempPassenger.getCurrentLocation();
        std::string destination = tempPassenger.getDestination();
        std::string RTA = tempPassenger.getRTA();
        int i;
        for(i = 0; i < Flightlist.size();i++){ //Kollar om flyg redan finns
            std::string forigin = Flightlist[i].departureAirport;
            std::string fdestination = Flightlist[i].arrivalAirport;
            if(forigin == origin && fdestination == destination){ //Om flyg med samma origin/destination finns-
                tempPassenger.setID(Flightlist[i].FlightNumber); //Ge passageraren flightnummer
                Flightlist[i].PassengerCount = Flightlist[i].PassengerCount + 1; //addera passagerarcount
                finishedPassengers.push_back(tempPassenger); //Pusha passagerare in i färdiga passagerar vektorn
            }
        }
        y = i + 1;
        if(y = Flightlist.size()){ //Om flyg med origin/destination inte finns

            
            Flight newFlight(NULL,NULL,origin,destination,flightnumber,1); //Skapandet av ny flight
                tempPassenger.setID(newFlight.FlightNumber); //Ge passageraren ett flightnummer.
                newFlight.PassengerCount = newFlight.PassengerCount + 1; //addera 1 till passengercount
                finishedPassengers.push_back(tempPassenger);
                Flightlist.push_back(newFlight);
                flightnumber++;
            
        }
    }
        
    /* ANDRA DELEN AV ALGORITMEN (TILLDELA FLYGPLAN TILL VARJE FLIGHT)*/
    std::vector<Flight> FlightlistSorted;
    int i;
    
    while (!Flightlist.empty()){  //DENNA LOOP SÄTTER IN FLIGHTSEN TILL EN NY VEKTOR I STORLEKSORDNING.
        int highestCount = 0;
        int vectorposition;
         for(i = 0;i < Flightlist.size(); i++){
            if(Flightlist[i].PassengerCount > highestCount){
                mostpassengers = Flightlist[i].PassengerCount;
                vectorposition = i;
            }
        }
        Flight tempholder = Flightlist[vectorposition];
        Flightlist.erase(Flightlist.begin()+i-1);
        FlightlistSorted.push_back(tempholder);
    }
    
    for(i = 0; i < FlightlistSorted.size(); i++){ //För varje flight
        std::vector<aircraft> AircraftatOrigin; //Storear varje flygplan på den flygplatsen.
        int h = 0;
        while(h < Aircraft.size()){ //Kollar vilka plan som finns vid den flygplatsen.
            if(Aircraft[h].getCurrentLocation() == FlightlistSorted[i].departureAirport){
                AircraftatOrigin.push_back(Aircraft[h]); //lägger till i vektorn om flygplanet är vid den flygplatsen
            }
        }
        
        
        /* KOD FÖR ATT HITTA POSITION AV FLYGPLATS*/
        int y = 0;
        int z = 0;
        while(Airports[y].getICAO() != FlightlistSorted[i].departureAirport){
            y++;
        }
        while(Airports[z].getICAO() != FlightlistSorted[i].arrivalAirport){
            z++;
        }
        double distance = calculateDistance(&Airports[y],)
            
        
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
                timeRTA.setHour(h);
                timeRTA.setMin(m);
                
                
            
    }
