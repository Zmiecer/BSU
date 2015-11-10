#ifndef Complex_H
#define Complex_H

//file contents here


#include <iostream>

using namespace std;

class Complex // класс комплексных чисел
{
private:
   double re;
   double im; // целая и мнимая части
   
// создаем конструкторы   
public:
   
   Complex() {};
   
   Complex (double r) // конструктор по умолчанию
   {
      re = r; 
	  im = 0;
   }
   
   Complex (double r, double i) // конструктор по умолчанию
   {
      re = r; 
	  im = i;
   } 
   
   Complex (Complex &c) // конструктор копирования
   {
      re = c.re; 
	  im = c.im;
   }
   
   ~Complex() {}
   
   float abs() // Модуль комплексного числа
   {
      return sqrt(re * re - im * im);
   }     

   Complex & operator = (Complex &c) // перегрузка оператора присваивания
   {
      re = c.re;
	  im = c.im;

	  return (*this);
   }

   Complex Complex::operator + (Complex &c) // перегрузка оператора сложения
   {
	  Complex temp;

	  temp.re = re + c.re;
	  temp.im = im + c.im;
	  return temp;
   }

   Complex Complex::operator - (Complex &c) // перегрузка оператора вычитания
   {
	  Complex temp;

	  temp.re = re - c.re;
	  temp.im = im - c.im;
	
	  return temp;
   }

   Complex Complex::operator * (Complex &c) // перегрузка оператора умножения
   {
	  Complex temp;

	  temp.re = re*c.re;
	  temp.im = im*c.im;

	  return temp;
   }

   Complex Complex::operator / (Complex &c) // перегрузка оператора деления
   {
	  Complex temp;

	  double r = c.re * c.re + c.im * c.im;
	  temp.re = (re * c.re + im * c.im) / r;
	  temp.re = (im * c.re - re * c.im) / r;

	  return temp;
   }   

   friend ostream &operator<<(ostream &, Complex &); // перегрузка оператора <<
   friend istream &operator>>(istream &, Complex &); // перегрузка оператора >>

};
#endif
