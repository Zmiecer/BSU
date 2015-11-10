#include "Matrix.h"

using namespace std;

int main()
{
	Matrix X(4, 2);
	X[0][0] = 1;
	X[1][0] = 1;
	X[2][0] = 1;
	X[3][0] = 1;

	X[0][1] = 3;
	X[1][1] = -2;
	X[2][1] = 5;
	X[3][1] = 7;

	Matrix Y(4, 1);

	Y[0][0] = 0;
	Y[1][0] = -4;
	Y[2][0] = 0;
	Y[3][0] = 2;


	Matrix Z(2, 1);

	Matrix X1(2, 4);
	X1[0][0] = 1;
	X1[0][1] = 1;
	X1[0][2] = 1;
	X1[0][3] = 1;

	X1[1][0] = 3;
	X1[1][1] = -2;
	X1[1][2] = 5;
	X1[1][3] = 7;

	//Z = ((((X.transpose())*X) ^ (-1))*(X.transpose()))*Y;
	Z = ((X1*X) ^ (-1))*X1*Y;

	cout << Z;
}