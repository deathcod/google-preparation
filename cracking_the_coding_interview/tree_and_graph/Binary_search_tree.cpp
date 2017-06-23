#include <bits/stdc++.h>
using namespace std;

class node
{
private:
	int value;
	node *left;
	node *right;
public:
	node(int v)
	{
		left = NULL;
		right = NULL;		
		value = v;
	};
	~node();
	void set_left(node *x) { left = x;}
	void set_right(node *x) { right = x;}
	void set_value(int x) {value = x;}
	node *get_left() { return left; }
	node *get_right() { return right; }
	int get_value() { return value; }
};

class Binary_search_tree
{
	node *root;
public:
	Binary_search_tree()
	{
		root = NULL;
	};
	~Binary_search_tree();
	void insert(int val);
	void del(int val);
	bool do_search(int val);
private:
	node * search(node *x,int val);
};

node * Binary_search_tree :: search(node *x, int val)
{
	while(x != NULL)
	{
		if(x->get_value() == val)
			return x;
		else if(x->get_value() > val)
		{
			if(x->get_left() == NULL)
				return x;
			else
				x = x->get_left();
		}
		else
		{
			if(x->get_right() == NULL)
				return x;
			else
				x = x->get_right();
		}
	}
}

void Binary_search_tree :: insert(int val)
{
	if(root == NULL)
	{
		root = new node(val);
		return;
	}
	node *x = search(root, val);
	if(x->get_value() == val)
	{
		cout << "value exists";
		return;
	}
	else
	{
		if(x->get_value() < val)
			x->set_right(new node(val));
		else
			x->set_left(new node(val));
	}
}

void Binary_search_tree :: del(int val)
{
	node *x = root;
	node *p = NULL;
	while(x != NULL)
	{
		if(x->get_value() == val)
			break;
		p = x;
		if(x->get_value() < val)
			x = x->get_right();
		else
			x = x->get_left();
	}
	if(x == NULL)
	{
		cout << "no value found";
		return ;
	}
	node *left = x->get_left();
	node *right = x->get_right();
	node *z = right;
	if(right == NULL)
		z = left;
	// if right is not null then offcourse z = right. so we are checking if 
	// the most smallest value in right if greater than left then set the current left to the 
	// left of the z(right) which is going to be replaced.
	if(right != NULL and left != NULL)
	{
		node  *temp = search(z, left->get_value());
		if(temp->get_value() < left->get_value())
			temp->set_right(left);
		else
			temp->set_left(left);
	}
	if(p == NULL)
		root = z;
	else if(p->get_right() == x)
		p->set_right(z);
	else
		p->set_left(z);
}

bool Binary_search_tree :: do_search(int val)
{
	node *x = search(root, val);
	return (x->get_value() == val);
}


int main(int argc, char const *argv[])
{
	Binary_search_tree *x = new Binary_search_tree();
	x->insert(8);
	x->insert(3);
	x->insert(10);
	x->insert(1);
	x->insert(6);
	x->insert(4);
	x->insert(7);

	cout << x->do_search(1) << "\n";

	x->del(4);cout << "\n";
	x->del(4);cout << "\n";
	x->del(6);cout << "\n";
	return 0;
}