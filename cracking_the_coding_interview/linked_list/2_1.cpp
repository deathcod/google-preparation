#include <bits/stdc++.h>
using namespace std;

typedef struct $
{
	int value;
	struct $ *next;
}node;

node *init()
{
	node *x = (node *)malloc(sizeof(node));
	x->value = 0;
	x->next = NULL;
	return x;
}

void del(node *parent)
{
	node *x = parent->next;
	parent->next = parent->next->next;
	free(x);
}

void compute(node *lst)
{
	while(lst!=NULL)
	{
		node *temp = lst;
		int comp_value = lst->value;

		while(temp != NULL and temp->next != NULL)
		{
			if(temp->next->value == comp_value)
				del(temp);
			temp = temp->next;
		}

		lst = lst->next;
	}
}

void insert(node *x, int value)
{
	x->next = init();
	x->next->value = value;
}

void display(node *x)
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
	node *lst = init();
	node *parent = lst;
	lst->value = a[0];
	for (int i = 1; i < 6; ++i)
	{
		insert(lst, a[i]);
		lst = lst->next;
	}

	display(parent);
	compute(parent);
	display(parent);
	return 0;
}