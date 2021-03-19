#include <bits/stdc++.h>
#include "crocodile.h"
 
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
const int MX = 1e5+5;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vpi adj[MX];
int dist[MX], dist2[MX];
bool vis[MX];
priority_queue<pi, vpi, greater<pi>> q;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
	// la idea es básicamente esta:
	// supongamos que estamos parados en un nodo u
	// sean v1, v2, ... sus vecinos
	// sea D(i) el minimo tiempo que le lleva al nodo i ir a una salida
	// Vamos a hacer un dijkstra comun, en el que D(u) = min(D(u), D(vi)+wi)
	// sin embargo, en el peor caso, el cocodrilo nos cierra esta arista
	// por lo que debemos acceder al segundo mejor costo.
	// es por esto que para cada nodo guardamos la segunda mejor distancia a este nodo
	F0R(i, M){
		int u = R[i][0], v = R[i][1], w = L[i];
		adj[u].pb(mp(v, w)); adj[v].pb(mp(u, w));
	}
	F0R(i, N) dist[i] = inf, dist2[i] = inf;
	F0R(i, K){
		dist[P[i]] = 0; dist2[P[i]] = 0;
		q.push(mp(0, P[i]));
	}
	while(sz(q)){
		int u = q.top().s; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		trav(v, adj[u]){
			if(dist2[u]+v.s < dist[v.f]){
				dist2[v.f] = dist[v.f];
				dist[v.f] = dist2[u]+v.s;
				q.push(mp(dist2[v.f], v.f));
			}else if(dist2[u]+v.s < dist2[v.f]){
				dist2[v.f] = dist2[u]+v.s;
				q.push(mp(dist2[v.f], v.f));
			}
		}
	}
	return dist2[0];
}
