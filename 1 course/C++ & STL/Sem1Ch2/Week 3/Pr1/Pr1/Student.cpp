#include "Student.h"

using namespace std;

Student::Student()
{
	Group=0;
	Name="0";
}

Student::Student(int a, string b)
{
	Group=a;
	Name=b;
	
}

Student& Student::operator= (const Student& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	return *this;
}

void Student::show()
	{
		cout << Group << " " << Name << " ";
	}

double Student::ball()
{
	return 0;
}

Student::~Student()
{
    //delete[] &Name;
	//cout << "Deleted" << endl;
}