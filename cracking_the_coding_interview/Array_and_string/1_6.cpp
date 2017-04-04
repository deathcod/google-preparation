#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[100][100] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	int *w, *x, *y, *z;
	for (int i = 0; i < n/2 ; ++i)
	{
		for (int j = i; j < n-i-1; ++j)
		{
			w = &a[i][j];
			x = &a[n-j-1][i];
			y = &a[n-i-1][n-j-1];
			z = &a[j][n-i-1];

			int f = *z;
			*z = *y;
			*y = *x;
			*x = *w;
			*w = f;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout <<  a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
input
======
4
1 0 0 0 
0 1 1 0
0 0 1 1
1 0 0 0

Output
=========
0 0 1 0 
0 1 1 0 
0 1 0 0 
1 0 0 1 


Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

*/