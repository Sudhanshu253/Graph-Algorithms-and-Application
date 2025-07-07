#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<int> ids, low;
vector<bool> onStack;
stack<int> st;
int id = 0;

void dfs(int u, vector<vector<int>> &sccs) {
    ids[u] = low[u] = id++;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (ids[v] == -1) dfs(v, sccs);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }

    if (ids[u] == low[u]) {
        vector<int> scc;
        while (true) {
            int v = st.top(); st.pop();
            onStack[v] = false;
            scc.push_back(v);
            if (v == u) break;
        }
        sccs.push_back(scc);
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges:\n";
    cin >> n >> m;

    adj.assign(n, {});
    ids.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, false);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<int>> sccs;
    for (int i = 0; i < n; ++i)
        if (ids[i] == -1) dfs(i, sccs);

    cout << "SCCs:\n";
    for (auto &scc : sccs) {
        for (int x : scc) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
