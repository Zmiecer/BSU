#include "Str10.h"

using namespace std;

Str10::Str10(int m)
{
	str[0] = m;
    str[1] = '\0';
}

int Str10::operator + (Str10 &s)
{
	int temp;
	temp=atoi(str) + atoi(s.str);
	return temp;
}

int  Str10::Chislo()
{
	int temp;
	temp=atoi(str);
	return temp;
}

bool Str10::operator >= (Str10 &s)
{
	int temp1, temp2;
	temp1=atoi(str);
	temp2=atoi(s.str);
	if (temp1>temp2) return true;
	else return false;
}

bool Str10::operator <= (Str10 &s)
{
	int temp1, temp2;
	temp1=atoi(str);
	temp2=atoi(s.str);
	if (temp1<temp2) return true;
	else return false;
}

void Str10::Sravnim(Str10 k2)
{
	int temp1, temp2;
	temp1=atoi(str);
	temp2=atoi(k2.str);
	if (temp1>temp2) cout << "Первое число больше второго." << endl;
		else 
			if (temp1==temp2) cout << "Числа равны." << endl;
			else cout << "Второе число больше первого." << endl;
}

/*::~Str10()
{
    delete [] str;
}

void Str10::Clear()
{
    delete[] str;
    n = 0;
    str = new char[n + 1];
    str[0] = '\0';
 
}*/