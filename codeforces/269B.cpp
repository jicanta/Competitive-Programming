// https://codeforces.com/problemset/problem/269/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	double pos;
	
	for(int i = 0; i < n; i++)
		cin >> a[i] >> pos;
		
	vector<int> dp;
	for(int x : a) {
		int pos = upper_bound(begin(dp), end(dp), x) - begin(dp);
		if(pos == (int)dp.size())
			dp.push_back(x);
		else dp[pos] = x;
	}
	
	cout << n - dp.size() << '\n';	
	return 0;
}
