/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   Flight.h
* Author: Kinfai Chin
*
* Created on den 2 oktober 2017, 16:59
*/

#ifndef FLIGHT_H
#define FLIGHT_H

#include "../util/time.h"
#include "aircraft.h"
#include "passenger.h"'
#include "airport.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string.h>

class Flight {
    
public:
     aircraft *Aircraft;
private:
	time2 departureTime;
	time2 arrivalTime;
	std::string departureAirportCode;
	std::string arrivalAirportCode;
        Airport * departureAirport;
        Airport * arrivalAirport;
	int FlightNumber;
        
        std::vector<Passenger*> Passengerlist;
        
public:
    
       
        
        
        bool operator< (const Flight &other) const {
            return getPassengerCount() < other.getPassengerCount();
        }
        
        std::string getdepartureAirportCode();
        std::string getarrivalAirportCode();
        
        Airport& getdepartureAirport();
        Airport& getarrivalAirport();
        
        std::vector<Passenger*>& getPassengerlist();
        
        void setArrivalTime(time2 tid);
        void setDepartureTime(time2 tid);
        
        time2 getDepartureTime();
        time2 getArrivalTime();
        
        
        int getID();
        int getPassengerCount() const;
        void setID(int ID);
        void addPassenger(Passenger *newPassenger);
        
        void removeExcessPassenger();
        

        //Non-default constructor
        Flight(time2 dT, time2 aT, std::string dA, std::string aA, int ID, std::vector<Airport> &Airports);
        
        std::string PrintFlight() const;
        
        friend std::string& operator <<(std::string &s, const Flight& flight );
};

#endif /* FLIGHT_H */

