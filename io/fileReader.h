/* 
 * File:   fileReader.h
 * Author: zacke
 *
 * Created on den 2 oktober 2017, 16:56
 */

#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "../flightScheduling/airport.h"
#include "../flightScheduling/fleet.h"
#include "../flightScheduling/aircraft.h"
#include "../flightScheduling/passenger.h"

/*
 * fileReader is a object that stores the path, stream and a bool var for the
 * state of the file. Virtual member function readFile that needs to be defined in the derived class
 * 
 * Attributes:
 * @path The path to the files to be read. Given by the user.
 * @file The stream for the program to read from the file..
 * @fileOpened The state of the file. True if its open, false if its closed.

 */
class fileReader{
protected:
    std::string path;
    std::ifstream file;
    bool fileOpened;
    virtual std::string readFileType(std::string& line) = 0;
public:
    template <typename type>
    /*
     * pure virtual function readFile
     * @param reference to the vector 
     * return
     */
    void readFile(std::vector<type>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                //std::cout<<readFileType(rad)<<std::endl;
                list.emplace_back(readFileType(rad));
            }
        }
    }
    
    void readFile(std::vector<Passenger>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                std::string checkValue = readFileType(rad);
                if(checkValue == "Passenger ID")continue;
                
                int ID = std::stoi(checkValue);
                std::string Destination = readFileType(rad);
                int currentLocation = std::stoi(readFileType(rad));
                std::string RTA = readFileType(rad);
                
                list.emplace_back(ID, Destination, currentLocation, RTA);
            }
        }
    }
    
    void readFile(std::vector<aircraft>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                std::string checkValue = readFileType(rad);
                if(checkValue == "ID")continue;
               
                std::string losID = checkValue;
                std::string losModelos = readFileType(rad);
                int losSeatos = std::stoi(readFileType(rad));
                std::string CL = readFileType(rad);
                list.emplace_back(losID, losModelos, losSeatos, CL);
            }
        }
    }
    
    void readFile(std::vector<fleet>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                std::string AircraftModel = readFileType(rad);
                int inService = std::stoi(readFileType(rad)); 
                int PassengerCapacity = std::stoi(readFileType(rad));
                int MaxRange = std::stoi(readFileType(rad));
                int CruisingSpeed = std::stoi(readFileType(rad));
                int CruisingHeight = std::stoi(readFileType(rad));
                
                list.emplace_back(AircraftModel, inService, PassengerCapacity, MaxRange, CruisingSpeed, CruisingHeight);
            }
        }
    }
    
    void readFile(std::vector<Airport>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                int id = std::stoi(readFileType(rad));
                std::string name = readFileType(rad);
                std::string city = readFileType(rad);
                std::string country = readFileType(rad);
                std::string iata = readFileType(rad);
                std::string icao = readFileType(rad);
                double lat = std::stod(readFileType(rad));
                double lon = std::stod(readFileType(rad));
                int alt = std::stoi(readFileType(rad));
                int zone = std::stoi(readFileType(rad));
                char dst = readFileType(rad)[0];
                std::string tz = readFileType(rad);
                
                std::string readType = readFileType(rad);
                Airport::airportType type;
                if(readType == "airport")
                    type = Airport::airportType::airport;
                else
                    type = Airport::airportType::U;
                
                
                std::string source = readFileType(rad);
                
                list.emplace_back(id, name, city, country, iata, icao, lat, lon,
                        alt, zone, dst, tz, type, source);
                
                
            }
        }
    }
    
    /*
     * function closeFile
     * Closes the opened file
     */
    void closeFile();
    /*
     * function openFile
     * @param filePath is the path to the file given by the user
     */
    bool openFile(std::string filePath);
    
};



#endif /* FILEREADER_H */

