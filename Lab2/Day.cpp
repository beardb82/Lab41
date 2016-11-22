#include "stdafx.h"
#include "Day.h"


Day::Day()
{
	theDay = 0;
}


Day::~Day()
{
}
bool Day::setDay(int d)
{
	if ((1 <= d) && (31 >= d))

	{
		theDay = d;
		return true;
	}
	
	theDay = 0;
	return false;
}