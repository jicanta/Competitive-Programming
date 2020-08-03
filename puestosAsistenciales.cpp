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
const int MX = 3e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "puesto"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vector<pi> adj[MX];
vi dist1 (MX, 0);
vi dist2 (MX, 0);
vi good (MX, 0);

void dfs(int node, int pa, bool ok){
	for(auto u : adj[node]){
		if(u.f != pa){
			if(ok) dist1[u.f] = dist1[node]+u.s;
			else dist2[u.f] = dist2[node]+u.s;
			dfs(u.f, node, ok);
		}
	}
}

vi vengo (MX, -1);

void path(int node, int pa){
	for(auto u : adj[node]){
		if(u.f != pa){
			vengo[u.f] = node;
			path(u.f, node);
		}
	}
}

int main(){
    NACHO();
    int n; cin >> n;
    vector<pi> edges (n);
    forn(i, n){
		int u, v, w; cin >> u >> v >> w;
		--u; --v;
		edges[i] = mp(u,v);
		good[u] = good[v] = 1;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	dfs(0, -1, 1);
	int maxi = 0, node1;
	forn(i, MX){
		if(dist1[i] > maxi){
			maxi = dist1[i];
			node1 = i;
		}
	}
	dfs(node1, -1, 0);
	maxi = 0;
	int node2;
	forn(i, MX){
		if(dist2[i] > maxi){
			maxi = dist2[i];
			node2 = i;
		}
	}
	path(node1, -1);
	int st = node2;
	vi chemin;
	while(st != -1){
		chemin.pb(st);
		st = vengo[st];
	}
	reverse(all(chemin));
	int puesto1, puesto2;
	dist1.clear();
	dist1.rsz(MX, 0);
	dfs(node1, -1, 1);
	bool uno = 0;
	forn(i, sz(chemin)){
		if(maxi % 2 == 0 && dist1[chemin[i]] == maxi/2){
			puesto1 = chemin[i];
			uno = 1;
			continue;
		}
		if(dist1[chemin[i]] <= maxi/2) puesto1 = chemin[i];
		else {puesto2 = chemin[i]; break;}
	}
	string ret = "";
	dist1.clear();
	dist1.rsz(MX, 0);
	dfs(puesto1, -1, 1);
	forn(i, n){
		int u = edges[i].f, v = edges[i].s;
		if(uno){
			if(dist1[u] < dist1[v]) ret+='-';
			else ret+='+';
		}else{
			if((u == puesto1 && v == puesto2) || (u == puesto2 && v == puesto1)) ret+='0';
			else if(dist1[u] < dist1[v]) ret+='-';
			else ret+='+';
		}
	} 
	cout << fixed << setprecision(1) << double(maxi)/2.0 << "\n";
	cout << ret << "\n";
}



