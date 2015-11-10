#include <iostream>
#include <vector>

using namespace std;

void main()
{
	char a;
	vector<char> v;
	for (int i=0; i<4; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	vector<char>::iterator iter;
	iter=v.begin();
	while (iter!=v.end())
	{
		cout << *iter << endl;
		iter++;
	}

	vector<char>::reverse_iterator revit;
	revit=v.rbegin();
	while (revit!=v.rend())
	{
		cout << *revit << endl;
		revit++;
	}

	/*vector<int> y;
	y.push_back(6);
	y.push_back(25);
	cout << y.max_size() << " " << y.capacity() << endl;*/
}