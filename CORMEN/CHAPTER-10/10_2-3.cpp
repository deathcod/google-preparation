#include <bits/stdc++.h>
using namespace std;
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

class QUEUE
{
	node *in;
	node *out;
public:
	QUEUE()
	{
		in = NULL;
		out = NULL;
	};
	~QUEUE();
	void Enqueue(int value);
	bool Dequeue();
};

void QUEUE :: Enqueue(int value)
{
	if( in == NULL)
		in = out = new node(value);
	else
	{
		node *x = new node(value);
		in->set_next(x);
		in = x;
	}
}

bool QUEUE :: Dequeue()
{
	if(out == NULL)
		return false;
	else
	{
		node *x =out;
		out = out->get_next();
		free(out);
		return true;
	}
}

int main(int argc, char const *argv[])
{
	QUEUE *x = new QUEUE();

	x->Enqueue(10);
	x->Enqueue(23);
	x->Enqueue(34);

	cout << x->Dequeue()<< "\n";
	cout << x->Dequeue()<< "\n";
	cout << x->Dequeue()<< "\n";
	cout << x->Dequeue()<< "\n";
	return 0;
}