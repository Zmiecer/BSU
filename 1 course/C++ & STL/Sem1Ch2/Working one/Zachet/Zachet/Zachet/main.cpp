#include "circle.h"
#include <string>
#include <fstream>
#include <math.h>

ofstream outfile("out.txt");

using namespace std;


void main ()
{
	setlocale(LC_ALL, "Russian");
	Point* arr[20];
	Point* temp;
	Point* arr1[20];
	Circle* arrc[20];
	Point* arr1c[20];
	string s;
	int k=0, n=0, u=0, x1, y1, r1;
	double l1[10], l2[10];
	/*for (int i=0; i<6; i++)
	{
		cout<< "Введите 1, если хотите ввести точку; 2, если хотите ввести окружность; 0, если хотите закончить ввод: " << endl;
		cin >>k;
	}*/

	cout << "Введите 1-ую точку: " << endl;
	cin >> x1 >> y1;
	Point p1(x1, y1); 
	n++;

	cout << "Введите 2-ую точку: " << endl;
	cin >> x1 >> y1;
	Point p2(x1, y1); 
	n++;

	cout << "Введите 3-юю точку: " << endl;
	cin >> x1 >> y1;
	Point p3(x1, y1); 
	n++;

	cout << "Введите 1-ую окружность: " << endl;
	cin >> x1 >> y1 >> r1;
	Circle c1(x1, y1, r1); 
	n++;

	cout << "Введите 2-ую окружность: " << endl;
	cin >> x1 >> y1 >> r1;
	Circle c2(x1, y1, r1); 
	n++;

	cout << "Введите 3-юю окружность: " << endl;
	cin >> x1 >> y1 >> r1;
	Circle c3(x1, y1, r1); 
	n++;

	arr[0]=&p1; 
	arr[1]=&p2;
	arr[2]=&p3;
	arr[3]=&c1;
	arr[4]=&c2;
	arr[5]=&c3;
	//s=typeid(arr[0]).name();
	k=6;
	int f=0;
	for (int i=0; i<n; i++)
		if (dynamic_cast<Circle*>(arr[i])==0)
		{
			arr1c[f]=arr[i];
			f++;
		}
	for (int i=0; i<f; i++)
		for (int j=i+1; j<f-1; j++)
			if (arr1c[i]->rasst()>arr1c[j]->rasst())
			{
					temp=arr1c[i];
					arr1c[i]=arr1c[j];
					arr1c[j]=temp;
			}
	for (int i=0; i<f; i++)
		cout << "Расстояние от " << i+1 << "-ой точки от центра:  " <<  arr1c[i]->rasst() << endl;
	cout << "Точек в массиве: " << f << endl;
	outfile << "Точек в массиве: " << f << endl;
	for (int i=0; i<f; i++)
		outfile << "Расстояние от " << i+1 << "-ой точки от центра:  " <<  arr1c[i]->rasst() << endl;

	arr1[0]=&p1; 
	arr1[1]=&p2;
	arr1[2]=&p3;
	arr1[3]=&c1;
	arr1[4]=&c2;
	arr1[5]=&c3;
	u=0;
	//s=typeid(arr1[5]).name();
	for (int i=0; i<n; i++)
		if (dynamic_cast<Circle*>(arr1[i]))
			{
				Circle* ptr=reinterpret_cast<Circle*> (arr1[i]);
				arrc[u]=ptr;
				u++;
			}
		cout << "Окружностей в массиве: " << u << endl;
		for (int j=0; j<u; j++)
			if(arrc[j]->r>arrc[j]->rasst())
			{
				cout << "Начало координат лежит в " << j+1 << "-ой окружности. С радиусом " << arrc[j]->r << endl;
				outfile << "Начало координат лежит в " << j+1 << "-ой окружности. С радиусом " << arrc[j]->r << endl;
			}
		
}