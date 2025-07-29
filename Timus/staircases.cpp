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
const int MAXN = 60001;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
  cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	vector<vector<ll>> ways(n + 1, vector<ll>(n, 0));
	ways[0][0] = 1;
	
	rep(i, 0, n + 1) {
		rep(j, 1, n) {
			rep(k, 0, j) {
				if(i - j >= 0) ways[i][j] += ways[i - j][k];
			}
		}
	}
	
	ll tot = 0LL;
	
	rep(i, 1, n) {
		tot += ways[n][i];
	}
	
	cout << tot << "\n";
	
	return 0; 
}
