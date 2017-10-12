/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "csvFileReader.h"
#include <iostream>
#include <sstream>

#define debug

#ifdef debug

//skickar tillbaka ett värde, och tar bort värdet från line.
std::string csvFileReader::readFileType(std::string& line){
    std::string unformated="";
    std::string temp;
    std::istringstream ss(line);
    
    std::cout <<"Orginal > "<< line << std::endl;
    if(getline(ss,temp,',')){
        if(temp[0]=='"'){ //removes quatiations
            
            temp=temp.substr(1,(temp.length()-1) -1); // temp.length()-1 is the last index
            //std::cout<<temp<<std::endl;
        }
        unformated+=temp;
        int startSub = line.find(",");
        if(startSub > 0) startSub += 1;//removes the ',' character
        else if(startSub < 0) startSub = 0;
        
        int subLength = (line.length()-startSub);
        
        line = line.substr(startSub, subLength);
    }
    std::cout <<"Klipp > "<< unformated << std::endl;
    std::cout <<"Ny > "<< line << std::endl;
    return unformated;
}
#else
std::string csvFileReader::readFileType(std::string& line){
    std::string unformated="";
    std::string temp;
    std::istringstream ss(line);
    while(getline(ss,temp,',')){
        if(temp[0]=='"'){ //removes quatiations
            
            temp=temp.substr(1,(temp.length()-1) -1); // temp.length()-1 is the last index
            //std::cout<<temp<<std::endl;
        }
        unformated+=temp;
        unformated+=" ";
        
     
    }
    return unformated;
}
#endif