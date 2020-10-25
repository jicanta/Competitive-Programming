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
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 2e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "moocast"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

tint dist(const pi &a, const pi &b){
	return abs(a.f-b.f)*abs(a.f-b.f)+abs(a.s-b.s)*abs(a.s-b.s);
}

void dfs(int node, vector<vi> &adj, vector<bool> &visited){
	visited[node] = 1;
	for(auto u : adj[node]){
		if(!visited[u]) dfs(u, adj, visited);
	}
}

int main(){
	NACHO();
	int n; cin >> n;
	vector<pi> a (n);
	forn(i, n) cin >> a[i].f >> a[i].s;
	int low = 0, high = 625000000;
	while(high-low > 1){
		int mid = low+(high-low)/2;
		vector<vi> g (n);
		vector<bool> visited (n, 0);
		forn(i, n){
			forsn(j, i+1, n){
				if(dist(a[i], a[j]) <= mid) g[i].pb(j), g[j].pb(i);
			}
		}
		bool ok = 1;
		dfs(0, g, visited);
		forn(i, n){
			if(!visited[i]) ok = 0;
		}
		if(ok) high = mid;
		else low = mid;
	} 
	cout << high << "\n";
}
