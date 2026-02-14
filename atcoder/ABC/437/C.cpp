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
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<pair<ll, ll>> a(n);
		rep(i, 0, n) cin >> a[i].first >> a[i].second;
		sort(all(a), [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
			return a.first+a.second < b.first+b.second;
		});
		ll curSum = 0;
		ll totSum = 0;
		rep(i, 0, n) totSum += a[i].second;
		int ret = 0;
		rep(i, 0, n) {
			totSum -= a[i].second;
			curSum += a[i].first;
			if(totSum >= curSum) ret = i+1;
		}
		cout << ret << '\n';
	}
}
