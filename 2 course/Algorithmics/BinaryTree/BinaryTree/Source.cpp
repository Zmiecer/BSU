#define _CRT_SECURE_NO_WARNINGS
#define INT long long

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

ofstream fout("output.txt");

void back(vector<INT> arr, INT n)
{
	stack<INT> st;
	INT max = arr[0];
	for (INT i = 0; i < arr.size(); i++)
	{
		if (!st.empty())
		{
			if (arr[i] >= max)
			{
				while (!st.empty() && st.top() < max)
				{
					fout << st.top() << " ";
					st.pop();
				}
				max = arr[i];
			}
			INT tmp = st.top();
			st.pop();
			while (!st.empty() && st.top() <= arr[i] && tmp < st.top() && tmp < arr[i])
			{
				fout << tmp << " ";
				tmp = st.top();
				st.pop();
			}
			st.push(tmp);
		}
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		fout << st.top() << " ";
		st.pop();
	}
	fout << endl;
}

void inside(vector<INT> arr, INT n)
{
	stack<INT> st;
	for (INT i = 0; i < arr.size(); i++)
	{
		if (!st.empty())
			if (arr[i] >= st.top())
			{
				while (!st.empty() && st.top() <= arr[i])
				{
					fout << st.top() << " ";
					st.pop();
				}
			}
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		fout << st.top() << " ";
		st.pop();
	}
	fout << endl;

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


	back(arr, n);
	inside(arr, n);


	
	fout.close();
}