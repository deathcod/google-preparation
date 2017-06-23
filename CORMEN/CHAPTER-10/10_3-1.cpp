#include <bits/stdc++.h>
#ifndef NIL
#define NIL -2
#endif
using namespace std;
/*
Representing 
Doouble Linked list on a multidimensional array
*/

class DLL_MDA
{
	int *next, *prev, *key;
	int parent;
	int size;
public:
	DLL_MDA(int N)
	{
		size = N+1;
		next = (int *)malloc(size * sizeof(int));
		key = (int *)malloc(size * sizeof(int));
		prev = (int *)malloc(size * sizeof(int));
		for (int i = 1; i <= size; ++i)
		{
			next[i] = -1;
		}
		parent = -1;
	};
	~DLL_MDA()
	{
		free(next);
		free(key);
		free(prev);
	};
	bool insert(int value);
	bool del(int value);
	void display();
};

bool DLL_MDA :: insert(int value)
{
	int index_insert = -1;
	for (int i = 1; i <= size; ++i)
	{
		if(next[i] == -1)
		{
			index_insert = i;
			break;
		}
	}
	if(index_insert == -1)
		return false;
	if(parent == -1)
	{
		parent = index_insert;
		prev[parent] = NIL;
		next[parent] = NIL;
		key[parent] = value;
	}
	else
	{
		int temp = next[parent];
		next[parent] = index_insert;
		next[index_insert] = temp;
		prev[index_insert] = parent;
		parent = index_insert;
		key[parent] = value;
	}
}

void DLL_MDA :: display()
{
	//print next
	for (int i = 1; i <= size; ++i)
		cout << next[i] << "\t";
	cout << "\n";

	//print key
	for (int i = 1; i <= size; ++i)
		cout << key[i] << "\t";
	cout << "\n";

	//print previous
	for (int i = 1; i <= size; ++i)
		cout << prev[i] << "\t";
	cout << "\n";
	cout << "++++++++++++++++++++++++++++++\n";

}
bool DLL_MDA :: del(int value)
{
	int temp = parent;
	if(parent == -1)
	{
		cout << "the array is empty";
		exit(0);
	}
	while(temp != NIL and key[temp] != value)
	{
		temp = prev[temp];
	}
	if(temp == NIL) return false;
	if(temp == parent) parent = prev[temp];
	if(parent == NIL) parent = -1;

	if(prev[temp] != NIL)
		next[prev[temp]] = next[temp];

	if(next[temp] != NIL)
		prev[next[temp]] = prev[temp];

	next[temp] = -1;

	return true;
}
int main(int argc, char const *argv[])
{
	DLL_MDA *x = new DLL_MDA(7);
	x->insert(9);
	x->insert(16);
	x->insert(4);
	x->insert(1);

	x->display();
	cout << x->del(16) << "\n";

	x->display();
	cout << x->del(16) << "\n";
	return 0;
}