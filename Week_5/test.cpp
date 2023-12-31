#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> d;
int n, m;

int Dijkstra(int s, int t) {
    // Initialize
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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