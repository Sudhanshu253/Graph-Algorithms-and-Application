#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if(rx == ry) return false; 
        if(rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if(rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
        return true;
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges;
    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_weight = 0;
    vector<Edge> mst_edges;

    for(auto &e : edges) {
        if(dsu.unite(e.u, e.v)) {
            mst_weight += e.weight;
            mst_edges.push_back(e);
        }
    }

    cout << "MST Weight: " << mst_weight << "\n";
    cout << "MST Edges:\n";
    for(auto &e : mst_edges) {
        cout << e.u << " - " << e.v << " (Weight: " << e.weight << ")\n";
    }

    return 0;
}
