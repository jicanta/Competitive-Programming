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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "lasers"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct cow{
	int x, y, id;
};

vector<cow> pos;
vpi adj[2*MX+5];
int dist[2*MX+5];
deque<int> q;
// 0-n-1 verticales
// n-2*n-1 horizontales

int main(){
    NACHO();
    // modelalo como un grafo.
    // cada nodo lo pensas como dos nodos: voy en vertical u horizontal
    // unis los nodos horizontales con mismo Y y los verticales con mismo X con peso 0
    // unis cada nodo horizontal con su respectivo vertical con peso 1
    // corres bfs 0-1 y ya estas
	int n; cin >> n;
	pos.rsz(n+2);
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	F0R(i, n) cin >> pos[i].x >> pos[i].y, pos[i].id = i;
	pos[n] = {sx, sy, n}; pos[n+1] = {ex, ey, n+1};
	sort(all(pos), [&](const cow &a, const cow &b){
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	F0R(i, n+2){
		adj[pos[i].id].pb(mp(n+2+pos[i].id, 1));
		adj[n+2+pos[i].id].pb(mp(pos[i].id, 1));
	}
	F0R(i, n+1){
		if(pos[i].x == pos[i+1].x){
			adj[pos[i].id].pb(mp(pos[i+1].id, 0));
			adj[pos[i+1].id].pb(mp(pos[i].id, 0));
		}
	}
	sort(all(pos), [&](const cow &a, const cow &b){
		if(a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	});
	F0R(i, n+1){
		if(pos[i].y == pos[i+1].y){
			adj[n+2+pos[i].id].pb(mp(n+2+pos[i+1].id, 0));
			adj[n+2+pos[i+1].id].pb(mp(n+2+pos[i].id, 0));
		}
	}
	F0R(i, n+2){
		dist[i] = inf;
		dist[n+2+i] = inf;
	}
	dist[n] = 0;
	dist[n+2+n] = 0;
	q.pf(n);
	q.pf(n+2+n);
	while(sz(q)){
		auto u = q.front();
		q.pop_front();
		trav(v, adj[u]){
			if(dist[u]+v.s < dist[v.f]){
				dist[v.f] = dist[u]+v.s;
				if(v.s == 0) q.pf(v.f);
				else q.pb(v.f);
			}
		}
	}
	if(min(dist[n+1], dist[n+2+n+1]) == inf) dist[n+1] = -1;
	cout << min(dist[n+1], dist[n+2+n+1]) << "\n";
}


