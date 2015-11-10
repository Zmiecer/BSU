#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip> 

using namespace std;

class clumb
{
public:
	int number;
	string shape;
	vector<string> flowers;

	clumb()
	{
		number=0;
		shape="Undefined";
	}

	clumb(int a, string b, vector<string> c)
	{
		number=a;
		shape=b;
		flowers=c;
	}
	friend ostream& operator<<( ostream& os, const clumb& s )
    {
		return os << setw(3) << s.number << setw(10) << s.shape << setw(10) << s.flowers.back();
	}

	void input(int a, string b)  
	{
		number=a;
		shape=b;
	}

	clumb& operator=(const clumb& s)
	{
		if (this == &s) return *this;
		number=s.number;
		shape=s.shape;
		flowers=s.flowers;
		return *this;
	}
};

int main()
{
	setlocale (LC_CTYPE, "rus");
	vector<string> str;
	vector<clumb> vec;
	str.push_back("rose");
	clumb hg(3, "circle", str);
	vec.push_back(hg);
	cout << vec.back() << endl;


	int x;
	string strh;
	FILE *file; 
	char *fname = "in.txt";
	char result_sting[50];
	file = fopen(fname,"r");
	clumb clumbes[100];
	ifstream filen ("in.txt");
	cout << "Исходный массив: " << endl;
	/*for (int i=0; !filen.eof(); i++)
	{
		filen >> x;
		filen >> strh;
		clumbes[i].input(x, strh);
		vec.push_back(clumbes[i]);
		cout << vec.back() << endl;
	}*/

	int i=0;
	while(fgets(result_sting,sizeof(result_sting),file))
	{
		printf("%s", result_sting);
	}
	cout << endl;
	fclose(file);
}