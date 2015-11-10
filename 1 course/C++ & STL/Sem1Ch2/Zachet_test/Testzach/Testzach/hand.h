#include <iostream>

using namespace std;

class hand
{
private:
public:
	int sila;

	hand()
	{
		sila=0;
	}

	virtual hand& operator = (hand &p)
	{
		sila=p.sila;
		return *this;
	}

	friend istream& operator>>( istream& is, hand& h )
    {
        int j;
        is >> j;
		h.sila=j;
        return is;
    }

    friend ostream& operator<<( ostream& os, const hand& h )
    {
		return os << h.sila;
	}
};

class lhand : public hand
{
public:
	lhand ()
	{
		sila=0;
	}

	lhand (int k)
	{
		sila=k;
	}

};

class rhand : public virtual hand
{
public:
	rhand ()
	{
		sila=0;
	}

	rhand (int k)
	{
		sila=k;
	}
};