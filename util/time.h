#ifndef TIME_H
#define TIME_H

/**
*Time object is used to calculate and evaluate flight scheduling for passengers. 
*/

class time2
{
private:

/**
*int h, m, s are used to store following hour, minute and seconds. 
*/
	int h, m, s;

public:
    //default constructor
    time2();
    
    
    //Non-default constructor (TAR BARA IN SEKUNDER)
    time2(double sec);
    
    time2 setTime(int hour, int min, int sec);
    
    time2 CompareTime(time2& tajm);
	
/**
*Returns hour int
*/
	int getHour(); 
	
/**
* Returns minute int
*/

	int getMin(); 
       
        
        void setMin(int hh);
        void setHour(int mm);
	

};
#endif
