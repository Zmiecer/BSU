//2.	Написать функцию, которая  находит минимальный элемент массива. С использованием этой функции реализовать сортировку числового массива.

#include <iostream>
using namespace std;
int min (int *a, int n);
int f, h;

void main()
{ int n, i, p, l, y, b[100];

cout << "Vvedite chislo elementov v massive:" << endl;
cin >> n;

cout << "Vvodite elementy massiva cherez Enter:" << endl;
int a[100];
for (i=0; i<n; i++) cin >> a[i];

p=a[min(a, n)];
cout << "Minimum: " << p << endl;
l=n;
i=0;
for (int j=0; j<l; j++) 
          { 
              p=min(a, n);
			  b[i]=a[p];
			  //cout << p << endl;
              for (int k=p; k<n; k++) 
				  a[k]=a[k+1];
              n--;
			  i++;
          }
n=l;
for (i=0; i<n; i++) cout << b[i] << " ";
cout << endl;
}

int min (int *a, int n)
{
int i,j,t;
t=a[0];
f=0;
for (i=0; i<n; i++) for (j=0; j<=n-1; j++) if (a[j]<t) {t=a[j]; f=j;}
return f;}