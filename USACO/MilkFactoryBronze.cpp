#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define trav(a, x) for(auto& a : x)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
#define esta(x,c) ((c).find(x) != (c).end())
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int mod = 998244353;
const int MX = 105; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool valid(T x, T y, T n, T m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
void NACHO(string name = "factory"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vi adj[MX];
bool visited[MX];

void dfs(int node){
	visited[node] = 1;
	trav(v, adj[node]){
		if(!visited[v]){
			dfs(v);
		}
	}
}
 
int main(){
	NACHO();
	int n; cin >> n;
	forn(i, n-1){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
	}
	int ret = -1;
	forn(i, n){
		bool ok = 1;
		forn(j, n){
			forn(k, n) visited[k] = 0;
			dfs(j);
			if(!visited[i]) ok = 0;
		}
		if(ok) ret = i+1;
	}
	cout << ret << "\n";
}
