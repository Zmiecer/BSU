#include <iostream>

using namespace std;

int a = 2, res, b = 6;

int main()
{
	/*__asm
	{
		mov ebx, a
		mov eax, a
		mul a
		mul a
		add ebx, eax
		mul a
		mul a
		add ebx, eax
		mov res, ebx
	}
	cout << res << endl;

	__asm
	{
		mov ebx, a
		mov eax, a
		mul eax
		sub eax, 1
		mov ebx, eax

		mov eax, a
		mul eax
		mul eax
		sub eax, 2

		cdq
		div ebx
		mov res, eax
	}
	cout << res << endl;

	_asm 
	{ 
		mov eax, a
		cmp eax, 0
		jnz a_not_n
		mov res, 0
		jmp end_ 

	a_not_n:
		mov eax, b
		cmp eax, 0
		jnz b_not_n
		mov res, 1
		jmp end_

	b_not_n:
		mov eax, b
		mov ebx, a
		cdq
		div ebx
		mov ebx, -1
		mul ebx
		mov res, eax
	end_:		
	}
	cout << res << endl;*/

	unsigned int c;
	cin >> c;
	int i;
	__asm
	{
		mov eax, c

		mov i, 1
	next1:
		imul c
		cmp edx, 0
		jnz endl_
		inc i
		jmp next1
	grb:
		mov res, 0
	endl_:
		mov eax, i
		mov res, eax

	}
	cout << res - 1 << endl;
}