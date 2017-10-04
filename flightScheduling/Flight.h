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
#include <iostream>
#include <iomanip>
#include <string.h>
#include "../util/time.h"


class Flight {
private:
	time * departureTime;
	time * arrivalTime;
	std::string departureAirport;
	std::string arrivalAirport;
	int FlightNumber;
	int PassengerCount;
public:
	std::string PrintFlight();
};

#endif /* FLIGHT_H */

