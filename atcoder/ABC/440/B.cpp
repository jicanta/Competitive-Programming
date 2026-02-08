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

const ll INF = 1e18;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n, w; cin >> n >> w;
		
		vl a(n), c(4*w);
		rep(i, 0, n) cin >> a[i], c[i%(2*w)] += a[i];
		rep(i, 0, 2*w) c[i+2*w] = c[i];
		vl s(4*w+1, 0);
		rep(i, 1, 4*w+1) s[i] = s[i-1]+c[i-1];
		ll ret = INF;
		rep(i, w, 4*w+1) ret = min(ret, s[i]-s[i-w]);
		cout << ret << '\n';
	}
	return 0;
}

