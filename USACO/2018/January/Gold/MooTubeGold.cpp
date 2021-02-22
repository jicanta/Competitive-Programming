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
 
void NACHO(string name = "mootube"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct DSU{
	vi e; 
	void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y){ 
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x;  return 1;
	}
};

vector<pair<pi, int>> edges (MX);
vvi Q (MX, vi (3));
int ret[MX];

int main(){
	NACHO();
	// en problemas de queries en grafo/arboles
	// pensa si hacer las queries offline
	// con cierto orden te da alguna ventaja.
	// Ej: en este caso, si procesas las queries
	// por K ordenado de mayor a menor
	// sabes que podes lograrlo con cierto k para
	// aquellos nodos que estan en la misma componente.
	int n, q; cin >> n >> q;
	F0R(i, n-1){
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		edges[i] = mp(mp(w, u), v);
	}
	DSU D; D.init(n);
	F0R(i, q){ cin >> Q[i][0] >> Q[i][1]; Q[i][2] = i;} 
	sort(rall(Q));
	sort(rall(edges));
	int cur = 0;
	F0R(i, q){
		int u = Q[i][1]-1;
		int w = Q[i][0];
		while(cur < n-1 && edges[cur].f.f >= w){
			D.unite(edges[cur].f.s, edges[cur].s);
			++cur;
		}
		ret[Q[i][2]] = D.size(u)-1;
	}
	F0R(i, q) cout << ret[i] << "\n";
}	
