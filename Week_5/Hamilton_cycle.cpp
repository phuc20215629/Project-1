/*
Description
Given an undirected graph G = (V,E). Write a program to check if G is a Hamiltonian graph.
Input
Line 1: a positive integer T (number of graphs)
Subsequent lines are information about T graphs, each has the following format:
Line 1: n and m (number of nodes and edges)
Line i+1 (i = 1, 2, ..., m): u and v : two end points of the ith edge
Output
In the i
th
 line, write 1 if the corresponding is a Hamiltonian graph, and write 0, otherwise
Example
Input
2
5 5
1 2
1 3
2 4
2 5
3 5
7 13
1 3
1 5
1 7
2 4
2 5
2 6
3 4
3 5 
3 7
4 6
4 7
5 7
6 7

Output
0
1
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cur;
vector<int> res;
vector<bool> visited;

int HamiltonCycle(int k, int v) {
    if (k == v + 1) {
        if (adj[cur[k - 1]][1]) {
            return 1;
        }
        return 0;
    }

    for (int y = 1; y <= v; y++) {
        if (!visited[y] && adj[cur[k - 1]][y]) {
            cur[k] = y;
            visited[y] = true;
            if (HamiltonCycle(k + 1, v) == 1) {
                return 1;
            }
            visited[y] = false;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int v, e;
        cin >> v >> e;

        adj.assign(v + 1, vector<int>(v + 1, 0));
        cur.resize(v + 1);
        visited.assign(v + 1, false);

        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }

        cur[1] = 1;
        visited[1] = true;
        res.push_back(HamiltonCycle(2, v));
        --T;
    }

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}