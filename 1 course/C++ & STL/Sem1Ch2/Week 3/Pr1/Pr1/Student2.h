#include <iostream>
#include "Student1.h"

using namespace std;


class Student2 : public Student1
	{
	public:
		int ses2[4];

		Student2& operator=(const Student2&);
		Student2& operator=(const Student1&);
		Student2& operator=(const Student&);
		void Ses2 (int *m);
		void show();
		double ball();
	};