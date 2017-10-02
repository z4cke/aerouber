/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   flightScheduler.h
* Author: Kinfai Chin
*
* Created on den 2 oktober 2017, 16:31
*/

#ifndef FLIGHTSCHEDULER_H
#define FLIGHTSCHEDULER_H

#include "Flight.h"
#include <vector>
#include <iostream>
#include <iomanip>
class FlightScheduler {
private:
	std::vector<Flight> *scheduledFlights = new std::vector<Flight>;

public:
	void startScheduleFlights(std::vector<passenger> &Passengers, std::vector<aircraft> &Aircraft, std::vector<airport> &Airports) {
		/*
		* Main program that assigns and creates flights depensing on passenger reuqest and the location of the aircraft.
		* The calculations and scheduling starts using the lists of passengers, aircraft and airports.
		* When the scheduling is done the flights will be insterted into the vector scheduledFlights.
		*/
	}

	double calculateDistance(Airport Origin, Airport Destination, Aircraft Aircraft) {
		/*
		* Caucluates the distance between two airports depending on which aircraft is being used due to the difference
		* in cruising altitude between different aircraft.
		*/

	}

	Time calcuateTime(double distance, Aircraft Aircraft) {
		/*
		* Takes the distance and aircraft speed to calculate the time it takes to reach destination.
		*/
	}

	std::vector<Flight> getFlights() {
		return scheduledFlights;
	}

};

#endif /* FLIGHTSCHEDULER_H */

