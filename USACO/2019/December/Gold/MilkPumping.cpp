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
const int MX = 1005;
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
 
void NACHO(string name = "pump"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct Node{
	int v, w, f;
	bool operator<(const Node &o)const{ return w > o.w; }
};

vector<Node> adj[MX];
int dist[MX][MX];
bool vis[MX][MX];

int main(){
    NACHO();
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v, w, f;
		cin >> u >> v >> w >> f;
		--u, --v;
		adj[u].pb({v, w, f});
		adj[v].pb({u, w, f});
	}
	priority_queue<Node> q;
	F0R(i, n) F0R(j, MX) dist[i][j] = inf;
	dist[0][MX-1] = 0;
	q.push({0, 0, MX-1});
	int ret = -inf;
	while(sz(q)){
		auto u = q.top().v;
		int f = q.top().f;
		q.pop();
		if(u == n-1){
			ckmax(ret, 1000000*f/dist[n-1][f]);
		}
		if(vis[u][f]) continue;
		vis[u][f] = 1;
		trav(v, adj[u]){
			int F = min(f, v.f);
			if(dist[u][f]+v.w < dist[v.v][F]){
				dist[v.v][F] = dist[u][f]+v.w;
				q.push({v.v, dist[v.v][F], F});
			}
		}
	}
	cout << ret << "\n";
}


