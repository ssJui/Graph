#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // Simpler 1D array of vectors
int depth[N];
int subtreeSize[N];

// Pass 'parent' to avoid going backward up the tree
void dfs(int node, int parent) {
    cout << node << " ";
    subtreeSize[node] = 1;
    for (auto u : adj[node]) {
        if (u != parent) { 
            depth[u] = depth[node] + 1; // Calculate depth before diving deeper
            dfs(u, node);               // The current 'node' becomes the 'parent' for the next step
            subtreeSize[node] += subtreeSize[u];
        }
    }
}

int main() {
    int n; 
    // In a tree, the number of edges is always strictly N - 1
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Assuming node 1 is the root
    depth[1] = 0;
    
    // Start DFS from node 1. We pass 0 as the parent since 1 has no parent.
    dfs(1, 0); 

    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << "depth:" << depth[i] << " " << "subtree size:" << subtreeSize[i] << "\n";
    }

    return 0;
}