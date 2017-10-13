/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Flight.h"
#include "airport.h"






        
//Non-default constructor
Flight::Flight(time2 aT, time2 dT, std::string dA, std::string aA, int ID, std::vector<Airport> &Airports){
    FlightNumber = ID;
    arrivalAirportCode = aA;
    arrivalTime = aT;
    departureAirportCode = dA;
    departureTime = dT;
    departureAirport = nullptr;
    arrivalAirport = nullptr;
    
    //Connect to airport
    for(Airport &a : Airports){
        if(departureAirport != nullptr && arrivalAirport != nullptr)
            break;
        
        
        if(departureAirport == nullptr){
            if(a.getICAO() == departureAirportCode)
                departureAirport = &a;
        }
        if(arrivalAirport == nullptr){
            if(a.getICAO() == arrivalAirportCode)
                arrivalAirport = &a;
        }
    }
    
    Aircraft = nullptr;
}


std::string Flight::PrintFlight() const{
    return "FLIGHT";
}

std::string& operator <<(std::string &s, const Flight& flight ){
    s = flight.PrintFlight();
    return s;
}




   std::string Flight::getdepartureAirportCode(){
       return departureAirportCode;
   }
   
   
   
   std::string Flight::getarrivalAirportCode(){
       return arrivalAirportCode;
   }
   
   Airport& Flight::getdepartureAirport(){
       return *departureAirport;
   }
   Airport& Flight::getarrivalAirport(){
       return *arrivalAirport;
   }
        
   
   
   int Flight::getID(){
       return FlightNumber;
   }
   
   int Flight::getPassengerCount() const{
       return Passengerlist.size();
   }
   
   
   void Flight::setID(int ID){
        FlightNumber = ID;
   }
   
   void Flight::addPassenger(Passenger *newPassenger){
       Passengerlist.push_back(newPassenger);
   }
   
   void Flight::removeExcessPassenger(){
       while(getPassengerCount() > Aircraft->getSeats()){
           Passengerlist[Passengerlist.size()-1]->removeFromFlight();
           Passengerlist.pop_back();//removes last passenger in the list.
       }
   }
   
   std::vector<Passenger*>& Flight::getPassengerlist(){
       return Passengerlist;
   }
   
   
  void Flight::setArrivalTime(time2 tid){
        arrivalTime = tid;
  }
  void Flight::setDepartureTime(time2 tid){
        departureTime = tid;
  }
  
  time2 Flight::getDepartureTime(){
      return departureTime;
  }
  
  time2 Flight::getArrivalTime(){
      return arrivalTime;
  }
  
  void Flight::cancelFlight(){
      while(getPassengerCount() > 0){
           Passengerlist[Passengerlist.size()-1]->removeFromFlight();
           Passengerlist.pop_back();//removes last passenger in the list.
       }
  }

  void Flight::confirmFlight(){
      for(Passenger *p : Passengerlist)
        p->addToFlight(this);
  }



