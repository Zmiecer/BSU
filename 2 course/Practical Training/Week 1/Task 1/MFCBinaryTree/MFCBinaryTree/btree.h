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

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void pre_order() const;
	node *getRoot();

	CString str = _T("");

	void straight(CString* str);

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void pre_order(node *Node) const;

	node *root;

	void straight(node *root, CString* str);

	
};

#endif