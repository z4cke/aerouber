/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <fleet.h>


std::string fleet::getAircraftModel(){
    return AircraftModel;
}
int fleet::getinService(){
    return inService;
}

int fleet::getPassengerCapacity(){
    return PassengerCapacity;
}
int fleet::getMaxRange(){
    return MaxRange;
}
int fleet::getSpeed(){
    return CruisingSpeed;
}
int fleet::getHeight(){
    return CruisingHeight;
}