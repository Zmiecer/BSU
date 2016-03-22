#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;



string in(int n, ifstream* fin)
{
	string str = "";
	while (n)
	{
		char c;
		fin->get(c);
		if (c != '\n')
		{
			str.push_back(c);
			n--;
		}
	}
	return str;
}

int main()
{
	ifstream fin("littera.in");
	int n;
	fin >> n;
	int tn = n;
	string str1 = in(n, &fin);
	string str2 = in(n, &fin);
	fin.close();
	string str = "";
	for (int i = 0; i < n; i++)
	{
		if ((65 <= str2[i] && str2[i] <= 90) || (97 <= str2[i] && str2[i] <= 122))
		{
			if (str2[i] - str1[i] < 0)
				str.push_back(str2[i] - str1[i] + 26 + 96);
			else
				str.push_back(str2[i] - str1[i] + 96);
		}
	}

	deque<char> key;
	int k = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (!key.empty())
		{
			if (key[k] == str[i])
			{
				k++;
				if (k >= key.size())
					k = 0;
			}
			else
			{
				key.push_back(str[i]);
				k = 0;
			}
		}
		else
			key.push_back(str[i]);
	}
	
	string minkey(key.begin(), key.end());
	
	
	for (int i = 0; i < key.size(); i++)
	{
		char t = key[0];
		key.pop_front();
		key.push_back(t);
		string tmpkey(key.begin(), key.end());
		if (tmpkey < minkey)
			minkey = tmpkey;
	}
	


	// Тут будет лексикографическое сравнение строк за O(n). А сейчас я хочу спать.

	/*
	int start = 0;
	int j = 1;
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i + j] < key[i])
		{
			start = j;
		}
	}

	int i = start;
	while (true)
	{
		if (i < key.size())
		{
			cout << key[i];
			i++;
		}
		else
		{
			i = 0;
		}
		if (i == start)
		{
			break;
		}
	}
	cout << endl;
	*/

	ofstream fout("littera.out");
	fout << minkey << endl;
	fout.close();
}