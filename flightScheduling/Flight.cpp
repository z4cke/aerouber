/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Flight.h"





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
Flight::Flight(time2 aT, time2 dT, std::string dA, std::string aA, int ID, int PassengerCount,aircraft *AAircraft){
    FlightNumber = ID;
    this->PassengerCount = PassengerCount;
    arrivalAirport = aA;
    arrivalTime = aT;
    departureAirport = dA;
    departureTime = dT;
    Aircraft = nullptr;
}


std::string Flight::PrintFlight() const{
    return "FLIGHT";
}

std::string& operator <<(std::string &s, const Flight& flight ){
    s = flight.PrintFlight();
    return s;
}




   std::string Flight::getdepartureAirport(){
       return departureAirport;
   }
   
   
   
   std::string Flight::getarrivalAirport(){
       return arrivalAirport;
   }
   int Flight::getID(){
       return FlightNumber;
   }
   
   int Flight::getPassengerCount(){
       return PassengerCount;
   }
   
   
   void Flight::setID(int ID){
        FlightNumber = ID;
   }
   
   void Flight::setPassengerCount(int Count){
       PassengerCount = Count;
   }




