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

const ld INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-12;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n; cin >> n;
	vii a(n);
	rep(i, 0, n) cin >> a[i].first >> a[i].second;
	sort(all(a), [&](const pii& a, const pii& b){
		if(a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	});
	
	vi dp;
	rep(i, 0, n) {
		int id = lower_bound(all(dp), a[i].second) - begin(dp);
		if(id == sz(dp)) dp.push_back(a[i].second);
		else dp[id] = a[i].second;
	}
	cout << sz(dp) << '\n';
	
	return 0;
}
