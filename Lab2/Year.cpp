#include "stdafx.h"
#include "Year.h"


Year::Year()
{
	theYear = 0;
}


Year::~Year()
{
}

bool Year::setYear(int y)
{

	if ((1 <= y) && (10000 >= y))

	{
		theYear = y;
		return 1;
	}
	else
		theYear = 0;
	return 0;
}