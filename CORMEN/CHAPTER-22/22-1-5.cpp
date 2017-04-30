// This is very unorganised but I will arrange it later.

#include <bits/stdc++.h>
void get_square(int v[10][10])
{
	int new_v[10][10] = {0};
	
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			new_v[i][j] = v[i][j];

	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(v[i][j] != 0)
			{
				for(int k=0; k<10; k++)
				{
					if(v[j][k] != 0)
						new_v[i][k] = 1;
				}
			}
		}
	}

	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
			printf("%d ",new_v[i][j]);
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	// Same graph in 22.1-1

	int v[10][10] = {	{0, 1, 0, 0, 0, 0},
						{0, 0, 1, 1, 0, 0},
						{0, 0, 0, 0, 0, 1},
						{0, 0, 1, 0, 0, 0},
						{1, 0, 0, 0, 0, 1},
						{0, 0, 0, 0, 0, 0}
					};


	get_square(v);
	return 0;
}