#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip> 

using namespace std;

string str="Bylinovich";

bool cmp1(pair<string,string> parka)
{
	if(parka.first==str) return 1; else return 0;
}

struct klichki
{
	string animal;
	string klichka;
};

struct maxik
{
	int sum;
	string surname;
};

int main()
{
	multimap<string, pair<string,string>> card;
	pair<string, pair<string, string>> s;
	string s1, s2, s3;
	klichki mass[20];
	maxik maxis[20];
	//¬вод
	ifstream fin ("base.txt");
	while (!fin.eof())
	{
		fin >> s1;
		fin >> s2;
		fin >> s3;
		s.first=s1;
		s.second.first=s2;
		s.second.second=s3;
		card.insert(s);
	}
	/*s1="Bylinovich";
	s2="Dog";
	s3="Sharick";
	s.first=s1;
	s.second.first=s2;
	s.second.second=s3;
	card.insert(s);
	s1="Berzh";
	s2="Dog";
	s3="Kebab";
	s.first=s1;
	s.second.first=s2;
	s.second.second=s3;
	card.insert(s);
	s1="Bylinovich";
	s2="Cat";
	s3="Kebab";
	s.first=s1;
	s.second.first=s2;
	s.second.second=s3;
	card.insert(s);
	s1="Wiggle";
	s2="Crocodile";
	s3="Misha";
	s.first=s1;
	s.second.first=s2;
	s.second.second=s3;
	card.insert(s);*/


	string arr[20];

	auto it=card.begin();
	string temp;
	int kol=0;
	int p=0;
	int i=0, k=0, max=0;
	for (temp=it->first; it!=card.end(); it++)
	{
		if(temp!=it->first)
		{
			cout << setw(10) << temp << setw(3) << kol << endl;
			maxis[p].sum=kol;
			maxis[p].surname=temp;
			p++;
			if (kol>=max) max=kol;
			k++;
			kol=1;
			temp=it->first;
			//cout << setw(10) << temp << setw(3) << kol << endl;
		}
		else
		{
			kol++;
			//cout << setw(10) << temp << setw(3) << kol << endl;
		}
		arr[i]=it->second.second;
		mass[i].animal=it->second.first;
		mass[i].klichka=it->second.second;
		i++;
	}
	cout << setw(10) << temp << setw(3) << kol << endl;
	if (kol>=max) max=kol;
	maxis[p].sum=kol;
	maxis[p].surname=temp;
	p++;
	k++;
	//cout << "Number of unique: " << k << endl << "Count in max: " << maxis[p-1].sum << endl;
	

	int size=i;
	sort(arr, arr+size);
	cout << "Animals with common names: " << endl;
	for (i=0; i<size; i++)
		if (mass[i].animal=="Cat" || mass[i].animal=="Dog")
		{
			for (int j=0; j<size; j++)
				if (mass[i].klichka==mass[j].klichka && mass[i].animal!=mass[j].animal)
					cout << mass[i].animal << " " << mass[i].klichka << endl;
		}

	//cout << "Number of Dogs: " << count_if(card.begin(), card.end(), cmp1) << endl;

	//ѕункт 3
	int sizik=p;
	for(p=0; p<sizik; p++)
	{
		if (maxis[p].sum==max)
		{
			cout << maxis[p].sum << " " << maxis[p].surname << endl;
			str=maxis[p].surname;
			//remove_if(card.begin(), card.end(), cmp1);
			it=card.begin();
			for (it; it!=card.end();)
				if (it->first == str) 
				{
					card.erase(it++);
				}
				else ++it;
		}
	}


	
	//remove_if(card.begin(), card.end(), cmp1);

}