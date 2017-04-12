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
public:
	node *parent;
public:
	linked_list()
	{
		parent  = NULL;
	};
	~linked_list();
	void del(node *x);// pass the node you actually want to delete
	node *reverse(node *x, node *y);
	void perform_reverse();
	void nth_element(node *x, int n);
	void compute();
	void insert(int value);
	void display();
};


/*functions*/

void linked_list:: del(node *x)
{
	x->value = x->next->value;
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
	display();
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

void linked_list :: display()
{
	node *x = parent;
	while(x!=NULL)
	{
		x->print();
		x = x->next;
	}
	cout << "\n";
}

void linked_list :: perform_reverse()
{
	parent = reverse(NULL, parent);
}

int fun(node *x, node *y, int buffer, int result)
{
	if(x==NULL and y==NULL and buffer ==0)
		return result;

	if(x!=NULL and y!=NULL)
	{
		int sum = x->value + y->value + buffer;
		x->value = y->value = sum%10;
		buffer = sum/10;
	}

	if(x==NULL and y!=NULL)
	{
		int sum = y->value + buffer;
		y->value = sum%10;
		buffer = sum/10;
		if(buffer!=0 and y->next==NULL)
			y->next = new node(0);
		result = 1;
		return fun(NULL, y->next, buffer, result);
	}

	if(x!=NULL and y==NULL)
	{
		int sum = x->value + buffer;
		x->value = sum%10;
		buffer = sum/10;
		if(buffer!=0 and x->next==NULL)
			x->next = new node(0);
		return fun(x->next, NULL, buffer, result);
	}

	return fun(x->next, y->next, buffer, result);
}
int main(int argc, char const *argv[])
{
	
	int x[3] = {3, 1, 5};
	int y[2] = {9, 5};

	linked_list *lst_x = new linked_list();
	linked_list *lst_y = new linked_list();
	for (int i = 0; i < 3; ++i)
	{
		lst_x->insert(x[i]);
	}
	for (int i = 0; i < 2; ++i)
	{
		lst_y->insert(y[i]);
	}

	lst_x->perform_reverse();
	lst_y->perform_reverse();

	if (fun(lst_x->parent, lst_y->parent, 0, 0) == 0)
		lst_x->display();
	else
		lst_y->display();
	
	return 0;
}