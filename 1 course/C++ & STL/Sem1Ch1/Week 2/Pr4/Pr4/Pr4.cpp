//Определить количество нулей в числе N! , не вычисляя факториал числа.
#include <iostream>
#include <cmath>
using namespace std;
int i, n, e;
double p, s, x, k;
void main() 
{   
	cout << "Vvedite N:" << endl;
    cin >> n;
	s=0;
	e=1;
	for (k=1; pow(5,k)<=n; k++)
		{e=e*5;
	//cout << e << endl;
		for (i=1; i<=n; i++)
			if (i%e==0) s++;}
   cout << "Kolichestvo nulei v chisle N! = " << s << endl;
}