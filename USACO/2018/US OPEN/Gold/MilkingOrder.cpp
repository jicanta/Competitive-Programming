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
 
void NACHO(string name = "milkorder"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi ob[MX];
vi adj[2*MX];
int vis[2*MX], deg[MX];
vi ord;
bool ok;

void dfs(int node){
	vis[node] = 1;
	trav(u, adj[node]){
		if(vis[u] == 1) ok = 0;
		else if(vis[u] == 0) dfs(u);
	}
	vis[node] = 2;
}

int main(){
    NACHO();
	int n, m; cin >> n >> m;
	F0R(i, m){
		int k; cin >> k;
		F0R(j, k){
			int x; cin >> x;
			--x;
			ob[i].pb(x);
		}
	}
	int low = 0, high = m;
	while(high-low > 1){
		int mid = low+(high-low)/2;
		ok = 1;
		F0R(i, 2*MX) adj[i].clear(), vis[i] = 0;
		F0R(i, mid+1){
			F0R(j, sz(ob[i])-1){
				adj[ob[i][j]].pb(ob[i][j+1]);
			}
		}
		F0R(i, n){
			if(!vis[i]) dfs(i);
		}
		if(ok) low = mid;
		else high = mid;
	}
	priority_queue<int, vi, greater<int>> q;
	F0R(i, 2*MX) adj[i].clear(), vis[i] = 0;
	F0R(i, low+1){
		F0R(j, sz(ob[i])-1){
			adj[ob[i][j]].pb(ob[i][j+1]);
			++deg[ob[i][j+1]];
		}
	}
	F0R(i, n) if(deg[i] == 0) q.push(i);
	while(sz(q)){
		auto u = q.top(); q.pop();
		ord.pb(u);
		trav(v, adj[u]){
			if(--deg[v] == 0) q.push(v);
		}
	}
	F0R(i, sz(ord)){
		cout << (i > 0 ? " " : "") << ord[i]+1;
	}
}
