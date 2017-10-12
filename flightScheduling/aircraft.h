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

#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "fleet.h"
#include <vector>

class aircraft{
private:
    std::string ID = "";
    std::string Model = "";
    int Seats = 0;
    std::string CurrentLocation = "";
    fleet *AircraftModel;
public:
    
    
//Non-default constructor
aircraft(std::string losID, std::string losModelos, int losSeatos, std::string CL);


    //Destructor
    ~aircraft();
    
//Copy constructor
aircraft(const aircraft& other);
    
//Copy-assignment constructor
aircraft& operator=(const aircraft& other);
    

    
    std::string getID();
    std::string getModel();
    int getSeats();
    std::string getCurrentLocation();
    fleet& getFleet();
    
    void connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet);
    
};

#endif /* AIRCRAFT_H */