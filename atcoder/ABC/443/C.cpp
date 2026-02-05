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
  
  int n, t; cin >> n >> t;
  ll ret = 0;
  int curOpen = 0;
  rep(i, 0, n) {
	  int x; cin >> x;
	  if(x - curOpen >= 0) {
		  ret += x - curOpen;
		  curOpen = x + 100;
	  }
  }
  ret += max(0, t - curOpen);
  cout << ret << '\n';
}
