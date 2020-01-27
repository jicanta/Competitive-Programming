#include <bits/stdc++.h>

using namespace std;

typedef long long tint;

const tint INF = 1e18;

#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios_base::sync_with_stdio(0);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

vector<tint> dij(int comienzo, int fin, vector<vector<pair<int,int>>> &adj, int K){
	int n = adj.size();
	vector<tint> dis (n, INF); dis[comienzo] = 0;
	vector<int> visited (n, 0);
	priority_queue<pair<tint,int>> q;
	q.push({0, comienzo});
	int cont = 0;
	vector<tint> paths (K);
	while(!q.empty() && cont < K){
		int a = q.top().second; tint w = q.top().first;
		q.pop();
		if(visited[a] > K) continue;
		visited[a]++;
		if(a == fin){
			paths[cont] = -w;
			cont++;
		}
		for(const auto &v : adj[a]){
			if(visited[v.first] <= K){
				q.push({w-v.second, v.first});
			}
		}
	}
	return paths;
}

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo){
	comienzo--; fin--;
	vector<vector<pair<int,int>>> adj (N);
	forn(i, M){
		origen[i]--; destino[i]--;
		adj[origen[i]].push_back({destino[i], tiempo[i]});
	}
	vector<tint> chemins = dij(comienzo, fin, adj, K);
	return chemins;
}
