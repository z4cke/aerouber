/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define airportFile "airport-test.csv"
#define fleetFile "fleet.csv"
#define aircraftFile "aircraft-test.csv"
#define outputFile "output.csv"


#include "aeroUber.h"
#include <string>

AeroUber::AeroUber():gui(this){
    
    loadFiles();
    gui.openGUI();
 
}

void AeroUber::startScheduler(){
    loadPassengerRequests();
    scheduler.startScheduleFlights(passengerList, aircraftList, airportList);
    
    csvFileWriter writer;
    
    writer.openFile(outputFile);
    writer.writeFile(scheduler.getFlights());
    writer.closeFile();
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

}



