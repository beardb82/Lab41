#pragma once
class Day
{
	private:
		int theDay;

public:
	Day();
	~Day();

	bool setDay(int);
	int getDay() { return theDay; }
};

