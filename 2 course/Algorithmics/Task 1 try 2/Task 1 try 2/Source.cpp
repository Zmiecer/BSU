// Task 36

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

ofstream fout("output.txt");

string back(vector<INT> arr, INT n)
{
	string str = "";
	stack<pair<INT, bool>> st;
	vector<pair<INT, bool>> vec;

	INT max = arr[0];
	for (INT i = 0; i < arr.size(); i++)
	{
		if (arr[i] < max)
			vec.push_back(make_pair(arr[i],true));
		else
		{
			max = arr[i];
			vec.push_back(make_pair(arr[i], false));
		}
	}

	for (INT i = 0; i < vec.size(); i++)
	{
		if (!st.empty())
		{
			pair<INT, bool> tmp = st.top();
			st.pop();
			//while (!st.empty() && st.top() <= arr[i] && tmp < st.top() && tmp < arr[i])
			if (!st.empty() && st.top().first <= vec[i].first && tmp.first < st.top().first && tmp.first < vec[i].first)
			{
				while (!st.empty() && st.top().first <= vec[i].first && tmp.first < st.top().first && tmp.first < vec[i].first)
				{
					ostringstream ostr;
					ostr << tmp.first;
					str.append(ostr.str());
					str.push_back(' ');
					//fout << tmp << " ";
					tmp = st.top();
					st.pop();
				}
			}
			else
			{
				int max = tmp.first;
				int j = st.size() - 1;
				bool first = true;
				while (!st.empty() && tmp.first < vec[i].first && (tmp.first < max || (first && tmp.second) || (tmp.first <= max && tmp.second)))
				{
					ostringstream ostr;
					ostr << tmp.first;
					str.append(ostr.str());
					str.push_back(' ');
					//fout << tmp << " ";
					tmp = st.top();
					st.pop();
					if (first)
						first = false;
				}
			}
			st.push(tmp);
		}
		st.push(vec[i]);
	}
	while (!st.empty())
	{
		ostringstream ostr;
		ostr << st.top().first;
		str.append(ostr.str());
		str.push_back(' ');
		//fout << st.top() << " ";
		st.pop();
	}
	//fout << endl;

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
					//fout << st.top() << " ";
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
		//fout << st.top() << " ";
		st.pop();
	}
	//fout << endl;

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

	string tmp;
	tmp = back(arr, n);
	tmp.pop_back();
	fout << tmp << endl;
	tmp = inside(arr, n);
	tmp.pop_back();
	fout << tmp << endl;

	fout.close();
}