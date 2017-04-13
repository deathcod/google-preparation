#include <bits/stdc++.h>
using namespace std;

class node
{
private:
	int value;
	node *left;
	node *right;
	bool right_insert; //This is for Threaded Binary Tree implementation
public:
	node(int v)
	{
		left = NULL;
		right = NULL;
		right_insert = false;
		value = v;
	};
	~node();
	void set_left(node *x) { left = x;}
	void set_right(node *x) { right = x;}
	void set_value(int x) {value = x;}
	void set_rightinsert(bool x) { right_insert = x;}
	node *get_left() { return left; }
	node *get_right() { return right; }
	int get_value() { return value; }
	bool get_rightinsert() { return right_insert; }
};


class tree_traversal
{
	node *root;
public:
	tree_traversal(node *x)
	{
		root = x;
	};
	~tree_traversal();
	void level_order_traversal();
	void inorder(node *x);
	void inorder_without_recursion(node *x);
	void preorder(node *x);
	void postorder(node *x);

	/*Threaded Binary Tree implementaion*/
	void convert();
	void inorder_threaded_binary_tree_traversal();

	node *get_root();
};

//4 2 7 5 8 1 3 9 6 
void tree_traversal :: inorder(node *x)
{
	if(x->get_left() != NULL)
		inorder(x->get_left());
	cout << x->get_value() << " ";
	if(x->get_right() != NULL)
		inorder(x->get_right());
}

//4 2 7 5 8 1 3 9 6 
void tree_traversal :: inorder_without_recursion(node *x)
{
	stack<node *> z;
	z.push(x);
	while(!z.empty())
	{
		node *f = z.top();
		if(f->get_left() != NULL)
			z.push(f->get_left());
		else
		{
			while(1)
			{
				cout << f->get_value() << " ";
				z.pop();
				if(f->get_right() != NULL)
				{
					z.push(f->get_right());
					break;
				}
				if(z.empty()) break;
				f = z.top();
			}
		}
	}
}


//1 2 4 5 7 8 3 6 9 
void tree_traversal :: preorder(node *x)
{
	cout << x->get_value() << " ";
	if(x->get_left() != NULL)
		preorder(x->get_left());
	if(x->get_right() != NULL)
		preorder(x->get_right());
}

//4 7 8 5 2 9 6 3 1 
void tree_traversal :: postorder(node *x)
{
	if(x->get_left() != NULL)
		postorder(x->get_left());
	if(x->get_right() != NULL)
		postorder(x->get_right());
	cout << x->get_value() << " ";
}


void tree_traversal :: convert()
{
	stack<node *> z;
	z.push(root);
	while(!z.empty())
	{
		node *f = z.top();
		if(f->get_left() != NULL)
			z.push(f->get_left());
		else
		{
			while(1)
			{
				z.pop();
				if(f->get_right() != NULL)
				{
					z.push(f->get_right());
					break;
				}
				if(z.empty()) break;
				f->set_right(z.top());
				f->set_rightinsert(true);
				f = z.top();
			}
		}
	}
}

void tree_traversal :: inorder_threaded_binary_tree_traversal()
{
	node*x = root;
	while(x != NULL)
	{
		if(x->get_left() != NULL)
			x = x->get_left();
		else
		{
			cout << x->get_value() << " ";
			if(x->get_rightinsert())
			{
				x = x->get_right();
				cout << x->get_value() << " ";
				x = x->get_right();
			}
			else
			{
				x = x->get_right();
			}
		}
	}
}
/*
OUTPUT
======

1
2 3
4 5 6
7 8 9
*/
void tree_traversal :: level_order_traversal()
{
	queue<node *> x,y,*q,*q1;
	q = &x;
	q1 = &y;
	q->push(root);
	while(!q->empty())
	{
		node *f = q->front();
		q->pop();
		cout << f->get_value() << " ";
		if(f->get_left() != NULL)
			q1->push(f->get_left());
		if(f->get_right() != NULL)
			q1->push(f->get_right());
		if(q->empty())
		{
			cout << "\n";
			queue<node *> *v;
			v = q;
			q = q1;
			q1 = v;
		}
	}
}

node * tree_traversal :: get_root()
{
	return root;
}


/*
tree structure
==============

      1
    /  \  
   2    3
 /  \    \
4   5     6
   / \   /
  7  8  9

*/
int main(int argc, char const *argv[])
{
	tree_traversal *x = new tree_traversal(new node(1));
	
	//constructing the tree
	x->get_root()->set_left(new node(2));
	x->get_root()->set_right(new node(3));
	x->get_root()->get_left()->set_left(new node(4));
	x->get_root()->get_left()->set_right(new node(5));
	x->get_root()->get_right()->set_right(new node(6));
	x->get_root()->get_left()->get_right()->set_left(new node(7));
	x->get_root()->get_left()->get_right()->set_right(new node(8));
	x->get_root()->get_right()->get_right()->set_left(new node(9));

	//Breath first search
	x->level_order_traversal();
	

	//Depth first search
	x->inorder(x->get_root());
	cout << "\n";

	x->inorder_without_recursion(x->get_root());
	cout << "\n";

	x->preorder(x->get_root());
	cout << "\n";

	x->postorder(x->get_root());
	cout << "\n";

	x->convert();
	x->inorder_threaded_binary_tree_traversal();
	cout << "\n";
	return 0;
}