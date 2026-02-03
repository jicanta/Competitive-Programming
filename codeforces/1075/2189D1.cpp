/// https://codeforces.com/contest/2189/problem/C1
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

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--) {
    int n, c; cin >> n >> c;
    string s; cin >> s;
	if(s[0] == '0' || s.back() == '0') {
		cout << -1 << '\n';
		continue;
	}
	ll retReal = 1, retModC = 1;
	rep(i, 0, n-1) {
		if(s[i] == '1')
			retReal = (2 * retReal) % MOD,
			retModC = (2 * retModC) % c;
		else
			retReal = (i * retReal) % MOD,
			retModC = (i * retModC) % c;
	}
	if(retModC == 0) retReal = -1;
	cout << retReal << '\n';
  }
}
