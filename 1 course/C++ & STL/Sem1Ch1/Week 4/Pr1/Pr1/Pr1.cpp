//Функция находит в строке десятичные константы и собирает их в отдельный массив.
//Функция заменяет их на шестнадцатеричные с тем же значением, например, «ааааа258ххх» на «ааааа0х102ххх».


#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int j , b[100];

int main ()
{
	string str, str1;
	char numb[40][11], bufi[100], bufs[100], string[100], str2[100];
	cout << "Vvedite stroku: " << endl;
	cin>>str;
	b[0]=0;
	int p=0;
	int count=0, k=0;
	strcpy (string, "");
	cout << "Chislovye const iz stroki: " << endl;
	for (int i=0; i<str.size(); i++)
	{
		if (str[i]>='0' && str[i]<='9')
		{
			numb[count][k++]=str[i]; 
			b[j]=10*b[j] +(numb[count][k-1]-'0'); 
			p++;
		}
		else 
			if (k!=0)
			{
				if (p!=0) 
				{
					itoa (b[j],bufi,16);
					strcat(string,bufi);
				}
				bufs[0]=str[i];
				strncat (string, bufs, 1);
				count++;
				//k=0; //Для первой задачи убрать знак "//"
				j++;
				b[j]=0;
				p=0;
			}
	}
	if (k!=0)
			{
				if (p!=0) 
				{
					itoa (b[j],bufi,16);
					strcat(string,bufi);
				}
				strcat (string,"");
			}
	cout << endl;
	/*cout << "Chisla iz stroki: " << endl;
	for (j=0; j<=count; j++) cout << b[j] << " ";
	cout << endl;*/ //Для первой задачи убрать "/*" и "*/"
	cout << "Zamena na 16-richnye: " << string << endl; // Для первой задачи поставить "//"
}