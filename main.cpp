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
#include "graphics/aeroGUI.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
    std::vector<entity> v;
    v.emplace_back(3, 2, 4);
    v.emplace_back(2, 2, 5);
    v.emplace_back(3, 1, 4);
    v.emplace_back(2, 2, 5);
    v.emplace_back(3, 1, 4);
    v.emplace_back(2, 2, 5);
    v.emplace_back(3, 1, 4);
    v.emplace_back(2, 22, 5);
    v.emplace_back(3, 1, 4);
    v.emplace_back(2, 32, 5);
    v.emplace_back(3, 1, 4);
    v.emplace_back(25, 2, 5);
    v.emplace_back(3, 1, 14);
    v.emplace_back(21, 2, 5);
    v.emplace_back(3, 1, 78);
    
    QApplication app(argc, argv);

    aeroGUI gui;
    gui.openGUI();
    
    csvFileWriter w;
    w.openFile("test.csv");
    w.writeFile(v);
    w.closeFile();
    // create and show your widgets here

    return app.exec();
}
