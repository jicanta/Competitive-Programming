// https://codeforces.com/problemset/problem/274/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

pair<long long, long long> dfs(int node, int pa, const vector<long long>& vals, const vector<vector<int>>& adj) {
	pair<long long, long long> cur = {0, 0};
	long long curVal = vals[node];
	for(auto u : adj[node]) if(u != pa) {
		pair<long long, long long> child = dfs(u, node, vals, adj);
		cur.first = max(cur.first, child.first);
		cur.second = max(cur.second, child.second);	
	}
	curVal += cur.first - cur.second;
	if(curVal < 0) cur.first += abs(curVal);
	if(curVal > 0) cur.second += curVal;
	return cur;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> adj(n);
	vector<long long> vals(n);
	
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++)
		cin >> vals[i];
	
	pair<long long, long long> ret = dfs(0, -1, vals, adj);
	cout << ret.first + ret.second << '\n';
	
	return 0;
}
