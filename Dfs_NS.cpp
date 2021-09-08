#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}
int main(){
	int n,m;
	cin>>n>>m;
	Graph g;
	
	while(m--){
		int u,v;
		cin>>u>>v;
		g.addEdge(u, v);

	}
	g.DFS(1);
}