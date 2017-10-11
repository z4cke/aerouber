/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   airport.h
 * Author: Erik Hammar
 *
 * Created on 02 October 2017, 22:19
 */

#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <sstream>


class Airport {
public:
    enum class airportType {airport, port, station, U}; 
private:
    int ID; /**The ID of the airport*/
    std::string name; /**Name of the airport*/
    std::string city; /**Name of the city where the airport is located*/
    std::string country; /**Name of the country where the airport is located*/
    std::string iata; /**The 3-letter code for the airport, NULL if not assigned*/
    std::string icao; /**The 4-letter code for the airport, NULL if not assigned*/
    double lat; /**Latitude of the airports geographical position*/
    double lon; /**Longitude of the airports geographical position*/
    int alt; /**Altitude of airport*/
    int zone; /**The timezone the airport is in*/
    char dst; /**If the airport is subjected to Daylight Savings Time, if then which*/
    std::string tz; /** Timezone in (Olson) format, eg. "America/Los_Angeles"*/
    airportType type; /**Type of communication center: Airport, trainstation etc.*/
    std::string source; /**The source of the airport data, for example "OurAirports"*/
    
public:
    Airport(int ID, std::string name, std::string city, std::string country, std::string iata, std::string icao, double lat, double lon, int alt, int zone, char dst, std::string tz, airportType type, std::string source):
    ID(ID), name(name), city(city), country(country), iata(iata), icao(icao), lat(lat), lon(lon), alt(alt), zone(zone), dst(dst), tz(tz), type(type), source(source)
    {};
    
    /**
     * Creates airport string
     * 
     * In each string it separates each value with a blank space
     * 
     * @return 
     */
        Airport(std::string line){
        std::istringstream ss(line);
        
        ss>>ID;
        ss>>city;
        ss>>country;
        ss>>iata;
        ss>>icao;
        ss>>lat;
        ss>>lon;
        ss>>alt;
        ss>>zone;
        ss>>dst;
        ss>>tz;
        std::string readType;
        ss>>readType;
        if(readType == "airport")
            type = airportType::airport;
        else
            type = airportType::U;
        ss>>source;
    }
       
    /**
     *  
     * @return the airport ID
     */
    int getID(); 
    
    /**
     * 
     * @return the airport name
     */
    std::string getName(); 
    
    /**
     * 
     * @return the city the airport serves
     */
    std::string getCity(); 
    
    /**
     * 
     * @return the country where the airport is located
     */
    std::string getCountry(); 
    
    /**
     * 
     * @return the airports IATA code
     */
    std::string getIATA();
    
    /**
     * 
     * @return the airports ICAO code
     */
    std::string getICAO();
    
    /**
     * 
     * @return the airport latitude position
     */
    double getLat(); 
    
    /**
     * 
     * @return the airports longitudinal position
     */
    double getLon();
    
    /**
     * 
     * @return the airports altitude
     */
    int getAlt();
    
    /**
     * 
     * @return the airports timezone
     */
    int getTimezone();
    
    /**
     * 
     * @return the airports Daylight Savings Time
     */
    char getDST(); 
    
    /**
     * 
     * @return the airports timezone in Olson format
     */
    std::string getTz(); 
    
    /**
     * 
     * @return the airports type
     */
    airportType getType(); 
    
    /**
     * 
     * @return the airports datasource
     */
    std::string getSource();
    
    /**
     * An enumeration to use for the type of the airport
     */
    //enum class airportType {Airport, Trainstation, Port, Unknown}; 
};

#endif /* AIRPORT_H */

