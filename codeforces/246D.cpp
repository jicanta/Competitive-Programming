// https://codeforces.com/problemset/problem/246/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_COLS = 100001;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis, 
		vector<set<int>>& seenCols, const vector<int> &col) {
	vis[node] = true;
	for(auto nei : adj[node]) {
		if(col[node] != col[nei])
			seenCols[col[node]].insert(col[nei]);
		if(not vis[nei])
			dfs(nei, adj, vis, seenCols, col);
	}
}

int getMaxDiversityColor(const vector<vector<int>>& adj, const vector<int>& col, int n) {
	vector<set<int>> seenCols(MAX_COLS);
	vector<bool> vis(n, false);
	for(int i = 0; i < n; i++) if(!vis[i])
		dfs(i, adj, vis, seenCols, col);
	int maxSz = -1, maxCol = 0;

	for(int i = 0; i < MAX_COLS; i++) if(int(seenCols[i].size()) > maxSz)
		maxSz = seenCols[i].size(), maxCol = i;
	return maxCol;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n);
	vector<int> col(n);
	
	for(int i = 0; i < n; i++)
		cin >> col[i];
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << getMaxDiversityColor(adj, col, n) << '\n';
	return 0;
}
