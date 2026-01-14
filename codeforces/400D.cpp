// https://codeforces.com/problemset/problem/400/D

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> quan(k), type(n);
    
    for(int i = 0; i < k; ++i)
		cin >> quan[i];
		
	int j = 0;
	for(int i = 0; i < n; ++i) {
		if(quan[j] == 0) ++j;
		type[i] = j;
		--quan[j];
	}
	vector<vector<int>> dist(n, vector<int>(n, INF));
	for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		dist[u][v] = w;
		dist[v][u] = w;
	}
	
	for(int k = 0; k < n; ++k) 
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				
	for(int i = 0; i < n; ++i)
		for(int j = i+1; type[j] == type[i]; ++j)
			if(dist[i][j] != 0) {
				cout << "No\n";
				return 0;
			}
				
	cout << "Yes\n";
		
	vector<vector<int>> ret(k, vector<int>(k, INF));
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j)
			ret[type[i]][type[j]] = min(ret[type[i]][type[j]], dist[i][j]);
			
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j)
			cout << (ret[i][j] == INF ? -1 : ret[i][j]) << " \n"[j+1==k];
	}
	
	
    return 0;
}
