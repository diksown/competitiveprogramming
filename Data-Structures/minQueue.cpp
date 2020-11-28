#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
struct minQueue {
	deque<ll> d;
	ll get_min(){
		return d.front();
	}
	void pop(ll remove_element){
		if (remove_element == d.front())
			d.pop_front();
	}
	void push(ll new_element){
		while(!d.empty() and d.back() > new_element)
			d.pop_back();
		d.push_back(new_element);
	}
};
 
int main(){
	minQueue m;
	m.push(1); // 1
	m.push(3); // 1 3
	m.push(2); // 1 3 2
	cout << m.get_min() << endl; // 1
	m.pop(1); // 3 2
	cout << m.get_min() << endl; // 2
}
