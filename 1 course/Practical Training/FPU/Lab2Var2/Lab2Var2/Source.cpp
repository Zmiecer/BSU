//sum k from 1 to infinity (((-1)^(k+1) * x^2) / (2k+1)!) * (4/3)^(4*k+2)
#include <iostream>

using namespace std;

int main()
{
	double k = 2, x = 1, sum = 0, base = 0;
	int n = 100;
	cout << "Insert x: ";
	cin >> x;
	cout << "Insert n: ";
	cin >> n;
	n--;
	double h6 = 6, hmin1 = -1, h2 = 2, h1 = 1, h4 = 4, h3 = 3;
	double a;
	_asm
	{
		//База
		finit
		fld x
		fmul x

		fmul h4
		fmul h4
		fmul h4
		fmul h4
		fmul h4
		fmul h4 //4^6

		fdiv h3
		fdiv h3
		fdiv h3
		fdiv h3
		fdiv h3
		fdiv h3 // 3^6

		fdiv h6
		fst base // (x^2 * (4^6/ 3^6)) / 6
		fstp sum

		mov ecx, n
		cmp ecx, 0
		je endd
	start:
		finit
		fld k
		fmul h2
		fadd h1 // 2*k + 1
		fmul h2
		fmul k // 2*k*(2*k + 1)


		fld base //вгрузка предыдущего значения
		fchs // (-1)*res

		fmul h4
		fmul h4
		fmul h4
		fmul h4 // (-1)*res*4^4

		fdiv h3
		fdiv h3
		fdiv h3
		fdiv h3 // (-1)*res*4^4/3^4

		fdivr // st(0)/st(1)

		fst base
		fadd sum
		fstp sum

		fld1
		fadd k
		fstp k
		loop start
	endd:
	}
	cout << sum << endl;
}