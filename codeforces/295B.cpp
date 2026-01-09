// https://codeforces.com/problemset/problem/295/B

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> adj[i][j];
	
	vector<int> nodes(n);
	for(int i = 0; i < n; i++)
		cin >> nodes[i];
	
	vector<vector<int>> dist(n, vector<int>(n, INF));
	vector<int> curNodes;
	auto getAllDists = [&]() {
		long long ret = 0;
		for(auto u : curNodes)
			for(auto v : curNodes)
				ret += dist[u][v];
		return ret;
	};
	
	auto updateDists = [&](int k) {
		for(auto u : curNodes)
			for(auto v : curNodes)
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
	};
	
	vector<long long> ret;
	for(int i = n - 1; i >= 0; i--) {
		int curNode = nodes[i] - 1;
		curNodes.push_back(curNode);
		for(auto u : curNodes)
			dist[u][curNode] = adj[u][curNode],
			dist[curNode][u] = adj[curNode][u];
		
		for(auto u : curNodes)
			for(auto v : curNodes)
				dist[u][curNode] = min(dist[u][curNode], dist[u][v] + dist[v][curNode]);
			
		for(auto u : curNodes)
			for(auto v : curNodes)
				dist[curNode][u] = min(dist[curNode][u], dist[curNode][v] + dist[v][u]);
				
		updateDists(curNode);
				
		ret.push_back(getAllDists());
	}
	
	reverse(begin(ret), end(ret));
	for(auto u : ret)
		cout << u << ' ';
	cout << '\n';
	
    return 0;
}
