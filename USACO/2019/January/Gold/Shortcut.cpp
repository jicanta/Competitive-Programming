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
const int MX = 10010;
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
 
void NACHO(string name = "shortcut"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vpl adj[MX];
vi tree[MX];
tint tot[MX];
tint distIni[MX];
tint pass[MX];
bool vis[MX];
tint pa[MX];

void dfs(int node, int pa){
	pass[node] = tot[node];
	trav(u, tree[node]){
		if(u != pa){
			dfs(u, node);
			pass[node] += pass[u];
		}
	}
}

int main(){
    NACHO();
	int n, m, t; cin >> n >> m >> t;
	F0R(i, n) cin >> tot[i];
	F0R(i, m){
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	priority_queue<pi, vpi, greater<pi>> q;
	F0R(i, n) distIni[i] = INF, pa[i] = INF;
	distIni[0] = 0LL;
	q.push({0, 0});
	while(sz(q)){
		auto u = q.top().s; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		trav(v, adj[u]){
			if(distIni[u]+v.s < distIni[v.f]){
				pa[v.f] = u;
				distIni[v.f] = distIni[u]+v.s;
				q.push({distIni[v.f], v.f});
			}else if(distIni[u]+v.s == distIni[v.f] && u < pa[v.f]){
				pa[v.f] = u;
			}
		}
	}
	FOR(i, 1, n){
		tree[pa[i]].pb(i);
		tree[i].pb(pa[i]);
	}
	dfs(0, -1);
	tint ret = 0;
	F0R(i, n){
		ckmax(ret, pass[i]*(distIni[i]-t));
	}
	cout << ret << "\n";
}