#include <iostream>

using namespace std;

class Point
{
public:
	int x;
	int y;

	Point();
	Point (int x1, int y1);
	Point (Point& p);

	virtual Point& operator = (Point& p)
	{
		x=p.x;
		y=p.y;
		return *this;
	}

	friend istream& operator>>( istream& is, Point& p )
    {
        int x1, y1;
		cout << "Vvedite coordinaty Ox & Oy: " << endl;
        is >> x1 >> y1;
		p.x=x1;
		p.y=y1;
        return is;
    }

    friend ostream& operator<<( ostream& os, const Point& p )
    {
		return os << "Ox: " << p.x << "Oy: " << p.y;
	}

	double rasst();
};