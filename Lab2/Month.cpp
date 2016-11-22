#include "stdafx.h"
#include "Month.h"


Month::Month()
{
	theMonth = 0;
}


Month::~Month()
{


}
bool Month::setMonth(int m)
{
	if ((1 <= m) && (12 >= m))

	{
		theMonth = m;
		return true;
	}
	else
		theMonth = 0;
	return false;
}