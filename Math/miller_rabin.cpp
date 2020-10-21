#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){
	return uniform_int_distribution<ll>(a, b)(rng);
}

ll mod_mul(ll a, ll b, ll mod){ 
	//return (a*b)%mod; 
	ll cur_mod = a;
	ll ans = 0;
	for (int i=0; i<63; i++){
		if ((b>>i)&1) ans = (ans + cur_mod)%mod;
		cur_mod = (2*cur_mod) % mod;
	}
	return ans;
}

ll fexp(ll a, ll e, ll mod){
	if (e == 0) return 1;
	ll p = fexp(a, e/2, mod);
	p = mod_mul(p, p, mod);
	if (e%2 == 1) 
		p = mod_mul(p, a, mod);
	return p;
}

//Miller-Rabin. Checks if p is strongly pseudoprime on base a.
//Complexity: O(log(p)) without modmul, O(log²(p)) with modmul.
bool miller_rabin (ll p, ll a){

	ll q = p-1, k=0;
	while(q % 2 == 0){
		q /= 2;
		k++;
	}

	ll cur = fexp(a, q, p);
	if (cur == 1 or cur == p-1) return true;

	for (int i=0; i<k; i++){
		if (cur == p-1) return true;
		if (cur == 1) return false;
		cur = mod_mul(cur, cur, p);
	}

	return false;
}

//Checks Miller-Rabin for k bases.
//k = 40 is a good start.
bool is_probably_prime(ll p, int k){
	if (p == 0 or p == 1) return false;
	if (p == 2 or p == 3) return true;
	if (p%2 == 0) return false;

	for (int i=0; i<k; i++) {
		if (!miller_rabin(p, rnd(1, p-1))) return false;
	}

	return true;
}

//Only for checking
bool is_prime(ll p){
	if (p == 0 or p == 1) return false;
	if (p == 2 or p == 3) return true;
	for (ll i=2; i*i<=p; i++) if (p%i==0) return false;
	return true;
}

int main(){
	int t = 0;
	while(1){
		ll p = rnd(0, 1e18);
		cout << "testing for p = " << p << endl;
		assert(is_probably_prime(p, 40) == is_prime(p));
		cout << "(tested " << ++t << " numbers)" << endl;
	}
}
