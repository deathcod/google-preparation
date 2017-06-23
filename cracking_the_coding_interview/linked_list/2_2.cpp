#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int value;
	node *next;
public:
	node(int val)
	{
		value = val;// I kept value = value it was not working that means it is not understand global and local variable.
		next = NULL;
	};
	~node();
	void print()
	{
		cout << value << " ";
	} 	
};

class linked_list
{
	node *parent;
public:
	linked_list()
	{
		parent  = NULL;
	};
	~linked_list();
	void del(node *x);
	node *reverse(node *x, node *y);
	void nth_element(node *x, int n);
	void compute();
	void insert(int value);
	void display(node *x);
};


/*functions*/

void linked_list:: del(node *x)
{
	x->next = x->next->next;
}

node* linked_list :: reverse(node *x, node *y)
{
	if(y == NULL)
		return x;

	node *temp = y->next;
	y->next = x;
	return reverse(y, temp);
}

void linked_list :: nth_element(node *x, int n)
{
	while(n>0)
	{
		if(n==1)
			x->print();
		x = x->next;
		n--;
	}
}

void linked_list :: compute()
{
	parent = reverse(NULL, parent);
	display(parent);
	int input;
	while(scanf("%d",&input) != EOF)
	{
		nth_element(parent, input);
	}
}

void linked_list :: insert(int value)
{
	if (parent == NULL)
		parent = new node(value);
	else
	{
		node *temp = parent;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new node(value);
	}
}

void linked_list :: display(node *x)
{
	while(x!=NULL)
	{
		cout << x->value << " ";
		x = x->next;
	}
	cout << "\n";
}
int main(int argc, char const *argv[])
{
	
	int a[6] = {2, 7, 9, 5, 2, 7};
	linked_list *x = new linked_list();
	for (int i = 0; i < 6; ++i)
	{
		x->insert(a[i]);
	}

	x->compute();
	
	return 0;
}