//1.	����� ��� �������� ������������ ����� (�� ��������� 1 � ���� �����).
#include <iostream>
#include <cmath>
using namespace std;
int n, i;

void main()
{   cout << "Vvedite n" << endl;;
	cin >> n;
	cout << "Vse deliteli chisla n:" << endl;
	for (i=2; i<=((n/2)+1); i++) {if ((n%i)==0) cout << i << " ";}}