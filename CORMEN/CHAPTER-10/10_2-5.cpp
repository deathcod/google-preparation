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

class CIRCULAR_LINKEDLIST
{
private:
	node *ptp;
public:
	CIRCULAR_LINKEDLIST()
	{
		ptp = NULL;
	};
	~CIRCULAR_LINKEDLIST();
	void insert(int value);
	bool del(int index);
	bool search(int value);
	int get_top();
	int get_top(node *x);
	void display();
};

void CIRCULAR_LINKEDLIST :: insert(int value)
{
	node *z = new node(value);
	if(ptp == NULL)
	{
		ptp = z;
		z->set_next(ptp);
	}
	else
	{
		node *f = ptp->get_next();
		ptp->set_next(z);
		z->set_next(f);
		ptp = z;
	}
}

bool CIRCULAR_LINKEDLIST :: del(int index)
{
	if(ptp == NULL)
	{
		cout << "no value\n";
		exit(0);
	}
	node *parent = ptp->get_next();
	if(index == 0)
	{
		if(parent->get_next() == parent)
			ptp = NULL;
		else
			ptp->set_next(parent->get_next());
	}
	else
	{
		int count = 0;
		while(count < index -1)
		{
			count++;
			parent = parent->get_next();
			if(parent == ptp) break;
		}
		if(parent == ptp)
			return false;

 		if(parent->get_next() == ptp)
			ptp = parent;

		parent->set_next(parent->get_next()->get_next());
	}
	return true;
}

bool CIRCULAR_LINKEDLIST :: search(int value)
{
	node *z = ptp->get_next();
	do
	{
		if(z->get_value() == value) return true;
		z = z->get_next();
	}while(z!=ptp->get_next());
	
	return false;
}

int CIRCULAR_LINKEDLIST :: get_top()
{
	return ptp->get_next()->get_value();
}


int CIRCULAR_LINKEDLIST :: get_top(node *x)
{
	return x->get_value();
}


void CIRCULAR_LINKEDLIST :: display()
{
	node *z = ptp->get_next();
	if(ptp == NULL)
		return;

	cout << "|| ";
	do
	{
		cout << z->get_value() << ",";
		z = z->get_next(); 
	} while (z!=ptp->get_next());
	cout << "|| \n";
}


int main(int argc, char const *argv[])
{
	CIRCULAR_LINKEDLIST *x = new CIRCULAR_LINKEDLIST();
	
	x->insert(10);

	//CASE 1
	cout << x->del(0)<< "\n";
	//cout << x->del(0)<< "\n";
	x->insert(12);
	x->insert(13);
	x->insert(14);
	x->display();

	// << x->del(1)<< "\n";
	x->insert(14);
	x->insert(15);

	cout << x->del(0)<< "\n";
	x->display();

	return 0;
}