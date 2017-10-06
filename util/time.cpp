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

time::time(double sec){
    h = 0;
    m = 0
    s = sec;
    s = (s + 1) % 60;
	if (s == 0)
	{
		m = (m + 1) % 60;
		if(m == 0)
			h = (h + 1) % 24;
	}
}

time time::CompareTime(time &one, time &two){
    
    time comparedtime;
    
    int timma = one.h - two.h;
    int minut = one.m - two.m;
    
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




