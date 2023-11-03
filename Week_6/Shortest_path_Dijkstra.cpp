/*
Description
Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
Input
Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
Line m+2: contains two integers s and t
Output
Write the weight of the shortest path found or write -1 if no path from s to t was found
Example
Input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

Output
97
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> d;
int n, m;

int Dijkstra(int s, int t) {
    // Initialize
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair : (w,v) sort by w ASC -> pair with the smalles w will be at the top
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > d[u]) {
            continue;  // Skip if a shorter path to u is already found
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    return d[t];
}

int main() {
    int s, t;
    cin >> n >> m;

    d.resize(n + 1, INT_MAX);
    adj.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> s >> t;
    cout << Dijkstra(s, t);

    return 0;
}