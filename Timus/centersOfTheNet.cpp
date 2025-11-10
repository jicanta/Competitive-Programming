#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pair<ll,ll>>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const int INF = 1e9;
const int MX = 10001;
const int mod = 998244353;
const int MOD = 83456729;

vi adj[MX];
int dist[MX];

void dfs(int node, int pa) {
	for(const auto& u : adj[node]) if(u != pa) {
		dfs(u, node);
		dist[node] = max(dist[node], 1 + dist[u]);
	}
}

int calcMaxDist(int node, int n) {
	rep(i, 0, n) dist[i] = 0;
	dfs(node, -1);
	return dist[node];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	rep(i, 1, n) {
		int p; cin >> p;
		p--;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	vi maxDist(n, 0);
	int minDist = INF;
	rep(i, 0, n) {
		maxDist[i] = calcMaxDist(i, n);
		minDist = min(minDist, maxDist[i]);
	}
	
	vi ret;
	rep(i, 0, n) if(maxDist[i] == minDist)
		ret.push_back(i);
	
	for(const auto& u : ret) cout << u + 1 << " ";
	
	return 0; 
}



