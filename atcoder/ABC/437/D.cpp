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

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	vl a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	sort(all(a)); sort(all(b));
	ll ret = 0;
	rep(t, 0, 2) {
		ll curSum = 0;
		int j = 0;
		rep(i, 0, n) {
			while(j < m && b[j] <= a[i]) curSum = (curSum%MOD+b[j]%MOD)%MOD, j++;
			j = min(j, m);
			ret = ((ret%MOD+j%MOD*a[i]%MOD-curSum%MOD)+MOD)%MOD;
		}
		swap(a, b);
		swap(n, m);
	}
	cout << ret << '\n';
}
