/* 
 * File:   csvFileWriter.h
 * Author: simjoh161
 *
 * Created on October 2, 2017, 5:12 PM
 */

#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H
#include "fileWriter.h"
#include <sstream>

/**
 * Writes all elements in a vector to a .csv file.
 */
class csvFileWriter : public fileWriter
{
    /**
     * Prints all values of an object to a .csv file.
     * 
     * @param values A string filled with all values that should be output for one object.
     */
    void printFileType(std::string& values){
        std::istringstream iss(values);
        std::string word;
        while(iss >> word) {
            /* do stuff with word */
            file << word;
            if(!iss.eof())
                file << ",";
        }
        file << std::endl;
    }
};


#endif /* CSVFILEWRITER_H */

