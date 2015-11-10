//2.	Вычислить число  π с точностью ε по формуле π=4(1-1/3+1/5-1/7+1/9. . . )
#include <iostream>
#include <cmath>
using namespace std;
double p, e, s, x, k, n;
void main() 
{
    cout << "Vvedite tochnost e:" << endl;
	cin >> e;
	e=pow (10, -e);
	p=1;
	s=1;
	for (n=2; fabs (p)>e; n++) 
		{p=-p*((2*n)-3)/((2*n)-1);
	cout << p << endl;
	     s=s+p;}
	cout << "Chislo pi= " << 4*s << endl;
}