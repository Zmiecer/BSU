#include <iostream>
#include <sstream>

using namespace std;

double x;
double a = 0, b = 0, c = 0;
double var = 11;
double s = 1;
double y = 0;
double resl, resc, resr;
double dva = 2;
double h0 = 0, h2 = 2, pi = 0, h = 0, hdiv, i = 0;
double k;
double s1;
double k1;
double n;
double base;
int m = 0;
int kol;
double diff;

int solve(double ll, double rr)
{
	double lbound = ll, rbound = rr, center = 0;
	_asm
	{
		mov ecx, 1000
		start:
		//Считает середину
		finit
			fld lbound
			fadd rbound
			fdiv dva
			fstp center


			//Считает значение функции в rbound
			fld lbound
			fstp x

			finit
			fld a
			fmul x
			fmul x //1
			fld x
			fadd var
			fstp y
			fld b
			fdiv y //2
			fld c //3
			fadd st(0), st(1)
			fadd st(0), st(2)
			fstp resl


			//Считает значение функции в center
			fld center
			fstp x

			finit
			fld a
			fmul x
			fmul x //1
			fld x
			fadd var
			fstp y
			fld b
			fdiv y //2
			fld c //3
			fadd st(0), st(1)
			fadd st(0), st(2)
			fstp resc

			//Считает значение функции в rbound
			fld rbound
			fstp x
			finit
			fld a
			fmul x
			fmul x //1
			fld x
			fadd var
			fstp y
			fld b
			fdiv y //2
			fld c //3
			fadd st(0), st(1)
			fadd st(0), st(2)
			fstp resr

			//Бисекция
			finit
			fld resl
			fmul resc
			ftst // c0, c1, c2, c3
			fstsw ax // flags to ax
			sahf // from ax to eflags
			jb change
			fld center
			fstp lbound
			jmp endd
		change :
		fld center
			fstp rbound
		endd :

		finit
			fld resc
			ftst
			fstsw ax
			sahf
			jz enddd

			sub ecx, 1
			cmp ecx, 0
			jnz start
		enddd :
	}
	cout << center << endl;
}


int main()
{
	// Problem 1
	
	//I. Найти корни уравнения на отрезке [-10,10] методом деления отрезка пополам.
	//Определить предварительно отрезки, содержащие корни (перемены знака выражения),
	//разбивая исходный отрезок на отрезки достаточно малой длины. ax^2 + b/(x + 11) + c = 0
	/*
	cout << "Insert a: ";
	cin >> a;
	cout << "Insert b: ";
	cin >> b;
	cout << "Insert c: ";
	cin >> c;
	cout << "Solutions:" << endl;
	solve(-10, 0);
	solve(0, 10);
	*/
	

	// Problem 2
	/*
	//На основании указанной формулы   вычислить значение числа ln2. 
	//Сравнить полученный результат с приближенным значением этого числа (смотри команды загрузки чисел). 
	//Построить таблицу оценки количества необходимых итераций для нахождения 5, 7, 9 и т.д. правильных цифр после десятичной точки.
	// ln(x+1) = sum k from 1 to infinity (-1)^(k+1)*x^k/k
	s = 0;
	k = 2;
	k1 = k - 1;
	m = 3;
	cout << "Insert number of repetitions: ";
	cin >> m;
	m--;
	x = 2;
	x--;
	s = x;
	base = x;
	_asm
	{
		mov ecx, m
		cmp ecx, 0
		je endd
	start:
		fld base
		fmul x
		fchs
		fst base
		fdiv k
		fadd s
		fstp s

		fld1
		fadd k
		fstp k
		loop start

		fldln2
		fstp s1

		fld s1
		fsub s
		fstp diff
	endd:
	}
	kol = -1;
	ostringstream ost1, ost2;
	ost1 << s;
	ost2 << s1;
	for (int i = 1; i < ost1.str().size(); i++)
		if (ost1.str()[i] != ost2.str()[i])
			break;
		else kol++;
	//while (diff <= 0.1 && diff != 0)
	//{
	//	diff *= 10;
	//	kol++;
	//}
	cout << s << endl << s1 << endl << kol << endl;
	*/
	

	// Problem 3
	/*
	// Вычислить определенный интеграл на отрезке [0,2pi] методом трапеций для следующих функций
	// f(x)=x*cos(x) 
	cin >> n;
	x = 0;
	s = 0;
	m = (int)n - 1;
	_asm
	{
		finit
		fldpi
		fstp pi

		fldpi
		fmul h2 
		fdiv n
		fst h //h
		fstp x

		fldpi
		fmul h2
		fcos
		fmul pi
		fstp s // base

		mov ecx, m
	start:
		finit
		fld x	// x
		fcos	// cos(x)
		fst i
		fmul x	// x*cos(x)
		//fst i
		fadd s	// st(0) = s + x*cos(x)
		fstp s	// s = s + x*cos(x)

		fld x
		fadd h
		fstp x
	loop start

		fld s
		//fmul h
		fstp s
	}
	cout << s << endl;
	*/

	// Problem 4
	
	// Разработать функцию вычисления значения степенной функции f(x)=(0.5)^x
	a = 0.5;
	cin >> x;
	double h1 = 1;
	_asm
	{
		; Во-первых, вычисляем z = a*log2(x)
		fld x				; Загружаем показатель степени
		fld a				; Загружаем основание
		fyl2x				; Стек FPU теперь содержит : ST(0) = a*log2(x)
		fld st(0)			; Создаем еще одну копию z
		frndint				; Округляем ST(0) = trunc(z) | ST(1) = z
		fxch st(1)			; ST(0) = z | ST(1) = trunc(z)
		fsub st(0), st(1)	; ST(0) = z - trunc(z) | ST(1) = trunc(z)
		f2xm1				; ST(0) = 2^(z - trunc(z)) - 1 | ST(1) = trunc(z)
		fadd h1				; ST(0) = 2 ^ (z - trunc(z)) | ST(1) = trunc(z)		
		fscale				; ST(0) = (2^(z - trunc(z)))*(2^trunc(z)) = 2^(z)
		fstp s				; Результат
	}
	cout << s << endl;
	
}

/*
// Для любого x, резерв
finit
fld a
fmul x
fmul x //1
fld x
fadd var
fstp y
fld b
fdiv y //2
fld c //3
fadd st(0), st(1)
fadd st(0), st(2)
fstp res1
*/