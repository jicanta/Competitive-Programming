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

struct TreeMax {
	typedef ll T;
	static constexpr T unit = LLONG_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct TreeMin {
	typedef ll T;
	static constexpr T unit = LLONG_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	TreeMin tminX(n), tminY(n); TreeMax tmaxX(n), tmaxY(n);
	rep(i, 0, n) {
		ll x, y; cin >> x >> y;
		ll newX = x+y, newY = y-x;
		tminX.update(i, newX);
		tmaxX.update(i, newX);
		tminY.update(i, newY);
		tmaxY.update(i, newY);
	}
	
	rep(_, 0, q) {
		int t; cin >> t;
		if(t == 1) {
			ll i, x, y;
			cin >> i >> x >> y;
			ll newX = x+y, newY = y-x;
			i--;
			tminX.update(i, newX);
			tmaxX.update(i, newX);
			tminY.update(i, newY);
			tmaxY.update(i, newY);
		} else {
			int l, r; cin >> l >> r;
			l--;
			ll x, y; cin >> x >> y;
			ll newX = x+y, newY = y-x;
			cout << max(max(abs(newX-tminX.query(l, r)), abs(tmaxX.query(l, r)-newX)), 
						max(abs(newY-tminY.query(l, r)), abs(tmaxY.query(l, r)-newY))) << '\n';
		}
	}
	
}
