/* 
 * File:   csvFileWriter.h
 * Author: simjoh161
 *
 * Created on October 2, 2017, 5:12 PM
 */

#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H
#include "fileWriter.h"

/**
 * Writes all elements in a vector to a .csv file.
 */
class csvFileWriter : public fileWriter
{

    /**
     * Prints all elements i a vector to a .csv file.
     * 
     * @param list A reference to a vector of elements that will be written to opened file.
     */
    template <typename type>
    void writeFile(std::vector<type>& list);

};


#endif /* CSVFILEWRITER_H */

