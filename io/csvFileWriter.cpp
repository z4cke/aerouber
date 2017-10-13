/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "csvFileWriter.h"

void csvFileWriter::printFileType(std::string& values){
    std::istringstream iss(values);
    std::string word;
    
    //gets word by word, separated by a space.
    while(getline(iss, word, ':')) {
        //print the value
        file << word;
        
        /*csv file, have commas separating each value on one line. 
         * The last value doesn't have a value after it*/
        if(!iss.eof())
            file << ",";
    }
    //each object is on a separate line.
    file << std::endl;
}