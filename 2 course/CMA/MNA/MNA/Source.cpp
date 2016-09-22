#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

vector<double> fillX(double a, double b, int numberOfNodes)
{
	vector<double> x;
	for (double i = a; i <= b; i += (b - a) / numberOfNodes)
	{
		x.push_back(i);
	}
	return x;
}

vector<double> fillF(vector<double> x)
{
	vector<double> f;
	for (int i = 0; i < x.size(); i++)
	{
		f.push_back(exp(x[i])*cos(x[i]) + log(x[i]));
	}
	return f;
}

void lagrange(int numberOfNodes, double a = 1, double b = 3, double step = 0.01)
{
	vector<double> x = fillX(a, b, numberOfNodes);

	vector<double> f = fillF(x);

	ofstream fout("output.txt");
	double ans = 0.0;
	for (double t = a; t <= b; t += step)
	{
		for (int i = 0; i < f.size(); i++)
		{
			double tmp = 1.0;
			for (int j = 0; j < x.size(); j++)
			{
				if (j != i)
					tmp *= (t - x[j]) / (x[i] - x[j]);
			}
			tmp *= exp(x[i])*cos(x[i]) + log(x[i]);
			ans += tmp;
		}
		fout << fixed << ans << endl; // Вывод значения в текущей точке
		ans = 0;
	}
	fout.close();
}

int main()
{
	double a = 1;
	double b = 3;
	int numberOfNodes = 2;

	cout << "Enter the starting position:" << endl;
	cin >> a;
	cout << "Enter the final position:" << endl;
	cin >> b;

	cout << "Enter the number of interpolation nodes:" << endl;
	cin >> numberOfNodes;
	
	lagrange(numberOfNodes);
}