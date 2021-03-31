#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vl = vector<tint>;
using vb = vector<bool>;
 
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
 
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const tint mod = 998244353;
const int MX = 2005;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "fencedin"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi x, y;

struct DSU{
	vi e; void init(int n){ e = vi(n, -1); }
	int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool unite(int x, int y){
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

map<int, vpi> ed;

int main(){
	NACHO();
	// si metes todas las aristas (8000000)
	// y luego ordenas da tle.
	// la clave esta en que hay 1000000000 pesos distintos.
	// ordenas estos y luego vas llenando.
	int a, b, n, m; cin >> a >> b >> n >> m;
	x.rsz(n+2); y.rsz(m+2);
	F0R(i, n) cin >> x[i];
	F0R(i, m) cin >> y[i];
	x[n] = a; y[m] = b;
	x[n+1] = 0; y[m+1] = 0;
	sort(all(x)); sort(all(y));
	DSU D; D.init((m+1)*(n+1)+m+1);
	FOR(i, 1, n+2){
		FOR(j, 1, m+2){
			int cur = (m+1)*(i-1)+j;
			// right
			if(i < n+1){
				int up = (m+1)*i+j;
				ed[y[j]-y[j-1]].pb(mp(cur, up));
			}
			// up
			if(j < m+1){
				int rit = (m+1)*(i-1)+j+1;
				ed[x[i]-x[i-1]].pb(mp(cur, rit));
			}
		}
	}
	tint ans = 0;
	trav(o, ed){
		trav(a, o.s){
			int u = a.f, v = a.s;
			if(D.unite(u, v)) ans += o.f;
		}
	}
	cout << ans << "\n";
}
