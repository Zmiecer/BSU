#include <iostream>
#include "hand.h"

using namespace std;

class robot
{
public:
	int r, l;
	robot ()
	{
		r=0;
		l=0;
	}

	robot (lhand lf, rhand rf)
	{
		r=rf.sila;
		l=lf.sila;
	}

	int difference ()
	{
		int temp=abs(r-l);
		return temp;
	}
};