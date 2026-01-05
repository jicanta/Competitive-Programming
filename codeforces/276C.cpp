// https://codeforces.com/problemset/problem/276/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(begin(a), end(a));
	
	vector<pair<int, int>> b(n);
	vector<pair<int, int>> queries(q);
	for(int i = 0; i < n; i++)
		b[i] = {0, i};
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		b[l].first++;
		if(r < n) b[r].first--;
		queries[i] = {l+1, r};
	}
	for(int i = 1; i < n; i++)
		b[i].first += b[i-1].first;
		
	vector<int> ret(n);
	sort(begin(b), end(b));
	for(int i = 0; i < n; i++) {
		ret[b.back().second] = a.back();
		b.pop_back();
		a.pop_back();
	}
	
	vector<int> sum(n+1, 0);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + ret[i-1];
	
	long long ans = 0;
	for(auto [l, r] : queries) {
		ans += sum[r] - sum[l-1];
	}
	
	cout << ans << '\n';
	return 0;
}
