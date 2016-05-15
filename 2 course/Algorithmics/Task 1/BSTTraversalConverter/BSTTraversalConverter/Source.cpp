#define _CRT_SECURE_NO_WARNINGS
#define INT long long

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <queue>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

string back(vector<INT> arr, INT n)
{
	string str = "";
	if (n >= 100)
	{
		stack<INT> st;
		vector<INT> vec;
		INT max = arr[0];
		for (INT i = 0; i < arr.size(); i++)
		{
			if (!st.empty())
			{
				if (arr[i] >= max)
				{
					while (!st.empty() && st.top() < max)
					{
						ostringstream ostr;
						ostr << st.top();
						str.append(ostr.str());
						str.push_back(' ');
						st.pop();
					}
					max = arr[i];
				}
				INT tmp = st.top();
				st.pop();
				while (!st.empty() && st.top() <= arr[i] && tmp < st.top() && tmp <= arr[i])
				{
					ostringstream ostr;
					ostr << tmp;
					str.append(ostr.str());
					str.push_back(' ');
					tmp = st.top();
					st.pop();
				}
				st.push(tmp);
			}
			st.push(arr[i]);
		}
		while (!st.empty())
		{
			ostringstream ostr;
			ostr << st.top();
			str.append(ostr.str());
			str.push_back(' ');
			st.pop();
		}
	}
	else
	{
		vector<INT> st;
		int count = 0;
		for (INT i = 0; i < arr.size(); i++)
		{
			if (!st.empty())
			{
				INT tmp = st.back();
				st.pop_back();
				if (!st.empty() && tmp < arr[i])
				{
					INT max = 0;
					INT imax = 0;
					for (INT j = st.size() - 1; j >= 0; j--)
					{
						if (st[j] <= arr[i] && st[j] >= max)
						{
							max = st[j];
							imax = j;
						}
					}
					if (max <= tmp)
						imax = st.size();
					for (INT j = st.size() - 1; j >= imax; --j)
					{
						ostringstream ostr;
						ostr << tmp;
						str.append(ostr.str());
						str.push_back(' ');
						tmp = st.back();
						st.pop_back();
						count++;
					}
				}
				st.push_back(tmp);
			}
			st.push_back(arr[i]);
		}
		while (!st.empty())
		{
			ostringstream ostr;
			ostr << st.back();
			str.append(ostr.str());
			str.push_back(' ');
			st.pop_back();
			count++;
		}
	}
	return str;
}

string inside(vector<INT> arr, INT n)
{
	string str = "";
	stack<INT> st;
	for (INT i = 0; i < arr.size(); i++)
	{
		if (!st.empty())
			if (arr[i] >= st.top())
			{
				while (!st.empty() && st.top() <= arr[i])
				{
					ostringstream ostr;
					ostr << st.top();
					str.append(ostr.str());
					str.push_back(' ');
					st.pop();
				}
			}
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		ostringstream ostr;
		ostr << st.top();
		str.append(ostr.str());
		str.push_back(' ');
		st.pop();
	}

	return str;
}

int main()
{
	INT n;

	ifstream fin("input.txt");
	fin >> n;

	vector<INT> arr(n);
	for (INT i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	fin.close();

	ofstream fout("output.txt");
	string tmp;
	tmp = back(arr, n);
	tmp.pop_back();
	fout << tmp << endl;
	tmp = inside(arr, n);
	tmp.pop_back();
	fout << tmp << endl;

	fout.close();
}