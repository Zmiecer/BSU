//5.	Найти все положительные простые дроби и их количество, знаменатель которых меньше заданного натурального числа.
#include <iostream>
#include <cmath>
using namespace std;
int n, i, k, r, f, m;

void main()
{ cout << "Vvedite n" << endl;;
	cin >> n;
	cout << "Vse protye droby, znamenatel kotoryh menshe n:" << endl;
	r=0;
	m=0;
	for (i=2; i<n; i++) { for (k=1; k<i; k++) {
		for (f=2; f<n; f++) if (k%f==0 && i%f==0) m++;
				  if (m==0) {cout << k << "/" << i << " "; r++;} m=0;}}
	cout << "Ih kolichestvo:" << r << endl;
	cout << rand ();
}