//2.	ѕроверить, €вл€етс€ ли натуральное число простым.
#include <iostream>
#include <cmath>
using namespace std;
int n, i, k;

void main()
{   cout << "Vvedite n" << endl;;
	cin >> n;
	k=0;
	cout << "Chislo yavlyaetsya ";
	for (i=2; i<=((n/2)+1); i++) {if ((n%i)==0) k++;}
    if ((k==0) || (n==2)) cout << "prostym." << endl; else cout << "sostavnym." << endl;
    }