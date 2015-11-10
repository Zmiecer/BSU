#include <iostream>
#include <windows.h>

using namespace std;

typedef int MATRIX[2][2];


static MATRIX* foo()
{
	MATRIX m;
	MATRIX m1;

	cout << "Enter the first matrix" << endl;
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)
			cin >> m1[i][j];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m[i][j] = (m1[i][j]);// *2;
			cout << m[i][j] << ' ';
		}

		cout << endl;
	}
	return &m;
}


int main()
{
	MATRIX* m2 = foo();
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			cout << *(m2[i][j]) << ' ';
		cout << endl;
	}
	int y = GetKeyState(VK_LCONTROL);
	cout << hex << y << endl;
	return 0;
}