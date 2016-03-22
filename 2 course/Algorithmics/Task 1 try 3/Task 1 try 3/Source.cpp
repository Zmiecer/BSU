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
					//fout << st.top() << " ";
					st.pop();
				}
				max = arr[i];
			}
			INT tmp = st.top();
			st.pop();
			while (!st.empty() && st.top() <= arr[i] && tmp < st.top() && tmp < arr[i])
			{
				ostringstream ostr;
				ostr << tmp;
				str.append(ostr.str());
				str.push_back(' ');
				//fout << tmp << " ";
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