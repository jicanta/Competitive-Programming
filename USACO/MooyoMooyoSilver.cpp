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
 
void NACHO(string name = "mooyomooyo"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

string tab[105];
bool visited[105][15];
int n, k;

void gravity(){
	R0F(i, n-1){
		F0R(j, 10){
			int k = i;
			while(k < n-1 && tab[k+1][j] == '0'){
				tab[k+1][j] = tab[k][j];
				tab[k][j] = '0';
				++k;
			}
		}
	}
}

int cur;
vpi cand;

void dfs(int x, int y){
	visited[x][y] = 1;
	cand.pb(mp(x, y));
	++cur;
	F0R(k, 4){
		int xx = x+dx[k], yy = y+dy[k];
		if(valid(xx, yy, n, 10) && tab[xx][yy] == tab[x][y] && !visited[xx][yy]){
			dfs(xx, yy);
		}
	}
}

int main(){
	NACHO();
	// la funcion gravity simula la gravedad
	// luego, es ir borrando las componentes
	// de tamaño mayor a k
	// pero tener cuidado de no haver gravity ni bien
	// borras una, ya que el enunciado dice
	// "If multiple such connected regions exist at the same time, they all disappear simultaneously"
	cin >> n >> k;
	F0R(i, n){
		cin >> tab[i];
	}
	gravity();
	while(1){
		bool ok = 0;
		F0R(i, n) F0R(j, 10) visited[i][j] = 0;
		F0R(i, n){
			F0R(j, 10){
				if(!visited[i][j] && tab[i][j] != '0'){
					cur = 0;
					cand.clear();
					dfs(i, j);
					if(cur >= k){
						ok = 1;
						trav(u, cand){
							tab[u.f][u.s] = '0';
						}
					}
				}
			}
		}
		gravity();
		if(!ok) break;
	}
	F0R(i, n){
		cout << tab[i] << "\n";
	}
}

