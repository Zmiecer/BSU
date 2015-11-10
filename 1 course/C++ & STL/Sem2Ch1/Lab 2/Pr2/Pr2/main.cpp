#include "Driver.h"


using namespace std;

bool cmp1(Driver v1, Driver v2)
{
	if (v1.number >= v2.number) return 0; else return 1;
}

int main()
{
	setlocale (LC_CTYPE, "rus");
	int x=0, y=0;
	Driver drivers[100];
	string str1, str2;
	vector<Driver> vec;

	ifstream file ("in.txt");
	cout << "Исходный массив: " << endl;
	for (int i=0; !file.eof(); i++)
	{
		file >> x;
		file >> str1;
		file >> y;
		file >> str2;
		drivers[i].input(x, str1, y, str2);
		vec.push_back(drivers[i]);
		cout << vec.back() << endl;
	}

	sort(vec.begin(), vec.end(), cmp1);
	
	vector<Driver>::iterator iter;
	
	cout << endl << "Сортированный массив: " << endl;
	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		cout << *iter << endl;
	}

	map<int, Driver> card;
	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		card[iter->number]=*iter;
	}

	
	cout << endl << "Введите искомый номер маршрута: " << endl;
	int Rou;
	cin >> Rou;
	cout << endl << "Искомые водители: " << endl;
	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		if(card[iter->number].route == Rou)
			cout << card[iter->number].surname << endl << endl;
	}

	cout << endl << "Введите искомую марку автобуса: " << endl;
	string Rou1;
	cin >> Rou1;
	cout << endl << "Искомые водители: " << endl;
	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		if(card[iter->number].brand == Rou1)
			cout << card[iter->number].surname << endl;
	}
	cout << card.count(23);
	cout << endl;
}