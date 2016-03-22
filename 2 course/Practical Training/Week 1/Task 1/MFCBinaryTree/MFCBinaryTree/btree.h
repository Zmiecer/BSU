#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

struct node
{
	int key_value;
	node *left;
	node *right;
};


class btree
{
public:
	btree();
	~btree();

	void insert(int);
	node *search(int);
	void destroy_tree();
	void pre_order() const;
	node *getRoot();

	CString str = _T("");

	void straight(CString*);

	
	void intoArray(int *, int);
	void intoArray(node *, int *, int);

private:

	void destroy_tree(node *);
	void insert(int , node *);
	node *search(int , node *);
	void pre_order(node *) const;

	node *root;

	void straight(node *, CString*);

	
};

#endif