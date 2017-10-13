/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   passenger.h
 * Author: Foad Ghafourian
 *
 * Created on 02 October 2017, 22:19
 */

#ifndef PASSENGER_H
#define PASSENGER_H
#include <sstream>
#include <iostream>
#include <string>

class Flight;

class Passenger {
private:
    int ID;
    std::string Destination;
    std::string currentLocation;
    std::string RTA;
    Flight* bookedOnFlight;
public:
    Passenger(int ID, std::string Destination, std::string currentLocation, std::string RTA):ID(ID), Destination(Destination), currentLocation(currentLocation), RTA(RTA), bookedOnFlight(nullptr){
        
    }
    
    /**
     * 
     * @Returns the ID.
     */
    int getID();

    /**
     * 
     * @Returns the Destination.
     */
    std::string getDestination();

    /**
     * 
     * @Returns the current location.
     */
    std::string getCurrentLocation();

    /**
     * 
     * @Returns the requested time arrival.
     */
    std::string getRTA();
    
    void setID(int flightID);
    
    void addToFlight(Flight* newFlight);
    
    void removeFromFlight();
    
    friend std::string& operator <<(std::string &s, Passenger& passenger);
};

#endif /* PASSENGER_H */

