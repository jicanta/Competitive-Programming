#include <bits/stdc++.h>
#include <fstream>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
typedef long long tint;
 
const int INF = 900000000;
const int MOD = 1e9+7;

vector<pair<int,int>> adj[15001];
vector<int> graph[15001];
vector<int> tr[15001];

vector<int> dij(int node, int n){
	vector<int> distance (n, INF);
	distance[node] = 0;
	vector<bool> visited(n,0);
	priority_queue<pair<int,int>> q;
	q.push({0,node});
	while(!q.empty()){
		auto s = q.top().second;
		q.pop();
		if(visited[s]) continue;
		visited[s] = 1;
		for(auto u : adj[s]){
			int b = u.first, w = u.second;
			if(distance[s]+w < distance[b]){
				distance[b] = distance[s]+w;
				q.push({-distance[b], b});
			}
		}
	}
	return distance;
}

bool visited[15001];
vector<int> ord;
int dp[15001];

void dfs(int node){
	visited[node] = 1;
	for(auto u : graph[node]){
		if(!visited[u]){
			dfs(u);
		}
	}
	ord.push_back(node);
}

int main(){
	ifstream cin("ambulancia.in");
	ofstream cout("ambulancia.out");
	int n, m; cin >> n >> m;
	int s, e; cin >> s >> e;
	s--;e--;
	forn(i, m){
		int u, v, w; cin >> u >> v >> w;
		u--;v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int> dist1 = dij(s, n);
	vector<int> dist2 = dij(e, n);
	forn(i, n){
		for(auto u : adj[i]){
			if(dist1[i] < dist1[u.first] && dist2[i] > dist2[u.first]){
				graph[i].push_back(u.first);
			}
		}
	}
	dfs(s);
	reverse(all(ord));
	forn(i, n){
		for(auto u : graph[i]){
			tr[u].push_back(i);
		}
	}
	dp[s] = 1;
	forn(i, ord.size()){
		for(auto u : tr[ord[i]]){
			dp[ord[i]]+=dp[u];
		}
	}
	cout << dp[e] << endl;
}
