#include <bits/stdc++.h>
using namespace std;
#ifndef NIL
#define NIL -2
#endif
class DLL_SDA
{
private:
	int *mem;
	int stack;
	int DLL;
	int size;
public:
	DLL_SDA(int N);
	~DLL_SDA();
	void insert(int value);
	void search(int value);
	void del(int value);
	bool isempty();
	bool isfull();
	void display();

private:
	int ALLOCATE_OBJECT(int index);
	void FREE_OBJECT(int index);
};

DLL_SDA :: DLL_SDA(int N)
{
	size = 3 * N;
	mem = (int *)malloc(size * sizeof(int));
	int current = 1;
	while(current + 3 <size)
	{
		mem[current] = current +3;
		current += 3;
	}
	mem[current] = NIL;
	stack = 1;
	DLL = -1;
}

int DLL_SDA :: ALLOCATE_OBJECT(int index)
{
	if(stack == NIL)
	{
		cout << "error :: out of memory\n";
		exit(0);
	}
	if(index == NIL or index == -1)
	{
		index = stack;
		stack = mem[stack];
		mem[index] = NIL;
		mem[index +2] = NIL;
		return index;
	}
	mem[index] = stack;
	int f = mem[stack];
	mem[stack] = NIL;
	mem[stack +2] = index;
	stack = f;
	return mem[index];
}

void DLL_SDA :: FREE_OBJECT(int index)
{
	mem[index] = stack;
	stack = index;
}

void DLL_SDA :: insert(int value)
{
	DLL = ALLOCATE_OBJECT(DLL);
	mem[DLL +1] = value;
}

void DLL_SDA :: search(int value)
{
	if(DLL == -1)
	{
		cout << "error :: no value\n";
		exit(0);
	}

	int temp = DLL;
	while(temp != NIL and mem[temp +1] == value) temp = mem[temp];
	if(temp == NIL)
		cout << "Search Found\n";
	else
		cout << "Search no found\n";
}


/*
Delete is created by keeping the user's interaction keeping in mind. 
[0] = mem[1]
[1] = mem[4]
[2] = mem[7]
*/
void DLL_SDA :: del(int index)
{
	if(DLL == NIL or DLL ==-1)
	{
		cout << "error :: no value\n";
		exit(0);
	}
	int temp = DLL;
	int count = 0;
	while(temp!=NIL and count < index)
	{
		temp = mem[temp +2];
		count += 1;
	}
	if (temp == NIL)
	{
		cout << "error :: no index found\n";
		exit(0);
	}
	if(temp == DLL)
		DLL = mem[DLL];
	if(mem[temp +2] != NIL)
		mem[mem[temp +2]] = mem[temp];

	if(mem[temp] != NIL)
		mem[mem[temp] +2] = mem[temp +2];

	FREE_OBJECT(temp);
}

bool DLL_SDA :: isempty()
{
	return (DLL == NIL or DLL == -1);
}

bool DLL_SDA :: isfull()
{
	return (stack == NIL);
}

void DLL_SDA :: display()
{
	cout << "\n__________________________\n";
	for (int i = 1; i <= size; ++i)
	{
		cout << mem[i] << " ";
	}
	cout << "\n__________________________\n";
}

int main(int argc, char const *argv[])
{
	DLL_SDA *x = new DLL_SDA(7);
	x->display();
	x->insert(9);
	x->insert(10);
	x->insert(11);

	x->display();

	x->del(1);

	x->display();
	x->search(11);
	x->search(10);

	x->insert(2);
	x->display();
	return 0;
}