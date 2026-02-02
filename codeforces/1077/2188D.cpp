// https://codeforces.com/contest/2188/problem/D
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

void upd(ll& ret, ll x, ll y, ll a, ll b, pair<ll, ll>& bst) {
	if((a&b) == 0 && abs(x-a)+abs(y-b) < ret) {
		ret = abs(x-a)+abs(y-b);
		bst = {a, b};
	}
	return;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--) {
	ll x, y; cin >> x >> y;
	ll ret = INF;
	pair<ll, ll> bst;
	upd(ret, x, y, x, y, bst);
	per(i, 0, 30) {
		if((x>>i)&1 && (y>>i)&1) {
			ll highBitsX = x>>i<<i;
			ll highBitsY = y>>i<<i;
			upd(ret, x, y, highBitsX+(1LL<<i), y, bst);
			upd(ret, x, y, x, highBitsY+(1LL<<i), bst);
			upd(ret, x, y, highBitsX-1, highBitsY, bst);
			upd(ret, x, y, highBitsX, highBitsY-1, bst);
		}
	}
	cout << bst.first << ' ' << bst.second << '\n';
  }
}
