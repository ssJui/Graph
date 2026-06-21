#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> path;
vector<bool> vis;
bool found;

bool dls(int u, int goal, int limit) {
    vis[u] = true;
    path.push_back(u);

    if (u == goal) return true;
    if (limit <= 0) {
        path.pop_back();
        vis[u] = false;
        return false;
    }

    for (int v : g[u]) {
        if (!vis[v]) {
            if (dls(v, goal, limit - 1)) return true;
        }
    }

    path.pop_back();
    vis[u] = false;
    return false;
}

void ids(int n, int start, int goal) {
    for (int depth = 0; depth <= n; depth++) {
        vis.assign(n, false);
        path.clear();

        if (dls(start, goal, depth)) {
            cout << "\nfound at depth " << depth << endl;
            cout << "path: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
            return;
        }
    }
    cout << "\nno path found\n";
}

int main() {
    int n, e;
    cout << "nodes: ";
    cin >> n;

    cout << "edges: ";
    cin >> e;

    g.resize(n);

    cout << "enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int s, t;
    cout << "start: ";
    cin >> s;
    cout << "goal: ";
    cin >> t;

    ids(n, s, t);

    return 0;
}
