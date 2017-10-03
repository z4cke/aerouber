#pragma once
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
	
/**
*Returns hour int
*/
	int getHour(); 
	
/**
* Returns minute int
*/

	int getMin(); 
	
/**
* Returns the time hh:mm
*/

	double getTime();
};
