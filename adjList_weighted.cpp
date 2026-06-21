#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Standard adjacency list
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << i << " -> { ";
        for(auto [j, w] : adj[i])
        {
            cout << "{" << j << ", " << w << "} ";
        }
        cout << "}" << endl;
    }
}
