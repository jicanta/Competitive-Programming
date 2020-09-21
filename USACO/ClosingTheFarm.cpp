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
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "closing"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	vector<vi> adj (n);
	forn(i, m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<bool> bad (n, 0);
	int c = 0;
	vector<bool> visited (n, 0);
	function<void(int)> dfs = [&](int node){
		++c;
		visited[node] = 1;
		for(auto u : adj[node]){
			if(!visited[u] && !bad[u] && !bad[node]){
				dfs(u);
			}
		}
	};
	dfs(0);
	if(c != n){
		cout << "NO" << "\n";
	}else cout << "YES" << "\n";
	forn(i, n-1){
		int node; cin >> node;
		bad[node-1] = 1;
		visited.clear();
		visited.rsz(n, 0);
		c = 0;
		int notbad;
		forn(j, n) if(!bad[j]){ notbad = j; break; }
		dfs(notbad);
		if(c == n-i-1){
			cout << "YES" << "\n";
		}else cout << "NO" << "\n";
	}
	int no; cin >> no;
}
