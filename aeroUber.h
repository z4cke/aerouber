/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aeroUber.h
 * Author: Foad Ghafourian
 *
 * Created on 02 October 2017, 22:18
 */
#ifndef AEROUBER_H
#define AEROUBER_H

#include <vector>
#include "io/csvFileWriter.h"
#include "io/csvFileReader.h"
#include "flightScheduling/flightScheduler.h"
#include "flightScheduling/passenger.h"
#include "flightScheduling/Flight.h"
#include "flightScheduling/fleet.h"
#include "graphics/aeroGUI.h"

using namespace std;

class AeroUber{
    private:
        std::vector<Passenger> passengerList;
        std::vector<fleet> fleetList;
        std::vector<aircraft> aircraftList;
        std::vector<Airport> airportList;
        aeroGUI gui;
        FlightScheduler scheduler;
    public:
        /**
         *   
         * Non-default constructor for creating AeroUber and start
         * opening csvFiles, filling the lists with passenger information and
         * start scheduling. 
         */
        
        AeroUber();
        
        /**
        * 
        * A function to start the scheduler.
        */
        void startScheduler();
private:    
        /**
        * 
        * A function to load the files. 
        */
        void loadFiles();
        
        /**
        * 
        * A function to load all the passenger requests
        */
        void loadPassengerRequests();
};

#endif /* AEROUBER_H */

