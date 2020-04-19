#include <bits/stdc++.h>

using namespace std;

struct matrix {
	vector<vector<int>> t;
	matrix(int n, int m):t(n, vector<int>(m)){}

	struct row_matrix{
		matrix &m;
		int i;
		row_matrix(matrix &m_, int i_):m(m_), i(i_){}
		int &operator[](int j){
			return m.t[i][j];
		}
	};
	row_matrix operator[](int i){
		return row_matrix(*this, i);
	}
	int &operator()(int i, int j){
		return t[i][j];
	}
};

int main(){
	matrix m(2, 2);
	m(0, 0) = 1;
	m(1, 1) = 2;


	m[0][1] = 3;
	matrix::row_matrix r = m[1];
	r[0] = 4;
	
	
	for (int i : {0, 1}){
		for (int j : {0, 1})
			cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}
