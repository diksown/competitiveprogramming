#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 

struct dsu {
	vector<int> f;
	dsu(int n){
		f.resize(n+1);
		iota(f.begin(), f.end(), 0);
	}
	int find(int a){
		return (a == f[a] ? a : f[a] = find(f[a]));
	}
	bool same(int a, int b){
		return find(a) == find(b);
	}
	void link(int a, int b){
		f[find(b)] = find(a);
	}
};

int main(){
	dsu p(3);
	cout << (int) p.same(1, 2) << endl; // 0 
	p.link(1, 2);
	cout << (int) p.same(1, 2) << endl; // 1
}
