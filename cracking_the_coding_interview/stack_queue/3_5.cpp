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


class QUEUE
{
private:
	STACK *s1;
	STACK *s2;
public:
	QUEUE()
	{
		s1 = new STACK();
		s2 = new STACK();
	};
	~QUEUE()
	{
		delete(s1);
		delete(s2);
	};
	void push(int value);
	bool pop();
	int front();
};

void QUEUE :: push(int value)
{
	while(!s2->isempty())
	{
		s1->push(s2->top());
		s2->pop();
	}
	s1->push(value);

}

bool QUEUE :: pop()
{
	while(!s1->isempty())
	{
		s2->push(s1->top());
		s1->pop();
	}
	if(s2->isempty()) return false;
	s2->pop();
	return true;
}

int QUEUE :: front()
{
	if(!s2->isempty())
		return s2->top();

	while(!s1->isempty())
	{
		s2->push(s1->top());
		s1->pop();
	}

	assert(!s2->isempty());
	return s2->top();
}


int main(int argc, char const *argv[])
{
	QUEUE *q = new QUEUE();
	
	q->push(5);
	q->push(2);
	q->push(6);
	q->push(1);

	//cout << s->top() << " ";
	q->pop();

	//cout << s->top() << " ";
	q->pop();

	//cout << s->top() << " ";
	cout << q->front();

	//cout << s->top() << " ";
	q->push(4);

	cout << "\n";
	return 0;
}