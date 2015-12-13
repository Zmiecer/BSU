#include "point.h"

using namespace std;

Point::Point()
	{
		x=0;
		y=0;
	}

Point::Point (int x1, int y1)
	{
		x=x1;
		y=y1;
	}

Point::Point (Point& p)
	{
		x=p.x;
		y=p.y;
	}


double Point::rasst()
	{
		return abs(sqrt((double)(x*x + y*y)));
	}