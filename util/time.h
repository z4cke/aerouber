#ifndef TIME_H
#define TIME_H

/**
*Time object is used to calculate and evaluate flight scheduling for passengers. 
*/

class time
{
private:

/**
*int h, m, s are used to store following hour, minute and seconds. 
*/
	int h, m, s;

public:
    //default constructor
    time();
    
    
    //Non-default constructor (TAR BARA IN SEKUNDER)
    time(double sec);
    
    time setTime(int hour, int min, int sec);
    
    time CompareTime(time& tajm);
	
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
