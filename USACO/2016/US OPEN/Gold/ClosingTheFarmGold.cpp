#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,int>;
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
const int MX = 2e5+5;
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
 
void NACHO(string name = "closing"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct DSU{
	vi e; int numComp;
	void init(int N) { e = vi(N,-1); numComp = 0; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y){ 
		x = get(x), y = get(y); if (x == y) return 0;
		--numComp;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x;  return 1;
	}
};

vi adj[MX];
bool open[MX], ret[MX];
int a[MX];

int main(){
	NACHO();
	// la calve esta en que borrar cosas
	// es equivalente a poner esas cosas pero en orden inverso.
	// es decir, el grafo que que te queda si haces las
	// ultimas i operaciones de agregar nodos
	// es igual al grafo que te queda si haces las primeras n-i
	// operaciones de borrar nodos.
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DSU D; D.init(n);
	F0R(i, n){
		int u; cin >> u;
		--u;
		a[i] = u;	
	}
	R0F(i, n){
		int u = a[i];
		open[u] = 1;
		++D.numComp;
		trav(v, adj[u]){
			if(open[v]) D.unite(u, v);
		}
		if(D.numComp == 1) ret[i] = 1;
		else ret[i] = 0;
	}
	F0R(i, n){
		if(ret[i]) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}	

