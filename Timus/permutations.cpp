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
const int MAXN = 1001;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

vi adj[MAXN];
bool vis[MAXN];
ll cur = 0;

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

void dfs(int node) {
	vis[node] = true;
	cur++;
	for(auto nei : adj[node]) {
		if(!vis[nei]) {
			dfs(nei);
		}
	}
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	ll ret = 1LL;
	rep(i, 0, n) {
		int x; cin >> x;
		adj[i].push_back(x - 1);
	}
	
	rep(i, 0, n) {
		if(!vis[i]) {
			cur = 0;
			dfs(i);
			ret = lcm(ret, cur);
		}
	}
	
	cout << ret << "\n";
	
	return 0; 
}
