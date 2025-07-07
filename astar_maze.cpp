#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int heuristic(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector<pii> astar(vector<vector<int>> &maze, pii start, pii goal) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<int>> g(rows, vector<int>(cols, 1e9));
    vector<vector<pii>> parent(rows, vector<pii>(cols, {-1, -1}));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    pq.push({0, start});
    g[start.first][start.second] = 0;

    int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

    while (!pq.empty()) {
        auto [cost, curr] = pq.top(); pq.pop();
        int r = curr.first, c = curr.second;
        if (curr == goal) break;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && maze[nr][nc] == 0) {
                int new_g = g[r][c] + 1;
                if (new_g < g[nr][nc]) {
                    g[nr][nc] = new_g;
                    parent[nr][nc] = {r, c};
                    pq.push({new_g + heuristic({nr, nc}, goal), {nr, nc}});
                }
            }
        }
    }

    // reconstruct path
    vector<pii> path;
    for (pii at = goal; at != pii{-1,-1}; at = parent[at.first][at.second])
        path.push_back(at);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };

    pii start = {0, 0}, end = {2, 3};
    vector<pii> path = astar(maze, start, end);

    cout << "Path:\n";
    for (auto [r, c] : path)
        cout << "(" << r << "," << c << ") ";
    cout << "\n";

    return 0;
}
