#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> p; 

void ucs(int n, vector<vector<p>> &g, int s, int t) {
    priority_queue<p, vector<p>, greater<p>> pq; 
    vector<int> d(n, INT_MAX);
    vector<int> par(n, -1);

    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty()) {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == t) break;

        for (auto x : g[u]) {
            int v = x.first;
            int w = x.second;

            if (d[v] > c + w) {
                d[v] = c + w;
                par[v] = u;
                pq.push({d[v], v});
            }
        }
    }

    if (d[t] == INT_MAX) {
        cout << "no path found\n";
        return;
    }

    vector<int> path;
    for (int v = t; v != -1; v = par[v]) {
        path.push_back(v);
    }

    cout << "\nmin cost = " << d[t] << endl;
    cout << "path: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n, e;
    cout << "nodes: ";
    cin >> n;

    cout << "edges: ";
    cin >> e;

    vector<vector<p>> g(n);

    cout << "enter u v cost (0-based):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    int s, t;
    cout << "start: ";
    cin >> s;
    cout << "goal: ";
    cin >> t;

    ucs(n, g, s, t);
    return 0;
}
