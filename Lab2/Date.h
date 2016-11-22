#pragma once
#include "Year.h"
#include "Day.h"
#include "Month.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Date

{
private:
	Day myDay;
	Month myMonth;
	Year myYear;



public:

Date::Date(int y, int m , int d);
	Date();
	~Date();

	
	int getYear() { return myYear.getYear(); }
	int getMonth() { return myMonth.getMonth(); }
	int getDay() { return myDay.getDay(); }

	bool  setDate(int y, int m, int d);
	void  setDate(string date);
	bool isLeapYear(int year);
	
	bool isValidDay(int year, int month, int day);
	
	

string getDate()
	 {
		 stringstream ss;
		 ss << setfill('0') << setw(2) << getMonth() << '-' << setw(2) << getDay() << '-' << setw(4) << getYear() << setfill(' ');
		 return ss.str();
	 }
};
