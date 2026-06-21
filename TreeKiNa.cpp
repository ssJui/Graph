//with adj list and weight
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //dekhte hbe edge er sonkha vertex er theke 1 kom kina, taile tree
    if(m != n-1){
        cout << it is not a tree << endl;
        return 0;
    }

    int visited[n+1];
    int level[n+1];
    queue<int> q;
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
        level[i] = 0;
    }
    q.push(1); //source change kore o kora jabe
    visited[1] = 1;
    level[1] = 1;

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        for(auto u: adj[node]){
            if(!visited[u]){
            visited[u] = 1;
            level[u] = level[node]+1;
            q.push(u);
           }
        }
        q.pop();
    }
    cout<<endl;
    //dekhete hobe sob gula vertex connected kina, taile tree
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(visited[i] = 0){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << it is not a tree << endl;
    }else{
        cout << it is a tree << endl;
    }
}