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

const int INF = 2'000'000'000;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
		
	int n, q; cin >> n >> q;
	vl a(n+2);
	rep(i, 0, n) cin >> a[i];
	a[n] = 0;
	a[n+1] = INF;
	sort(all(a));
	vl d(n+2, 0);
	rep(i, 1, n+2) d[i] = d[i-1]+a[i]-a[i-1]-1;
	
	rep(_, 0, q) {
		ll x, y; cin >> x >> y;
		ll lbId = lower_bound(all(a), x) - begin(a);
		ll lb = a[lbId];
		if(lb-x >= y)
			cout << x+y-1 << '\n';
		else {
			y = y-lb+x;
			ll low = lbId, high = n+2;
			while(high-low>1) {
				ll mid = low+(high-low)/2;
				if(d[mid]-d[lbId] >= y) high = mid;
				else low = mid;
			}
			y = y-d[low]+d[lbId];
			cout << a[low]+y << '\n';
		}
	}
	
	return 0;
}

