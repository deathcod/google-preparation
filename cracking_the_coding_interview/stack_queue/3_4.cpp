#include <bits/stdc++.h>
using namespace std;

void function(int n, char start, char aux, char end)
{
	if(n==0)
		return;
	function(n-1, start, end, aux);
	printf("%c %c\n", start, end);
	function(n-1, aux, start, end);
}

int main(int argc, char const *argv[])
{
	function(5, 'A', 'B', 'C');
	return 0;
}

//Khan Achademy tutorial actually helped me to visualize the concept.