//1.	Реализовать функцию сортировки числового массива по возрастанию (например «пузырьком»).

#include <iostream>
using namespace std;
int a[100], n, i;
void main()
{
	cout << "Vvedite kolichestvo elementov v massive:" << endl;
	cin >> n;
	cout << "Vvodite elementy massiva cherez Enter:" << endl;
	for (i=0; i<n; i++) cin >> a[i];
	for (i=0; i<n; i++)
	for (int j=0; j<n; j++)
		if (a[j]>a[j+1]) swap (a[j],a[j+1]);
	cout << "Otsortirovanniy massiv: " << endl;
	for (i=1; i<n; i++) cout << a[i] << ", ";
	cout << a[n] << endl;
}