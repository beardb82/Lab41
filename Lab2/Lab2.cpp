// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Day.h"
#include "Date.h"
#include "Month.h"
#include "Year.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
Date date;
Day day;
Month month;
Year year;
int main()
{


	ofstream myfile;


	int DayAray[] = { 0, 10, 25, 32, 28 };
	int MonthAray[] = { 0, 10, 12, 13, 2 };
	int YearAray[] = { 0, 1981, 1492, 10001, 2004 };
	int size;
	size = sizeof DayAray / sizeof(int);
	myfile.open("Date.txt");

	try
		{
			date.setDate("13-14-1982");  // No string in front of setDate
			

		}

		catch (exception e)

		{
			myfile << "your string date was not valid";
			date.setDate(1, 1, 1);
		}
	
	for (int i = 0; i < size; i++)
	{




		bool good; 
		good = date.setDate(YearAray[i], MonthAray[i], DayAray[i]);   // No need for this, can be accomplished in your if statement 

		if (good)
		{
			myfile << "This date is ok " << date.getDate() << endl;
		}


		else
		{

			myfile << setfill('0') << setw(2) << MonthAray[i] << "-" << setw(2) << DayAray[i] << "-" << setw(4) << YearAray[i] << " is not a valid date" << endl;
		}

		



		
	}
		myfile.close();
		system ("pause"); 
			return 0;
}