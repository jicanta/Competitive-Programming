#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
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
 
void NACHO(string name = "mootube"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n, q;
	cin >> n >> q;
	vector<vector<pi>> adj (n);
	forn(i, n-1){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	vector<bool> visited (n, 0);
	vector<vi> ret (n, vi (n, 0));
	function<void(int, int, int)> dfs = [&](int node, int curmin, int cur){
		visited[node] = 1;
		for(auto u : adj[node]){
			if(!visited[u.f]){
				int mini = min(curmin, u.s);
				ret[cur][u.f] = mini;
				dfs(u.f, mini, cur);
			}
		}
	};
	forn(i, n){
		visited.clear();
		visited.rsz(n, 0);
		dfs(i, INF, i);
	}
	forn(i, q){
		int k, v;
		cin >> k >> v;
		--v;
		int ans = 0;
		forn(j, n){
			ans+=(ret[v][j] >= k);
		}
		cout << ans << "\n";
	}
}
