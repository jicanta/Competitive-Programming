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
const int MX = 505;
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
 
void NACHO(string name = "skilevel"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int t;

struct edge{
	int u, v, w;
	bool operator<(const edge &o)const{ return w < o.w; }
};

struct DSU{
	vi e, ret; vvi ch; void init(int N, int M){ e = vi(M*N+M, -1); ch = vvi(M*N+M); ret = vi(M*N+M, -1); F0R(i, N*M+M) ch[i].pb(i);  }
	int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int x, int y){ return get(x) == get(y); }
	bool unite(int x, int y, int cur){
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		trav(u, ch[y]) ch[x].pb(u);
		ch[y].clear();
		if(-e[x] >= t){ 
			trav(u, ch[x]) ret[u] = cur;
			ch[x].clear();
		}
		return 1;
	}
};

int a[MX][MX];
bool s[MX][MX];
vector<edge> ed;

int main(){
    NACHO();
    int n, m; cin >> n >> m >> t;
    F0R(i, n) F0R(j, m) cin >> a[i][j];
    F0R(i, n) F0R(j, m) cin >> s[i][j];
    if(t == 1){
		cout << 0 << "\n";
		return 0;
	}
	DSU D; D.init(n, m);
    F0R(i, n){
		F0R(j, m){
			F0R(k, 4){
				int x = i+dx[k], y = j+dy[k];
				if(valid(x, y, n, m)){
					ed.pb({m*i+j, m*x+y, abs(a[i][j]-a[x][y])});
				}
			}
		}
	}
	sort(all(ed));
	F0R(i, sz(ed)){
		D.unite(ed[i].u, ed[i].v, ed[i].w);
	}
	tint ret = 0;
	F0R(i, n){
		F0R(j, m){
			if(s[i][j]) ret += D.ret[m*i+j];
		}
	}
	cout << ret << "\n";
}


