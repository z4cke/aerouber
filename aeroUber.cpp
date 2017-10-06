/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define airportFile "airport.csv"

#include "aeroUber.h"
#include "graphics/aeroGUI.h"
#include "io/csvFileWriter.h"
#include "io/csvFIleReader.h"
#include "flightScheduler.h"
#include "flightScheduler/passenger.h"
#include "flightScheduler/Flight.h"
#include "flightScheduler/Fleet.h"

AeroUber::AeroUber(){
    csvFileReader reader;
    reader.openFile(airportFile);
}
void AeroUber::startScheduler(){
}

void AeroUber::loadFiles(){
}

void AeroUber::loadPassengerRequests(){
}



