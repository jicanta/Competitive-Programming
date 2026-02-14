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

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m, q; cin >> n >> m >> q;
	vector<vi> a(n, vi(m));
	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
	vi row(n, 0);
	rep(_, 0, q) {
		int x; cin >> x;
		rep(i, 0, n) rep(j, 0, m) row[i] += a[i][j]==x;
	}
	int maxi = 0;
	rep(i, 0, n) maxi = max(maxi, row[i]);
	cout << maxi << '\n';
}
