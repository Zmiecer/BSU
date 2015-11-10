#include <iostream>
using namespace std;


int find (int c[], int n, int val)
{
	int a,b,m;
	for (a=0, b=n-1; a<=n;)
	{
		m=(a+b)/2;
		if(c[m]==val)
			return m;
		if(c[m]>val)
			b=m-1;
		else
		{
			if (val<c[m+1]) return m+1;
			a=m+1;
		}
	}

}

int main()
{ 
	int a[100];
	int x, i, n, k;
	cout << "Vvedite chislo elementov v massive: "<< endl;
	cin >> n;
	cout << "Vvodite elementy massiva cherez Enter: "<< endl;
	for (i=0; i<n; i++) 
		cin >> a[i];
	cout << "Vvedite element, kotoryi neobhodimo vstavit v massiv: "<< endl;
	cin >> x;
	k=find(a, n, x);
	cout << "Nomer iskomoi pozicii: "<< endl;
	cout << k+1;
	cout << endl;
}