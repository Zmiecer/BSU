#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

ofstream fout("output.txt");

void back(vector<unsigned int> arr, unsigned int n)
{
	stack<unsigned int> st1;
	stack<unsigned int> st;
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (!st.empty())
			if (arr[i] >= st.top())
			{
				int tmp = st.top();
				st.pop();
				while (!st.empty() && tmp <= arr[i] && tmp < st.top())
				{
					//if (tmp < arr[0])
					//	st1.push(tmp);
					//else
					{
						fout << tmp << " ";
					}
					tmp = st.top();
					st.pop();
				}
				st.push(tmp);
			}
		if (arr[i] > arr[0])
			while (!st1.empty())
			{
				fout << st1.top() << " ";
				st1.pop();
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

void inside(vector<unsigned int> arr, unsigned int n)
{
	stack<unsigned int> st;
	for (unsigned int i = 0; i < arr.size(); i++)
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
	unsigned int n;

	ifstream fin("input.txt");
	fin >> n;

	vector<unsigned int> arr(n);
	for (unsigned int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	fin.close();

	

	back(arr, n);
	inside(arr, n);


	
	fout.close();
}