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
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "moop"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct pt{
	int x, y;
	bool operator<(const pt &o)const{
		if(x == o.x) return y < o.y;
		return x < o.x;
	}
};

bool visited[MX];

void dfs(int node, vector<vi> &adj){
	visited[node] = 1;
	for(auto u : adj[node]){
		if(!visited[u]) dfs(u, adj);
	}
}

int main(){
	NACHO();
	//Si lo pensás un toque la respuesta es la cantidad
	//de componentes en el grafo.
	int n; cin >> n;
	vector<pt> a (n);
	forn(i, n) cin >> a[i].x >> a[i].y;
	sort(all(a));
	set<pi> act;
	vector<vi> g (n);
	act.insert(mp(a[0].y, 0));
	forsn(i, 1, n){
		for(auto it = act.begin(); it != act.end(); it++){
			if(it->f <= a[i].y){
				g[i].pb(it->s);
				g[it->s].pb(i);
			}else{
				break;
			}
		}
		act.insert(mp(a[i].y, i));
	}
	int ret = 0;
	forn(i, n){
		if(!visited[i]){
			++ret;
			dfs(i, g);
		}
	}
	cout << ret << "\n";
}
