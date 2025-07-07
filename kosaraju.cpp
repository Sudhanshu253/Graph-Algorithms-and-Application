#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &order) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs1(v, adj, visited, order);
    order.push(u);
}

void dfs2(int u, vector<vector<int>> &rev, vector<bool> &visited, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : rev[u])
        if (!visited[v]) dfs2(v, rev, visited, component);
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges:\n";
    cin >> n >> m;

    vector<vector<int>> adj(n), rev(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    stack<int> order;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i)
        if (!visited[i]) dfs1(i, adj, visited, order);

    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, rev, visited, component);
            for (int x : component)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
