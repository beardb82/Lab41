// Lab3
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include "Date.h"

using namespace std;

struct TestData {
	string test;
	int setToYear;
	int setToMonth;
	int setToDay;
	bool expectBool;
	int expectInt1;
	int expectInt2;
	int expectInt3;
	string expectString;
	string description;
};

TestData getTestData(ifstream&);
void cheerleaders();
void funnyface();

int _tmain(int argc, _TCHAR* argv[])
{
	Date date;

	bool testResult, expectResult;
	int noOfTests = 0, failedTests = 0;

	ofstream labOut("RodLab3Results.txt");
	if (!labOut)
	{
		cout << "Error opening output file \n";
		system("pause");
		return 1;
	}

	ifstream in("RodLab3Test.txt");
	if (in)
	{
		TestData t;
		t = getTestData(in);
		while (in)
		{
			noOfTests++;
			testResult = expectResult = true;

			if (t.test == "SetDate")	// test the setDate (int yr, int mo, int da)
			{
				testResult = date.setDate(t.setToYear, t.setToMonth, t.setToDay);
				if (testResult != t.expectBool || date.getYear() != t.expectInt1 || date.getMonth() != t.expectInt2 || date.getDay() != t.expectInt3)
				{
					expectResult = false;
					labOut << "*** failed " << t.description << endl;
					labOut << "  expect: " << t.expectInt1 << ends << t.expectInt2 << ends << t.expectInt3 << endl;
					labOut << "received:" << date.getYear() << ends << date.getMonth() << ends << date.getDay() << endl;
				}
			}
			else if (t.test == "GetDate")		// test the getDate that returns date as a string
			{
				testResult = date.setDate(t.setToYear, t.setToMonth, t.setToDay);
				if (t.expectString != date.getDate())
				{
					expectResult = false;
					labOut << "*** failed " << t.description << endl;
					labOut << "  expect: " << t.expectString << endl;
					labOut << "received: " << date.getDate() << endl;
				}
			}
			else if (t.test == "Over")
			{
				testResult = t.expectBool;
				Date date2;
				date2.setDate(t.setToYear, t.setToMonth, t.setToDay);
				if (date2.getYear() != t.expectInt1 || date2.getMonth() != t.expectInt2 || date2.getDay() != t.expectInt3)
				{
					expectResult = false;
					labOut << "*** failed " << t.description << endl;
					labOut << "  expect: " << t.expectInt1 << ends << t.expectInt2 << ends << t.expectInt3 << endl;
					labOut << "received:" << date2.getYear() << ends << date2.getMonth() << ends << date2.getDay() << endl;
				}
			}

			if (testResult == t.expectBool && expectResult)
			{
				labOut << "passed test " << noOfTests << ends << t.description << endl;
			}
			else
			{
				failedTests++;
				labOut << "failed test " << noOfTests << ends << t.description << endl;
			}

			t = getTestData(in);
		}
	}
	else
	{
		cout << "input file not found\n";
	}

	labOut << "\n\n" << noOfTests << " tests run\n" << failedTests << " tests failed\n";
	cout   << "\n\n" << noOfTests << " tests run\n" << failedTests << " tests failed\n";

	labOut.close();
	in.close();

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
		in.ignore(100, '\n');
		nextChar = in.peek();
	}

	if (!in.eof())
		in >> t.test >> t.setToYear >> t.setToMonth >> t.setToDay >> t.expectBool >>
		t.expectInt1 >> t.expectInt2 >> t.expectInt3 >> t.expectString >> t.description;

	return t;
}

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