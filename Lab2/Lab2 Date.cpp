// Lab2 
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Year.h"
#include "Month.h"
#include "Day.h"

using namespace std;

struct TestData {
	string test;
	int setTo;
	bool expect;
	int value;
	string description;
};

TestData getTestData(ifstream&);
void cheerleaders();
void funnyface();

int _tmain(int argc, _TCHAR* argv[])
{
	Year year;
	Month month;
	Day day;
	bool testResult;
	int testValue, noOfTests = 0, failedTests = 0;

	ofstream labOut("RodLab2Results.txt");
	if (!labOut)
	{
		cout << "Error opening output file \n";
		system("pause");
		return 1;
	}

	ifstream in ("RodLab2Test.txt");
	if (in)
	{
		TestData t;
		t = getTestData(in);
		while (in)
		{
			noOfTests++;
			if (t.test == "DC")
			{
				testResult = true;
				testValue = day.getDay();
			}
			else if (t.test == "YC")
			{
				testResult = true;
				testValue = year.getYear();
			}
			else if (t.test == "MC")
			{
				testResult == true;
				testValue == month.getMonth();
			}
			else if (t.test == "Y")
			{
				testResult = year.setYear(t.setTo);
				testValue = year.getYear();
			}
			else if (t.test == "M")
			{
				testResult = month.setMonth(t.setTo);
				testValue = month.getMonth();
			}
			else if (t.test == "D")
			{
				testResult = day.setDay(t.setTo);
				testValue = day.getDay();
			}

			if (testResult == t.expect && testValue == t.value) 
			{
				labOut << "passed " << t.description << endl;
			}
			else
			{
				failedTests++;
				labOut << "*** failed " << t.description << "  value = " << testValue << endl;
			}

			t = getTestData(in);
		}
	}
	else
	{
		cout << "input file not found\n";
	}

	labOut << "\n\n" << noOfTests << " tests run\n";
	labOut << failedTests << " tests failed\n";
	in.close();
	labOut.close();

	cout << "\n\n" << noOfTests << " tests run\n";
	cout << failedTests << " tests failed\n";

	noOfTests > 0 && failedTests == 0 ? cheerleaders() : funnyface();

	system("pause");
	return 0;
}

TestData getTestData(ifstream &in)
{
	TestData t;
	char nextChar;

	//  skip the comment lines in the parameter testing file
	nextChar = in.peek();
	while (nextChar == '/' && !in.eof())
	{
		in.ignore(100,'\n');
		nextChar = in.peek();
	}

	if (!in.eof()) in >> t.test >> t.setTo >> t.expect >> t.value >> t.description;

	return t;
}
//-----------------------------------------------------------
void funnyface()
{
	cout << "\n\n\n Sorry - some tests failed \n";
	cout << "                              \\./        \n";
	cout << "                             (o o)       \n";
	cout << "-------------------------oOOo-(_)-oOOo-------------------------\n\n\n";
}
//-----------------------------------------------------------
void cheerleaders()
{
	cout << "\n\n\nAll Tests Passed\n\nHERE'S THE CHEERLEADERS! \n\n";
	cout << "\n     *\\o_               _o/*  \n";
	cout << "      /  *             *  \\  \n";
	cout << "     <\\                   /> \n\n\n\n";
}