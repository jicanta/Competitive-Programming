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
const int MAXN = (1<<16) + 1;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	ll n, k; cin >> n >> k;
	
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	rep(i, 2, n + 1) {
		dp[i][0] = dp[i-1][1] + dp[i-1][0];
		dp[i][1] = dp[i-1][0];
	}
	ll tot = dp[n][0] + dp[n][1];
	
	if(k > tot) {
		cout << -1 << "\n";
		return 0;
	}
	
	string s = "";
	int prev = 0;
	k--;
	rep(i, 0, n) {
		int rest = n - i - 1;
		
		if(prev == 1) {
			s += '0';
			prev = 0;
			continue;
		}
		
		tot = dp[rest][0] + dp[rest][1];
		
		if(k < tot) {
			s += '0';
			prev = 0;
		} else {
			s += '1';
			prev = 1;
			k -= tot;
		}
	}
	
	cout << s << "\n";
	
	return 0; 
}

