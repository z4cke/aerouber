/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "aircraft.h"


int getID();
std::string getModel();
int getSeats();
std::string getCurrentLocation;
    
fleet& getFleet();
    
void connectAircraftToFleet(std::vector<aircraft> &aircrafts, std::vector<fleet> &fleet);