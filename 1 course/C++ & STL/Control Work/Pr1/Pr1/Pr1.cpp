#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student
{
	string surname;
	int year;
	double index;
	Student(string a, int b, double c) : surname(a), year(b), index(c) {}
	Student() {}
};

int n;
string str;
Student students[100];
double average = 0;

void read() 
{
	n = 0;
	getline(cin, str);
	while(str.find(" ") != string::npos) 
	{
		size_t space = str.find(" ");
		string s = str.substr(0, space);
		str.erase(0, space + 1);
		space = str.find(" ");
		string year = str.substr(0, space);
		str.erase(0, space + 1);
		space = str.find(" ");
		string index = str.substr(0, space);
		str.erase(0, space + 1);
		int Year;
		double Index;
		stringstream(year) >> Year;
		stringstream(index) >> Index;
		students[n++] = Student(s, Year, Index); 
	}
}

bool cmp(Student a, Student b) {
	return a.index < b.index;
}

void sort() {
	sort(students, students + n, cmp);
}

double calculate() {
	double res = 0;
	for(int i = 0; i < n; ++i) {
		res += (double)students[i].year;
	}
	return res / (double)n;
}

string find_student() {
	double t = students[0].year;
	string s = students[0].surname;
	for(int i = 1; i < n; ++i) {
		if(fabs(students[i].year - average) < t)
			s = students[i].surname;
			t = fabs(students[i].year - average);
		}
	
	return s;
}

string Longname(){
	string s = students[0].surname;
	int t = students[0].surname.length();
	for(int i = 1; i < n; ++i) {
		if(students[i].surname.length() >= t) {
			t = students[i].surname.length();
			s = students[i].surname;
		}
	}
	return s;
}

int main () 
{
	cout << "Vvedite stroku: " << endl;
	read();
	
	sort();
	average = calculate();
	cout << "Student s godom rozhdenya, naybolee blizkim k centru: " << endl;
	cout << find_student() << endl;
	cout << "Otsortirovannyi massiv: " << endl;
	for(int i = 0; i < n; ++i) {
		cout << students[i].surname << ' ' << students[i].year << ' ' <<students[i].index << endl;
	}
	cout << "Student s samoi dlinnoi familiei: " << endl;
	cout << Longname() << endl << endl;
}