#include <cstring>
#include <iostream>
#include <string>


using namespace std;
 
class Str
{
public:
	char* str;
    int n;


    Str();
    Str(const char*);
    Str(const Str&);
    Str(char); 
    ~Str(); 
    virtual void Clear();
    Str& operator=(const Str&);
    Str operator+=( Str&);
    bool operator>(const Str&)const;
    bool operator<(const Str&)const;
    bool operator==(const Str&)const;
    const char* c_str()const;
    int size()const;
	virtual int Chislo();

    friend istream& operator>>( istream& is, Str& s )
	{
        string s1;
        is >> s1;
        s.n = s1.size();
        delete[] s.str;
        s.str = new char[s.n + 1];
        strcpy(s.str, s1.c_str());
        return is;
    }
    friend ostream& operator<<( ostream& os, const Str& s )
    {
        return os << s.str;
    }
    friend std::istream& getline(std::istream& is, Str& s)
    {
        std::string s1;
        std::getline(is, s1);
        s.n = s1.size();
        delete[] s.str;
        s.str = new char[s.n + 1];
        strcpy(s.str, s1.c_str());
        return is;
    }
};