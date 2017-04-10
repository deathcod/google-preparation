#include <bits/stdc++.h>
using namespace std;

class node
{
private:
	int value;
	node *next;

public:
	node(int v)
	{
		value = v;
		next = NULL;
	};
	~node();
	void set_next(node *y) { next = y;}
	void set_value(int val) { value = val;}
	node *get_next() { return next;}
	int get_value() { return value;}
};

class LINKED_LIST
{
	node *parent;
	node *NIL;
public:
	LINKED_LIST()
	{
		parent = NIL = new node(0);
	};
	~LINKED_LIST();
	void insert(int value);
	bool list_search(int value);
};

void LINKED_LIST :: insert(int value)
{
	node *z = new node(value);
	z->set_next(parent);
	parent = z;
}

bool LINKED_LIST :: list_search(int value)
{
	node *z = parent;
	NIL->set_value(value);
	while(z->get_value() != value)
	{
		z = z->get_next();
	}
	return (z!=NIL);
}

int main(int argc, char const *argv[])
{
	LINKED_LIST *z = new LINKED_LIST();
	z->insert(10);
	z->insert(11);
	z->insert(12);

	cout << z->list_search(11) << "\n";
	cout << z->list_search(2) << "\n";
	cout << z->list_search(10) << "\n";
 	return 0;
}