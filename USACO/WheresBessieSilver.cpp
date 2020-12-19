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
const int MX = 25; 
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
 
void NACHO(string name = "where"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n;
string tab[MX];
bool visited[MX][MX];

void dfs(int x, int y, int u, int d, int l, int r){
	visited[x][y] = 1;
	F0R(k, 4){
		int xx = x+dx[k], yy = y+dy[k];
		if(u <= xx && xx <= d && l <= yy && yy <= r && tab[xx][yy] == tab[x][y] && !visited[xx][yy]){
			dfs(xx, yy, u, d, l, r);
		}
	}
}

int main(){
	NACHO();
	// haces una busqueda exhaustiva
	// vas por las O(n^4) formas de elegir un subatblero
	// te fijas con floodfill si el subtablero cumple
	// lo del enunciado.
	// luego haces un chequeo final para ver cuales
	// estan totalmente cobtenidos en otro.
	cin >> n;
	F0R(i, n) cin >> tab[i];
	int ret = 0;
	vector<pair<pi, pi>> can;
	F0R(u, n){
		FOR(d, u, n){
			F0R(l, n){
				FOR(r, l, n){
					F0R(i, n) F0R(j, n) visited[i][j] = 0;
					vi c (26, 0);
					FOR(i, u, d+1){
						FOR(j, l, r+1){
							if(!visited[i][j]){
								dfs(i, j, u, d, l, r);
								++c[tab[i][j]-'A'];
							}
						}
					}
					int q = 0;
					bool two = 0;
					bool one = 0;
					F0R(i, 26){
						if(c[i] > 0) ++q;
						if(c[i] >= 2) two = 1;
						if(c[i] == 1) one = 1;
					}
					if(two && one && q == 2){
						can.pb(mp(mp(u, d), mp(l, r)));
					}
				}	
			}
		}
	}
	F0R(i, sz(can)){
		int U = can[i].f.f, D = can[i].f.s, L = can[i].s.f, R = can[i].s.s;
		bool ok = 1;
		F0R(j, sz(can)){
			if(i == j) continue;
			int u = can[j].f.f, d = can[j].f.s, l = can[j].s.f, r = can[j].s.s;
			if(u <= U && U <= d && u <= D && D <= d && l <= L && L <= r && l <= R && R <= r) ok = 0;
		}
		ret += ok;
	}
	cout << ret << "\n";
}


