#include "Str.h"

using namespace std;

class Str10 : public Str
{
public:
	Str10() {};
	Str10(int m);
	int Str10::operator + (Str10 &s);
	int Chislo();
	bool Str10::operator >= (Str10 &s);
	bool Str10::operator <= (Str10 &s);
	void Sravnim(Str10 k2);
	//~Str10();
	//void Clear();
};