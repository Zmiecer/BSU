#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
char x;

using namespace std;

bool Pr1(string S) {return S[0]==x;}

int main()
{
	string str;
	int k=0;
	list<string> nicht;
	ifstream fin ("in.txt");
	while (!fin.eof())
	{
		fin >> str;
		nicht.push_back(str);
	}
	nicht.sort();


	list<string>::iterator iter;
	list<string>::iterator iter1;
	list<string>::iterator iter2;
	
	cout << "Sorted list: " << endl;
	for (iter=nicht.begin(); iter!=nicht.end(); iter++)
		cout << *iter << endl;

	cout << endl;
	cout << "Please, insert the letter on which I must delete some symbols: ";
	cin >> x;
	for (iter=nicht.begin(); iter!=nicht.end(); iter++)
	{
		str=(*iter);
		if (str[0]==x)
		{
			if (k==0)
			{
				iter1=iter;	
				k++;
			}
			if (k!=0)
			{
				k++;
			}
		}
	}

	iter1=find_if(nicht.begin(), nicht.end(), Pr1);

	if (k==0) cout << endl << "No symbols to delete" << endl;
	else
	{	iter2=iter1;
		for (int i=0; i<k-1; i++)
			iter2++;
		nicht.erase(iter1, iter2);
	}
	cout << endl;
	cout << "Formated list: " << endl;
	for (iter=nicht.begin(); iter!=nicht.end(); iter++)
		cout << *iter << endl;
	cout << endl;
}