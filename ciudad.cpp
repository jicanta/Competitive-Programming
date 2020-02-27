#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 100000000;
const long double PI = 3.141592653;

vector<pair<int,int>> adj[30000];
map<pair<int,pair<int,int>>, int> id;
///0 a 9999 -> sin abrir
///10000 a 19999 -> abriendo una
///20000 a 29999 > abriendo dos

vector<int> dis(int nodo, vector<pair<int,int>> &chemin, int fin){
	int x = 30000;
	vector<bool> visited (x, 0);
	vector<int> dist (x, INF); dist[nodo] = 0;
	priority_queue<pair<int,int>> q;
	vector<pair<int,int>> vengo (x, {-1,-1});
	q.push({0, nodo});
	while(!q.empty()){
		int s = q.top().second; q.pop();
		if(visited[s]) continue;
		visited[s] = 1;
		for(const auto &u : adj[s]){
			int b = u.first, w = u.second;
			if(dist[s]+w < dist[b]){
				vengo[b] = {s, w};
				dist[b] = dist[s]+w;
				q.push({-dist[b], b});
			}
		}
	}
	int mini = min({dist[fin-1], dist[10000+fin-1], dist[20000+fin-1]});
	int st;
	if(mini == dist[fin-1]){
		chemin = {};
		return dist;
	}else if(mini == dist[10000+fin-1]){
		st = 10000+fin-1;
	}else st = 20000+fin-1;
	int p = -1;
	while(st != -1){
		chemin.push_back({st, p});
		auto s = vengo[st];
		st = s.first;
		p = s.second;	
	}
	return dist;
}

int main(){
	//ifstream cin("ciudad.in");
	//ofstream cout("ciudad.out");
	int n, m, k; cin >> n >> m >> k;
	forn(i, m){
		int u, v, w; cin >> u >> v >> w;
		u--;v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		adj[10000+u].push_back({10000+v,w});
		adj[10000+v].push_back({10000+u,w});
		adj[20000+u].push_back({20000+v,w});
		adj[20000+v].push_back({20000+u,w});
	}
	forn(i, k){
		int u, v, w; cin >> u >> v >> w;
		u--;v--;
		id[{u, {v,w}}] = id[{v, {u,w}}]= i+1;
		adj[u].push_back({10000+v, w});
		adj[v].push_back({10000+u, w});
		adj[10000+u].push_back({20000+v, w});
		adj[10000+v].push_back({20000+u, w});
	}
	vector<pair<int,int>> chemin;
	vector<int> dist = dis(0, chemin, n);
	int mini = min({dist[n-1], dist[10000+n-1], dist[20000+n-1]});
	if(mini == dist[n-1]){
		cout << 1 << " " << mini << "\n";
	}else if(mini == dist[10000+n-1]){
		cout << 2 << " ";
		forn(i, chemin.size()-1){
			if(chemin[i].first >= 200000 && chemin[i+1].first < 20000 && chemin[i+1].first >= 10000){
				cout << id[{chemin[i].first-20000, {chemin[i+1].first-10000, chemin[i+1].second}}] << " ";
			}
			if(chemin[i].first >= 10000 && chemin[i].first < 20000 && chemin[i+1].first < 10000){
				cout << id[{chemin[i].first-10000, {chemin[i+1].first, chemin[i+1].second}}] << " ";
			}
		}
		cout << dist[10000+n-1] << "\n";
	}else{
		cout << 3 << " ";
		vector<int> ret;
		forn(i, chemin.size()-1){
			if(chemin[i].first >= 20000 && chemin[i+1].first < 20000 && chemin[i+1].first >= 10000){
				ret.push_back(id[{chemin[i].first-20000, {chemin[i+1].first-10000, chemin[i+1].second}}]);
			}
			if(chemin[i].first >= 10000 && chemin[i+1].first < 10000){
				ret.push_back(id[{chemin[i].first-10000, {chemin[i+1].first, chemin[i+1].second}}]);
			}
		}
		for(int i=int(ret.size())-1;i>=0;i--){
			cout << ret[i] << " ";
		}
		cout << dist[20000+n-1] << "\n";
	}
}
