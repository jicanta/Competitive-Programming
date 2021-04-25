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
const int MX = 4005; 
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
 
void NACHO(string name = ""){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
 
string tab[MX];
bool visited[MX][MX];
int dist[MX][MX];
 
int main(){
	NACHO();
	// consideramos el grafo con una arista entre todo par de de celdas
	// adyacentes huellas, donde el costo de la arista es 1 si la huella es
	// distinta y es 0 si es la misma huella.
	// La respuesta es entonces el longest shortest-path desde la celda (0, 0).
	int n, m; cin >> n >> m;
	F0R(i, n) cin >> tab[i];
	visited[0][0] = 1;
	dist[0][0] = 1;
	deque<pi> q;
	q.pf(mp(0, 0));
	int ret = 0;
	while(sz(q)){
		auto u = q.front();
		q.pop_front();
		int x = u.f, y = u.s;
		ret = max(ret, dist[x][y]);
		F0R(k, 4){
			int xx = x+dx[k], yy = y+dy[k];
			if(valid(xx, yy, n, m) && !visited[xx][yy] && tab[xx][yy] != '.'){
				int w = (tab[x][y] != tab[xx][yy] ? 1 : 0);
				visited[xx][yy] = 1;
				dist[xx][yy] = dist[x][y]+w;
				if(w == 0){
					q.pf(mp(xx, yy));
				}else q.pb(mp(xx, yy));
			} 
		}
	}
	cout << ret << "\n";
}
