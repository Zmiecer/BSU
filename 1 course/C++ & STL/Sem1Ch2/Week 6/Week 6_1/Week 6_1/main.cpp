#ifndef VECTOR_H
#define VECTOR_H


#include  "vector.h"

using namespace std;


void main()
{
	vector<int> vu(3);
	vector<int> fu(3);
	vector<int> v(2);
	vector<int>::iterator p;
	v[0]=10;
	v[1]=20;
	v[2]=30;

	cout << v[0] << " size: " << v.size << endl;

	v[3]=10;
	v[4]=20;
	v[5]=30;
	v[6]=40;
	cout << v[6] << " size: " << v.size << endl;
}

#endif