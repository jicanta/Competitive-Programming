#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
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
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "lightson"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

bool on[MX][MX];
bool visited[MX][MX];
bool pup[MX][MX];
int n;
vpi tab[MX][MX];

void dfs(int x, int y){
	visited[x][y] = 1;
	pup[x][y] = 1;
	trav(u, tab[x][y]){
		on[u.f][u.s] = 1;
		if(!visited[u.f][u.s] && pup[u.f][u.s]) dfs(u.f, u.s);
	}
	F0R(k, 4){
		int xx = x+dx[k], yy = y+dy[k];
		if(valid(xx, yy, n, n)) pup[xx][yy] = 1;
		if(valid(xx, yy, n, n) && on[xx][yy] && !visited[xx][yy]) dfs(xx, yy);
	}	
}

int main(){
	NACHO();
	// Basicamente, corres el dfs que harias siempre.
	// Sin embargo, hay que tener en cuenta que tal vez un vecino tuyo esta apagado
	// pero luego de recorrer otro vecino tuyo lo podes encender.
	// Por eso llevas registro de que vecinos viste, para luego ir a ellos si los encendes
	// en algun momento.
	int m;
	cin >> n >> m;
	on[0][0] = 1;
	F0R(i, m){
		int a, b, c, d; cin >> a >> b >> c >> d;
		--a, --b, --c, --d;
		tab[a][b].pb(mp(c, d));
	}
	dfs(0, 0);
	int ret = 0;
	F0R(i, n){
		F0R(j, n) ret += on[i][j];
	}
	cout << ret << "\n";
}
