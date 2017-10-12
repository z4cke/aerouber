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

#ifdef TIME_H
#include <iostream>
#include <iomanip>
#include <string.h>

class Flight {
private:
	time2 * departureTime;
	time2 * arrivalTime;
	std::string departureAirport;
	std::string arrivalAirport;
	int FlightNumber;
	int PassengerCount;
        
public:
	
        //Default constructor
        Flight();
        
        //Non-default constructor
        Flight(time2 dT, time2 aT, std::string dA, std::string aA, int ID, int PassengerCount);
        
        std::string PrintFlight() const;
        
        friend std::string& operator <<(std::string &s, const Flight& flight );
};

#endif /* FLIGHT_H */
#endif
