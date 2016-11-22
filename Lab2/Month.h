#pragma once
class Month
{
private:
	int theMonth;


public:
	Month();
	~Month();
	
	bool setMonth(int);
	int getMonth() { return theMonth; }
};
