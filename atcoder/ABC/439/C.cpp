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
	vi sq;
	rep(i, 1, 3200) sq.push_back(i*i);
	
    vi s(n+1, 0);
	vi cand;
	rep(i, 0, sz(sq))
		rep(j, i+1, sz(sq)) if(sq[i]+sq[j] <= n) {
			++s[sq[i]+sq[j]]; 
			if(s[sq[i]+sq[j]] == 1) cand.push_back(sq[i]+sq[j]);
		}
	sort(all(cand));
	vi ret;
	for(auto u : cand) if(s[u] == 1)
		ret.push_back(u);
	
	cout << sz(ret) << '\n';
	rep(i, 0, sz(ret))
		cout << ret[i] << " \n"[i+1==sz(ret)];
	return 0;
}
