#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 2e5+7;

struct segTree{
	ll tree[4*MAX];
	ll f(ll a, ll b){ // f = min, max, xor, sum...
		return a+b;
	}
	ll nul(){ //f(x, nul()) = x
		return 0;
	}
	void update(int v, int tl, int tr, int pos, ll amount){
		if (tl == tr){
			tree[v] = amount;
			return;
		}
		int tm = (tl + tr)/2;
		if (pos <= tm) update(2*v, tl, tm, pos, amount);
		else update(2*v+1, tm+1, tr, pos, amount);
		tree[v] = f(tree[2*v], tree[2*v+1]);
	}
	void update(int pos, ll amount){
		update(1, 0, MAX-1, pos, amount);
	}
	ll query(int v, int tl, int tr, int l, int r){
		if (r < tl   or  tr < l) return nul();
		if (l <= tl and tr <= r) return tree[v];
		int tm = (tl+tr)/2;
		return f(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
	}
	ll query(int l, int r){
		return query(1, 0, MAX-1, l, r);
	}
};

int main(){
	segTree a;
	for (int i=0; i<10; i++) a.update(i, 1<<i);
	cout << a.query(4, 5) << endl; // 2^4 + 2^5 = 48
	cout << a.query(0, 8) << endl; // 2^0 + 2^1 + ... + 2^8 = 2^9 - 1 = 511
	cout << a.query(0, 0) << endl; // 2^0 = 1
}
