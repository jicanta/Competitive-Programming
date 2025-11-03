#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pair<ll,ll>>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const int INF = 1000000000;
const int MX = 3e5+1;
const int mod = 998244353;

struct DSUW {
	vi p, szz;
	vl w;
	
	DSUW(int n) : p(n+1), szz(n+1, 1), w(n+1, 0) {
		rep(i, 0, n+1) p[i] = i;
	}
	
	int get(int x) {
		if(p[x] == x) return x;
		int r = get(p[x]);
		w[x] = (w[x] + w[p[x]]) % 2;
		return p[x] = r;
	}
	
	ll val(int x) {
		get(x);
		return ((w[x] % 2) + 2) % 2;
	}
	
	bool unite(int a, int b, ll v) {
		ll wa = val(a), wb = val(b);
		int ra = get(a), rb = get(b);
		if(ra == rb)
			return (((wa - wb) % 2) + 2) % 2 == v;
		if(szz[ra] > szz[rb]) {
			swap(ra, rb);
			swap(wa, wb);
			v *= -1LL;
			v = ((v % 2) + 2) % 2;
		}
		p[ra] = rb;
		szz[rb] += szz[ra];
		w[ra] = (((v - wa + wb) % 2) + 2) % 2;
		return true;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    while(cin >> n && n != -1) {
		int q; cin >> q;
		int ret = -1;
		
		vector<pair<pair<int, int>, ll>> queries;
		map<int, int> comp;
		rep(i, 0, q) {
			int a, b; ll dd; string s; 
			cin >> a >> b >> s;
			if(s == "even") dd = 0;
			else dd = 1;
			if(comp.count(a-1) == 0) comp[a-1] = sz(comp);
			if(comp.count(b) == 0) comp[b] = sz(comp);
			queries.push_back({{comp[b], comp[a-1]}, dd});
		}
		
		DSUW d(2*q+1);
		
		rep(i, 0, q) {
			if(!d.unite(queries[i].first.first, queries[i].first.second, queries[i].second) && ret == -1) ret = i;
		}
		if(ret == -1) ret = q;
	
		cout << ret << "\n";
	}
	
	return 0; 
}



