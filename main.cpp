/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: simjoh161
 *
 * Created on October 2, 2017, 4:47 PM
 */

#include <QApplication>
#include <vector>

#include "io/csvFileWriter.h"
#include "util/entity.h"
#include "aeroUber.h"
#include "graphics/aeroGUI.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
    QApplication app(argc, argv);
    // create and show your widgets here
    AeroUber aero;
    
    return app.exec();
}
