#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point{
	double x, y;
	Point(){};
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}
	Point operator + (const Point &p) const { return Point(x+p.x, y+p.y); }
	Point operator - (const Point &p) const { return Point(x-p.x, y-p.y); }
	Point operator * (const double &k) const { return Point(x*k, y*k); }
	Point operator / (const double &k) const { return Point(x/k, y/k); }
	double operator * (const Point &p) const { return x * p.x + y * p.y; }
	double operator ^ (const Point &p) const { return x * p.y - y * p.x; }
	double operator ~ () const { return hypot(x, y); }
};	

int main(){
	Point p(0, 3), q(4, 0);
	cout << p.x << " " << p.y << endl;
	cout << (p*q) << " " << (p^q) << endl;
}
