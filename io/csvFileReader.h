/* 
 * File:   csvFileReader.h
 * Author: zacke
 *
 * Created on den 2 oktober 2017, 17:48
 */

#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H
#include "fileReader.h"
#include "entity.h"
/*
 * Inherit from the the parent class FileReader. Stores the data and sorts them into created vector.
 */

class csvFileReader : public fileReader{
    std::string readFileType(std::string& line);

    /*function readFile
     *Reads the file of type ‘csv’ and puts the data into the vector.
     */
//    template <typename type>
//    void readFile(std::vector<type>& list);
//    
//    void readFile(std::vector<entity>& list);
    
};


#endif /* CSVFILEREADER_H */

