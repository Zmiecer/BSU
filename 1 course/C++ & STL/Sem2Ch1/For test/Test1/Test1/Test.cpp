#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;
void main()
{
	//1
	vector<int> v;//любые виды векторов
	vector<char> c(5);
	vector<char> ch(5,'x');
	//vector<char> cha(v);
	
	
	
	


	
	
	//2
	int ar[5];
	vector<char> vex(5);
	
	
	
	
	
	
	//3
	int s=v.size();
	int cap=v.capacity();
	
	
	
	
	
	
	//4 через итератор
	vector<int>::iterator iter;
	iter=v.begin();
	cout<<*iter;
	
	
	
	
	
	
	//5
	v.push_back(5);
	list<int> ilist;
	ilist.push_back(30);
	ilist.push_front(10);
	v.insert(v.begin()+2,15);
	
	
	
	
	
	
	//6
	iter=v.begin();
	iter=v.end();
	
	
	
	
	
	
	//7
	ilist.push_back(30);
	ilist.push_front(10);
	//8

	
	
	
	
	
	
	//9
	ilist.push_back(30);
	ilist.push_front(10);
	
	
	
	
	
	
	//10
	int ms=v.max_size();
	
	
	
	
	
	
	//11
	v.resize(3);
	v.resize(5,'x');
	
	
	
	
	
	
	//12 через copy
	v.erase(v.begin());
	
	
	
	
	
	
	//13
	v.push_back(10);
	v.pop_back();
	
	
	
	
	
	
	//14
	
	
	
	
	
	
	//15
	deque<int> deq;
	deque<int>::iterator dit;
	dit=deq.begin();
	cout<<*dit;
	
	
	
	
	
	
	//16
	deq.push_back(1);
	deq.push_front(1);
	
	
	
	
	
	
	//17
	deq.pop_back();
	deq.pop_front();
	
	
	
	
	
	
	//18
	deq.push_front(1);
	deq.pop_front();
	
	
	
	
	
	
	
	//19
	deq.push_back(1);
	deq.pop_back();
	
	
	
	
	
	
	
	
	
	
	
	
	//20
	list<int> list2;
	ilist.merge(list2);
	
	
	
	
	
	
	
	
	
	
	
	
	//21
	remove_if(list2.begin(),list2.end(),4);
	//22
	
	
	
	
	
	
	//23
	list2.unique();
}