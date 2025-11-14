#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> res;
vector<int> path;
vector<bool> visited;

void dfs(int u, int t, const vector<vector<int>>& adj) {
    visited[u] = true;
    path.push_back(u);
    if (u == t) {
        res.push_back(path);
    } else {
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, t, adj);
            }
        }
    }
    path.pop_back();
    visited[u] = false;
}

vector<vector<int>> getPath(int n, vector<vector<int>>& g, int s, int t) {
    res.clear();
    path.clear();
    visited.assign(n, false);
    vector<vector<int>> adj(n);
    for (auto& edge : g) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto& list : adj) {
        sort(list.begin(), list.end());
    }
    dfs(s, t, adj);
    return res;
}

int main() {
    int n = 4;
    vector<vector<int>> g = {{0,1},{0,2},{1,2},{1,3},{3,2}};
    int s = 0, t = 2;
    vector<vector<int>> paths = getPath(n, g, s, t);
    for (auto& p : paths) {
        cout << "{";
        for (size_t i = 0; i < p.size(); ++i) {
            if (i) cout << ", ";
            cout << p[i];
        }
        cout << "}\n";
    }
    return 0;
}