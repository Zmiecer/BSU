#include <iostream>  
#include <iomanip>

extern "C"  int* __cdecl dividers(int, int*);

int main()
{
	int a;
	int arr[100];
	int* arr1;
	std::cin >> a;
	dividers(a, arr);
	int n = *(arr);
	std::cout << "Number of dividers: " << n << std::endl << "Dividers: " << std::endl;
	for (int i = 1; i < n + 1; i++)
		std::cout << *(arr+i) << std::endl;
}