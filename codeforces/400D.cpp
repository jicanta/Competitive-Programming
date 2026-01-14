// https://codeforces.com/problemset/problem/400/D

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }

	bool join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return false;
		if(e[a] > e[b]) swap(a,b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

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
	vector<vector<int>> dist(k, vector<int>(k, INF));
	UF uf(n);
	for(int i = 0; i < k; ++i) dist[type[i]][type[i]] = 0;
    for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		dist[type[u]][type[v]] = min(dist[type[u]][type[v]], w);
		dist[type[v]][type[u]] = min(dist[type[v]][type[u]], w);
		if(w == 0) uf.join(u, v);
	}
	
	for(int i = 0; i < n; ++i) {
		int j = i;
		while(j < n && type[j] == type[i]) {
			if(uf.find(i) != uf.find(j)) {
				cout << "No\n";
				return 0;
			}
			j++;
		}
	}
	
	for(int kk = 0; kk < k; ++kk) 
		for(int i = 0; i < k; ++i)
			for(int j = 0; j < k; ++j)
				dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
				
				
	cout << "Yes\n";
			
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j)
			cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " \n"[j+1==k];
	}
	
	
    return 0;
}
