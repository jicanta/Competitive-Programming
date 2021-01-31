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
const int MX = 1e5+5;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
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
 
void NACHO(string name = "atlarge"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi adj[MX];
int dist[MX];
int distL[MX];
vi le;
int ret = 0;

void dfs(int node, int p){
	trav(u, adj[node]){
		if(u != p){
			dist[u] = dist[node]+1;
			dfs(u, node);
		}
	}
}

void sfd(int node, int pa, bool ok){
	bool act = ok;
	if(dist[node] >= distL[node] && ok){
		++ret; 
		act = 0;
	}
	trav(u, adj[node]){
		if(u != pa) sfd(u, node, act);
	}
}

int main(){
    NACHO();
    // supongamos que estamos en un nodo tal que la distancia minima de
    // alguna hoja a este nodo es menor o igual
    // que la distancia de la rziz a este nodo.
    // en otras palabras, un nodo que puede ser bloqueado con una sola vaca guardia.
    // este nodo si o si debe ser bloqueado, ya que sino Bessie escapa.
    // la respuesta es el numero de nodos que cumplen con la condicion susodicha.
    // para no contar de mas, si hay un nodo que cumple eso, todos los nodos en su subarbol lo cumpliran
    // pero no debemos contarlos.
	int n, k; cin >> n >> k;
	F0R(i, n-1){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	F0R(i, n) if(sz(adj[i]) == 1) le.pb(i);
	dfs(k-1, -1);
	F0R(i, n) distL[i] = inf;
	queue<int> q;
	F0R(i, sz(le)){
		q.push(le[i]);
		distL[le[i]] = 0;
	}
	while(sz(q)){
		auto u = q.front();
		q.pop();
		trav(v, adj[u]){
			if(distL[v] == inf){
				distL[v] = distL[u]+1;
				q.push(v);
			}
		}
	}
	sfd(k-1, -1, 1);
	cout << ret << "\n";
}


