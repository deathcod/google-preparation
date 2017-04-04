#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int value;
	int minimum;
	node *next;
public:
	node(int v, int m)
	{
		value = v;
		minimum = m;
		next = NULL;
	};
	~node();
};

class Stack
{
public:
	node *stack;
	int minimum;
public:
	Stack()
	{
		minimum = 1e9;
	};
	~Stack();
	void push(int value);
	bool pop();
	int mini();
};

void Stack :: push(int value)
{
	minimum = (minimum > value) ? value : minimum;
	node *x = new node(value, minimum);

	if(stack != NULL)
		x->next = stack;

	stack = x;
}

bool Stack :: pop()
{
	if(stack == NULL)
		return false;

	stack = stack->next;
}


int Stack :: mini()
{
	assert(stack != NULL);
	return stack->minimum;
}


int main(int argc, char const *argv[])
{
	Stack *s = new Stack();
	
	s->push(10);
	s->push(12);
	s->push(8);
	s->push(11);

	cout << s->mini() << " ";
	s->pop();

	cout << s->mini() << " ";
	s->pop();

	cout << s->mini() << " ";
	s->pop();

	cout << s->mini() << " ";
	cout << "\n";
	return 0;
}