/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aeroForm.h
 * Author: simjoh161
 *
 * Created on October 6, 2017, 3:38 PM
 */

#ifndef _AEROFORM_H
#define _AEROFORM_H

#include "ui_aeroForm.h"

class aeroGUI;

class aeroForm : public QMainWindow {
    Q_OBJECT
public:
    aeroForm();
    void connectToGUI(aeroGUI* gui){this->gui = gui;}
    void resetTitle();
    std::string getPath();
    
public slots:
    void textChanged(const QString& text);
    void browseButtonClicked();
    void start_clicked();

private:
    Ui::aeroForm widget;
    aeroGUI* gui;
};

#endif /* _AEROFORM_H */
