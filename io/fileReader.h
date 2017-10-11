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
#include <iostream>

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
    virtual std::string readFileType(std::string& line) = 0;
public:
    template <typename type>
    /*
     * pure virtual function readFile
     * @param reference to the vector 
     * return
     */
    void readFile(std::vector<type>& list){
        std::string rad;
        if(fileOpened == true){
            while(getline(file, rad)){
                //std::cout<<readFileType(rad)<<std::endl;
                list.emplace_back(readFileType(rad));
            }
        }
    }
    
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

