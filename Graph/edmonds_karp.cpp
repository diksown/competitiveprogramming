#include <bits/stdc++.h>
using namespace std;
#define MAX 1003
#define INF 0x3f3f3f3f

int capacity[MAX][MAX];
vector<int> adj[MAX];

int bfs(int s, int t, vector<int>& parent){
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INF});
	while(!q.empty()){
		int v = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next: adj[v]){
			if (parent[next] == -1 and capacity[v][next]){
				parent[next] = v;
				int newflow = min(flow, capacity[v][next]);
				if (next == t) return newflow;
				q.push({next, newflow});
			}
		}
	}
	return 0;
}

int maxflow(int s, int t){
	int flow = 0, newflow;
	vector<int> parent(MAX);
	while(newflow = bfs(s, t, parent)){
		cout << newflow << endl;
		flow += newflow;
		int cur = t;
		while(cur != s){
			int p = parent[cur];
			capacity[p][cur] -= newflow;
			capacity[cur][p] += newflow;
			cur = p;
		}
	}
	return flow;
}

int main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i=0; i<m; i++){
		int u, v, cap;
		cin >> u >> v >> cap;
		capacity[u][v] = cap;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << maxflow(s, t) << endl;
}

/*

6 9 1 6
1 2 10
1 3 10
2 3 2
2 5 4
2 4 8
3 4 9
4 5 6
4 6 10
5 6 10
   
           4
    (2)-------(5)
    /| \       | \
 10/ |  \      |  \10
  /  |   \     |   \
(1)  |2   8   6|   (6)
  \  |     \   |   /
 10\ |      \  |  /10
    \|       \ | /
    (3)-------(4)
          9 

*/
