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

const ll INF = 1e18;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, k, x; cin >> n >> k >> x;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	vl curSol(n, 0);
	ll curSum = k*a[0];
	curSol[0] = k;
	priority_queue<pair<ll, vl>> q;
	map<vl, bool> seen;
	q.push({curSum, curSol});
	seen[curSol] = true;
	rep(_, 0, x) {
		auto u = q.top(); q.pop();
		cout << u.first << '\n';
		rep(i, 0, n-1) {
			if(u.second[i] > 0 && u.second[i+1] < k) {
				vl nxtSol = u.second;
				nxtSol[i]--;
				nxtSol[i+1]++;
				if(not seen[nxtSol])
					q.push({u.first-a[i]+a[i+1], nxtSol}),
					seen[nxtSol] = true;
			}
		}
	}
		
	return 0;
}

