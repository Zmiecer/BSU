#include <iostream>
#include <fstream>
using namespace std;
ifstream infile1("int1.txt");
ifstream infile2("int2.txt");
ofstream outfile("out1.txt");
class cl
{
protected:
	int ar[8],w[8];
	int x,b,t,p,h;
public:
	cl() { x=0;b=0;t=0;p=0;h=0; }
	virtual void add(bool f)
	{
		for(int i=0;i<8;i++) ar[i]=0;
		if(f)
		{ 
			while(!infile1.eof())
			{
				infile1>>w[h];h++;
			}
		}
		else 
		{ 
			while(!infile2.eof())
			{
				infile2>>w[h];
				h++;
			}
		}
		for(int i=0;i<=h-1;i++)
		{
			p=w[i]%32;
			p=32-p;
			b=w[i]/32;
			ar[b]=ar[b]|(1<<p);
		}
	}
	virtual void del()
	{
		for(int i=0;i<8;i++)
		{
			ar[i]=NULL;
		}
	}
	virtual void display()
	{
		cout<<"Result: ";
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<32;j++)
			{
				if(ar[i]==(ar[i]|(1<<(32-j)))) 
					cout<<32*i+j<<' ';
			}
		}
		cout<<endl;
	}
};

class mn: public cl
{
private:
public:
	void add(bool f)
	{
		cl::add(f);
	}

	void display()
	{
		cl::display();
	}

	void del()
	{
		cl::del();
	}

	void srav(mn a,mn b)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<32;j++)
			{
				if(a.ar[i]==(a.ar[i]|(1<<(32-j)))&& b.ar[i]==(b.ar[i]|(1<<(32-j))))
				{
					cout<<32*i+j<<' ';
					outfile<<32*i+j;
				}
			}
		}
		cout<<endl;
	}
};

void main()
{
	mn a,b,c;
	bool f=true;
	a.add(f);
	a.display();

	f=false;
	b.add(f);
	b.display();
	c.srav(a,b);
	a.del();
	b.del();
}
