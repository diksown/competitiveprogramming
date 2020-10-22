#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


struct matrix {
	vector<vector<double>> m;
	matrix(){};
	matrix(int n){
		m = vector<vector<double>>(n, vector<double>(n, 0));
	};
	matrix operator * (const matrix &a){
		int n = m.size();
		matrix ans(n);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				for (int k=0; k<n; k++){
					ans.m[i][j] += m[i][k] * a.m[k][j];
					//ans.m[i][j] %= mod;
				}
			}
		}
		return ans;
	}
	matrix operator ^ (const ll &k){
		matrix ans = (*this);
		if (k == 1) return ans;
		ans = (ans ^ (k/2));
		ans = ans * ans;
		if (k % 2) ans = ans * (*this);
		return ans;
	}
};

int main(){
	cout << setprecision(8) << fixed;
	ll n; cin >> n;
	double p; cin >> p;
	matrix k;
	k.m = {
		{1, 0},
		{p, 1-2*p}
	};
	k = k^n;
	cout << k.m[1][0]+k.m[1][1] << endl;
}

