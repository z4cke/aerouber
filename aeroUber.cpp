/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define airportFile "airport.csv"
#define fleetFile "fleet.csv"
#define aircraftFile "aircraft.csv"
#define outputFile "output.csv"

#include "aeroUber.h"
#include "graphics/aeroGUI.h"
#include "io/csvFileWriter.h"
#include "io/csvFIleReader.h"
#include "flightScheduler.h"
#include "flightScheduler/passenger.h"
#include "flightScheduler/Flight.h"
#include "flightScheduler/Fleet.h"
#include "aeroGUI.h"

AeroUber::AeroUber(){
    
    loadFiles();
    gui.openGUI();
 
}

void AeroUber::startScheduler(){
    loadPassengerRequests();
    scheduler.startScheduleFlights(passengerList, aircraftList, airportList, fleetList);
    
    csvFileWriter writer;
    
    writer.openFile(outputFile);
    writer.readFile(outputFile);
    writer.closeFile();
    
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
    reader.read.File(aircraftList);
    reader.closeFile();
}

void AeroUber::loadPassengerRequests(){
    csvFileReader reader;
    
    reader.openFile(gui.getPath());
    reader.readFile(gui.getPath());
    reader.closeFile(gui.getPath());

}



