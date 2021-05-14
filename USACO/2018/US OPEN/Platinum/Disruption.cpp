#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
const int MX = 50005;
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
 
void NACHO(string name = "disrupt"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vi adj[MX];
set<pi> s[MX];
int depth[MX];
vpi out[MX];
pi edges[MX];
int ret[MX];

void dfs(int node, int pa){
	trav(u, adj[node]){
		if(u != pa){
			depth[u] = depth[node]+1;
			dfs(u, node);
			if(sz(s[node]) < sz(s[u])) swap(s[node], s[u]);
			trav(v, s[u]){
				if(s[node].count(mp(v.f, v.s))) s[node].erase(mp(v.f, v.s));
				else s[node].ins(mp(v.f, v.s));
			}
			s[u].clear();
		}
	}
	trav(u, out[node]){
		if(s[node].count(mp(u.s, u.f))) s[node].erase(mp(u.s, u.f));
		else s[node].ins(mp(u.s, u.f));
	}
	ret[node] = (sz(s[node]) ? s[node].begin()->f : -1);
}

int main(){
	NACHO();
	// llamo arista extra a las aristas adicionales que tienen un costo.
	// estas aristas pueden salvar a todas las aristas que esten en el camino
	// del arbol original entre sus dos extremos.
	// Lo que hago es guardarme para cada nodo un set de aristas vivas,
	// esto es un set con aristas que puedo usar. Si algun nodo
	// tiene dos aristas vivas iguales, las borro a las dos, ya que quiere decir que ambos nodos
	// estan abajo mio, por lo que no podre usarlos. 
	// Dicho en otras palabras, para cada nodo nos guardamos
	// el conjunto de aristas que podemos usar para ir mas arriba.
	// Por eso la respuesta final de una arista es la respuesta del nodo mas abajo.
	int n, m; cin >> n >> m;
	F0R(i, n-1){
		int u, v; cin >> u >> v;
		--u, --v;
		edges[i] = mp(u, v);
		ret[i] = inf;
		adj[u].pb(v); adj[v].pb(u);
	}
	F0R(i, m){
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		out[a].pb(mp(i, c));
		out[b].pb(mp(i, c));
	}
	dfs(0, -1);
	F0R(i, n-1){
		int a = edges[i].f, b = edges[i].s;
		if(depth[a] > depth[b]) cout << ret[a] << "\n";
		else cout << ret[b] << "\n";
	}
}

