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

void print128(__int128 x) {
	if (x == 0) {
		cout << "0";
		return;
	}
	string res;
	while(x) {
		res += (char)('0' + x % 10);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // No entra, necesita bignum
  
	ll n, s; cin >> n >> s;
	
	n *= 2;
	
	if(s & 1 || s > 9 * n) {
		cout << 0 << "\n";
		return 0;
	}
	
	vector<vector<__int128>> ways(s / 2 + 1, vector<__int128>(n / 2 + 1, 0));
	
	ways[0][0] = 1LL;
	rep(i, 0, s / 2 + 1) {
		rep(j, 0, n / 2 +  1) {
			rep(k, 0, 10) {
				if(i - k >= 0 && j - 1 >= 0) ways[i][j] += ways[i - k][j-1]; 
			}
		}
	}
	
	print128(ways[s / 2][n / 2] * ways[s / 2][n / 2]);
	
	return 0; 
}
