/*
Description
Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)

Input
Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge

Output
Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
Example

Input
6 7
2 4
1 3
3 4
5 6
1 2
3 5
2 3

Output
1 2 3 4 5 6
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        cout << p << " ";
        
        for(int u : adj[p]) {
            if(!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

void lexicographicOrder(int n) {
    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    visited.resize(n + 1, false);
    adj.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    lexicographicOrder(adj.size());

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) BFS(i);
    }
    
    return 0;
}
