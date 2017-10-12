# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = aerouber
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += aeroUber.cpp flightScheduling/Flight.cpp flightScheduling/FlightScheduler.cpp flightScheduling/aircraft.cpp flightScheduling/airport.cpp flightScheduling/fleet.cpp flightScheduling/passenger.cpp graphics/aeroForm.cpp graphics/aeroGUI.cpp io/csvFileReader.cpp io/csvFileWriter.cpp io/fileReader.cpp io/fileWriter.cpp main.cpp util/entity.cpp util/time.cpp
HEADERS += aeroUber.h flightScheduling/Flight.h flightScheduling/aircraft.h flightScheduling/airport.h flightScheduling/fleet.h flightScheduling/flightScheduler.h flightScheduling/passenger.h graphics/aeroForm.h graphics/aeroGUI.h io/csvFileReader.h io/csvFileWriter.h io/fileReader.h io/fileWriter.h util/entity.h util/time.h
FORMS += graphics/aeroForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
equals(QT_MAJOR_VERSION, 4) {
QMAKE_CXXFLAGS += -std=c++11
}
equals(QT_MAJOR_VERSION, 5) {
CONFIG += c++11
}
