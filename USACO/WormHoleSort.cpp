#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define NACHO ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long tint;

tint INF = 1e16+1;



vector<bool> visited;

void dfs(int node, vector<vector<pair<int,int>>> &adj, int mid){
	visited[node] = 1;
	for(const auto &v : adj[node]){
		if(!visited[v.first] && v.second >= mid) dfs(v.first, adj, mid);
	}
}

int main(){
	NACHO;
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");
	int n, m; cin >> n >> m;
	vector<int> pos (n);
	vector<pair<int,int>> des;
	vector<vector<pair<int,int>>> adj (n);
	forn(i, n){
		cin >> pos[i];
		if(i+1 != pos[i]) des.push_back({pos[i]-1, i});
	}
	forn(i, m){
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	if(des.size() == 0){
		cout << -1 << "\n";
		return 0;
	}
	int low = 0, high = 1e9+1;
	while(high-low > 1){
		int mid = low+(high-low)/2;
		visited.clear();
		visited.resize(n, 0);
		dfs(des[0].second, adj, mid);
		bool ok = 1;
		forn(i, des.size()){
			if(!visited[des[i].second]) ok = 0;
		}
		if(ok) low = mid;
		else high = mid;
	}
	cout << low << "\n";
}
