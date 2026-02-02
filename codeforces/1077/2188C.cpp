// https://codeforces.com/contest/2188/problem/C
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
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

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--) {
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	vi b = a;
	sort(all(b));
	if(a == b) {
		cout << -1 << '\n';
		continue;
	}
	int mini = *min_element(all(a)), maxi = *max_element(all(a));
	int ret = INF;
	rep(i, 0, n) if(a[i] != b[i])
		ret = min(ret, max(maxi - a[i], a[i] - mini));
	cout << ret << '\n';
  }
}
