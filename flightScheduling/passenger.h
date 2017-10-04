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

class Passenger {
private:
    int ID;
    int Destination;
    int currentLocation;
    int RTA;
public:

    /**
     * 
     * @Returns the ID.
     */
    int getID();

    /**
     * 
     * @Returns the Destination.
     */
    int getDestination();

    /**
     * 
     * @Returns the current location.
     */
    int getCurrentLocation();

    /**
     * 
     * @Returns the requested time arrival.
     */
    int getRTA();
};

#endif /* PASSENGER_H */

