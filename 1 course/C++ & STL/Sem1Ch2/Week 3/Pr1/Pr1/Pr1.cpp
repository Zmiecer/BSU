#include "iostream"
#include "Student2.h"

using namespace std;

int k[4], l[4];


void main()
{
	setlocale(LC_ALL, "Russian");
	Student* Starr[100];
	Student1* Stdarr[100];
	Student2* St2arr[100];
	Student St[20];
	Student1 St1[20];
	Student2 St2[20];
	int N=0;
	double  S=0;

	/*cin >> St1[0];	
	N++;
	for (int i=0; i<4; i++)
	{
		cin >> k[i];
	}
	St1[0].Ses1(k);
	St1[0].show();
	cout << endl;


	cin >> St2[0];
	N++;
	for (int i=0; i<4; i++)
	{
		cin >> k[i];
	}
	for (int i=0; i<4; i++)
	{
		cin >> l[i];
	}
	St2[0].Ses1(k);
	St2[0].Ses2(l);
	St2[0].show();
	cout << endl;

	cout << St1[0].ball() << " " << St2[0].ball() << endl;

	Starr[0]=&St1[0];
	Starr[1]=&St2[0];
	for (int i=0; i<N; i++)
		Starr[i]->show();
	cout << endl;

	for (int i=0; i<N; i++)
		S+=Starr[i]->ball();
	cout << (double)S/N;
	cout << endl;*/


	
	int m=0, n=0, d=1, x, a=0, b=0, c=0, z=0;
	S=0;

	for (int i=0; d!=0; i++)
	{
		cout << "������� 0 ��� ����� �������� ��������, 1 ��� ����� �������� ����� ������ ������, 2 ��� ����� �������� ����� ���� ������, 3 ��� ����, ����� ��������� ����:" << endl;
		cin >> x;
		if (x==3) d=0;
	if (x==0) 
		{
			cout << "������� ������ � ������� �������� ����� ������:" << endl;
			cin >> St[a]; 
			a++;
			i--;
		}
		if (x==1) 
		{
			cout << "������� ������ � ������� �������� ����� ������:" << endl;
			cin >> St1[b];
			cout << "������� ������ ����� ������ ������:" << endl;
			for (int i=0; i<4; i++)
			{
				cin >> k[i];
			}
			St1[b].Ses1(k);
			Stdarr[i]=&St1[b];
			//St1[b].show();
			b++;
			n++;
		}
		if (x==2) 
		{
			cout << "������� ������ � ������� �������� ����� ������:" << endl;
			cin >> St2[c]; 
			cout << "������� ������ ����� ������ ������:" << endl;
			for (int i=0; i<4; i++)
			{
				cin >> k[i];
			}
			cout << "������� ������ ����� ������ ������:" << endl;
			for (int i=0; i<4; i++)
			{
				cin >> l[i];
			}
			St2[c].Ses1(k);
			St2[c].Ses2(l);
			Stdarr[i]=&St2[c];
			St2arr[z]=&St2[c];
			z++;
			//St2[c].show();
			c++;
			n++;
		}
	}
	
	
	int g, h, u=1;
	
	for (;u!=0 || h!=0;)
	{
		cout << "������� 1, ���� ������ ��������� ������� ���� ����� ������ ������, 2 - ������� ���� ����� ������ ������, � 0 - ���� ������ ��������� ������� ������� ����: " << endl;
		cin >> h;
		if (h==1)
		{
			cout << "������� ����� ������ ��� �������� �������� ����� �� ������ ������" << endl;
			cin >> g;
			S=0;
			for (int i=0; i<n; i++)
			{
				//cout << Stdarr[i]->Group << endl;
				if (Stdarr[i]->Group==g)
					for (int j=0; j<4; j++) 
					{
						//cout << S << " " << Stdarr[i]->ses1[j] << endl;
						S+=Stdarr[i]->ses1[j];
						m++;
					}
			}
			cout << "������� ���� �� ������ ������ � " << g << " ������: " << (double)S/m << endl;
		}
	
		if (h==2)
		{
			cout << "������� ����� ������ ��� �������� �������� ����� �� ���� �������" << endl;
			cin >> g;
			S=0;
			m=0;
			for (int i=0; i<n; i++)
			{
				//cout << Stdarr[i]->Group << endl;
				if (Stdarr[i]->Group==g)
					for (int j=0; j<4; j++) 
					{
						//cout << S << " " << Stdarr[i]->ses1[j] << endl;
						S+=St2arr[i]->ses1[j] + St2arr[i]->ses2[j];
						m+=2;
					}
			}
			cout << "������� ���� �� ���� ������� � " << g << " ������: " << (double)S/m << endl;
		}
		
		if (h==0) u=0;
	}
}