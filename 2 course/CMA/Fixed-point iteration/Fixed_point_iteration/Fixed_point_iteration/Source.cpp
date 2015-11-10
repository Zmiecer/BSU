#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int k = 60;
	long double x1[2], x2[2], x3[2];
	long double g[3];
	g[0] = 1.296296296f;
	g[1] = -2.71363636f;
	g[2] = -2.329090909f;

	long double a[4][4];
	a[1][1] = 0;
	a[2][2] = 0;
	a[3][3] = 0;

	a[1][2] = -0.333333f;
	a[1][3] = 0.555556f;
	a[2][1] = -0.272727f;
	a[2][3] = -0.5f;
	a[3][1] = 0.3272727f;
	a[3][2] = -0.2f;


	x1[0] = (long double)g[0];
	x2[0] = (long double)g[1];
	x3[0] = (long double)g[2];

	int j = 1;
	for (int i = 1; i <= k; i++)
	{
		
		if (j == 1)
		{
			x1[j] = a[1][2] * x2[j - 1] + a[1][3] * x3[j - 1] + g[0];
			x2[j] = a[2][1] * x1[j - 1] + a[2][3] * x3[j - 1] + g[1];
			x3[j] = a[3][1] * x1[j - 1] + a[3][2] * x2[j - 1] + g[2];
			j = 0;
		}
		else
		{
			x1[j] = a[1][2] * x2[j + 1] + a[1][3] * x3[j + 1] + g[0];
			x2[j] = a[2][1] * x1[j + 1] + a[2][3] * x3[j + 1] + g[1];
			x3[j] = a[3][1] * x1[j + 1] + a[3][2] * x2[j + 1] + g[2];
			j = 1;
		}

	}
	cout << "x1 = " << x1[j] << endl << "x2 = " << x2[j] << endl << "x3 = " << x3[j] << endl;
	long double nz1 = abs(2.7f*x1[j] + 0.9f*x2[j] - 1.5f*x3[j] - 3.5f);
	long double nz2 = abs(4.5f*x1[j] - 2.8f*x2[j] + 6.7f*x3[j] - 2.6f);
	long double nz3 = abs(5.1f*x1[j] + 3.7f*x2[j] - 1.4f*x3[j] + 0.14f);
	long double nz = max(max(nz1, nz2), nz3);
	cout << "Nevyazka = " << fixed << nz << endl;

}


//int main()
//{
//	int k = 100;
//	long double x1[1000], x2[1000], x3[1000];
//	long double g[3];
//	g[0] = 1.296296296f;
//	g[1] = -2.71363636f;
//	g[2] = -2.329090909f;
//
//	long double a[4][4];
//	a[1][1] = 0;
//	a[2][2] = 0;
//	a[3][3] = 0;
//
//	a[1][2] = -0.333333f;
//	a[1][3] = 0.555556f;
//	a[2][1] = -0.272727f;
//	a[2][3] = -0.5f;
//	a[3][1] = 0.3272727f;
//	a[3][2] = -0.2f;
//
//
//	x1[0] = (long double)g[0];
//	x2[0] = (long double)g[1];
//	x3[0] = (long double)g[2];
//
//	int j = 0;
//	for (int i = 1; i <= k; i++)
//	{
//		x1[i] = a[1][2] * x2[i - 1] + a[1][3] * x3[i - 1] + g[0];
//		x2[i] = a[2][1] * x1[i - 1] + a[2][3] * x3[i - 1] + g[1];
//		x3[i] = a[3][1] * x1[i - 1] + a[3][2] * x2[i - 1] + g[2];
//
//	}
//	cout << "x1 = " << x1[k] << endl << "x2 = " << x2[k] << endl << "x3 = " << x3[k] << endl;
//	long double nz1 = abs(2.7f*x1[k] + 0.9f*x2[k] - 1.5f*x3[k] - 3.5f);
//	long double nz2 = abs(4.5f*x1[k] - 2.8f*x2[k] + 6.7f*x3[k] - 2.6f);
//	long double nz3 = abs(5.1f*x1[k] + 3.7f*x2[k] - 1.4f*x3[k] + 0.14f);
//	long double nz = max(max(nz1, nz2), nz3);
//	cout << "Nevyazka = " << fixed << nz << endl;
//
//}


//int main()
//{
//	int k = 50;
//	long double x1[100], x2[100], x3[100];
//	long double g[3];
//	g[0] = 2.46;
//	g[1] = -1.82;
//	g[2] = -0.9;
//
//	long double a[4][4];
//	a[1][1] = 0;
//	a[2][2] = 0;
//	a[3][3] = 0;
//
//	a[1][2] = -0.09375;
//	a[1][3] = -0.55208;
//	a[2][1] = -0.85714;
//	a[2][3] = 0.035714;
//	a[3][1] = -0.21951;
//	a[3][2] = -0.45122;
//
//
//	x1[0] = g[0];
//	x2[0] = g[1];
//	x3[0] = g[2];
//
//
//	for (int i = 1; i <= k; i++)
//	{
//		x1[i] = a[1][2] * x2[i - 1] + a[1][3] * x3[i - 1] + g[0];
//		x2[i] = a[2][1] * x1[i - 1] + a[2][3] * x3[i - 1] + g[1];
//		x3[i] = a[3][1] * x1[i - 1] + a[3][2] * x2[i - 1] + g[2];
//	}
//	cout << x1[k] << " " << x2[k] << " " << x3[k] << endl;
//}

//int main()
//{
//	int k = 11;
//	long double x1[100], x2[100], x3[100];
//	long double g[3];
//	g[0] = 1.2;
//	g[1] = 1.3;
//	g[2] = 1.4;
//
//	long double a[4][4];
//	a[1][1] = 0;
//	a[2][2] = 0;
//	a[3][3] = 0;
//
//	a[1][2] = -0.1;
//	a[1][3] = -0.1;
//	a[2][1] = -0.2;
//	a[2][3] = -0.1;
//	a[3][1] = -0.2;
//	a[3][2] = -0.2;
//
//
//	x1[0] = 1.2;
//	x2[0] = 1.3;
//	x3[0] = 1.4;
//
//
//	for (int i = 1; i <= k; i++)
//	{
//		x1[i] = a[1][2]*x2[i - 1] + a[1][3]*x3[i - 1] + g[0];
//		x2[i] = a[2][1]*x1[i - 1] + a[2][3]*x3[i - 1] + g[1];
//		x3[i] = a[3][1]*x1[i - 1] + a[3][2]*x2[i - 1] + g[2];
//	}
//	cout << x1[k] << " " << x2[k] << " " << x3[k] << endl;
//}