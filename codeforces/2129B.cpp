// https://codeforces.com/problemset/problem/2129/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
			
		int ret = 0;
		for(int i = 0; i < n; i++) {
			int l = 0, r = 0;
			for(int j = 0; j < i; j++)
				l += a[j] > a[i];
			for(int j = i+1; j < n; j++)
				r += a[j] > a[i];
			ret += min(l, r);
		}
		cout << ret << '\n';
	}
    
    return 0;
}
