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

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	vl deg(n, 0);
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		u--, v--;
		deg[u]++;
		deg[v]++;
	}
	rep(i, 0, n) {
		cout << max(0LL, (n-deg[i]-1) * (n-deg[i]-2)*(n-deg[i]-3) / 6) << " \n"[i+1==n];
	}	
}
