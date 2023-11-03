/*
Description
Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. 
c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10^4, 1 <= M <= 10^6)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of ith arc
Output
Write the value of the max-flow found
Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
vector<vector<int>> rG;
vector<int> parent;

bool BFS(int s, int t) {
    vector<bool> visited;
    visited.resize(n + 1, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 1; v <= n; v++) {
            if(!visited[v] && rG[u][v] > 0) {
                if(v == t) {
                    parent[t] = u;
                    return true;
                }

                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

    return false;
}

int Ford_Fulkerson(int s, int t) {
    int max_flow = 0;
    int u, v;

    while(BFS(s, t)) {
        int path_flow = INT_MAX;
        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rG[u][v]);
        }

        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            rG[u][v] -= path_flow;
            rG[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int s, t;
    cin >> n >> m;   
    cin >> s >> t;

    parent.resize(n + 1);
    G.resize(n + 1, vector<int>(n + 1));
    rG.resize(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
        rG[u][v] = w;
    }

    
    cout << Ford_Fulkerson(s, t);
    return 0;

}