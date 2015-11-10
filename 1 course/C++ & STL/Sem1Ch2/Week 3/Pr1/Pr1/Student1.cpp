#include "Student1.h"

using namespace std;

Student1& Student1::operator= (const Student& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	for (int i=0; i<4; i++)
	{
		ses1[i]=0;
	}
	return *this;
}
Student1& Student1::operator= (const Student1& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	for (int i=0; i<4; i++)
	{
		ses1[i]=s.ses1[i];
	}
	return *this;
}

void Student1::Ses1 (int *m)
{
	for (int i=0; i<4; i++) ses1[i]=m[i];
}

void Student1::show()
{
	cout << Group << " " << Name << " ";
	for (int i=0; i<4; i++)
	{
		cout << ses1[i] << " ";
	}
}

double Student1::ball()
{
	int s=0;
	for (int i=0; i<4; i++)
		s+=ses1[i];
	return (double)s/4;
}