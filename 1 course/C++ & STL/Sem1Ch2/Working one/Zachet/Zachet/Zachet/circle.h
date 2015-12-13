#include "point.h"

using namespace std;

class Circle : public Point
{
public:
	int r;

	Circle ()
	{
		x=0;
		y=0;
		r=0;
	}

	Circle (int x1, int y1, int r1)
	{
		x=x1;
		y=y1;
		r=r1;
	}

	Circle (Circle& c)
	{
		x=c.x;
		y=c.y;
		r=c.r;
	}

	Circle& operator = (Circle& c)
	{
		x=c.x;
		y=c.y;
		r=c.r;
		return *this;
	}

	friend istream& operator>>( istream& is, Circle& c )
    {
        int x1, y1, r1;
		cout << "Vvedite coordinaty Ox & Oy & radius of circle: " << endl;
        is >> x1 >> y1 >> r1;
		c.x=x1;
		c.y=y1;
		c.r=r1;

        return is;
    }

    friend ostream& operator<<( ostream& os, const Circle& c )
    {
		return os << "Ox: " << c.x << "Oy: " << c.y << "Radius: " << c.r;
	}
};