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


class super_node
{
public:
	STACK *s;
	super_node *next;
	int size;
	int N;
public:
	super_node(int n)
	{
		N = n;
		s = NULL;
		next = NULL;
		size = 0;
	};
	~super_node();
	int top();
	bool pop();
	bool push(int value);
};


bool super_node :: push(int value)
{
	if( s == NULL)
		s = new STACK();
	if(size == N)
		return false;
	s->push(value);
}

bool super_node :: pop()
{
	return (s->pop());
}

int super_node :: top()
{
	return (s->top());
}

class SUPER_STACK
{
public:
	super_node * parent;
	int N;
public:
	SUPER_STACK(int n)
	{
		N = n;
		parent = NULL;
	};
	~SUPER_STACK();
	void push(int value);
	bool pop();
};

void SUPER_STACK :: push(int value)
{
	if(parent == NULL)
		parent = new super_node(N);

	if(!parent->push(value))
	{
		super_node *z = new super_node(N);
		z->push(value);
		z->next = parent;
		parent = z;
	}
}

bool SUPER_STACK :: pop()
{
	if(parent == NULL)
		return false;

	parent->s->pop();
	if(parent->size == 0)
	{
		parent = parent->next;
	}
}

int main(int argc, char const *argv[])
{
	SUPER_STACK *s = new SUPER_STACK(2);
	
	s->push(10);
	s->push(12);
	s->push(8);
	s->push(11);

	//cout << s->top() << " ";
	s->pop();

	//cout << s->top() << " ";
	s->pop();

	//cout << s->top() << " ";
	s->pop();

	//cout << s->top() << " ";
	s->pop();

	cout << "\n";
	return 0;
}