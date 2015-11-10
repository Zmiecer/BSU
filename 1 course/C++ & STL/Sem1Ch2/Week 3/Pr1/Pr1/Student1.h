#include <iostream>
#include "Student.h"

using namespace std;


class Student1 : public Student
{
public:
//protected:
	int ses1[4];

	void Ses1 (int *m);
	Student1& operator=(const Student&);
	Student1& operator=(const Student1&);
	void show();
	double ball();
};