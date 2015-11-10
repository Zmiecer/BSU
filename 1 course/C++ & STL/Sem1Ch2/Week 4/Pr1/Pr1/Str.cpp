#include "Str.h"

using namespace std; 


Str::Str() : n(0), str(new char)
{
    str[0] = '\0';
}
 

Str::Str(const char* s) : n(s ? strlen(s) : 0)
{
    str = new char[n + 1];
    strcpy(str, s ? s : "");
}
 

Str::Str(char c) : n(1), str(new char[2])
{
    str[0] = c;
    str[1] = '\0';
}


Str::Str(const Str& st) : n(st.n), str(new char[st.n + 1])
{
    strcpy(str, st.str);
}
 

Str::~Str()
{
    delete [] str;
}
 

void Str::Clear()
{
    delete[] str;
    n = 0;
    str = new char[n + 1];
    str[0] = '\0';
 
}
 

Str Str::operator+= ( Str& st)
{
        char* k = new char[n + st.n + 1];
        return strcat(strcpy(k, str), st.str);
 
}
 
Str& Str::operator= (const Str& s)
{
    if (this == &s) return *this;
    delete [] str ;
    n = s.n;
    str = new char[n + 1];
    strcpy(str, s.str);
    return *this;
}
 

bool Str::operator== (const Str& p)const
{
    if(strcmp(str,p.str)==0)
    return true;
    else
        return false;
}
 
bool Str::operator> (const Str& p)const
{
    return strcmp(str, p.str) > 0;
}
 
bool Str::operator< (const Str& p)const
{
    return strcmp(str, p.str) < 0;
}

const char* Str::c_str() const
{
    return str;
}
 
int Str::size() const
{
    return n;
}

int Str::Chislo()
{
	return 0;

}