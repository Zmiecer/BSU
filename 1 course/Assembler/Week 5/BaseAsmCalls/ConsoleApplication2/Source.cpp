#include <iostream>  
#include <iomanip>

extern "C"  int __fastcall fast(int, int, int);

extern "C"  int __stdcall stnd(int, int, int);

extern "C"  int __cdecl decl(int, int, int);


int main()
{
	std::cout << std::setw(10) << "fastcall: ";
	int n = fast(-12, 5, 6);
	std::cout << "a*x-b=" << n << std::endl;

	std::cout << std::setw(10) << "stdcall: ";
	int m = stnd(-12, 5, 6);
	std::cout << "a*x-b=" << m << std::endl;

	std::cout << std::setw(10) << "cdecl: ";
	int l = decl(-12, 5, 6);
	std::cout << "a*x-b=" << l << std::endl;
	return 0;
}