#include <iostream>
#include "Complex.h"


using namespace std;

class Stack
{
	Complex a;
	int count;

public:
//создание стека
void Creation()
{ count=0; } 

//проверка стека на пустоту
int Full(Stack *p)
{
if (p->count==0) return 1;
//else if (p->count==n) return -1;
else return 0;
} 


//добавление элемента
int Add(Complex c)
{
a=c;
count++;
return 0;
} 

//удаление элемента
void Delete()
{ 
	count--; 
} 

//вывод верхнего элемента
Complex Top()
{ return a; } 

//размер стека
int Size(Stack *p)
{ return p->count; }

};