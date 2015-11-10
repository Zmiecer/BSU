//1.	�������� ���������, ������� ���������, ��������� �� ����������� ������ � ���������, ���� ��� ������� �� ������ ����: ( ) [ ] { }. (������������ ��������� ������ ����). ���� ���������� �� ��������� ���������



#include <iostream>
#include <string>
using namespace std;
const int n=20;

struct Stack
{
char A[n];
int count;
}; 

//�������� �����
void Creation(Stack *p)
{ p->count=0; } 

//�������� ����� �� �������
int Full(Stack *p)
{
if (p->count==0) return 1;
//else if (p->count==n) return -1;
else return 0;
} 

//���������� ��������
void Add(Stack *p, char k)
{
int value;
p->A[p->count]=k;
p->count++;
} 

//�������� ��������
void Delete(Stack *p)
{ p->count--; } 

//����� �������� ��������
char Top(Stack *p)
{ return p->A[p->count-1]; } 

//������ �����
int Size(Stack *p)
{ return p->count; } 


void main()
{
Stack s;
Creation(&s);
string str;
int u;
char t;
cin >> str;
u=1;
for (int i=0; i<str.size(); i++) 
   {
	  t=str[i]; //cout << t;
	  if (u!=0)
	  switch (t)
	  {
	      case ('('): Add(&s, t); break;
		  case ('{'): Add(&s, t); break;
		  case ('['): Add(&s, t); break;
		  case (')'): if (Top(&s)=='(') Delete(&s); 
					  else { cout << "Incorrect"; u=0;} break;
		  case ('}'): if (Top(&s)=='{') Delete(&s); 
					  else { cout << "Incorrect"; u=0;} break;
		  case (']'): if (Top(&s)=='[') Delete(&s); 
					  else { cout << "Incorrect"; u=0;} break;
	  }
   }
if (Full(&s)==1) 
	cout << "Correct" << endl; 
else cout << "Incorrect" << endl;
}