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
const int MAXN = 202;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

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
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	vii p(n);
	
	rep(i, 0, n) {
		cin >> p[i].first >> p[i].second;
	}
	
	sort(all(p), [&](const pii &a, const pii & b) {
		if(a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	});
	FT ft(32001);
	vi quan(n, 0);
	
	rep(i, 0, n) {
		if(i == 0) {
			quan[0]++;
			ft.update(p[i].second, 1);
			continue;
		}
		quan[ft.query(p[i].second + 1)]++;
		ft.update(p[i].second, 1);
	}
	
	rep(i, 0, n) cout << quan[i] << "\n";
	
	return 0; 
}

