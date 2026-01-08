// https://codeforces.com/problemset/problem/339/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

template<class T> struct SegTree{
	int size;
	int h;
	vector<T> st;	
	
	int func(int a, int b, int depth) {
		if((h - depth) % 2 == 1)
			return a | b;
		return a ^ b;
	}
	
	void init(int n){
		size = 1;
		h = 0;
		while(size < n){
			size*=2;
			h++;
		}
		st.assign(2*size, 0);
	}
	
	void build(int node, int tl, int tr, vector<T> &a, int depth){
		if(tr-tl == 1){
			if(tl < (int)a.size()) st[node] = a[tl];
			return;
		}
		int tm = (tl+tr)/2;
		build(2*node+1, tl, tm, a, depth + 1);
		build(2*node+2, tm, tr, a, depth + 1);
		st[node] = func(st[2*node+1], st[2*node+2], depth);	
	}
	
	void build(vector<T> &a){ build(0, 0, size, a, 0);  }
	
	void update(int node, int tl, int tr, int pos, int val, int depth){
		if(tr-tl == 1){
			st[node] = val;
			return;
		}
		int tm = (tl+tr)/2;
		if(pos < tm) update(2*node+1, tl, tm, pos, val, depth + 1);
		else update(2*node+2, tm, tr, pos, val, depth + 1);
		st[node] = func(st[2*node+1], st[2*node+2], depth);
	}
	
	void update(int pos, int val){ update(0, 0, size, pos, val, 0);  }
	
	T query(int node, int tl, int tr, int l, int r, int depth){
		if(tr <= l || tl >= r) return 0;
		if(l <= tl && tr <= r) return st[node];
		int tm = (tl+tr)/2;
		return func(query(2*node+1, tl, tm, l, r, depth + 1), query(2*node+2, tm, tr, l, r, depth + 1), depth);
	}
	
	T query(int l, int r){ return query(0, 0, size, l, r, 0); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int sz = 1<<n;
	vector<int> a(sz);
	
	for(int i = 0; i < sz; i++)
		cin >> a[i];
	
	SegTree<int> st;
	st.init(sz);
	st.build(a);
	
	for(int _ = 0; _ < m; _++) {
		int i, v;
		cin >> i >> v;
		st.update(i - 1, v);
		cout << st.query(0, sz) << '\n';
	}
	
	return 0;
}
