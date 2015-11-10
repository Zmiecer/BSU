#include <iostream>
#include <string>

using namespace std;

void main ()
{
	string m[40];
	unsigned int s=0;
	int n=18;
	for (int i=0; i<n; i++)
		m[i]=97+i;
	//for (int i=0; i<n; i++)
		//s+=m[i];
	for (int i=0; i<n; i++)
		cout << m[i] << endl;
}