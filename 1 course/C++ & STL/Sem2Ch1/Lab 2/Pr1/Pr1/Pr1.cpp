#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>



using namespace std;

string y;
string sur;
int S;

class student
{
public:
	string surname;
	int group;
	int marks[4];
	student() 
	{
		surname="Undefined";
		group=0;
		for (int i=0; i<4; i++) marks[i]=0;
	}
	student(string a, int b, int* c) : surname(a), group(b) 
	{
		for (int i=0; i<4; i++) marks[i]=c[i];
	}
	friend ostream& operator<<( ostream& os, const student& s )
    {
		return os << s.group << " " << s.surname << " " << s.marks[0] << " " << s.marks[1] << " " << s.marks[2] << " " << s.marks[3];
	}
	void inside(string a, int b, int* c)  
	{
		surname=a; 
		group=b;
		for (int i=0; i<4; i++) marks[i]=c[i];
	}
	student& operator=(const student& s)
	{
		if (this == &s) return *this;
		group=s.group;
		surname=s.surname;
		for (int i=0; i<4; i++) marks[i]=s.marks[i];
		return *this;
	}

	int sum()
	{
		S=0;
		for (int i=0; i<4; i++)
			S+=marks[i];
		return S;
	}
};


string str;
student students[100];
int n;

bool cmp1(student par1, student par2)
{
	if (par1.surname > par2.surname) return 0; else return 1;
}

bool cmp2(student par1)
{
	if (par1.surname == sur) return 1; else return 0;
}

int main()
{
	student u;
	string str;
	int x, k=0;
	int arr[4];
	int mar[100];
	string strr[100];
	vector<student> paralel;

	/*cin >> str;
	cin >> x;
	for (int i=0; i<4; i++) 
		cin >> arr[i];
	student st(str, x, arr);
	cout << st << endl;*/

	ifstream file ("in.txt");
	for (int i=0; !file.eof(); i++)
	{
		file >> strr[i];
		file >> x;
		file >> y;
		for (int j=0; j<4; j++)
		{
			mar[j]=y[j]-'0';
		}
		//cout << strr[i] << x << y << endl;
		students[i].inside(strr[i], x, mar);
		k++;
	}
	//cout << k << endl;
	cout << "List of students:" << endl;
	for (int i=0; i<k; i++)
	{
		paralel.push_back(students[i]);
		//cout << students[i] << endl;
		cout << paralel[i] << endl;
	}
	vector<student>::iterator iter;
	sort(paralel.begin(), paralel.end(), cmp1);
	iter=paralel.begin();
	for (int i=0; i<k; i++)
		cout << paralel[i] << endl;

	for (iter=paralel.begin(); iter!=paralel.end(); iter++)
		cout << *iter << endl;


	cout << "Enter surname of student that you want to delete: " << endl;
	cin >> sur;
	remove_if(paralel.begin(), paralel.end(), cmp2);
	/*for (iter=paralel.begin(); iter!=paralel.end(); iter++)
		if (iter->surname == sur) paralel.erase(iter);*/
	

	for (iter=paralel.begin(); iter<paralel.end()-1; iter++)
	{
		//cout.width (20);
		cout << *iter << " Ko-ko-ko" << endl;
	}
	map<string,student> card;
	/*student stud;
	student studik;
	card["x"]=studik;
	cout << card["x"] << endl;
	string sk;*/
	cout << endl;

	iter=paralel.begin();
	int i=0;
	for (iter=paralel.begin(); iter<paralel.end()-1; iter++)
	{
		//card[paralel[i].surname]=paralel[i];
		card[paralel[i].surname]=*iter;
		cout << card[paralel[i].surname] << endl;
		i++;
	}
	//card[sk]=stud;
	//cout << card[sk] << endl;
	map<string,student>::iterator itr;
	/*i=0;
	for (itr=card.begin(); itr!=card.end(); iter++)
	{
		cout << *itr << endl;
	}*/
	i=0;
	for (iter=paralel.begin(); iter<paralel.end()-1; iter++)
	{
		//cout << card[paralel[i].surname] << endl;
		for (int j=0; j<4; j++)
			if (card[paralel[i].surname].marks[j]<4) 
			{
				cout << card[paralel[i].surname].surname << " - looser" << endl;
				break;
			}
		i++;
	}

	int max=paralel.begin()->sum();
	i=0;
	for (iter=paralel.begin(); iter<paralel.end()-1; iter++)
	{
		if(card[paralel[i].surname].sum()>max)
		{
			max=card[paralel[i].surname].sum();
			cout << card[paralel[i].surname].sum() << endl;
		}
		i++;
	}
	cout << max << endl;
}