#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip> 

using namespace std;


class Man
{
public:
	string type;
	string name;
	string surname;

	Man() 
	{
		type="Undefined";
		name="Undefined";
		surname="Undefined";
	}
	Man(string a, string b, string c) :  type(a), name(b), surname(c) {}

	friend ostream& operator<<( ostream& os, const Man& s )
    {
		cout << setw(10);
		return os << setw(10) << s.type << setw(10) << s.name << setw(10) << s.surname;
	}

	void input(string a, string b, string c)  
	{
		type=a;
		name=b;
		surname=c;
	}

	Man& operator=(const Man& s)
	{
		if (this == &s) return *this;
		type=s.type;
		name=s.name;
		surname=s.surname;
		return *this;
	}
};