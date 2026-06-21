#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> path;
vector<bool> vis;
bool found = false;

void dls(int u, int goal, int limit) {
    if (limit < 0 || found) return;

    vis[u] = true;
    path.push_back(u);

    if (u == goal) {
        found = true;
        return;
    }

    if (limit > 0) {
        for (int v : g[u]) {
            if (!vis[v]) {
                dls(v, goal, limit - 1);
            }
        }
    }

    if (!found) path.pop_back(); 
    vis[u] = false; 
}

int main() {
    int n, e;
    cout << "nodes: ";
    cin >> n;

    cout << "edges: ";
    cin >> e;

    g.resize(n);
    vis.resize(n, false);

    cout << "enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int s, t, limit;
    cout << "start: ";
    cin >> s;
    cout << "goal: ";
    cin >> t;
    cout << "depth limit: ";
    cin >> limit;

    dls(s, t, limit);

    if (found) {
        cout << "\npath found within depth " << limit << ":\n";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "\nno path found within depth limit\n";
    }

    return 0;
}
