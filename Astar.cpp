#include <bits/stdc++.h>
using namespace std;

struct Node {
    int vertex;
    int g; 
    int f; 

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

vector<int> AStar(int n,
                  vector<vector<pair<int,int>>>& adj,
                  vector<int>& heuristic,
                  int source,
                  int goal)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<int> gCost(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    gCost[source] = 0;

    pq.push({source, 0, heuristic[source]});

    while(!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;

        if(u == goal)
            break;

        for(auto edge : adj[u])
        {
            int v = edge.first;
            int cost = edge.second;

            int newG = gCost[u] + cost;

            if(newG < gCost[v])
            {
                gCost[v] = newG;
                parent[v] = u;

                int newF = newG + heuristic[v];

                pq.push({v, newG, newF});
            }
        }
    }

    vector<int> path;

    if(gCost[goal] == INT_MAX)
        return path;

    for(int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest Cost = " << gCost[goal] << endl;

    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    vector<int> heuristic(n + 1);

    cout << "Enter heuristic values:\n";

    for(int i = 1; i <= n; i++)
        cin >> heuristic[i];

    int source, goal;
    cin >> source >> goal;

    vector<int> path = AStar(n, adj, heuristic, source, goal);

    if(path.empty())
    {
        cout << "No Path Found\n";
    }
    else
    {
        cout << "Path: ";
        for(int node : path)
            cout << node << " ";

        cout << endl;
    }

    return 0;
}