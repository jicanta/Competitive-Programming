#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
#define dbg cout << "hu" << endl;
 
struct ari{
	int v;
	int w;
	int id;	
};

int cost[5001];

vector<ari> adj [1001];

void dijkstra(int node, int n){
	vector<int> distance (n, 50000001);
	distance[node] = 0;
	vector<bool> visited (n, 0);
	priority_queue<pair<int,int>> q;
	vector<pair<ari,int>> vengo (n, {{-1,-1,-1}, -1});
	q.push({0, node});
	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		if(visited[a]) continue;
		visited[a] = 1;
		for(auto &u:adj[a]){
			int b = u.v, w = u.w;
			if(distance[a]+w < distance[b]){
				distance[b] = distance[a]+w;
				q.push({-distance[b], b});
				vengo[b] = {u,a};
			}
		}
	}
	forn(i, n){
		if(i != node){
			int st = i;
			while(st != node){
				cost[vengo[st].first.id]++;
				st = vengo[st].second;
			}
		}
	}
}

int main(){
    ifstream cin("congestion.in");
	ofstream cout("congestion.out");
	int n, m; cin >> n >> m;
	forn(i, m){
		int u, v; int w; cin >> u >> v >> w;
		u--;v--;
		adj[u].push_back({v,w,i});
	}
	forn(i, n){
		dijkstra(i, n);
	}
	int maxi = 0;
	forn(i, m){
		maxi = max(maxi, cost[i]);
	}
	vector<int> ret;
	forn(i, m){
		if(cost[i] == maxi) ret.push_back(i+1);
	}
	cout << int(ret.size()) << " " << maxi << "\n";
	forn(i, ret.size()){
		cout << ret[i];
		if(i != int(ret.size())-1) cout << " ";	
	}
}
