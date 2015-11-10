//–азделители чисел в строке Ц знаки операций + и -. ¬ычислить значение выражени€.

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int j , b[100];

int main ()
{
	string str;
	char a, znak;
	int b=0, k=0, s=0;
	cout << "Vvedite vyrazhenie: " << endl;
	cin>>str;
	znak='0';
	for (int i=0; i<str.size(); i++)
	{
		if (str[i]>='0' && str[i]<='9') 
		{
				a=str[i];
				b=10*b + (a-'0');
		}
		else
		{
			if (znak=='+') {s=s+b;}
			if (znak=='-') {s=s-b;}
			if (znak=='0') 
			{
					znak=str[i];
					s=b;
			}
			b=0;
			znak=str[i];
					
		}
	}
if (znak=='+') {s=s+b;}
if (znak=='-') {s=s-b;}
cout << str << "=" << s << endl;
}