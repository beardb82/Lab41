#pragma once
class Year
{

private: int theYear;


public:
	Year();
	~Year();

	bool setYear(int);
	int getYear() { return theYear; }

};

