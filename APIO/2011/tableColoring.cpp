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
const int MX = 2e5+5;
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

vpi adj[MX];
int col[MX];
bool vis[MX];
bool ok = 1;

void dfs(int node){
	vis[node] = 1;
	trav(u, adj[node]){
		if(vis[u.f]){
			if(u.s == 0) { if(col[node] == col[u.f]) ok = 0; }
			else if(col[node] != col[u.f]) ok = 0;
		}else{
			if(u.s == 0) col[u.f] = 1-col[node];
			else col[u.f] = col[node];
			dfs(u.f);
		}
	}
}

int main(){
	NACHO();
	// si conocemos tres celdas de un tablero de 2x2,
	// ya sabemos cual debe ser la cuarta.
	// si la cantidad de B's es par, la cuarta debe ser una B.
	// sino, una R.
	// por ello, podemos definir la recurrencia c(x, y) (donde c(x, y) = 1 si la celda (x, y) es azul y 0 si es roja):
	// c(x, y) = not (c(x-1, y) xor c(x, y-1) xor c(x-1, y-1))
	// A su vez, no es dificil ver que la primer fila y la primer columna
	// te determinan automaticamente todo el tablero
	// (para ver esto, jugue mucho con excel)
	// en particular, c(x, y) = not (c(0, 0) xor c(0, y) xor c(x, 0) xor (x*y) mod 2)
	// es decir, las celdas de la primer fila y de la primer columna son en principio independientes
	// por ello, si el tablero es vacio, tenemos 2^(n+m-1) formas de llenarlo.
	// sin embargo, cuando nos dan el color de una celda que no pertenece a la primer fila o primer columna,
	// estas celdas comienzan a ser dependientes.
	// vamos a modelar el problema como un grafo, en el que las celdas (0, y) y (x, 0) son nodos.
	// y para cada celda coloreada (x, y) mando una arista entre (0, y) y (x, 0).
	// veamos algunas cosas:
	// si la celda (x, y) es roja:
	// si x e y son pares, (x, 0) y (0, y) tienen el mismo color.
	// si al menos uno de x, y son impares, (x, 0) y (0, y) tienen colores distintos.
	// si la celda (x, y) es azul:
	// si son ambos pares, (x, 0) y (0, y) tienen colores distintos.
	// sino, tienen el mismo color.
	// ahora, solo nos interesa cuando tienen color distinto.
	// si el color de (0, y) y (x, 0) es distinto, mando una arista entre estos nodos.
	// como el grafo debe ser bipartito, hay dos formas de llenarlo.
	// por lo tanto, la respuesta es 2^(cantidad de componentes-1).
	// si alguna componente no es bipartita, la respuesta es 0.
	// nota: en realidad, no es bipartito, simplemente es colorear el grafo
	// segun informacion de las aristas.
	// 
	int n, m, k; cin >> n >> m >> k;
	F0R(i, k){
		int x, y, c; cin >> x >> y >> c;
		if(c == 1){
			if((x & 1) || (y & 1)){
				adj[x].pb(mp(n+y, 0));
				adj[n+y].pb(mp(x, 0));
			}else{
				adj[x].pb(mp(n+y, 1));
				adj[n+y].pb(mp(x, 1));
			}
		}else{
			if(x % 2 == 0 && y % 2 == 0){
				adj[x].pb(mp(n+y, 0));
				adj[n+y].pb(mp(x, 0));
			}else{
				adj[x].pb(mp(n+y, 1));
				adj[n+y].pb(mp(x, 1));
			}
		}
	}
	int tot = 0;
	FOR(i, 1, n+m+1){
		if(!vis[i]) ++tot, dfs(i);
	}
	if(!ok) cout << 0 << "\n";
	else{
		int ret = 1;
		F0R(i, tot-1) ret = (ret*2)%1000000000;
		cout << ret << "\n";
	}
}


