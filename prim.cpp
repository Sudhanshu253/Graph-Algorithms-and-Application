#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int primMST(int n, vector<vector<pii>> &adj) {
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});  // {weight, node}
    int total_cost = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total_cost += weight;
        for (auto &[v, w] : adj[u]) {
            if (!inMST[v]) pq.push({w, v});
        }
    }

    return total_cost;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges:\n";
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "MST Total Cost: " << primMST(n, adj) << endl;
    return 0;
}
