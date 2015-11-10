#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Student
{
public:
//protected:
	int Group;
	string Name;

	Student();
	Student (int a, string b);
    Student& operator=(const Student&);
	virtual void show();
	virtual double ball();
	~Student();

protected:
	friend istream& operator>>( istream& is, Student& s )
    {
        int j;
		string str;
        is >> j >> str;
		s.Group=j;
		s.Name=str;
        return is;
    }
    friend ostream& operator<<( ostream& os, const Student& s )
    {
        return os << s.Group << " " << s.Name;
	}
};