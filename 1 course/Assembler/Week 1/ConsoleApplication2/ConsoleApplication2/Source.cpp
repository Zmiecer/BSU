#include <iostream>

using namespace std;

int main()
{
	int x, res = 0;
	cin >> x;
	__asm
	{
		mov eax, x
	start_:
		cmp eax, 10
		jg end_
		mov ebx, 10
		div ebx
		mov ebx, edx
		test ebx, 1 
		jz chet_
		jmp start_
	chet_:
		inc res
		jmp start_
	end_:

	}

	cout << res << endl;
}