#include "Matrix.h"

using namespace std;

Matrix fillA(int n)
{
	Matrix A(n, n);
	A[0][0] = 2.2;
	A[0][1] = 1;
	A[0][2] = 0.5;
	A[0][3] = 2;
	A[1][0] = 1;
	A[1][1] = 1.3;
	A[1][2] = 2;
	A[1][3] = 1;
	A[2][0] = 0.5;
	A[2][1] = 2;
	A[2][2] = 0.5;
	A[2][3] = 1.6;
	A[3][0] = 2;
	A[3][1] = 1;
	A[3][2] = 1.6;
	A[3][3] = 2;
	return A;
}

Matrix Danilevsky(Matrix A)
{
	int n = A.maxsize();
	Matrix M(n, n);

	Matrix MM(n, n);
	for (int i = 0; i < n; i++)
		MM[i][i] = 1;

	for (int j = 0; j < n - 1; j++)
	{
		M.clear();
		for (int i = 0; i < n; i++)
			M[i][i] = 1;
		for (int i = 0; i < n; i++)
		{
			if (n - 2 - j != i)
				M[n - 2 - j][i] = -A[n - 1 - j][i] / A[n - 1 - j][n - 2 - j];
			else
				M[n - 2 - j][i] = 1.0 / A[n - 1 - j][n - 2 - j];
		}
		A = (M ^ (-1))*A*M;
		MM *= M;
	}
	cout << "Frobenius matrix: " << endl << fixed << A;

	Matrix y(4, 1);
	double yy = 5.65203;
	y[3][0] = 1;
	for (int i = 2; i >= 0; i--)
		y[i][0] = y[i + 1][0] * yy;

	cout << endl << "Eigenvector: " << endl << (MM*y);
	return A;
}

int main()
{
	int n = 4;
	Matrix A = fillA(n);
	Danilevsky(A);
}