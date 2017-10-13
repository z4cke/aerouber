/* 
 * File:   fileWriter.h
 * Author: simjoh161
 *
 * Created on October 2, 2017, 5:01 PM
 */

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include <vector>

/**
 * Writes all elements in a vector to a file.
 * 
 * @path std::string with path to the file to write to.
 * @file std::ofstream a stream to output to the file.
 * @fileOpened true if the file is opened, false otherwise.
 */
class fileWriter{
protected:
    std::string path;
    std::ofstream file;
    bool fileOpened;
    
    /**
     * A pure virtual function.
     * Prints all values of one object to the file, with the formating for a certain type defined in subclass.
     * 
     * @param values A string filled with all values, separated with a ':', that should be output for one object.
     */
    virtual void printFileType(std::string& values) = 0;
    
public:
    
    
    
    /**
     * Prints all elements in a vector to a file of a certain type. The structure of a printing 
     * for different file types has to be implemented in a subclass for the desired file output.
     * 
     * @param list A reference to a vector of elements that will be written to opened file.
     */
    template <typename type>
    void writeFile(std::vector<type>& list){
        std::string values;
        for(type& v : list){
            values << v;
            printFileType(values);
        }
    }
    
    /**
     * Opens a the file to write to at specified path.
     * 
     * @param filePath A std::string of the path to the file.
     * @return true if the file was opened successfully, false otherwise.
     */
    bool openFile(std::string filePath);
    
    /**
     * Cleans up and shutdowns the stream to the file.
     */
    void closeFile();
    
};


#endif /* FILEWRITER_H */

