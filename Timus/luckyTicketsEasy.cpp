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
const int MAXN = 128;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	
	vector<vector<ll>> ways(9 * n / 2 + 1, vector<ll>(n / 2 + 1, 0));
	
	
	rep(i, 1, 9 * n / 2 + 1) {
		rep(j, 0, n / 2 +  1) {
			ways[0][j] = 1;
			rep(k, 0, 10) {
				if(i - k >= 0 && j - 1 >= 0) ways[i][j] += ways[i - k][j-1]; 
			}
		}
	}
	
	ll sum = 0;
	rep(i, 0, 9 * n / 2 + 1) {
		sum += ways[i][n / 2] * ways[i][n / 2];
	}
	cout << sum << "\n";
	
	return 0; 
}
