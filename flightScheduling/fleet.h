/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fleet.h
 * Author: Kinfai Chin
 *
 * Created on den 6 oktober 2017, 10:33
 */

#ifndef FLEET_H
#define FLEET_H
#include <sstream>
#include <string>

class fleet{
private:
    std::string AircraftModel;
    int inService;
    int PassengerCapacity;
    int MaxRange;
    int CruisingSpeed;
    int CruisingHeight;
public:
    fleet(std::string line){
    std::istringstream ss(line);
        
        ss>>inService;
        ss>>PassengerCapacity;
        ss>>MaxRange;
        ss>>CruisingSpeed;
        ss>>CruisingHeight;
    }

    
    std::string getAircraftModel();
    int getinService();
    int getPassengerCapacity();
    int getMaxRange();
    int getSpeed();
    int getHeight();
};



#endif /* FLEET_H */
