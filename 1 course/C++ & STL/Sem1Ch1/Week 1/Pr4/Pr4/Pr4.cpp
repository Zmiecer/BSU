//4.	Найти количество различных цифр в записи заданного натурального числа.
#include <iostream>
#include <cmath>
using namespace std;
int n, i, k, r, p, a[100], b[100], j;

void main()
{cout << "Vvedite n" << endl;
	cin >> n;
	r=0;
		p=n;
        for(;p>0;r++) p/=10;
//cout << r; Количество цифр в числе
	cout << "Kolichestvo razlichnyh cifr chisla n: ";
	for (i=0; i<r; i++) {a[i]=n%10; n=n/10;};
   //for (i=0; i<r; i++) cout << a[i] << " "; Вывод массива цифр числа
   for (i=0; i<r; i++) 
	   for (j=0; j<=9; j++)  
		   if (a[i]==j) b[j]=1;
   k=0;
   //for (i=0; i<=9; i++) cout << b[i] << " ";
   for (i=0; i<=9; i++) 
	   if (b[i]==1) k++;
   cout << k << endl;
}