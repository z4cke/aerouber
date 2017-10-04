/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "fileReader.h"
bool fileReader::openFile(std::string filePath){
    file.open(filePath.c_str());
    fileOpened = file.is_open();
    return fileOpened;
}
void fileReader::closeFile(){
    if(file.is_open()){
        file.close();
        fileOpened = file.is_open();
    }
}