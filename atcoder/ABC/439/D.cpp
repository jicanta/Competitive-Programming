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
using ld = long double;

const ld INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-12;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	ll ret = 0;
	map<int, ll> ret3, ret7, q3, q7;
	per(i, 0, n) {
		if(a[i] % 5 == 0) {
			ret += ret3[a[i]/5]+ret7[a[i]/5];
		}
		if(a[i] % 3 == 0) {
			ret3[a[i]/3] += q7[a[i]/3];
			q3[a[i]/3]++;
		}
		if(a[i] % 7 == 0) {
			ret7[a[i]/7] += q3[a[i]/7];
			q7[a[i]/7]++;
		}
	}
	ret3.clear(), ret7.clear();
	q3.clear(); q7.clear();
	rep(i, 0, n) {
		if(a[i] % 5 == 0) {
			ret += ret3[a[i]/5]+ret7[a[i]/5];
		}
		if(a[i] % 3 == 0) {
			ret3[a[i]/3] += q7[a[i]/3];
			q3[a[i]/3]++;
		}
		if(a[i] % 7 == 0) {
			ret7[a[i]/7] += q3[a[i]/7];
			q7[a[i]/7]++;
		}
	}
	cout << ret << '\n';
	
	return 0;
}

