//Fenwick Tree. In the main, a program to calculate the number of inversions
//of an array. Query: O(logn). Update: O(logn).  Memory: O(n). 1-based.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 1e5+5;

ll fenwick[MAX];

ll query(int p){
	ll sum = 0;
	for (int i=p; i>0; i-=i&-i) sum+=fenwick[i];
	return sum;
}

ll query(int l, int r){
	return query(r) - query(l-1);
}

void update(int p, ll val){
	for (int i=p; i<MAX; i+=i&-i) fenwick[i]+=val;
}

int main(){
	int n; cin >> n;
	vector<ll> v(n);
	for (auto &x: v) cin >> x;
	int nInv = 0;
	for (int i=0; i<n; i++){
		update(v[i], 1);
		nInv+=query(v[i]+1, MAX-1);
	}
	cout << nInv << endl;
}
