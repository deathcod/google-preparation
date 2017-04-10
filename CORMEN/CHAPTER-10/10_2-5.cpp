#include <bits/stdc++.h>
using namespace std;

class node
{
public:
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

class CIRCULAR_LINKEDLIST
{
public:
	node *parent;
public:
	CIRCULAR_LINKEDLIST()
	{
		parent = NULL;
	};
	~CIRCULAR_LINKEDLIST();
	void insert(int value);
	bool del(node *x);
	bool search(int value);
	int get_top();
	int get_top(node *x);
	void display();
};

void CIRCULAR_LINKEDLIST :: insert(int value)
{
	node *z = new node(value);
	if(parent == NULL)
	{
		parent = z;
		z->set_next(parent);
	}
	else
	{
		node *f = parent->get_next();
		parent->set_next(z);
		z->set_next(f);
	}
}

bool CIRCULAR_LINKEDLIST :: del(node *x)
{
	if(parent == NULL)
		return false;

	if(x == NULL)
		return false;

	if (parent == x)
	{
		if (parent->get_next() == parent)
		{
			cout << "CASE 1" << "\n";
			parent = NULL;
		}
		else
		{
			parent->set_value(parent->get_next()->get_value());
			parent->set_next(parent->get_next()->get_next());
			cout << "CASE 2" << "\n";
		}
	}
	else
	{
		node *pre = parent->get_next();
		if(pre->get_next() == parent and pre == x)
		{
			parent->set_next(parent);
			cout << "CASE 4" << "\n";
		}
		else
		{
			pre = parent;
			while(pre->get_next()!=x and pre->get_next() != parent)
			{
				pre = pre->get_next();
			}
			if(pre->get_next() == parent)
				return false;

			pre->set_value(pre->get_next()->get_value());
			pre->set_next(pre->get_next()->get_next());
			cout << "CASE 5" << "\n";
		}
	}
	return true;
}

bool CIRCULAR_LINKEDLIST :: search(int value)
{
	node *z = parent;
	if(z->get_value() == value)
		return true;

	z = parent->get_next();
	while(z!=parent and z->get_value() == value)
	{
		z = z->get_next();
	}
	return(z != parent);

}

int CIRCULAR_LINKEDLIST :: get_top()
{
	return parent->get_value();
}


int CIRCULAR_LINKEDLIST :: get_top(node *x)
{
	return x->get_value();
}


void CIRCULAR_LINKEDLIST :: display()
{
	node *z = parent;
	if(parent == NULL)
		return;

	cout << "|| ";
	do
	{
		cout << z->get_value() << ",";
		z = z->get_next(); 
	} while (z!=parent);
	cout << "|| \n";
}


int main(int argc, char const *argv[])
{
	CIRCULAR_LINKEDLIST *x = new CIRCULAR_LINKEDLIST();
	
	x->insert(10);

	//CASE 1
	cout << x->del(x->parent)<< "\n";
	cout << x->del(x->parent)<< "\n";
	x->insert(12);
	x->insert(13);
	x->insert(14);
	x->display();

	cout << x->del(x->parent)<< "\n";
	x->insert(14);
	x->insert(15);

	x->display();
	// cout << x->del(x->parent->get_next()) << "\n";
	// cout << x->get_top(x->parent) << " ";
	// cout << x->get_top(x->parent->get_next()) << " ";

	// cout << x->del(x->parent->get_next())<< "\n";
	// cout << x->get_top(x->parent) << " ";
	// cout << x->get_top(x->parent->get_next()) << " ";

	// cout << x->del(x->parent->get_next())<< "\n";
	// cout << x->get_top(x->parent) << " ";
	// cout << x->get_top(x->parent->get_next()) << " ";

	// cout << x->del(x->parent->get_next())<< "\n";
	// cout << x->get_top(x->parent) << " ";
 // 	cout << x->get_top(x->parent->get_next()) << " ";
 // 	cout << x->get_top(x->parent->get_next()->get_next()->get_next()) << " ";

	return 0;
}