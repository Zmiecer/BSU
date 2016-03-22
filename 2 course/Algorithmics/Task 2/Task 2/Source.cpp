#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	while (n)
	{
		int d, t;
		cin >> d >> t;
		vec.push_back(make_pair(t, d));
		n--;
	}

	sort(vec.begin(), vec.end());

	int time = 0 - vec.begin()->first + 1;
	//cout << time << endl;

	int dir = 0;
	bool changed = false;
	bool lol = false;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i].second - vec[i - 1].second < 0)
		{
			if (dir == 0)
				dir = -1;
			else
				if (dir == 1)
				{
					if (!changed)
					{
						dir = -1;
						changed = true;
					}
					else
					{
						break;
					}
				}
		}
		if (vec[i].second - vec[i - 1].second >= 0)
		{
			if (dir == 0)
				dir = 1;
			else
				if (dir == -1)
				{
					if (!changed)
					{
						dir = 1;
						changed = true;
					}
					else
					{
						break;
					}
				}
		}
		if (time + (int)fabs((double)(vec[i].second - vec[i - 1].second)) <= vec[i].first)
			time += (int)fabs((double)(vec[i].second - vec[i - 1].second));
		else
		{
			lol = true;
		}
	}
	if (!lol)
		cout << time << endl;
	else
		cout << "No solution" << endl;
}