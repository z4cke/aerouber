#ifndef AEROGUI_H
#define AEROGUI_H

#include <string>
#include "aeroForm.h"

class aeroGUI
{
private:
    std::string requestPath;
    aeroForm gui;
    //aeroUber* aero;

public:
    
    aeroGUI();
    
    //aeroUber* aero);
    
    
    
    /**
    * Starts the GUI.
    */
    void openGUI();
    
    /**
    * returns path
    */
    std::string getPath();
    
    
    /**
     * Starts the scheduling in aeroUber.
     */
    void start();
		


};

#endif /* AEROGUI_H*/