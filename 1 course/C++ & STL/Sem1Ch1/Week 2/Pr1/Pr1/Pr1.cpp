//1.	Вычислить значение функции sin(x), используя разложение в ряд с точностью ? (вводятся x и ?)
#include <iostream>
#include <cmath>
using namespace std;
double p, e, s, x, k, n;
void main() 
{ 
	cout << "Vvedite x:" << endl;
        cin >> x;
        cout << "Vvedite tochnost e:" << endl;
	cin >> e;
	e=pow (10, -e);
	p=x;
	s=x;
	for (n=2; fabs (p)>e; n++) 
		{p=(-p*x*x)/(n*(n+1));
	//cout << p << endl;
	     s=s+p;}
	cout << "My sin(x)= " << s << endl;
        cout << "Real sin(x)= " << sin(x) << endl;
}