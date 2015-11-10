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


int Point::rasst(int a, int b)
	{
		return 6;//abs(sqrt((double)((x-a)*(x-a) + (y-b)*(y-b))));
	}