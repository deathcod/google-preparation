#include <bits/stdc++.h>
using namespace std;

// This is the smallest part of the stack, a node which creates the stack
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
	node *get_next() { return next;}
	int get_value() { return value;}
};

class STACK
{
private:
	node *stack;

public:
	STACK()
	{
		stack = NULL;
	};
	~STACK();
	void push(int value);
	bool pop();
	int top();
	bool isempty();
};

void STACK :: push(int value)
{
	node *x = new node(value);

	if(stack != NULL)
		x->set_next(stack);

	stack = x;
}

bool STACK :: pop()
{
	if(stack == NULL)
		return false;

	stack = stack->get_next();
}

int STACK :: top()
{
	assert(stack != NULL);
	return stack->get_value();
}

bool STACK :: isempty()
{
	return (stack == NULL);
}

int main(int argc, char const *argv[])
{
	STACK *s1 = new STACK();
	STACK *s2 = new STACK();

	s1->push(5);
	s1->push(2);
	s1->push(6);
	s1->push(1);
	s1->push(4);

	s2->push(s1->top());
	s1->pop();

	while(!s1->isempty())
	{
		if(s2->top() > s1->top())
		{
			s2->push(s1->top());
			s1->pop();
		}
		else
		{
			int x = s1->top();
			s1->pop();
			while(!s2->isempty() && s2->top() < x)
			{
				s1->push(s2->top());
				s2->pop();
			}
			s2->push(x);
		}
	}
	while(!s2->isempty())
	{
		cout << s2->top() << ",";
		s2->pop();
	}
	cout << "\n";
	return 0;
}