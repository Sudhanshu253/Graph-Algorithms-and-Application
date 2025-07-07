#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

string rotate_left(const string &s) {
    return s.substr(1) + s[0];
}

string rotate_right(const string &s) {
    return s.back() + s.substr(0, s.size() - 1);
}

vector<string> neighbors(const string &state) {
    return { rotate_left(state), rotate_right(state) };
}

vector<string> bfs(string start, string target) {
    unordered_set<string> visited;
    queue<pair<string, vector<string>>> q;
    q.push({start, {}});

    while (!q.empty()) {
        auto [curr, path] = q.front(); q.pop();
        if (curr == target) return path;
        if (visited.count(curr)) continue;
        visited.insert(curr);
        for (string next : neighbors(curr)) {
            auto new_path = path;
            new_path.push_back(next);
            q.push({next, new_path});
        }
    }
    return {};
}

int main() {
    string start = "ABCDEF";
    string goal = "CDEFAB";

    auto path = bfs(start, goal);
    cout << "Steps to solve:\n";
    for (auto &s : path)
        cout << s << "\n";

    return 0;
}
