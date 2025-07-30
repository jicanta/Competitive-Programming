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

vi adj[MAXN];
bool can = true;
bool col[MAXN], vis[MAXN];

void dfs(int node) {
	vis[node] = true;
	for(auto nei : adj[node]) {
		if(vis[nei] && col[nei] == col[node]) {
			can = false;
			return;
		} else if(!vis[nei]) {
			col[nei] = 1 - col[node];
			dfs(nei);
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    rep(i, 0, n) {
		int nei;
		while(cin >> nei && nei != 0) {
			adj[i].push_back(nei - 1);
			adj[nei - 1].push_back(i);
		}
	}
	
	dfs(0);
	
	if(can) {
		rep(i, 0, n) cout << col[i];
		cout << "\n";
	} else {
		cout << -1 << "\n";
	}
	
	
	return 0; 
}

