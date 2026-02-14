#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using ll = long long;
using vl = vector<ll>;
using ld = long double;

const int MOD = 998244353;

int curNode = 0;
int n;
vi getNode;
vector<vi> label;
vector<vii> neis;
map<pii, int> adj;
vi ret;

void insert(int i, int x, int y) {
	int node = getNode[x];
	if(not adj.count({node, y})) {
		curNode++, neis[node].push_back({y, curNode});
		adj[{node, y}] = curNode;
	}
	getNode[i+1] = adj[{node, y}];
	label[adj[{node, y}]].push_back(i+1);
}

void dfs(int node) {
	for(auto u : label[node]) if(u >= 1)
		ret.push_back(u);
	for(auto [y, nei] : neis[node]) {
		dfs(nei);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n;
	getNode.resize(n+1);
	neis.resize(n+1);
	label.resize(n+1);
	getNode[0] = 0;
	rep(i, 0, n) {
		int x, y; cin >> x >> y;
		insert(i, x, y);
	}
	
	rep(i, 0, n) sort(all(label[i])), sort(all(neis[i]));
	
	dfs(0);
	rep(i, 0, n) cout << ret[i] << " \n"[i+1==n];	
}
