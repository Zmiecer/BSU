#include <iostream>

using namespace std;

int main()
{
	//3. Задан одномерный массив определенной размерности. Получить другой массив, не содержащий повторяющихся элементов. 
	/*
	int a[] = { 4, 3, 3, 3, 5, 3 };
	int b[] = { 0, 0, 0, 0, 0, 0 };
	int n = 6;
	int j = 1;
	int sol = 0, var = 0;

	_asm
	{
		mov ecx, 6
		mov eax, 1
		mov esi, 0
		mov edi, 0

	start:
		add edi, 4
		mov eax, a[esi]
		cmp a[edi], eax
		jne tost1


		sub n, 1
		add esi, 4
		mov edi, esi
		//add edi, 4
		
		loop start
		jmp endend

	tost1:
		

		mov eax, 20
		cmp edi, eax
		jg tost2
		jmp start

	tost2:
		mov edi, esi
	

		mov eax, a[esi]

		mov var, esi
		mov esi, sol
		mov b[esi], eax
		add sol, 4
		mov esi, var

		add esi, 4
		mov edi, esi
		loop start

	endend:

	}
	for (int i = 0; i < n; i++)
		cout << b[i] << endl;
	*/



	//6. Двумя массивами задаются коэффициенты двух многочленов разных степеней. Определить их произведение и сумму. 
	//Сумма
	/*int n = 6;

	int a[] = { 4, 3, 9, 3, 5, 3 };
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << "*x^" << n - i - 1 << " + ";
	cout << a[n - 1] << endl;

	cout << "+" << endl;

	int b[] = { 0, 4, 2, 3, 7, 1 };
	for (int i = 0; i < n - 1; i++)
		cout << b[i] << "*x^" << n - i - 1 << " + ";
	cout << b[n - 1] << endl << "=" << endl;
	
	_asm
	{
		mov ecx, 6
		mov esi, 0

	start:
		mov eax, a[esi]
		add b[esi], eax
		add esi, 4
		loop start

	}

	for (int i = 0; i < n-1; i++)
		cout << b[i] << "*x^" << n-i-1 << " + ";
	cout << b[n-1] << endl;
	*/

	//Произведение
	/*int n = 3;
	int m = 6;

	int a[] = { 1, 1, 1};
	//for (int i = 0; i < n-1; i++)
	//	cout << a[i] << "*x^" << i << " + ";
	//cout << a[n - 1] << "*x^" << n-1;


	cout << endl << "*" << endl;
	int b[] = { 1, 1, 1 };
	//for (int i = 0; i < n-1; i++)
	//	cout << b[i] << "*x^" << i << " + ";
	//cout << b[n - 1] << "*x^" << n - 1;

	//cout << endl << "=" << endl;

	int c[] = { 0, 0, 0, 0, 0, 0 };
	int i = 0;
	_asm
	{
		mov ecx, n
		mov esi, 0
		mov edi, 0 //Лучше использовать только esi и i, j
	start:
		mov eax, a[esi]
		mul b[edi]
		mov i, esi
		add esi, edi
		add c[esi], eax
		mov esi, i
		cmp edi, 8
		je ENDD
		add edi, 4
		jmp start

	ENDD:
		add esi, 4 //В идеале, нужно тестить esi на превышение n
		mov edi, 0
		loop start
	}

	for (int i = 0; i < m; i++)
		cout << c[i] << " ";
	cout << endl;
	// << "*x^" << i << " + ";
	//cout << c[m - 1] << "*x^" << m - 1;
	*/

	//12. Удалить из первого массива элементы, встречающиеся во втором массиве.Третий массив не использовать.

	
	//13. На плоскости задано множество точек, представленное в виде двух массивов.
	//	Определить минимальный по площади прямоугольник со сторонами, параллельными осям координат, 
	//	и вмещающий в себя все точки.
	/*int arr1[] = { 1, 5, 7, 2, 4, 5, 4 };
	int arr2[] = { 5, 1, 4 };
	int n = 3;
	int i = 0, j = 0;

	_asm
	{
		mov ecx, 3
		mov esi, 0
		
	start:
		mov esi, i
		mov edi, j
		cmp arr2[esi], arr1[edi]
		je comp
		jump start
		

	comp:

	}*/


	int arr1[] = { 3, 5, 7, 2, 4, 5, 4 };
	int arr2[] = { 5, 1, 4, 3, 6, 6, 2 };
	int i = 0, j = 0, n = 7, a = 0, b = 0, s = 1;
	int minx, miny, maxx, maxy;
	_asm
	{
		mov ecx, 7
		mov esi, 0
		mov eax, arr1[esi]
		mov maxx, eax
		mov esi, 4

	start1:
		mov eax, maxx
		cmp eax, arr1[esi]
		jl comp1
		add esi, 4

		cmp esi, 24
		jg endend1

		jmp start1

	comp1:
		mov eax, arr1[esi]
		mov maxx, eax
		add esi, 4

		cmp esi, 24
		jg endend1

		jmp start1

	endend1:
	//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

	mov ecx, 7
	mov esi, 0
	mov eax, arr2[esi]
	mov maxy, eax
	mov esi, 4

		start2:
			mov eax, maxy
			cmp eax, arr2[esi]
			jl comp2
			add esi, 4

			cmp esi, 24
			jg endend2

			jmp start2

		comp2:
			mov eax, arr2[esi]
			mov maxy, eax
			add esi, 4

			cmp esi, 24
			jg endend2

			jmp start2

		endend2:
		//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
			mov ecx, 7
			mov esi, 0
			mov eax, arr1[esi]
			mov minx, eax
			mov esi, 4

		start3:
			mov eax, minx
			cmp eax, arr1[esi]
			jg comp3
			add esi, 4

			cmp esi, 24
			jg endend3

			jmp start3

			comp3 :
			mov eax, arr1[esi]
			mov minx, eax
			add esi, 4

			cmp esi, 24
			jg endend3

			jmp start3

		endend3 :
		//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
			mov ecx, 7
			mov esi, 0
			mov eax, arr1[esi]
			mov miny, eax
			mov esi, 4

		start4:
			mov eax, miny
			cmp eax, arr2[esi]
			jg comp4
			add esi, 4

			cmp esi, 24
			jg endend4

			jmp start4

		comp4 :
			mov eax, arr2[esi]
			mov miny, eax
			add esi, 4

			cmp esi, 24
			jg endend4

			jmp start4

		endend4 :
			mov eax, maxx
			sub eax, minx
			mov a, eax

			mov eax, maxy
			sub eax, miny
			mov b, eax

			mov eax, a
			mul b
			mov s, eax
	}

	//cout << '(' << maxx << ',' << minx << ") (" << maxy << ',' << miny << ')' << endl;
	cout << "S = " << s << endl;

	return 0;
}