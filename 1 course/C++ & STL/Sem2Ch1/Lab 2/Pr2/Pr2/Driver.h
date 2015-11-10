#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip> 

using namespace std;


class Driver
{
public:
	int route;
	string surname;
	int number;
	string brand;

	Driver() 
	{
		route=0;
		surname="Undefined";
		number=0;
		brand="Undefined";
	}
	Driver(int a, string b, int c, string d) :  route(a), surname(b), number(c), brand(d) {}

	friend ostream& operator<<( ostream& os, const Driver& s )
    {
		cout << setw(10);
		return os << setw(3) << s.route << setw(10) << s.surname << setw(4) << s.number << setw(7) << s.brand;
	}

	void input(int a, string b, int c, string d)  
	{
		route=a;
		surname=b;
		number=c;
		brand=d;
	}

	Driver& operator=(const Driver& s)
	{
		if (this == &s) return *this;
		route=s.route;
		surname=s.surname;
		number=s.number;
		brand=s.brand;
		return *this;
	}
};