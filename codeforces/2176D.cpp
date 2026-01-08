// https://codeforces.com/problemset/problem/2176/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> edges(m);
		vector<long long> val(n + 1);
		
		for(int i = 0; i < n; i++)
			cin >> val[i + 1];
		
		for(int i = 0; i < m; i++)
			cin >> edges[i].first >> edges[i].second;
		
		sort(begin(edges), end(edges), [&](const pair<int, int> &a, const pair<int, int> &b) {
			return val[a.first] + val[a.second] > val[b.first] + val[b.second];
		});
		
		vector<map<long long, long long>> dp(n + 1);
		// dp[node][value] = number of paths starting from node u that immediately go to a node with value 'value' 
		
		long long ret = 0;
		for(auto [u, v] : edges) {
			long long add = (dp[v][val[u] + val[v]] % MOD + 1 % MOD) % MOD;
			dp[u][val[v]] = (dp[u][val[v]] + add % MOD) % MOD;
			ret = (ret + add % MOD) % MOD;
		}
		cout << ret << '\n';
	}
	
	return 0;
}
