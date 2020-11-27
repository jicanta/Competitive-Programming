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
 
 bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "revegetate"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vector<pi> adj[MX];
bool visited[MX];
int col[MX];
bool ok = 1;

void dfs(int node){
	visited[node] = 1;
	trav(u, adj[node]){
		if(!visited[u.f]){
			if(u.s == 0) col[u.f] = col[node];
			else col[u.f] = 1-col[node];
			dfs(u.f);
		}else{
			if(u.s == 0 && col[u.f] != col[node]) ok = 0;
			if(u.s == 1 && col[u.f] == col[node]) ok = 0;
		}
	}
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	forn(i, m){
		char a; int u, v;
		cin >> a >> u >> v;
		--u, --v;
		if(a == 'S'){
			adj[u].pb(mp(v, 0));
			adj[v].pb(mp(u, 0));
		}else{
			adj[u].pb(mp(v, 1));
			adj[v].pb(mp(u, 1));
		}
	}
	int pos = 0;
	forn(i, n){
		if(!visited[i]){
			//col[i] = 1;
			dfs(i);
			++pos;
		}
	}
	if(!ok){
		cout << 0 << "\n";
		return 0;
	}
	cout << 1;
	forn(i, pos) cout << 0;
	cout << "\n";
}
//OVERFLOW!!!!!
//grafo no conexo?!
