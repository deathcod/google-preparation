#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int flag;
	int value;
public:
	node()
	{
		flag = -1;
		value = 0;
	};
	~node();
};

class Stack
{
public:
	node a[100];
	int first;
	int second;
	int third;
	int N;
public:
	Stack(int n)
	{
		N=n;
		first = -1;
		second = -1;
		third = -1;
	};
	~Stack();
	bool insert(int *stack, int value);
	int top(int stack);
	bool pop(int *stack);
	
};

bool Stack :: insert(int *stack, int value)
{
	for (int i = 0; i < N; ++i)
	{
		if(a[i].flag == -1)
		{
			if(*stack == -1)
			{
				*stack  = i;
				a[i].flag = -5;
				a[i].value = value;
				return true;
			}
			else
			{
				a[i].flag = *stack;
				a[i].value = value;
				*stack = i;
				return true;
			}
		}
	}
	return false;
}

int Stack :: top(int stack)
{
	assert(stack != -1);
	return a[stack].value;
}

bool Stack :: pop(int *stack)
{
	if(*stack == -1)
		return false;

	int f = a[*stack].flag;
	a[*stack].flag = -1;
	a[*stack].flag = 0;
	*stack = f;

	if(*stack == -5)
		*stack = -1;
	return true;
}
int main(int argc, char const *argv[])
{
	Stack *s = new Stack(6);
	s->insert(&s->first, 12);
	s->insert(&s->first, 3);
	s->insert(&s->second, 9);

	cout << s->top(s->first) << " ";
	cout << s->top(s->second) << " ";

	s->pop(&s->first);
	cout << s->top(s->first) << " ";

	s->pop(&s->first);
	cout << s->top(s->first) << " ";

	cout << "\n";
	return 0;
}