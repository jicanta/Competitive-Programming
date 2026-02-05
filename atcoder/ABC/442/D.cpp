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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	FT ft(n);
	vi a(n);
	rep(i, 0, n) {
		int x; cin >> x;
		ft.update(i, x);
		a[i] = x;
	}
	rep(_, 0, q) {
		int t; cin >> t;
		if(t == 1) {
			int x; cin >> x; x--;
			swap(a[x], a[x+1]);
			ft.update(x, -a[x+1]);
			ft.update(x+1, -a[x]);
			ft.update(x, a[x]);
			ft.update(x+1, a[x+1]);
		} else {
			int l, r; cin >> l >> r;
			cout << ft.query(r) - ft.query(l-1) << '\n';
		}
	}
}
