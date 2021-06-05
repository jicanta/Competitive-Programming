#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
const int mod = 998244353;
const int MX = 55;
const tint INF = 1e18; 
const int inf = 2e8;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct DSU{
	vi e; void init(int N) { e = vi(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool unite(int x, int y){
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return 1;
	} 
};

int main(){
	NACHO();
	// si solo me falta conocer un elemento de una fila, puedo conocer ese elemento.
	// consideremos el grafo G en el que hay una arista de peso B[i][j]
	// entre (i, j) si A[i][j] = -1.
	// Que ocurre si en este grafo hay un ciclo?
	// no podemos determinar los valores de estos elementos.
	// la intuicion es que si tenemos un arbol (que es aciclico)
	// si vamos borrando las hojas, podemos reconstruir la respuesta.
	// por lo tanto, si hay un ciclo, debemos "romper" una arista (es decir, descubir un numero).
	// nos conviene romper las aristas con costo minimo.
	// esto es equivalente a encontrar el maximum spanning tree.
	// la respuesta es entonces la suma de aristas totales-maxST
	int tc; cin >> tc;
	int c = 1;
	while(tc--){
		int n; cin >> n;
		vvi a (n, vi (n)), b (n, vi (n));
		F0R(i, n) F0R(j, n) cin >> a[i][j];
		F0R(i, n) F0R(j, n) cin >> b[i][j];
		int x;
		F0R(i, n) cin >> x;
		F0R(i, n) cin >> x;
		vector<pair<int, pi>> ed;
		DSU D; D.init(2*n+5);
		int tot = 0;
		F0R(i, n){
			F0R(j, n){
				if(a[i][j] == -1){
					ed.pb(mp(b[i][j], mp(i, n+j)));
					tot += b[i][j];
				}
			}
		}
		sort(rall(ed));
		int max_spanning_tree = 0;
		trav(x, ed){
			int u = x.s.f, v = x.s.s, w = x.f;
			if(D.unite(u, v)) max_spanning_tree += w;
		}
		cout << "Case #" << c++ << ": " << tot-max_spanning_tree << "\n"; 
	}
}


