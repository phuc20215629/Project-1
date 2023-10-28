#include <bits/stdc++.h> 
using namespace std; 

// DSU data structure 
// path compression + rank by union 
class DSU { 
	vector<vector<int>> dsu;

public: 
	DSU(int n) 
	{ 
		dsu.resize(n + 1, vector<int>(2, 0));

		for (int i = 1; i <= n; i++) { 
			dsu[i][0] = -1; 
			dsu[i][1] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (dsu[i][0] == -1) 
			return i; 

		return dsu[i][0] = find(dsu[i][0]); 
	} 

	// Union function 
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

	// Function to add edge in a graph 
	void addEdge(int x, int y, int w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 

	void kruskalsMST() 
	{ 
		// Sort all edges 
		sort(edgelist.begin(), edgelist.end()); 

		// Initialize the DSU 
		DSU s(V); 
		int ans = 0; 
		// cout << "Following are the edges in the "
		// 		"constructed MST"
		// 	<< endl; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int u = edge[1]; 
			int v = edge[2]; 

			// Take this edge in MST if it does 
			// not form a cycle 
			if (s.find(u) != s.find(v)) { 
				s.unite(u, v); 
				ans += w; 
				// cout << u << " -- " << v << " == " << w 
				// 	<< endl; 
			} 
		} 
		cout << "Minimum Cost Spanning Tree: " << ans; 
	} 
}; 

// Driver code 
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

	// Function call 
	g.kruskalsMST(); 

	return 0; 
}