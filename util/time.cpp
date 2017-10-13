/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "time.h"
#include <cstdlib>


//Default constructor
time2::time2(){
    h=m=s=0;
}

time2::time2(double sec){ //ND constructor (tar in sekunder)
    h = 0;
    m = 0;
    s = sec;
    while (s > 59){
        s = s - 60;
        m = m + 1;
        if(m > 59){
            m = m - 60;
            h = h + 1;
        }
    }
}

time2::time2(std::string line){
    s = 0;
    h=std::atoi(line.substr(11,2).c_str());
    m=std::atoi(line.substr(14,2).c_str());
}

 bool operator>(const time2& tid1,const time2& tid2){
    int tid1s = tid1.h * 3600 + tid1.m *60 + tid1.s;
    int tid2s = tid2.h * 3600 + tid2.m *60 + tid2.s;
    return (tid1s>tid2s);
 }
 
 time2 operator-(const time2& tid1,const time2& tid2){
    int tid1s = tid1.h * 3600 + tid1.m *60 + tid1.s;
    int tid2s = tid2.h * 3600 + tid2.m *60 + tid2.s;
    tid1s = tid1s - tid2s;
    
    time2 differans(tid1s);
    return differans;
 }

time2 time2::CompareTime(time2 &one){
    time2 comparedtime(0);
    
    int timma = h - one.h;
    int minut = m - one.m ;
    
    if(timma < 0){timma = -timma;}
    if(minut < 0){minut = -minut;}
    comparedtime.h = timma;
    comparedtime.m = minut;
    return comparedtime;
}

int time2::getHour(){
    return h;
}

int time2::getMin(){
    return m;
}

void time2::setHour(int hh){
    h = hh;
}

void time2::setMin(int mm){
    m = mm;
}

std::string time2::getTimeAsString(){
    return std::to_string(h)+"."+std::to_string(m)+"."+std::to_string(s);
}








