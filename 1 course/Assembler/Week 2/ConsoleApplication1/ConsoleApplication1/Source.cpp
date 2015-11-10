#include <iostream>

using namespace std;

int main()
{
	int x, res = 0, sum = 0, sym = 0, y = 0, k = 0, xx = 0;
	cin >> x;
	xx = x;
	/*__asm
	{
		mov eax, x
		start_ :
		mov eax, xx
		cmp eax, 0
			je end_
			mov ebx, 10
			cdq
			div ebx
			mov xx, eax
			add sum, edx
			mov k, edx
			mov eax, y
			mov ebx, 10
			mul ebx
			add eax, k
			mov y, eax
			mov ebx, k
			test ebx, 1
			jz chet_
			jmp start_
		chet_ :
		add res, 1
			jmp start_
		end_ :
			mov eax, x
			mov ebx, y
			cmp eax, ebx
			je sym_
			jmp endend_
		sym_:
			mov sym, 1
		endend_:
	}

	cout << "Number of chet: " << res << endl << "Summa cifr: " << sum << endl << "Symmetrija: " << sym << endl;
	*/

	res = 0;

	__asm
	{
		bsr eax, x
		mov res, eax
	}
	cout << res + 1 << endl;
}