#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1000005;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "fenceplan"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct cow{
	int x, y, p;
};

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	vector<pi> a (n);
	forn(i, n){
		cin >> a[i].f >> a[i].s;
	}
	vector<vi> adj (n);
	forn(i, m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<bool> visited (n, 0);
	int maxiX = -INF, miniX = INF, maxiY = -INF, miniY = INF;
	function<void(int)> dfs = [&](int node){
		maxiX = max(maxiX, a[node].f);
		miniX = min(miniX, a[node].f);
		maxiY = max(maxiY, a[node].s);
		miniY = min(miniY, a[node].s);
		visited[node] = 1;
		for(auto u : adj[node]){
			if(!visited[u]) dfs(u);
		}
	};
	int pem = INF;
	forn(i, n){
		if(!visited[i]){
			maxiX = -INF, miniX = INF, maxiY = -INF, miniY = INF;
			dfs(i);
			pem = min(pem, 2*(maxiX-miniX)+2*(maxiY-miniY));
		}
	}
	cout << pem << "\n";
}
