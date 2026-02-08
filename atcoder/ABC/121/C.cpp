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

int main() {
	cin.tie(0)->sync_with_stdio(false);
		
	int n; ll m; cin >> n >> m;
	vector<pair<ll, ll>> a(n);
	rep(i, 0, n) cin >> a[i].first >> a[i].second;
	sort(all(a));
	ll mini = 0;
	rep(i, 0, n) {
		mini += min(m, a[i].second)*a[i].first;
		m -= min(m, a[i].second);
	}
	cout << mini << '\n';
	
	return 0;
}

