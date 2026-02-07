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
	
	int n; cin >> n;
	string s; cin >> s;
	int qa = 0, qb = 0;
	ll ret = 0;
	FT ft(2*n+1);
	ft.update(n, +1);
	rep(i, 0, n) {
		qa += s[i] == 'A';
		qb += s[i] == 'B';
		ret += ft.query(n + qa - qb);
		ft.update(n + qa - qb, +1);
	}
	cout << ret << '\n';
	
	return 0;
}
