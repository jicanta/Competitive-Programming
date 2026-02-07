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

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	vector<pair<ll, ll>> a(n);
	rep(i, 0, n) cin >> a[i].first >> a[i].second;
	
	vector<vl> dpPre(n+1, vl(m+1, 0));
	vector<vl> dpSuf(n+2, vl(m+1, 0));
	
	rep(i, 1, n+1) {
		rep(j, 0, m+1) {
			dpPre[i][j] = dpPre[i-1][j];
			if(j-a[i-1].first >= 0) 
				dpPre[i][j] = max(dpPre[i][j], dpPre[i-1][j-a[i-1].first]+a[i-1].second);
		}
	}
	per(i, 1, n+1) {
		rep(j, 0, m+1) {
			dpSuf[i][j] = dpSuf[i+1][j];
			if(j-a[i-1].first >= 0) 
				dpSuf[i][j] = max(dpSuf[i][j], dpSuf[i+1][j-a[i-1].first]+a[i-1].second);
		}
	}
	
	ll maxVal = dpPre[n][m];
	
	rep(i, 1, n+1) {
		ll maxiWithout = 0;
		ll maxiWith = 0;
		rep(j, 0, m+1) {
			maxiWithout = max(maxiWithout, dpPre[i-1][j]+dpSuf[i+1][m-j]);
			if(m-j-a[i-1].first >= 0) 
				maxiWith = max(maxiWith, dpPre[i-1][j]+dpSuf[i+1][m-j-a[i-1].first]);
		}
		if(maxiWithout == maxVal && maxiWith+a[i-1].second == maxVal) cout << 'B';
		else if(maxiWith+a[i-1].second == maxVal) cout << 'A';
		else cout << 'C';
	}
	cout << '\n';
		
	return 0;
}
