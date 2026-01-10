// https://codeforces.com/problemset/problem/439/D

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

template<class F>
int ternSearch(int a, int b, F f){
	assert(a<=b);
	while(b - a >= 5){
		int mid = (a+b)/2;
		if(f(mid) > f(mid+1)) a = mid; // (A)
		else b = mid+1;
	}
	for(int i = a; i <= b; i++) if(f(a) > f(i)) a = i; // (B)
	return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	
	auto cost = [&](int maxi) {
		long long ret = 0;
		for(int i = 0; i < m; i++)
			ret += max(0, b[i] - maxi);
		for(int i = 0; i < n; i++)
			ret += max(0, maxi - a[i]);
		return ret;
	  };
	
    int bestX = ternSearch(1, 1e9+1, cost);
	cout << cost(bestX) << '\n';
    return 0;
}
