#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    // For a strict tree, m will always be exactly n - 1
    cin >> n >> m;

    // Standard C++ way to create an adjacency list of size n+1
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Standard C++ way to initialize arrays with 0
    vector<int> visited(n + 1, 0);
    vector<int> level(n + 1, 0);
    
    queue<int> q;
    
    // Setup the source node
    q.push(1); 
    visited[1] = 1;
    level[1] = 1; // Level 1 is the root

    while (!q.empty()) {
        int node = q.front();
        q.pop(); // Popped immediately

        cout << "Node " << node << " is at level " << level[node] << "\n";

        for (auto u : adj[node]) {
            if (!visited[u]) {
                visited[u] = 1;
                level[u] = level[node] + 1;
                q.push(u);
            }
        }
    }
    cout << endl;
    
    return 0;
}