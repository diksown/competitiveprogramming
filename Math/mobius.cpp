#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(sqrt(n))
// gcd(a, b) = 1 -> µ(a)*µ(b) = µ(a*b)
int mobius(ll n) {
	int counter = 0;
	for (ll i = 2; i*i <= n; i++) {
		if (n%i==0) {
			if (n%(i*i) == 0) return 0;
			counter++;
			n/=i;
		}
	}
	if (n > 1) counter++;
	if (counter%2 == 0) return 1;
	else return -1;
}

int main(){
	ll n;
	cin >> n;
	cout << mobius(n) << endl;
}
