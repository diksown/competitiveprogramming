#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main(){
	int n; cin >> n;
	vector<int> dp;
	for (int i=0; i<n; i++){
		int x; cin >> x;
		auto it = lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end()) dp.pb(x);
		else *it = x;
	}
	cout << dp.size() << endl;
}
