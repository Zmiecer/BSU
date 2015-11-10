//5.         Найти k-ую цифру числа, полученного последовательной записью натуральных чисел 1 2 3 4 5 6 7 8 9 10 11 . . .
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string str, str1, s;
int k, n, i;
char p;

string intToStr(int n)
{
     s = n == 0 ? "0" : "";
     while(n >0)
     {
          s = (char)('0'+n%10) + s;
          n /= 10;
     }
     return s;
}

void main() 
{
	cout << "Vvedite k:" << endl;
	cin >> k;
n=k+1;
for (i=1; i<n; i++) 
   {
	str1=intToStr(i);
    str+=str1;
    }
cout << "k-aya cifra chisla: " << str[k-1] << endl;
}