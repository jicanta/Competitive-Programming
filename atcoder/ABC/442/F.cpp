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

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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
	
	int n; cin >> n;
	vector<string> a(n);
	rep(i, 0, n) cin >> a[i];
	
	vector<vi> rowCost(n, vi(n+1));
	vector<vi> quanWhite(n, vi(n+1, 0)), quanBlack(n, vi(n+1, 0));
	
	rep(i, 0, n) {
		rep(j, 1, n+1) {
			int white = a[i][j-1] == '.';
			quanWhite[i][j] = quanWhite[i][j-1] + white;
			quanBlack[i][j] = quanBlack[i][j-1] + 1-white;
		}
	}
	rep(i, 0, n) {
		rowCost[i][0] = quanWhite[i][n];
		rep(qw, 1, n+1) {
			rowCost[i][qw] = 
				quanBlack[i][qw] + quanWhite[i][n] - quanWhite[i][qw];
		}
	}
	
	vi prevDp(n+1, 0);
	Tree st(n+1);
	rep(i, 0, n+1) st.update(i, 0);
	rep(i, 0, n) {
		vi dp(n+1);
		rep(j, 0, n+1) {
			dp[j] = rowCost[i][j] + st.query(j, n+1);
		}
		prevDp = dp;
		rep(j, 0, n+1) st.update(j, prevDp[j]);
	}
	cout << st.query(0, n+1) << '\n';
}
