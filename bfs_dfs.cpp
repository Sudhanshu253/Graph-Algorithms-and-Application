#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj, visited);
}

void bfs(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }

    cout << "DFS from node 0: ";
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
    cout << "\n";

    cout << "BFS from node 0: ";
    bfs(0, adj);
    cout << "\n";
    return 0;
}
