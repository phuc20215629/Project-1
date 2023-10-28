/*
Description
Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v) ∈ E has weight w(u,v). Compute minimum spanning tree of G.
Input
Line 1: N and M (1≤N,M≤10^5) in which N is the number of nodes and M is the number of edges.
Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
Output
Write the weight of the minimum spanning tree found.
Example
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7
*/

#include <bits/stdc++.h> 
using namespace std; 

class DSU { 
	vector<vector<int>> dsu;

public: 
	DSU(int n) 
	{ 
		dsu.resize(n + 1, vector<int>(2, 0));

		for (int i = 1; i <= n; i++) { 
			dsu[i][0] = -1;     //parent[i]
			dsu[i][1] = 1;      //rank[i]
		} 
	} 
 
	int find(int i) 
	{ 
		if (dsu[i][0] == -1) 
			return i; 

		return dsu[i][0] = find(dsu[i][0]); 
	} 
 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (dsu[s1][1] < dsu[s2][1]) { 
				dsu[s1][0] = s2; 
			} 
			else if (dsu[s1][1] > dsu[s2][1]) { 
				dsu[s2][0] = s1; 
			} 
			else { 
				dsu[s2][0] = s1; 
				dsu[s1][1]++; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<int>> edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 
 
	void addEdge(int x, int y, int w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 

	void kruskalsMST() 
	{ 
 
		sort(edgelist.begin(), edgelist.end()); 

		DSU s(V); 
		int ans = 0; 
 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int u = edge[1]; 
			int v = edge[2]; 

			if (s.find(u) != s.find(v)) { 
				s.unite(u, v); 
				ans += w; 
			} 
		} 
		cout << ans; 
	} 
}; 


int main() 
{ 
	int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
		cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

	g.kruskalsMST(); 

	return 0; 
}