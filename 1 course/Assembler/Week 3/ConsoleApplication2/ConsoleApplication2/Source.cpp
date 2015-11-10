#include <iostream>  

extern "C"  int __fastcall Remainder(int,int);

void main() 
{  
	std::cout << "remainder=" << Remainder(-12,5) << std::endl; 
}  