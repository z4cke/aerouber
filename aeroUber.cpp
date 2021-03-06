/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//#define debugFiles

#ifdef debugFiles
    #define airportFile "airport-test.csv"
    #define fleetFile "fleet.csv"
    #define aircraftFile "aircraft-test.csv"
    #define outputFile "output.csv"
#else
    #define airportFile "airport.csv"
    #define fleetFile "fleet.csv"
    #define aircraftFile "aircraft.csv"
    #define outputFile "output.csv"
#endif

#include "aeroUber.h"
#include <string>
#include <iostream>

AeroUber::AeroUber():gui(this){
    
    loadFiles();
    gui.openGUI();
 
}

void AeroUber::startScheduler(){
    loadPassengerRequests();
    std::cout << "Starting calculator" << std::endl; 
    scheduler.startScheduleFlights(passengerList, aircraftList, airportList);
    std::cout << "Calculation complete" << std::endl; 
    
    
    std::cout << "Starting output" << std::endl; 
    csvFileWriter writer;
    
    writer.openFile(outputFile);
    writer.writeFile(passengerList);//scheduler.getFlights());
    writer.closeFile();
    std::cout << "Output complete" << std::endl; 
    
    
    std::cout << "Return to gui" << std::endl; 
    gui.openGUI();
    
}

void AeroUber::loadFiles(){
    csvFileReader reader;
   
    // reads airport file and fills the airport vector.
    reader.openFile(airportFile);
    reader.readFile(airportList);
    reader.closeFile();

    // reads fleet file and fills the aircraft vector.
    reader.openFile(fleetFile);
    reader.readFile(fleetList);
    reader.closeFile();
   
    //reads aircraft file and fills the aircraft vector.
    reader.openFile(aircraftFile);
    reader.readFile(aircraftList);
    reader.closeFile();
    
    aircraft::connectAircraftToFleet(aircraftList, fleetList);

}

void AeroUber::loadPassengerRequests(){
    csvFileReader reader;
    
    reader.openFile(gui.getPath());
    reader.readFile(passengerList);
    reader.closeFile();
    std::cout << "Passenger requests loaded." << std::endl; 
}



