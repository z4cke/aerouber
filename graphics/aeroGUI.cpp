/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "aeroGUI.h"
#include "../aeroUber.h"

aeroGUI::aeroGUI(AeroUber* aero):aero(aero){
    gui.connectToGUI(this);
}


void aeroGUI::openGUI(){
        gui.setEnabled(true);
        gui.show();
}

std::string aeroGUI::getPath(){
    return requestPath;
}

void aeroGUI::start(){
    gui.setEnabled(!gui.isEnabled());
    aero->startScheduler();
}