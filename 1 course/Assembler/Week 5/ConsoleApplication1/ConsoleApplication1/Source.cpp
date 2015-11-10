#include <iostream>  
#include <iomanip>

extern "C"  int __fastcall fast(int, int);


int main()
{
	int a, x;
	std::cout << "Enter a: " << std::endl;
	std::cin >> a;
	std::cout << "Enter n: " << std::endl;
	std::cin>> x;
	int n = fast(a, x);
	
	std::cout << "a^n= " << n << std::endl;

	return 0;
}