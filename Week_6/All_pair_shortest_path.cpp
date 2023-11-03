/*
Description
Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). 
Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
Input
Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
Output
Line i (i = 1, 2, ..., n): write the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
Example
Input
4 9 
1 2 9 
1 3 7 
1 4 2 
2 1 1 
2 4 5 
3 4 6 
3 2 2 
4 1 5 
4 2 8
Output
0 9 7 2  
1 0 8 3  
3 2 0 5  
5 8 12 0
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;

int n, m;

int Dijkstra(int s, int t) {
    vector<int> d;
    d.resize(n + 1, INT_MAX);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(dist > d[u]) continue;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d[t];
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i == j) cout << 0 << " ";
            else cout << Dijkstra(i, j) << " ";
        }
        cout << endl;
    }
}