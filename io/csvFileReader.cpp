/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "csvFileReader.h"
#include <iostream>
#include <sstream>

std::string csvFileReader::readFileType(std::string& line){
    std::string unformated="";
    std::string temp;
    std::istringstream ss(line);
    int c = 0;
    while(getline(ss,temp,',')){
        unformated+=temp;
        unformated+=" ";
        c++;
//        std::cout<<"count: "<<c<<std::endl;
//        std::cout<<unformated<<std::endl;
//        std::cout<<temp<<std::endl;
     
    }
    return unformated;
}


//template <typename type>
//void csvFileReader::readFile(std::vector<type>& list){
//    std::string rad;
//    if(fileOpened = true){
//        while(getline(file,rad)){
//            std::cout<<rad<<std::endl;
//        }
//    }
//}
//void csvFileReader::readFile(std::vector<entity>& list){
//    std::string rad;
//    std::cout<<"Hejsan"<<std::endl;
//    if(fileOpened = true){
//        while(getline(file,rad)){
//            std::cout<<rad<<std::endl;
//        }
//    }
//}
