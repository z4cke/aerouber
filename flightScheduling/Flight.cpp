/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Flight.h"



void Flight::PrintFlight(){

}


Flight::Flight(){
    Flight.FlightNumber = NULL;
    Flight.PassengerCount = NULL;
    Flight.arrivalAirport = NULL;
    Flight.arrivalTime = NULL;
    Flight.departureAirport = NULL;
    Flight.departureTime = NULL;
}
        
//Non-default constructor
Flight::Flight(int ID, int PassengerCount std::string aA time aT, std::string dA,time dT ){
    Flight.FlightNumber = ID;
    Flight.PassengerCount = PassengerCount;
    Flight.arrivalAirport = aA;
    Flight.arrivalTime = aT;
    Flight.departureAirport = dA;
    Flight.departureTime = dT;
}