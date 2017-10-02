/* 
 * File:   fileReader.h
 * Author: zacke
 *
 * Created on den 2 oktober 2017, 16:56
 */

#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <vector>
#include <string>

/*
 * fileReader is a object that stores the path, stream and a bool var for the
 * state of the file. Virtual member function readFile that needs to be defined in the derived class
 * 
 * Attributes:
 * @path The path to the files to be read. Given by the user.
 * @file The stream for the program to read from the file..
 * @fileOpened The state of the file. True if its open, false if its closed.

 */
class fileReader{
protected:
    std::string path;
    std::ifstream file;
    bool fileOpened;
public:
    template <typename type>
    /*
     * pure virtual function readFile
     * @param reference to the vector 
     * return
     */
    virtual void readFile(std::vector<type>& list)=0;
    /*
     * function closeFile
     * Closes the opened file
     */
    void closeFile();
    /*
     * function openFile
     * @param filePath is the path to the file given by the user
     */
    bool openFile(std::string filePath);
    
};



#endif /* FILEREADER_H */

