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
using namespace std;

class AeroUber{
    private:
        std::vector<Passenger> passengerList;
        std::vector<Fleet> fleetList;
        std::vector<Aircraft> aircraftList;
        std::vector<Airport> airportList;
    public:
        
        /**
        * 
        * A function to start the scheduler.
        */
        void startScheduler();
        
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

