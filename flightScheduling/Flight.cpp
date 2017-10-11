/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Flight.h"



std::string Flight::PrintFlight(){
    return "FLIGHT";
}


Flight::Flight(){
    FlightNumber = 0;
    PassengerCount = 0;/*
    arrivalAirport;
    arrivalTime;
    departureAirport;
    departureTime;
    */
}
        
//Non-default constructor
Flight::Flight(time2 dT, time2 aT, std::string dA, std::string aA, int ID, int PassengerCount){
    FlightNumber = ID;
    this->PassengerCount = PassengerCount;
    /*
    arrivalAirport = aA;
    arrivalTime = aT;
    departureAirport = dA;
    departureTime = dT;
     */
}