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

#include "aircraft.h"
#include "Flight.h"
#include "airport.h"
#include "passenger.h"
#include <vector>
#include <iostream>
#include <iomanip>
class FlightScheduler {
private:
	std::vector<Flight> *scheduledFlights = new std::vector<Flight>;

public:
    FlightScheduler();
 
    
        /*
	* Main program that assigns and creates flights depensing on passenger reuqest and the location of the aircraft.
	* The calculations and scheduling starts using the lists of passengers, aircraft and airports.
	* When the scheduling is done the flights will be insterted into the vector scheduledFlights.
	*/
	void startScheduleFlights(std::vector<Passenger> Passengers, std::vector<aircraft> Aircraft, std::vector<Airport> Airports);
	/*
	* Caucluates the distance between two airports depending on which aircraft is being used due to the difference
	* in cruising altitude between different aircraft.
	*/
	double calculateDistance(Airport &Origin, Airport &Destination, aircraft &Aircraft);
        
        
        /* Takes the distance and aircraft speed to calculate the time it takes to reach the destination
         */
	time calcuateTime(double distance, aircraft &Aircraft);

	std::vector<Flight> getFlights() {
		return scheduledFlights;
	}

};

#endif /* FLIGHTSCHEDULER_H */

