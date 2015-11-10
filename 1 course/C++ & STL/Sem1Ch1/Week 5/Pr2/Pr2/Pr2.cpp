//2.	ѕродолжить вычисление выражени€ с учетом приоритета операций. ”сложнить за счет введени€ вложенных скобок. ƒл€ решени€ найдите алгоритм перевода в обратную польскую запись  алгебраического выражени€


#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
const int n=20;
char tempik[50];
int j=0;
string temp;

struct Stack
{
char A[n];
int count;
}; 


void Creation(Stack *p)
{ p->count=0; } 


int Full(Stack *p)
{
if (p->count==0) return 1;
//else if (p->count==n) return -1;
else return 0;
} 


void Add(Stack *p, char k)
{
p->A[p->count]=k;
p->count++;
} 


void Delete(Stack *p)
{ p->count--; } 


double Top(Stack *p)
{ return p->A[p->count-1]; } 


int Size(Stack *p)
{ return p->count; } 



string Perevod(string &str)
{
	int n;
	int m=str.size();
	Stack oper;
	Creation(&oper);
	//for (int i=0; i<m; i++)
	//	temp[i]=' ';
	string temp = tempik + '\n';


	for (int i=0; i<m; i++)
	{
		if (str[i]>='0' && str[i]<='9')
		{
			tempik[j]=str[i];
			j++;
			//cout << tempik[j-1] << endl;
		}
		else 
			if (str[i]!=')') 
			{
				Add(&oper, str[i]);
				if (i!=0) 
				{
					tempik[j]=' ';
					j++;
				}
				//cout << tempik[j-1] << endl;
			}
			else 
			{
				for (;Top(&oper)!='(';)
				{
					tempik[j]=' ';
					j++;
					tempik[j]=Top(&oper);
					Delete(&oper);
					j++;
				}
				Delete(&oper);
			}	
	}
tempik[j]='\0';
cout << "OPZ: " << tempik << endl; 
return tempik;
}




void main()
{
	Stack s;
	Creation(&s);
	string str;
	int i, count=0, k=0;
	double b[100], x=0, y=0, f=0;
	char t;
	cout << "Vvedite vash primer: ";
	getline(cin, str);
	temp="[(!)" + Perevod(str) +" ]\n";


	j=0;
	b[j]=0;
	for (i=0; i<temp.size(); i++) 
	   {
		   t=temp[i]; //cout << t << endl;
		   if (t>='0' && t<='9')
			{
				t=temp[i]; 
				b[j]=10*b[j] +(t-'0'); 
				//cout << b[j] << endl;
			}
		   if (t==' ' && temp[i-1]>='0' && temp[i-1]<='9') 
		   {
			   Add(&s, b[j]); 
			   j++; 
			   b[j]=0; 
			   //cout << Top(&s)<< endl;
		   }
		if (t=='+') 
		   {
			   x=Top(&s); 
			   Delete(&s); 
			   y=Top(&s); 
			   Delete(&s);
			   f=x+y;
			   Add(&s,f);
			   //cout << Top(&s) << endl;
		   }
		   if (t=='*') 
		   {
			   x=Top(&s); 
			   Delete(&s); 
			   y=Top(&s); 
			   Delete(&s);
			   f=x*y;
			   Add(&s,f);
			   //cout << Top(&s) << endl;
		   }
		  if (t=='-') 
		   {
			   x=Top(&s); 
			   Delete(&s); 
			   y=Top(&s); 
			   Delete(&s);
			   f=y-x;
			   Add(&s,f);
			   //cout << Top(&s) << endl;
		   }
		   if (t=='/') 
		  {
			   x=Top(&s); 
			   Delete(&s); 
			   y=Top(&s); 
			   Delete(&s);
			   f=(double)y/x;
			   //cout << f << endl;
			   Add(&s,f);
			   //cout << Top(&s) << endl;
		   }


	 }
	cout << "Resultat: " <<  Top(&s) << endl;

}




/*string Perevod(string str)
{
	Stack stach1, stach2;
	int n, r;
	string s1, s2, sum;
	double average = 0;
	int k=0;

	while(str.find(")") != string::npos) 
	{
		size_t scoba = str.find(")");
		string s1 = str.substr(0, scoba);
		str.erase(0, scoba + 1);
		if (s1[0]>='0' && s1[0]<='9')
		{
			for (int j=0; j<s1.size(); j++)
				r=10*r + (int)(s1[j]-'0');
			Add(&stach1, r);
		}
		else Add(&stach2, s1[0]);
	}

	return sum;
}*/
