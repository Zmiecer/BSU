#ifndef Complex_H
#define Complex_H

//file contents here


#include <iostream>

using namespace std;

class Complex // ����� ����������� �����
{
private:
   double re;
   double im; // ����� � ������ �����
   
// ������� ������������   
public:
   
   Complex() {};
   
   Complex (double r) // ����������� �� ���������
   {
      re = r; 
	  im = 0;
   }
   
   Complex (double r, double i) // ����������� �� ���������
   {
      re = r; 
	  im = i;
   } 
   
   Complex (Complex &c) // ����������� �����������
   {
      re = c.re; 
	  im = c.im;
   }
   
   ~Complex() {}
   
   float abs() // ������ ������������ �����
   {
      return sqrt(re * re - im * im);
   }     

   Complex & operator = (Complex &c) // ���������� ��������� ������������
   {
      re = c.re;
	  im = c.im;

	  return (*this);
   }

   Complex Complex::operator + (Complex &c) // ���������� ��������� ��������
   {
	  Complex temp;

	  temp.re = re + c.re;
	  temp.im = im + c.im;
	  return temp;
   }

   Complex Complex::operator - (Complex &c) // ���������� ��������� ���������
   {
	  Complex temp;

	  temp.re = re - c.re;
	  temp.im = im - c.im;
	
	  return temp;
   }

   Complex Complex::operator * (Complex &c) // ���������� ��������� ���������
   {
	  Complex temp;

	  temp.re = re*c.re;
	  temp.im = im*c.im;

	  return temp;
   }

   Complex Complex::operator / (Complex &c) // ���������� ��������� �������
   {
	  Complex temp;

	  double r = c.re * c.re + c.im * c.im;
	  temp.re = (re * c.re + im * c.im) / r;
	  temp.re = (im * c.re - re * c.im) / r;

	  return temp;
   }   

   friend ostream &operator<<(ostream &, Complex &); // ���������� ��������� <<
   friend istream &operator>>(istream &, Complex &); // ���������� ��������� >>

};
#endif
