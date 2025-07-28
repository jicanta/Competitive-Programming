#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const int inf = 1000000000;
const int MAXN = 128;

vi adj[MAXN];
vi treeAdj[MAXN];
vi adjRet[MAXN];
int n;

int bfs(int node, bool ot, int nodee) {
	vb visited(n, false);
	vi dist(n, 0);
	queue<int> q;
	q.push(node);
	if(ot) q.push(nodee);
	int maxiDist = 0, maxiNode;
	
	while(sz(q)) {
		auto u = q.front();
		q.pop();
		visited[u] = true;
		
		for(auto nei : adj[u]) {
			if(!visited[nei]) {
				visited[nei] = true;
				treeAdj[u].push_back(nei);
				treeAdj[nei].push_back(u);
				dist[nei] = dist[u] + 1;
				if(dist[nei] > maxiDist) {
					maxiDist = dist[nei];
					maxiNode = nei;
				}
				q.push(nei);
			}
		}
	}
	
	rep(i, 0, n) visited[i] = false, dist[i] = 0;
	q.push(maxiNode);
	maxiDist = 0;
	
	while(sz(q)) {
		auto u = q.front();
		q.pop();
		visited[u] = true;
		
		for(auto nei : treeAdj[u]) {
			if(!visited[nei]) {
				visited[nei] = true;
				dist[nei] = dist[u] + 1;
				if(dist[nei] > maxiDist) {
					maxiDist = dist[nei];
				}
				q.push(nei);
			}
		}
	}
	
	return maxiDist;
}

map<pii, bool> edge;
map<pii, bool> seen;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	
	int m; cin >> n >> m;
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		u--, v--;
		edge[{u, v}] = true;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int miniRet = inf;
	int centerRet = 0, centerRett = 0;
	rep(center, 0, n) {
		rep(i, 0, n) treeAdj[i].clear();
		int curRet = bfs(center, false, center);
		if(curRet < miniRet) {
			miniRet = curRet;
			centerRet = center;
			centerRett = center;
		}
	}
	bool ot = false;
	rep(i, 0, n) {
		for(auto nei : adj[i]) {
			rep(j, 0, n) treeAdj[j].clear();
			int curRet = bfs(i, true, nei);
			if(curRet < miniRet) {
				miniRet = curRet;
				centerRet = i;
				centerRett = nei;
				ot = true;
			}
		}
	}
	rep(i, 0, n) treeAdj[i].clear();
	bfs(centerRet, ot, centerRett);
	
	rep(i, 0, n) {
		for(auto nei : treeAdj[i]) {
			if(seen[{i, nei}] || seen[{nei, i}]) continue;
			if(edge[{i, nei}]) {
				cout << i + 1 << " " << nei + 1 << "\n";
			} else {
				cout << nei + 1 << " " << i + 1 << "\n";
			}
			seen[{i, nei}] = true;
		}
	}
	
	
	return 0; 
}
