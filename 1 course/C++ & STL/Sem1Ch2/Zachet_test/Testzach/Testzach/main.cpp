#include <iostream>
#include "robot.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int x1, x2, y1, y2;
	hand* arr[10];
	cout << "������� ���� " << 1 << "-�� " <<  "�����" << " ����: ";
	cin >> x1; 
	cout << "������� ���� " << 2 << "-�� " <<  "�����" << " ����: ";
	cin >> x2;
	cout << "������� ���� " << 1 << "-�� " <<  "������" << " ����: ";
	cin >> y1;
	cout << "������� ���� " << 2 << "-�� " <<  "������" << " ����: ";
	cin >> y2;
	int n=4;
	rhand r1(x1), r2(x2);
	lhand l1(y1), l2(y2);
	arr[0]=&r1;
	arr[1]=&r2;
	arr[2]=&l1;
	arr[3]=&l2;
	l1=l2;
	r1.sila=l1.sila;
	cout << r1 << " " << r2 << " " << l1 << " " << l2 << endl;
	robot r(x1, y2);
	cout << "��������: " << r.difference() << endl;
	int g=0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (arr[i]->sila==arr[j]->sila)
				g++;
	cout << "����� ��� ��� � ���������� �����: " << g << endl;
}