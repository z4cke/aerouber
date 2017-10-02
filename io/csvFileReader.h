/* 
 * File:   csvFileReader.h
 * Author: zacke
 *
 * Created on den 2 oktober 2017, 17:48
 */

#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H
/*
 * Inherit from the the parent class FileReader. Stores the data and sorts them into created vector.
 */
class csvFileReader:public fileReader{
public:
    /*function readFile
     *Reads the file of type ‘csv’ and puts the data into the vector.
     */
    template <typename type>
    void readFile(std::vector<type>& list);
};


#endif /* CSVFILEREADER_H */

