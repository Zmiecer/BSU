#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


// Можно запилить класс многочленов от одной переменной/класс переменных, состоящий из коэффициента и степени и радоваться жизни. Но лень =)
class mn
{
public:
	double degree;
	double koeff;

	
};

double res(vector<double> x, vector<double> f, double t)
{
	double ans = 0.0;
	for (int i = 0; i < f.size(); i++)
	{
		double tmp = 1.0;
		for (int j = 0; j < x.size(); j++)
		{
			if (j != i)
				tmp *= (t - x[j]) / (x[i] - x[j]);
		}
		tmp *= f[i];
		ans += tmp;
	}
	return ans;
}

int main()
{
	vector<double> x;
	vector<double> f;

	int a = 1;
	int b = 3;

	int n = 2;

	x.push_back(a);
	f.push_back(1.469);

	x.push_back(b);
	f.push_back(-18.786);

	ofstream fout("output.txt");
	for (double i = a; i < b; i += 0.01)
	{
		fout << fixed << res(x, f, i) << endl;
	}
	fout.close();

}