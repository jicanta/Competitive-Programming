
#include <bits/stdc++.h>

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
 
const int MOD = 1000000; 
const int mod = 998244353;
const int MX = 1005;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;
 
const int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
 
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

string a[MX];
int rockd[MX][MX], dist[MX][MX];
vpi centers[MX];
int n, d;

void bfsRock(){
	bool vis[MX][MX];
	queue<pi> q;
	F0R(i, n){
		F0R(j, n){
			vis[i][j] = 0; 
			if(a[i][j] == '#'){
				vis[i][j] = 1;
				q.push(mp(i, j));
			}
		}
	}
	while(sz(q)){
		auto u = q.front(); q.pop();
		F0R(k, 4){
			int x = u.f+dx[k], y = u.s+dy[k];
			if(valid(x, y, n, n) && !vis[x][y] && a[x][y] != '#'){
				rockd[x][y] = rockd[u.f][u.s]+1;
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
}

void bfsRobot(){
	bool vis[MX][MX];
	queue<pi> q;
	F0R(i, n){
		F0R(j, n){
			vis[i][j] = 0; 
			dist[i][j] = -1;
			if(a[i][j] == 'S'){
				vis[i][j] = 1;
				dist[i][j] = 0;
				q.push(mp(i, j));
			}
		}
	}
	while(sz(q)){
		auto u = q.front(); q.pop();
		int tam = (dist[u.f][u.s])/d;
		a[u.f][u.s] = 'W';
		if(rockd[u.f][u.s] <= tam){
			--dist[u.f][u.s];
			centers[dist[u.f][u.s]/d].pb(mp(u.f, u.s));
			continue;
		}
		centers[dist[u.f][u.s]/d].pb(mp(u.f, u.s));
		F0R(k, 4){
			int x = u.f+dx[k], y = u.s+dy[k];
			if(valid(x, y, n, n) && !vis[x][y] && a[x][y] != '#' && rockd[x][y] > tam){
				dist[x][y] = dist[u.f][u.s]+1;
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
}

int main(){
	NACHO();
	// calculo la distancia de las piedras a cada casilla para saber cuanto se puede expandir un cluster de robots.
	// hago un bfs para calcular que casillas pueden ser centro de un cluster y cual es el tamaño maximo
	// del cluster que son centro.
	// Luego, en centers[i] me guardo aquellas celdas que son centro de un cluster que puede expandirse hasta i de largo.
	// Pinto aquellas celdas que estan a distncia <= i de esos centros.
	// Esto no lo hago tirando un bfs desde cada uno, ya que se va de tiempo.
	// primero agrego los vecinos de aquellos centros que pueden expandirse hasta 500.
	// Luego, agrego los centros de 499, y sigo asi.
	// Tadaa
	cin >> n >> d;
	F0R(i, n) cin >> a[i];
	bfsRock();
	bfsRobot();
	deque<pi> q;
	R0F(expansion, 500){
		vpi toadd;
		F0R(i, sz(q)){
			pi u = q[i];
			a[u.f][u.s] = 'W';
			F0R(k, 4){
				int x = u.f+dx[k], y = u.s+dy[k];
				if(valid(x, y, n, n) && a[x][y] != '#' && a[x][y] != 'W'){
					a[x][y] = 'W';
					toadd.pb(mp(x, y));
				}
			}
		}
		while(sz(q)) q.pop_front();
		trav(u, centers[expansion]){
			q.pb(u);
		}
		trav(u, toadd){
			q.pb(u);
		}
	}
	int ret = 0;
	F0R(i, n){
		//cout << a[i] << endl;
		F0R(j, n){
			if(a[i][j] == 'W') ++ret;
		}
	}
	cout << ret << "\n";
}
