#include "stdafx.h"
#include <iomanip> 
#include <iostream>
#include <algorithm>

using namespace std;

const int n = 25;
long double matrix[n][n];
long double a[n], b[n], c[n], f[n];



void fillMatrix()
{
	const int k = 5;
	for (int i = 0; i < n; i++)
		f[i] = i + 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;

	matrix[0][0] = 25;
	for (int i = 0; i < n; i++)
	{
		c[i] = 20 - (long double)(i + 1) / k;
		matrix[i][i + 1] = c[i];
	}

	for (int i = 1; i < n; i++)
	{
		b[i] = 20 - c[i - 1];
		matrix[i][i] = b[i];
	}

	matrix[1][0] = 1;
	for (int i = 1; i < n - 1; i++)
	{
		a[i + 1 ] = (-1)*matrix[i][i - 1];
		matrix[i + 1][i] = a[i + 1];
	}

	/*for (int i = 0; i < n; i++)
	{
		cout << setw(3) << a[i] << " " << setw(3) << b[i] << " " << setw(3) << c[i] << endl;
	}*/

	a[0] = 0;
	a[1] = 1;
	b[0] = 25;
	c[24] = 0;
}

void matrixOut()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout /*<< fixed << setprecision(3)*/ << matrix[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	fillMatrix();

	long double alpha[n + 1], beta[n + 1];
	alpha[1] = -c[0] / b[0];
	beta[1] = f[0] / c[0];

	for (int i = 1; i < n; i++)
	{
		alpha[i + 1] = -c[i] / (a[i] * alpha[i] + b[i]);
		beta[i + 1] = (f[i] - a[i] * beta[i]) / (a[i] * alpha[i] + b[i]);
	}

	long double x[n];
	
	x[n - 1] = (f[n - 1] - a[n - 1] * beta[n - 1]) / (a[n - 1] * alpha[n - 1] + b[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];
	}
	
	
	matrixOut();
	for (int i = 0; i < n; i++)
	{
		cout << fixed << setw(3) << "x[" << setw(2) << i + 1 << setw(3) << "] = " << x[i] << endl;
	}
	
	
	/*
	for (int i = 0; i < n; i++)
		cout << a[i] * x[i-1] + b[i] * x[i] + c[i] * x[i+1] << endl;
	*/

	double nevyazka[n];
	for (int i = 0; i < n; i++)
	{
		nevyazka[i] = fabs(a[i] * x[i - 1] + b[i] * x[i] + c[i] * x[i + 1] - f[i]);
		cout << setw(3) << "nevyazka[" << setw(2) << i + 1 << setw(3) << "] = " << fixed << setprecision(3) << nevyazka[i] << endl;
	}
	cout << "Nevyazka: " << *max_element(nevyazka, nevyazka+n) << endl;
	return 0;
}
