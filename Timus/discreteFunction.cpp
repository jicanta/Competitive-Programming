#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pair<ll,ll>>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const ll INF = 1000000000000000000;
const int MX = 35;
const int mod = 998244353;
const int MOD = 83456729;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	vl p(n);
	rep(i, 0, n) cin >> p[i];
	
	ll ans = -INF;
	int idx = -1;
	
	rep(i, 0, n-1) {
		if(abs(p[i+1] - p[i]) > ans) {
			ans = abs(p[i+1] - p[i]);
			idx = i;
		}
	}
	
	cout << idx + 1 << " " << idx + 2 << "\n";
	
	return 0; 
}



