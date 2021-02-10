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
 
tint cdiv(tint a, tint b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
tint fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "clocktree"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi adj[MX];
int dp[MX];
int num[MX];
int orig[MX];

int modi(int a){
	return (a % 12 == 0 ? 12 : a % 12);
}

void dfs(int node, int pa){
	trav(u, adj[node]){
		if(u != pa){
			dfs(u, node);
			dp[node] += dp[u];
			dp[node] += (12-num[u]);
			num[node] = modi(num[node]+12-num[u]);
			num[u] = 12;
		}
	}
}

int main(){
	NACHO();
	// la clave es pensar en las hojas.
	// la unica forma de llevarlas a 12
	// es ir desde el padre hasta esta tantas veces como lo
	// necesites.
	// luego haces dp.
	int n; cin >> n;
	F0R(i, n) cin >> num[i], orig[i] = num[i];
	F0R(i, n-1){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v); adj[v].pb(u);
	}
	int ret = 0;
	F0R(i, n){
		F0R(j, n) num[j] = orig[j], dp[j] = 0;
		dfs(i, -1);
		if(num[i] == 12 || num[i] == 1) ++ret;
	}
	cout << ret << "\n";
}


