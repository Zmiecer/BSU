#include <iostream>
#include <time.h>
#pragma runtime_checks( "sc", restore )

using namespace std;

int main()
{
	int a, b, k, m, n, x, y;
	cin >> a >> b;
	m = a;
	n = b;
	int p = 1, q = 0, r = 0, s = 1;

	while (m != 0 && n != 0)
	{
		if (m >= n)
		{
			m -= n;
			p -= r;
			q -= s;
		}
		else
		{
			n -= m;
			r -= p;
			s -= q;
		}
	}
	
	if (m == 0)
	{
		k = n;
		x = r;
		y = s;
	}
	else
	{
		k = m;
		x = p;
		y = q;
	}

	cout << k << endl << x << endl << y << endl;
}