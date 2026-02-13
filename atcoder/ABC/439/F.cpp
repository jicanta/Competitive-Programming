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
const int MOD = 998244353;
const ld EPS = 1e-12;
const int MX = 2e5+5;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
	vl quanSmaller(n, 0), quanGreater(n, 0);
	ll ret = 0;
	FT ft(n+1);
	rep(i, 0, n)
		quanSmaller[i] = ft.query(a[i]),
		ft.update(a[i], +1); 
	FT nft(n+1);
	per(i, 0, n)
		quanGreater[i] = nft.query(a[i]),
		nft.update(a[i], +1);
		
	ll curRet = 0LL;
	rep(i, 0, n) {
		ret = (ret%MOD+quanGreater[i]%MOD*curRet%MOD)%MOD;
		ret = (ret%MOD+quanGreater[i]%MOD*quanSmaller[i]%MOD)%MOD;
		if(i > 0) curRet=(curRet*2)%MOD;
		curRet = (curRet%MOD+quanSmaller[i]%MOD)%MOD;
	}
	cout << ret << '\n';
	
	return 0;
}

// conjeturo que 
// an-1 > an
// a1 < a2
// ya me determina una subsecuencia
// a1 < a2 < a3 > a4 < a5 > a6
