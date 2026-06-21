#include<bits/stdc++.h>
using namespace std;

const long long N = 3e5 + 5;
const long long inf = 1e9;
vector<pair<int, int>> adj[N];
int dist[N];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <=m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v}); //for directed graph
	}
	int source = 1;
	for(int i = 1; i <= n; i++){
		dist[i] = inf;
	}
	dist[source] = 0;
	set<pair<int, int>> st;
	for(int i = 1; i <= n; i++){
		st.insert({dist[i], i});
	}
	while(st.size()){
		pair<int, int> p = *st.begin();
		st.erase(p);
		int d = p.first;
		int cur_node = p.second;
		for(pair<int, int> pp : adj[cur_node]){
			int nxt_node = pp.second;
			int edge_w = pp.first;
			if(d + edge_w < dist[nxt_node]){
				//st.erase({dist[nxt_node], nxt_node});
				dist[nxt_node] = d + edge_w;
				st.insert({dist[nxt_node], nxt_node});
			}
		}
	}
	for(int i = 1; i <=n; i++){
		cout << dist[i] << " " ;
	}
}