#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;

const int INF = 1e9;
const int MOD = 1e9+7;
const int N = 100001;

vector<int> adj[N];

vector<int> bfs(int node, int n){
	queue<int> q;
	q.push(node);
	vector<int> distance (n, INF);
	distance[node] = 0;
	vector<bool> visited (n, 0);
	visited[node] = 1;
	while(!q.empty()){
		auto s = q.front();
		q.pop();
		for(auto u : adj[s]){
			if(visited[u]) continue;
			visited[u] = 1;
			distance[u] = distance[s]+1;
			q.push(u);
		}
	}
	return distance;
}

int main(){
	NACHO;
	int n, m; cin >> n >> m;
	int d; cin >> d;
	forn(i, m){
		int u, v; cin >> u >> v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> a = bfs(0,n);
	vector<int> b = bfs(n-1,n);
	int c = 0;
	forn(i, n) if(a[i]+b[i] <= d) c++;
	cout << c << "\n";
}
