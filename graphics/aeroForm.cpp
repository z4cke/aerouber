/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   aeroForm.cpp
 * Author: simjoh161
 *
 * Created on October 6, 2017, 3:38 PM
 */

#include "aeroForm.h"
#include <QFileDialog>
#include "aeroGUI.h"


aeroForm::aeroForm() {
    widget.setupUi(this);
    connect(widget.pathSection, SIGNAL(textChanged(const QString&)), this,
            SLOT(textChanged(const QString&)));
    connect(widget.browseButton, SIGNAL(released()), this,
            SLOT(browseButtonClicked()));
    connect(widget.startButton, SIGNAL(released()), this,
            SLOT(start_clicked()));

}


void aeroForm::textChanged(const QString& text){
    if(text.trimmed().length() < 5){
        widget.startButton->setEnabled(false);
        return;
    }
    widget.startButton->setEnabled(text.trimmed().endsWith(".csv"));
 
}

void aeroForm::browseButtonClicked(){
    
    QString path = QFileDialog::getOpenFileName(this, "Open File", "", "Passenger requests (*.csv)");
    if(path.length() > 0)
        widget.pathSection->setText(path);
}


void aeroForm::start_clicked(){
    setWindowTitle(QApplication::translate("aeroForm", "AeroUber - a flight scheduling software - calculating", 0, QApplication::UnicodeUTF8));
    setEnabled(false);
    gui->start();
}
