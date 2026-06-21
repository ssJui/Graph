#include <bits/stdc++.h>
 
using namespace std;
 
 
int main()
{
    int n,m; cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0; i<m; ++i)
    {
        int u,v; cin>>u>>v;
        // cout<<u<<' '<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[n+1]; 
    memset(visited,0,sizeof(visited));
    vector<int>node_from_components;
    for(int i=1; i<=n; ++i)
    {
        if(visited[i]==1) continue;
 
        queue<int>q; 
        q.push(i);
        visited[i] = 1;
        node_from_components.push_back(i);
        while(!q.empty())
        {
            int node = q.front();
            // cout<<node<<' ';
            q.pop();
            for(auto v:adj[node])
            {
                if(visited[v]==0)
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        // cout<<endl;
    }
 
    cout<<node_from_components.size()-1<<'\n';
 
    for(int i=1; i<(int)node_from_components.size(); ++i)
    {
        cout<<node_from_components[i-1]<<' '<<node_from_components[i]<<'\n';
    }
 
}
