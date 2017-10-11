/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "time.h"


//Default constructor
time::time(){
    h=m=s=0;
}

time::time(double sec){ //ND constructor (tar in sekunder)
    int h,m,s;
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

time time::CompareTime(time &one){
    time comparedtime(0);
    
    int timma = h - one.h;
    int minut = m - one.m ;
    
    if(timma < 0){timma = -timma;}
    if(minut < 0){minut = -minut;}
    comparedtime.h = timma;
    comparedtime.m = minut;
    return comparedtime;
}

int time::getHour(){
    return h;
}

int time::getMin(){
    return m;
}




