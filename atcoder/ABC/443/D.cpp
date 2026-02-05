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
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	vi b = a;
	rep(i, 1, n)
		b[i] = min(b[i], b[i-1]+1);
	per(i, 0, n-1)
		b[i] = min(b[i], b[i+1]+1);
	ll ret = 0;
	rep(i, 0, n) ret += max(0, a[i] - b[i]);
	cout << ret << '\n';
  }
}
