// https://codeforces.com/problemset/problem/459/D

#include <bits/stdc++.h>

using namespace std;

struct FT {
	vector<long long> s;
	FT(int n) : s(n) {}
	void update(int pos, long long dif){ // a[pos] += dif
		for (; pos < (int)s.size(); pos |= pos+1) s[pos] += dif;
	}
	long long query(int pos){ // sum of values in [0, pos)
		long long res=0;
		for(; pos>0; pos &= pos-1) res += s[pos-1];
		return res;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	vector<int> pre(n, 0), suf(n, 0);
	map<int, int> f;
	for(int i = 0; i < n; i++)
		f[a[i]]++, pre[i] = f[a[i]];
	f.clear();
	for(int i = n-1; i >= 0; i--)
		f[a[i]]++, suf[i] = f[a[i]];
	
	long long ret = 0;
	FT ft(n+1);
	for(int i = 0; i < n; i++)
		ft.update(suf[i], +1);
	
	for(int i = 0; i < n; i++)
		ft.update(suf[i], -1),
		ret += ft.query(pre[i]);
	
	cout << ret << '\n';
    return 0;
}
