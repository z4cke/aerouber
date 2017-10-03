/* 
 * File:   fileWriter.cpp
 * Author: simjoh161
 *
 * Created on October 2, 2017, 6:39 PM
 */

#include "fileWriter.h"

/**
 * Opens a the file to write to at specified path.
 * 
 * @param filePath A std::string of the path to the file.
 * @return true if the file was opened successfully, false otherwise.
 */
bool fileWriter::openFile(std::string filePath){
    /** opens the file*/
    file.open(filePath, std::ofstream::out);
    
    /** checks if the file is opened*/
    fileOpened = file.is_open();
    return fileOpened;
}
    
/**
 * Cleans up and shutdowns the stream to the file.
 */
void fileWriter::closeFile(){
    /** if the file is opened close the file */
    if(fileOpened)
        file.close();
}