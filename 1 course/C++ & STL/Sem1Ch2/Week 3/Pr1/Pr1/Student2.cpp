#include "Student2.h"

using namespace std;

Student2& Student2::operator= (const Student& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	for (int i=0; i<4; i++)
	{
		ses1[i]=0;
	}
	for (int i=0; i<4; i++)
	{
		ses2[i]=0;
	}
	return *this;
}

Student2& Student2::operator= (const Student1& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	for (int i=0; i<4; i++)
	{
		ses1[i]=s.ses1[i];
	}
	for (int i=0; i<4; i++)
	{
		ses2[i]=0;
	}
	return *this;
}

Student2& Student2::operator= (const Student2& s)
{
	if (this == &s) return *this;
	Group=s.Group;
	Name=s.Name;
	for (int i=0; i<4; i++)
	{
		ses1[i]=s.ses1[i];
	}
	for (int i=0; i<4; i++)
	{
		ses2[i]=s.ses2[i];
	}
	return *this;
}


void Student2::Ses2 (int *m) 
{
	for (int i=0; i<4; i++) ses2[i]=m[i];
}

void Student2::show()
{
	cout << Group << " " << Name << " ";
	for (int i=0; i<4; i++)
	{
		cout << ses1[i] << " ";
	}
	for (int i=0; i<4; i++)
	{
		cout << ses2[i] << " ";
	}
}

double Student2::ball()
{
	int s=0;
	for (int i=0; i<4; i++)
		s+=ses1[i];
	for (int i=0; i<4; i++)
		s+=ses2[i];
	return (double)s/8;
}