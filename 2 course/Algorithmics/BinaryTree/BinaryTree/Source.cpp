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
#include <algorithm>

using namespace std;

ofstream fout("output.txt");

string back(vector<INT> arr, INT n)
{
	string str = "";
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
				INT max = 0;// arr[i]+1;
				INT imax = -1;
				//vector<INT>::reverse_iterator imax;
				//vector<INT>::reverse_iterator it;
				for (INT j = st.size() - 1; j >= 0; j--)
				{
					if (st[j] <= arr[i] && st[j] > tmp)
					{
						//max = st[j];
						imax = j;
						break;
					}
				}
				if (imax == -1)// || max == tmp)
					imax = st.size();
				for (INT j = st.size() - 1; j >= imax; --j)
				{
					ostringstream ostr;
					ostr << tmp;
					str.append(ostr.str());
					if (count != arr.size() - 1)
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
		if (count != arr.size() - 1)
			str.push_back(' ');
		st.pop_back();
		count++;
	}
	

	/*
	INT max = arr[0];

	vector<pair<INT, bool>> vec;
	for (INT i = 0; i < arr.size(); i++)
	{
		if (arr[i] <= max)
			vec.push_back(make_pair(arr[i], true));
		else
		{
			max = arr[i];
			vec.push_back(make_pair(arr[i], false));
		}
	}




	//for (vector<pair<INT, bool>>::iterator it = vec.begin(); it < vec.end(); ++it)
	//	cout << it->first << ' ' << it->second << endl;

	
	stack<pair<INT, bool>> st1;
	for (INT i = 0; i < vec.size(); i++)
	{

		if (!st1.empty())
		{
			pair<INT, bool> tmp = st1.top();
			st1.pop();
			while (!st1.empty() && tmp <= vec[i] && st1.top() <= vec[i] && tmp.second)
			{
				ostringstream ostr;
				ostr << tmp.first;
				str.append(ostr.str());
				str.push_back(' ');
				tmp = st1.top();
				st1.pop();
			}
			st1.push(tmp);
		}
		st1.push(vec[i]);
	}
	while (!st1.empty())
	{
		ostringstream ostr;
		ostr << st1.top().first;
		str.append(ostr.str());
		str.push_back(' ');
		st1.pop();
	}
	*/

	//INT max = arr[0];
	/*
	for (INT i = 0; i < arr.size(); i++)
	{
		
		if (!st.empty())
		{
			INT tmp = st.top();
			st.pop();
			while (!st.empty() && tmp <= arr[i] && st.top() <= arr[i] && tmp <= st.top())
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
	*/

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
					//fout << st.top() << ' ';
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
		//fout << st.top() << ' ';
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
	//tmp.pop_back();
	fout << tmp << endl;
	tmp = inside(arr, n);
	tmp.pop_back();
	fout << tmp << endl;

	fout.close();
}