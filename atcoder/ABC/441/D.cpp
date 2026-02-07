#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for(int i = (int)b-1; i >= a; i--)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vb = vector<bool>;
using ld = long double;

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;
const int MX = 2e5+5;

int n, m, l, s, t;

vi good;

vii adj[MX];

void dfs(int node, int quanEdges = 0, int curCost = 0) {
	if(quanEdges > l || curCost > t) return;
	if(quanEdges == l && s <= curCost && curCost <= t) {
		good[node] = true;
		return;
	}
	for(auto u : adj[node]) {
		auto [nei, w] = u;
		dfs(nei, quanEdges+1, curCost+w);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> m >> l >> s >> t;
	rep(i, 0, m) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
	}
	good.assign(n, 0);
	dfs(0);

	rep(i, 0, n) if(good[i])
		cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}
