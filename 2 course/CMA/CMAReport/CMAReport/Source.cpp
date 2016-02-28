#include "Matrix.h"
#include <math.h>
#include <fstream>

using namespace std;

ofstream fout;


Matrix fillA(Matrix A, int alpha)
{
	A[0][0] = 8;
	A[0][1] = 4;
	A[0][2] = 1;
	//A[0][3] = -1;
	A[1][0] = 3;
	A[1][1] = 5;
	A[1][2] = 4;
	//A[1][3] = 2;
	A[2][0] = 2 - alpha;
	A[2][1] = 3;
	A[2][2] = 1;
	//A[2][3] = 9;
	//A[3][0] = 5;
	//A[3][1] = 1;
	//A[3][2] = 1;
	//A[3][3] = 4;

	//cout << "Исходная A: " << endl << A << endl;

	A[0][0] = 2;
	A[0][1] = 1;
	A[0][2] = 1;
	//A[0][3] = 1;
	A[1][0] = 1;
	A[1][1] = 2;
	A[1][2] = 1;
	//A[1][3] = 1;
	A[2][0] = 1;
	A[2][1] = 1;
	A[2][2] = 2;
	//A[2][3] = 1;
	//A[3][0] = 1;
	//A[3][1] = 1;
	//A[3][2] = 1;
	//A[3][3] = 2;

	/*
	A[0][0] = 8;
	A[0][1] = 4;
	A[0][2] = 1;
	A[0][3] = -1;
	A[1][0] = 3;
	A[1][1] = 9;
	A[1][2] = 1;
	A[1][3] = -1;
	A[2][0] = 10;
	A[2][1] = -10;
	A[2][2] = 28;
	A[2][3] = 6;
	A[3][0] = -3;
	A[3][1] = 3;
	A[3][2] = 1;
	A[3][3] = 9;
	*/

	//cout << "A в канонической форме: " << endl << A << endl;

	return A;
}

Matrix fillf(Matrix f, int alpha)
{
	f[0][0] = alpha + 1;
	f[1][0] = 4;
	f[2][0] = 3;
	//f[3][0] = alpha - 5;

	//cout << "Исходный f: " << endl << f << endl;

	f[0][0] = 6;
	f[1][0] = 15;
	f[2][0] = -51;
	//f[3][0] = 3;

	//cout << "f в канонической форме: " << endl << f << endl;

	return f;
}

Matrix fillB(Matrix A)
{
	Matrix B(3, 3);
	B[0][0] = 0;
	B[0][1] = -A[0][1] / A[0][0];
	B[0][2] = -A[0][2] / A[0][0];
	//B[0][3] = -A[0][3] / A[0][0];
	B[1][0] = -A[1][0] / A[1][1];
	B[1][1] = 0;
	B[1][2] = -A[1][2] / A[1][1];
	//B[1][3] = -A[1][3] / A[1][1];
	B[2][0] = -A[2][0] / A[2][2];
	B[2][1] = -A[2][1] / A[2][2];
	B[2][2] = 0;
	//B[2][3] = -A[2][3] / A[2][2];
	//B[3][0] = -A[3][0] / A[3][3];
	//B[3][1] = -A[3][1] / A[3][3];
	//B[3][2] = -A[3][2] / A[3][3];
	//B[3][3] = 0;

	//cout << "Матрица B: " << endl << B << endl;

	return B;
}

Matrix fillg(Matrix A, Matrix f)
{
	Matrix g(3, 1);
	g[0][0] = f[0][0] / A[0][0];
	g[1][0] = f[1][0] / A[1][1];
	g[2][0] = f[2][0] / A[2][2];
	//g[3][0] = f[3][0] / A[3][3];

	//cout << "Вектор g: " << endl << g << endl;

	return g;
}

Matrix fixed_point_iteration(Matrix A, Matrix f, double ep)
{
	cout << endl;
	cout.width(50);
	cout << right << "Метод простых итераций" << endl << endl;

	fout << endl;
	fout.width(50);
	fout << right << "Метод простых итераций" << endl << endl;

	Matrix B(3, 3);
	B = fillB(A);

	Matrix g(3, 1);
	g = fillg(A, f);
	Matrix x(g);

	int k;
	k = (int)((log10(ep) + log10(1.0 - B.norm()) - log10(g.norm())) / log10(B.norm()));
	cout << "Необходимое количество итераций по условию сходимости: " << k << endl;
	fout << "Необходимое количество итераций по условию сходимости: " << k << endl;

	Matrix x0(x);

	k = 0;
	while (k > -1)
	{
		x0 = x;
		x = B*x + g;
		k++;
		if ((x - x0).norm() < ep)
			break;
	}
	cout << "Итоговое количество итераций по оценке поправки: " << k << endl;
	cout << endl << "Решение: " << endl << x << endl;
	fout << "Итоговое количество итераций по оценке поправки: " << k << endl;
	fout << endl << "Решение: " << endl << x << endl;


	return x;
}

double mult(Matrix A, Matrix B)
{
	double product = 0.0;

	for (int i = 0; i < A.maxsize(); i++)
		product += A[i][0] * B[i][0];

	return product;
}

Matrix gradient(Matrix A, Matrix f, double ep)
{
	cout << endl;
	cout.width(50);
	cout << right << "Метод градиентного спуска" << endl << endl;

	fout << endl;
	fout.width(50);
	fout << right << "Метод градиентного спуска" << endl << endl;

	Matrix x(f);

	int k = 0;
	
	Matrix r(4, 1);
	r = A*x - f;

	Matrix x0(x);

	while (k > -1)
	{
		x0 = x;
		x = x - (mult(r, r) / mult(r, A*r))*r;
		r = A*x - f;
		k++;
		if ((x-x0).norm() < ep)
			break;
	}

	cout << "Необходимое количество итераций: " << k << endl;
	cout << endl << "Решение: " << endl << x << endl;
	fout << "Необходимое количество итераций: " << k << endl;
	fout << endl << "Решение: " << endl << x << endl;


	return x;
}

Matrix fillL(Matrix A)
{
	Matrix B(3, 3);
	B[0][0] = 0;
	B[0][1] = 0;
	B[0][2] = 0;
	//B[0][3] = 0;
	B[1][0] = A[1][0];
	B[1][1] = 0;
	B[1][2] = 0;
	//B[1][3] = 0;
	B[2][0] = A[2][0];
	B[2][1] = A[2][1];
	B[2][2] = 0;
	//B[2][3] = 0;
	//B[3][0] = A[3][0];
	//B[3][1] = A[3][1];
	//B[3][2] = A[3][2];
	//B[3][3] = 0;

	//cout << "Матрица B: " << endl << B << endl;

	return B;
}

Matrix fillD(Matrix A)
{
	Matrix B(3, 3);
	B[0][0] = A[0][0];
	B[0][1] = 0;
	B[0][2] = 0;
	//B[0][3] = 0;
	B[1][0] = 0;
	B[1][1] = A[1][1];
	B[1][2] = 0;
	//B[1][3] = 0;
	B[2][0] = 0;
	B[2][1] = 0;
	B[2][2] = A[2][2];
	//B[2][3] = 0;
	//B[3][0] = 0;
	//B[3][1] = 0;
	//B[3][2] = 0;
	//B[3][3] = A[3][3];

	//cout << "Матрица B: " << endl << B << endl;

	return B;
}

Matrix relax(Matrix A, Matrix f, double ep)
{
	cout << endl;
	cout.width(50);
	cout << right << "Метод релаксации" << endl << endl;

	fout << endl;
	fout.width(50);
	fout << right << "Метод релаксации" << endl << endl;

	Matrix x(f);

	int k = 0;
	double w = 1;
	cout << "Введите w от 0 до 2: " << endl;
	cin >> w;
	while (w <= 0 || w >= 2)
	{
		cout << "Введите ещё раз: " << endl;
		cin >> w;
	}
	cout << endl;

	Matrix D(3, 3);
	Matrix L(3, 3);
	D = fillD(A);
	L = fillL(A);

	Matrix x0(x);

	while (k > -1)
	{
		x0 = x;
		x = ((D + w*L) ^ (-1))*(w*f - w*A*x + D*x + w*L*x);
		k++;
		if ((x - x0).norm() < ep)
			break;
	}

	cout << "Принятое значение w: " << w << endl;
	cout << "Необходимое количество итераций: " << k << endl;
	cout << endl << "Решение: " << endl << x << endl;

	fout << "Принятое значение w: " << w << endl;
	fout << "Необходимое количество итераций: " << k << endl;
	fout << endl << "Решение: " << endl << x << endl;
	

	return x;
}

Matrix zeidel(Matrix A, Matrix f, double ep)
{
	cout << endl;
	cout.width(50);
	cout << right << "Метод Зейделя" << endl << endl;

	fout << endl;
	fout.width(50);
	fout << right << "Метод Зейделя" << endl << endl;

	Matrix B(3, 3);
	B = fillB(A);

	Matrix g(3, 1);
	g = fillg(A, f);
	Matrix x(g);

	Matrix H(3, 3);
	Matrix F(3, 3);
	H = fillL(B);
	F = B - H;

	Matrix x0(x);

	Matrix E(3, 3);
	E[0][0] = 1;
	E[1][1] = 1;
	E[2][2] = 1;
	//E[3][3] = 1;

	int k = 0;
	while (k > -1)
	{
		x0 = x;
		x = ((E - H) ^ (-1))*(F*x + g);
		k++;
		if ((x - x0).norm() < ep)
			break;
	}

	cout << "Необходимое количество итераций: " << k << endl;
	cout << endl << "Решение: " << endl << x << endl;

	fout << "Необходимое количество итераций: " << k << endl;
	fout << endl << "Решение: " << endl << x << endl;


	return x;
}

Matrix gauss_zeidel(Matrix A, Matrix f, double ep)
{
	cout << endl;
	cout.width(50);
	cout << right << "Метод Гаусса-Зейделя" << endl << endl;

	
	fout << endl;
	fout.width(50);
	fout << right << "Метод Гаусса-Зейделя" << endl << endl;

	Matrix x(f);

	Matrix D(3, 3);
	Matrix L(3, 3);
	D = fillD(A);
	L = fillL(A);
	Matrix U(3, 3);
	U = A - D - L;

	

	Matrix x0(x);

	int k = 0;
	while (k > -1)
	{
		x0 = x;
		x = ((D + L) ^ (-1))*((-1)*U*x + f);
		k++;
		if ((x - x0).norm() < ep)
			break;
	}

	cout << "Необходимое количество итераций: " << k << endl;
	cout << endl << "Решение: " << endl << x << endl;

	fout << "Необходимое количество итераций: " << k << endl;
	fout << endl << "Решение: " << endl << x << endl;

	

	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double ep = 1.0/2.0 * 1e-4;
	int alpha = 5;
	Matrix A(3, 3);
	Matrix f(3, 1);
	A = fillA(A, alpha);
	f = fillf(f, alpha);

	fout.open("out.txt");

	fixed_point_iteration(A, f, ep);
	//gradient(A, f, ep);
	//relax(A, f, ep);
	//eidel(A, f, ep);
	gauss_zeidel(A, f, ep);

	fout.close();
}