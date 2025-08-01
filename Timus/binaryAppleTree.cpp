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
const int MAXN = 101;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int maxWeight[MAXN][MAXN];
vii adj[MAXN];

void dfs(int node, int pa) {
	int quanNeis = 0;
	vi maxWeightLeft(MAXN, 0);
	vi maxWeightRight(MAXN, 0);
	for(auto nei : adj[node]) {
		if(nei.first == pa) continue;
		dfs(nei.first, node);
		if(quanNeis > 0) {
			rep(i, 1, MAXN) {
				maxWeightRight[i] = nei.second + maxWeight[nei.first][i - 1]; 
			}
		} else {
			rep(i, 1, MAXN) {
				maxWeightLeft[i] = nei.second + maxWeight[nei.first][i - 1]; 
			}
		}
		quanNeis++;
	}
	rep(i, 0, MAXN) {
		rep(j, 0, i + 1) {
			maxWeight[node][i] = max(maxWeight[node][i], maxWeightLeft[j] + maxWeightRight[i - j]);
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n, q; cin >> n >> q;
	
	rep(i, 0, n-1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	dfs(0, -1);
	
	cout << maxWeight[0][q] << "\n";
	
	return 0; 
}

