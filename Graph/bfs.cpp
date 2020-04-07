#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 1e5+3;
int distances[MAX];
int visited[MAX];
vector<int> edges[MAX];

void bfs(int k){
	distances[k] = 0;
	visited[k] = 1;
	queue<int> q;
	q.push(k);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: edges[v]){
			if (!visited[x]){
				visited[x] = 1;
				q.push(x);
				distances[x] = distances[v]+1;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int source = 1;
	bfs(source);
	for (int i=1; i<=n; i++) 
			printf("distance from vertex %d to vertex %d is %d.\n", source, i, distances[i]);
}

	/*                    
	 5 5       (1) ----(5)-----(3)
	 1 5        |       |
	 1 2        |       |
	 2 4        |       |
	 4 5       (2)-----(4)
	 3 5            
	*/
