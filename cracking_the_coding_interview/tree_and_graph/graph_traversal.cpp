#include <bits/stdc++.h>
using namespace std;

class graph_traversal
{
public:
	graph_traversal();
	~graph_traversal();
	
	void bfs(int source, int n);
	void dfs();
	void dfs_traverse();
	void dfs_on_stack();	
};

void graph_traversal :: bfs(int source, std::vector< std::vector<int> > G, int n)
{
	int visited[n] = {0};
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while(!q.empty())
	{
		int f = q.front();
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

void graph_traversal :: dfs_traverse(int vertex, int *visited,std::vector< std::vector<int> > G)
{	
	visited[vertex] = 1;
	for (int i = 0; i < G[vertex].size(); ++i)
	{
		if(visited[G[vertex][i]] == 0)
			dfs_traverse(G[vertex][i], visited, G);
	} 
}

void graph_traversal :: dfs(int source, std::vector< std::vector<int> > G, int n);
{
	int visited[n] = {0};
	dfs_traverse(source, visited, G);
}

void graph_traversal :: dfs_using_stack(int source, std::vector< std::vector<int> > G, int n)
{
	stack<int> st;
	int time = -1;
	st.push(source);
	int colour[n] = {0};
	int f[n] = {0};
	int d[n] = {0};
	while(!q.empty())
	{
		int temp = st.top();
		if(colour[temp] == 0)
			st.pop();

		else if(colour[temp] == 1)
		{
			time += 1;
			colour[temp] =1;
			f[temp] = time;
			st.pop();
		}
		else
		{
			time += 1;
			colour[temp] = 1;
			d[temp] = time;
			for(int i=0; i<temp.size(); i++)
				if(colour[v[temp][i]] == 0)
					st.push(v[temp][i]);
		}
	}
}