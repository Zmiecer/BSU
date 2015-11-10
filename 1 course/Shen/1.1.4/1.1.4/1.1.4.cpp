#include <iostream>

using namespace std;

int main()
{
	int a = 2, n = 7, b=1;

	while (n!=0)
	{
		if (n % 2 == 0)
		{
			n /= 2; //   3    1
			a *= a; //   4    16
		}
		else
		{
			n -= 1; // 6    2    0
			b *= a; // 2    8    128
		}
	}
	cout << b << endl;
}