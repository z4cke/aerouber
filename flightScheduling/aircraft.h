/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aircraft.h
 * Author: Kinfai Chin
 *
 * Created on den 6 oktober 2017, 10:27
 */
#include "fleet.h"
#ifndef AIRCRAFT_H
#define AIRCRAFT_H


class aircraft{
private:
    int ID;
    std::string Model;
    int Seats;
    std::string CurrentLocation;
    fleet &AircraftModel;
public:
    int getID();
    std::string getModel();
    int getSeats();
    std::string getCurrentLocation;
    
    fleet& getFleet();
    
    void connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet);
    
};

#endif /* AIRCRAFT_H */

