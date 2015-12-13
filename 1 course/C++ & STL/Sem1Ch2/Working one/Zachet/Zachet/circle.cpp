#include "circle.h"

using namespace std;

Circle::Circle ()
	{
		x=0;
		y=0;
		r=0;
	}

Circle::Circle (int x1, int y1, int r1)
	{
		x=x1;
		y=y1;
		r=r1;
	}

Circle::Circle (Circle& c)
	{
		x=c.x;
		y=c.y;
		r=c.r;
	}