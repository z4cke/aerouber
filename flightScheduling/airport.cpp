/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "airport.h"

using namespace std;

enum class airportType {Airport, Trainstation, Port, Unknown};

int Airport::getID() {
    return ID;
}

std::string Airport::getName() {
    return name;
}

std::string Airport::getCity() {
    return city;
}

std::string Airport::getCountry(){
    return country;
}

std::string Airport::getIATA() {
    return iata;
}

std::string Airport::getICAO() {
    return icao;
}

double Airport::getLat() {
    return lat;
}

double Airport::getLon() {
    return lon;
}

int Airport::getAlt() {
    return alt;
}

int Airport::getTimezone() {
    return zone;
}

char Airport::getDST() {
    return dst;
}

std::string Airport::getTz() {
    return tz;
}

Airport::airportType Airport::getType() {
    return type;
}

std::string Airport::getSource() {
    return source;
}

