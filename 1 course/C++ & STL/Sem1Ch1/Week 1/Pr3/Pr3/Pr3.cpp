//3.	����� ��� ������� �������� ������������ ����� (�� ��������� 1 � ���� �����).
#include <iostream>
#include <cmath>
using namespace std;
int n, i, d, f, r, k, a[100];

void main()
{   cout << "Vvedite n" << endl;;
	cin >> n;
	cout << "Vse prostye deliteli chisla n:" << endl;
	d=0;
	i=0;
	for (d=2; d<=((n/2)+1); d++) {if ((n%d)==0) {a[i]=d; i++;}} //����� ���� ��������� ����� n
	f=i;
	//for (i=0; i<f; i++) cout << a[i] << " "; // ����� ���� ��������� ����� n
	r=0;
	for (i=0; i<f; i++) //������� �� ���������
	           {for (k=2; k<(a[i]/2+1); k++) //�������� �� ��������
	                 {if ((a[i]%k)==0) r++;} 
	                       if (r==0) cout << a[i] << " "; r=0;} // ����� ������� ��������� ����� n
    }