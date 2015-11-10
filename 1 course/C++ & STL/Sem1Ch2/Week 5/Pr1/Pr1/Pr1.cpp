/*#include <iostream>
#include "Integer.h"
#include <fstream>

using namespace std;

void main()
{
	//fstream infile, outfile;
	ofstream outfile;
	ifstream infile;
	string str;
	infile.open("in.txt");
	int x;
	infile >> x;
	cout << x << endl;
	long int m[8];
	int k=0, f=0;
	//cin >> x;
	int mask=0x00000001;//8;32;256;
	int shift = (x%32-1);
	int b=mask << shift;
	//m[x/32] | b;
	cout << (m[x%32] & b) << endl;
	//unsigned int j=(m[x/32] & b);

	//f=m[x/32];
	/*for (int i=0; i<x; i++)
	{
		f=f >> 1;
		k++;
	}
	//cout << k << endl;
	outfile.open("out.txt");
	outfile << "Writing this to a file.\n";
	outfile << "Writing this to a file." <<endl;
    outfile.close();

}*/