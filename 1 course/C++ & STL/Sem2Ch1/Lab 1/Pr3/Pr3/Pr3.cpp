#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

int y;
bool numberof(int f) {return f==y;}
bool biggerthan(int f) {return f>y;}

int main()
{
	int x, t, k=0, l=0, m=0, n=0, o=0;

	vector<int> cont1;
	list<int> cont2;
	deque<int> cont3;

	ifstream fin ("in.txt");
	while (!fin.eof())
	{
		fin >> x;
		cont1.push_back(x);
		cont2.push_back(x);
		cont3.push_back(x);
	}

	vector<int>::iterator iter1;
	list<int>::iterator iter2;
	deque<int>::iterator iter3;
	for (iter1=cont1.begin(); iter1!=cont1.end(); iter1++)
		cout << *iter1 << " ";
	cout << endl;
	for (iter2=cont2.begin(); iter2!=cont2.end(); iter2++)
		cout << *iter2 << " ";
	cout << endl;
	for (iter3=cont3.begin(); iter3!=cont3.end(); iter3++)
		cout << *iter3 << " ";
	cout << endl;

	cout << "Insert coin: " << endl;
	cin >> t;
	cout << "Insert number: " << endl;
	cin >> y;


	switch(t)
	{
	case(1):
	{
		k=count_if(cont1.begin(), cont1.end(), numberof);
		l=count_if(cont1.begin(), cont1.end(), biggerthan);
		m=cont1.size();
		n=accumulate(cont1.begin(), cont1.end(), n, plus<int>());
		o=n/cont1.size();
		break;
	}
	case(2):
	{
		k=count_if(cont2.begin(), cont2.end(), numberof);
		l=count_if(cont2.begin(), cont2.end(), biggerthan);
		m=cont2.size();
		n=accumulate(cont2.begin(), cont2.end(), n, plus<int>());
		o=n/cont2.size();
		break;
	}
	case(3):
	{
		k=count_if(cont3.begin(), cont3.end(), numberof);
		l=count_if(cont3.begin(), cont3.end(), biggerthan);
		m=cont3.size();
		n=accumulate(cont3.begin(), cont3.end(), n, plus<int>());
		o=n/cont3.size();
		break;
	}
	}
	cout << k << endl;
	cout << l << endl;
	cout << m << endl;
	cout << n << endl;
	cout << o << endl;
}