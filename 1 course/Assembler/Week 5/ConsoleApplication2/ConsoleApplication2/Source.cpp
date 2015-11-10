//2. В массиве целочисленных элементов заменить все элементы 0 на 1.
#include <iostream>  
#include <iomanip>
extern "C"  char* __cdecl func(char*);
extern "C"  int __cdecl space(char*);

int main()
{
	char* str1;
	char str[] = { 'a', '0', 'B'};
	str1 = func(str);
	for (int i = 0; i < 3; i++)
		std::cout << *(str1 + i) << ' ';
	std::cout << std::endl;



	char str2[] = { 'a', '0', 'B', ' ', 's', ' ', 'd', 'd'};
	int res;
	res = space(str2);
	std::cout << res << std::endl;

	return 0;
}