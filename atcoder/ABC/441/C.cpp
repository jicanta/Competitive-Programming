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

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	ll n, k; ll x; cin >> n >> k >> x;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	
	ll low = 0, high = n+1;
	sort(all(a));
	
	while(high - low > 1) {
		ll mid = low + (high - low) / 2;
		ll rest = n - mid;
		ll present = k - rest;
		ll curSum = 0;
		rep(i, n - mid, n - mid + present) curSum += a[i];
		if(curSum >= x) high = mid;
		else low = mid;
	}
	if(high == n+1) high = -1;
	cout << high << '\n';
	
	return 0;
}
