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
 
void NACHO(string name = "dining"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vpi adj[MX];
int distN[MX], distY[MX];
bool vis[MX];

int main(){
    NACHO();
	int n, m, k; cin >> n >> m >> k;
	F0R(i, m){
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	priority_queue<pi, vpi, greater<pi>> q;
	F0R(i, n) distN[i] = inf;
	q.push(mp(0, n-1));
	distN[n-1] = 0;
	while(sz(q)){
		auto u = q.top().s; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		trav(v, adj[u]){
			if(distN[u]+v.s < distN[v.f]){
				distN[v.f] = distN[u]+v.s;
				q.push(mp(distN[v.f], v.f));
			}
		}
	}
	F0R(i, n) vis[i] = 0;
	F0R(i, n) distY[i] = inf;
	F0R(i, k){
		int x, v;
		cin >> x >> v;
		--x;
		distY[x] = distN[x]-v;
		q.push(mp(distN[x]-v, x));
	}
	while(sz(q)){
		auto u = q.top().s; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		trav(v, adj[u]){
			if(distY[u]+v.s < distY[v.f]){
				distY[v.f] = distY[u]+v.s;
				q.push(mp(distY[v.f], v.f));
			}
		}
	}
	F0R(i, n-1){
		if(distY[i] <= distN[i]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}
