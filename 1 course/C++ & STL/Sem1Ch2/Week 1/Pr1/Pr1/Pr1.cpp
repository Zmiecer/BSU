#include <iostream>
#include <ostream>
#include <istream>
#include <conio.h>
#include <math.h>
#include "Complex.h"
#include "Stack.h"

using namespace std;


ostream &operator<<(ostream &out, Complex &c)
{
   out << c.re << " + i * " << c.im << "\n";
   
   return out;
}

istream &operator>>(istream &in, Complex &c)
{
   in >> c.re >> c.im;
   
   return in;
}

int main()
{
	double a,b,c,d;
	cout << "Vvedite 2 testovyh elementa:" << endl;
	cout << "Real:" << endl;
	cin >> a;	
	cout << "Image:" << endl;
	cin >> b;
	cout << "Real:" << endl;
	cin >> c;	
	cout << "Image:" << endl;
	cin >> d;
    Complex value1(a,b);
    Complex value2(c,d);
    
    cout << value1 << value2 << endl;
    cout << value1 + value2 << endl;
    cout << value1 - value2 << endl;
    cout << value1 * value2 << endl;
    cout << value1 / value2 << endl;    
    value1 = value2;
    cout << value1 << " = " << value2 << endl;

	Complex mass[20];
	int n;
	double x,y;
	cout << "Vvedite chislo elementov v massive: " << endl;
	cin >> n;
	cout << "Vvodite elementy massiva cherez Enter: " << endl;
    for (int i=0; i<n; i++)
	{
		cout << "Real:" << endl;
		cin >> x;
		cout << "Image:" << endl;
		cin >> y;
		mass[i] = Complex(x,y);
	}

	cout << "Vyvod elementov massiva:" << endl;
	for (int i=0; i<n; i++)
	{
		cout << mass[i];
	}

	Stack stach;
	double g,h;
	stach.Creation();
	cout << "Vvedite complex chislo dlya stack'a: " << endl;
	cin >> g >> h;
	Complex f(g,h);
	stach.Add(f);
	cout << "Top chislo:" << endl;
	cout << stach.Top();
	

    return 0;
}