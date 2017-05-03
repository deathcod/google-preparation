#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2


class graph_traversal
{
public:
	graph_traversal(){};
	~graph_traversal();
	
	void bfs(int source, std::vector<int> G[8], int n);
	void bfs_CORMEN(int source, std::vector<int> G[8], int n);
	void dfs(int source, std::vector<int> G[8], int n);
	void dfs_CORMEN(std::vector<int> G[8], int n);
	void dfs_traverse_CORMEN(int vertex, int *colour, int *parent, int *d, int *f, int time, std::vector<int> G[8], int n);
	void dfs_traverse(int vertex, int *visited, std::vector<int> G[8]);
	void dfs_using_stack(int source, std::vector<int> G[8], int n);	
};



// This is the implementation I use in competitive programming
void graph_traversal :: bfs(int source, std::vector<int> G[8], int n)
{
	int visited[n+1] = {0};
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while(!q.empty())
	{
		int f = q.front();
		cout << f << "\n";
		q.pop();
		for(int i=0; i<G[f].size() ;i++)
		{
			if(visited[G[f][i]] == 0)
			{
				visited[G[f][i]] = 1;
				q.push(G[f][i]);
			}
		}
	}
}

// This the implementation of bfs as givrn in CORMEN.
void graph_traversal :: bfs_CORMEN(int source, std::vector<int> G[8],int n)
{
	int colour[n+1] = {WHITE};
	int f[n+1] = {0};
	int d[n+1] = {0};
	int parent[n+1] = {0};
	queue<int> q;

	q.push(source);
	colour[source] = GRAY;
	d[source] = 0;
	parent[source] = 0;

	while(!q.empty())
	{
		int u = q.front();
		cout << u << "\n";
		q.pop();
		for (int v = 0; v < G[u].size(); ++v)
		{
			if(colour[G[u][v]] == WHITE)
			{
				colour[G[u][v]] = GRAY;
				d[G[u][v]] = d[G[u][v]] + 1;
				parent[G[u][v]] = u;
				q.push(G[u][v]);
			}
		}
		colour[u] = BLACK;
	}
}

void graph_traversal :: dfs_CORMEN(std::vector<int> G[8],int n)
{
	int colour[n] = {WHITE};
	int parent[n] = {0};
	int time = 0;
	int d[n] = {0};
	int f[n] = {0};
	for (int i = 1; i <=n; ++i)
	{
		if(colour[i] == WHITE)
			dfs_traverse_CORMEN(i, colour, parent, d ,f ,time ,G, n);	
	}
}

void graph_traversal :: dfs_traverse_CORMEN(int vertex, int *colour, int *parent, int *d, int *f, int time, std::vector<int> G[8], int n)
{
	cout << vertex << "\n";
	colour[vertex] = GRAY;
	time = time +1;
	d[vertex] = time;
	for (int v = 0; v < G[vertex].size(); ++v)
	{
		if(colour[G[vertex][v]] == WHITE)
		{
			parent[G[vertex][v]] = vertex;
			dfs_traverse_CORMEN(G[vertex][v], colour, parent,d ,f ,time ,G ,n );
		}
	}
	colour[vertex] = BLACK;
	f[vertex] = time = time +1;
}

void graph_traversal :: dfs_traverse(int vertex, int *visited,std::vector<int> G[8])
{	
	visited[vertex] = 1;
	cout << vertex <<"\n";
	for (int i = 0; i < G[vertex].size(); ++i)
	{
		if(visited[G[vertex][i]] == 0)
			dfs_traverse(G[vertex][i], visited, G);
	} 
}

void graph_traversal :: dfs(int source, std::vector<int> G[8], int n)
{
	int visited[n+1] = {0};
	dfs_traverse(source, visited, G);
}

void graph_traversal :: dfs_using_stack(int source, std::vector<int> G[8], int n)
{
	stack<int> st;
	int time = -1;
	st.push(source);
	int colour[n] = {WHITE};
	int f[n] = {0};
	int d[n] = {0};
	while(!st.empty())
	{
		int temp = st.top();
		cout << temp << "\n";

		if(colour[temp] == GRAY)
		{
			time += 1;
			colour[temp] = BLACK;
			f[temp] = time;
			st.pop();
		}
		else
		{
			time += 1;
			colour[temp] = GRAY;
			d[temp] = time;
			for(int i=0; i<G[temp].size(); i++)
				if(colour[G[temp][i]] == WHITE)
					st.push(G[temp][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> G[7+1];
	G[1].push_back(2);
	G[1].push_back(5);
	G[1].push_back(4);

	G[2].push_back(3);
	G[2].push_back(4);

	G[3].push_back(5);
	G[3].push_back(6);

	G[5].push_back(7);

	G[6].push_back(7);

	graph_traversal *x = new graph_traversal();

	cout << "BFS\n";
	x->bfs(1, G, 7);

	cout << "DFS\n";
	x->dfs(1, G, 7);

	cout << "DFS USING STACK\n";
	x->dfs_using_stack(1, G, 7);

	cout << "BFS CORMEN\n";
	x->bfs_CORMEN(1, G, 7);

	cout << "DFS CORMEN\n";
	x->dfs_CORMEN(G, 7);
	return 0;
}