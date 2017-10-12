/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flightScheduler.h"
#include <math.h>

void FlightScheduler::startScheduleFlights
(std::vector<Passenger> &Passengerlist, std::vector<aircraft> &Aircraft, std::vector<Airport> &Airports){
    
    time2 hoho(3600);
    time2 hehe(7200);
    Flight Simon(hoho, hehe, "ESSA", "ESGN", 123, 1, nullptr);
    scheduledFlights.emplace_back(time2(3600), time2(7200), "ESSA", "ESGN", 123, 1, nullptr);
    scheduledFlights.push_back(Simon);
    
    

    //Första delen av algoritmen (Assigna alla passagerare till flights)
    int flightnumber = 1;
    std::vector<Flight> Flightlist;                             //lista med skapade flyg (TEMPORÄR, ALLT KOMMER SKICKAS IN I scheduledFlights NÄR BERÄKNINGAR ÄR FÄRDIGA.)
    
    std::vector<Passenger> PassengerlistCopy = Passengerlist;   //Kopia av listan som vi kan modifiera.
    std::vector<Passenger> finishedPassengers;                  //Lista med passagerare som fått flyg tilldelat till sig.
    
    while(!PassengerlistCopy.empty()){
        
        // TAR UT INFORMATION OM DEN PASSAGERARE VIARBETAR MED JUST NU.
        Passenger currentPassenger = PassengerlistCopy.back(); //Den passagerare vi arbetar med just nu.
        PassengerlistCopy.pop_back();
        std::string passengerOrigin = currentPassenger.getCurrentLocation();
        std::string passengerDestination = currentPassenger.getDestination();
        std::string RTA = currentPassenger.getRTA();
        
        //Kollar om flyg redan finns
        unsigned int i;
        for(i = 0; i <= Flightlist.size()+1;i++){ 
            std::string FlightOrigin = Flightlist[i].getdepartureAirport();
            std::string FlightDestination= Flightlist[i].getarrivalAirport();

            
            //Om flyg med samma origin/destination finns-
            if(FlightOrigin == passengerOrigin && FlightDestination == passengerDestination){
                currentPassenger.setID(Flightlist[i].getID());
                currentPassenger.setID(Flightlist[i].getID());                              //Ge passageraren flightnummer
                Flightlist[i].setPassengerCount(Flightlist[i].getPassengerCount() + 1);     //addera passagerarcount
                finishedPassengers.push_back(currentPassenger);                             //Pusha passagerare in i färdiga passagerar vektorn
            }
            
            
            //Om flyg med origin/destination inte finns
            unsigned int y = i + 1;
            if(y == Flightlist.size()){ 
            Flight newFlight(NULL, NULL, passengerOrigin, FlightDestination , flightnumber, 1, NULL); //Skapandet av ny flight
                currentPassenger.setID(newFlight.getID());                                      //Ge passageraren ett flightnummer.
                newFlight.setPassengerCount(newFlight.getPassengerCount() + 1);                  //addera 1 till passengercount
                finishedPassengers.push_back(currentPassenger);
                Flightlist.push_back(newFlight);
                flightnumber++;
            }
            
            //Tabort alla temporära referenser till objekt
            delete &currentPassenger;
            
        }
        delete &PassengerlistCopy;
    }
    
        //Andra delen av algoritmen (Tilldela flygplan till varje flight)
    
        // Skapar en lista med flygen fast sorterade beroende på antal passagerare.
    std::vector<Flight> FlightlistSorted;   
    
    while (!Flightlist.empty()){              //Kollar igenom varje flight.
        unsigned int y;
        int highestCount = 0;
        int vectorPosition;
        
        for(y = 0; y < Flightlist.size(); y++){
            if(Flightlist[y].getPassengerCount()> highestCount){
            highestCount = Flightlist[y].getPassengerCount();
            vectorPosition = y;
            }
        }
            
        Flight tempholder = Flightlist[vectorPosition];
        Flightlist.erase(Flightlist.begin()+y-1);
        FlightlistSorted.push_back(tempholder);
    }
    
    unsigned int i; //Kollar vilka flygplan som finns vid varje flygplats.
    for(i = 0; i < FlightlistSorted.size(); i++){ //För varje flight
        std::vector<aircraft> AircraftatOrigin; //Innehåller varje flygplan på den flygplatsen.
        int h = 0;
        while(h < Aircraft.size()){ //Kollar vilka plan som finns vid den flygplatsen.
            if(Aircraft[h].getCurrentLocation() == FlightlistSorted[i].getdepartureAirport()){
                AircraftatOrigin.push_back(Aircraft[h]);                                            //lägger till i vektorn om flygplanet är vid den flygplatsen
            }
        }
        
        //Kod för att assigna flygplan för flyget.
        int temp;
        for(temp = 0; temp < AircraftatOrigin.size(); temp++){
           /* if(FlightlistSorted[i].getPassengerCount() < AircraftatOrigin[temp].getSeats() 
                    && FlightlistSorted[i].Aircraft->getSeats()< AircraftatOrigin[temp].getSeats()){
                    FlightlistSorted[i]->Aircraft = AircraftatOrigin[temp];
            }*/
        }
        AircraftatOrigin.erase(AircraftatOrigin.begin() + temp - 1);
        
        
        
        
        
    }

        
        
        
        
#if 0
        /* KOD FÖR ATT HITTA POSITION AV FLYGPLATS*/
        int y = 0;
        int z = 0;
        while(Airports[y].getICAO() != FlightlistSorted[i].departureAirport){
            y++;
        }
        while(Airports[z].getICAO() != FlightlistSorted[i].arrivalAirport){
            z++;
        }
//        double distance = calculateDistance(&Airports[y],)
            
        
    }
    
        /* TREDJE DELEN AV ALGORITMEN (TILLDELA DEPARTURETIME OCH ARRIVALTIME) */


#endif
} //Funktionens slut



double FlightScheduler::calculateDistance(Airport &Origin, Airport &Destination, aircraft &Aircraft){
    double A1 = (Origin.getLat() * M_PI)/180;
    double B1 = (Origin.getLon() * M_PI)/180;
    double A2 = (Destination.getLat() * M_PI)/180;
    double B2 = (Destination.getLon() * M_PI)/180;
       double rad = 637100 + Aircraft.getFleet().getHeight();
    
    double deltaA = A1 - A2;
    double deltaB = B1 - B2;
    
    if (deltaA < 0){
        deltaA = -deltaA;
    }
    if (deltaB < 0){
        deltaB = -deltaB;
    }
    
    double a = sin(deltaA/2) * sin(deltaA/2) * cos(A1) * cos(A2) * sin(deltaB/2) * sin(deltaB/2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double distance = rad * c/1000;
    
    
    return distance; //in kilometers
}



time2 FlightScheduler::calculateTime (double distance, aircraft &Aircraft){ 
    int speed = Aircraft.getFleet().getSpeed();
    distance = distance / 1000; //Conversion to from M to KM
    double timmar = speed / distance;
    double sekunder = timmar*3600;
    time2 hoho(sekunder); //<-- Constructor
    
    return hoho;
}
    

    
    time2 FlightScheduler::stringtotimeconverter(std::string RTA){
                int h;
                int m;
                std::string line = RTA;
                h=std::atoi(line.substr(11,2).c_str());
                m=std::atoi(line.substr(14,2).c_str());
                time2 timeRTA;
                timeRTA.setHour(h);
                timeRTA.setMin(m);
                
                return timeRTA;
                
            
    }