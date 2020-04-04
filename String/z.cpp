#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<int> z_func(string s){
	int n = s.size(), l=0, r=0, i;
	vector<int> z(n);
	for (i=1; i<n; i++){
		if (i<=r) z[i] = min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]-1>r){
			l = i;
			r = i+z[i]-1;
		}
	}
	return z;
}
 
int main(){
	string s;
	cin >> s;
	vector<int> v = z_func(s);
	for (auto x: v) cout << x << " ";
	cout << endl;
}
