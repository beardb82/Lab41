#include "stdafx.h"
#include "Date.h"
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include <iostream>
#include <string>
#include <iomanip>

Date::Date()
{
}


Date::~Date()
{
}

Date::Date(int y, int m, int d)
	{
		Date::setDate(y, m, d);
			
		return;
	}
 
  

bool Date::isLeapYear(int year)
	 {
		  if (year % 4 == 0)
		  {
			  return true;
		  }

		  return false;
  
	  }

bool Date::isValidDay(int year, int month, int day)

	  {
		  int monthDays[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		   
		  if (isLeapYear(year))
		  { 	 
			int month =  getMonth();
			if (day <= monthDays[month - 1])
			cout << year << " is a leap year" << endl;
			return true;
		  }
	      
		  return false;
	}
	
void Date:: setDate(string date)
	  {
		  //string input;
		  int n = 0;
		  int myArray[3];

		  istringstream ss(date);
		  string token;


		  while (getline(ss, token, '-')) {
			  myArray[n] = atoi(token.c_str());
			  n++;

		  }

		  if (setDate(myArray[2], myArray[0], myArray[1])) 
			{

			}
		  else
			{
			  cout << " String date is invalid " << " setting date to " << getDate() << endl;
			}


		  }

	  

	  
bool Date::setDate(int y, int m, int d  )

{
	if (isValidDay(y, m, d))
	{
		if (myYear.setYear(y)& myMonth.setMonth(m)& myDay.setDay(d))
		{

			return true;
		}

		myYear.setYear(1);
		myMonth.setMonth(1);
		myDay.setDay(1);
		return false;
	}
	return false;
}



