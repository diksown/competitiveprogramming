#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[MAX];

vector<int> dij(int k){
	vector<bool> visited(MAX, false);
	vector<int> dist(MAX, INF);
	dist[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, k});
	while(!pq.empty()){
		int x = pq.top().second; pq.pop();
		if (visited[x]) continue;
		visited[x] = 1;
		for (auto p: adj[x]){
			int v = p.first, d = p.second;
			if (dist[v] > dist[x] + d){
				dist[v] = dist[x] + d;
				pq.push({-dist[v], v});
			}
		}
	}
	return dist;
}

int main(){
	int n, m; 
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}
	int source = 3;
	vector<int> dists = dij(source);
	for (int i=1; i<=n; i++) 
		printf("distance from vertex %d to vertex %d is %d.\n", source, i, dists[i]);
}

	/*              1       10
	 5 5       (1) ----(5)-----(3)
	 1 5 1      |       |
	 1 2 7     7|       |47
	 2 4 12     |       |
	 2 5 47    (2)-----(4)
	 3 5 10         12
	*/
