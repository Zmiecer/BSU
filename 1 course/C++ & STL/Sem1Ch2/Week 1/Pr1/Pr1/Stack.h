#include <iostream>
#include "Complex.h"


using namespace std;

class Stack
{
	Complex a;
	int count;

public:
//�������� �����
void Creation()
{ count=0; } 

//�������� ����� �� �������
int Full(Stack *p)
{
if (p->count==0) return 1;
//else if (p->count==n) return -1;
else return 0;
} 


//���������� ��������
int Add(Complex c)
{
a=c;
count++;
return 0;
} 

//�������� ��������
void Delete()
{ 
	count--; 
} 

//����� �������� ��������
Complex Top()
{ return a; } 

//������ �����
int Size(Stack *p)
{ return p->count; }

};