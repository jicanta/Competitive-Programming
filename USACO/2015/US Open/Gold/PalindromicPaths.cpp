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
 
const int MOD = 1e9+7; 
const tint mod = 998244353;
const int MX = 505;
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
 
void NACHO(string name = "palpath"){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct mi{
	int v; explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(tint _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b){
	if((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi& operator-=(mi &a, mi b){
	if((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b){ return a += b; }
mi operator-(mi a, mi b){ return a -= b; }
mi operator*(mi a, mi b){ return mi((tint)a.v*b.v); }
mi& operator*=(mi &a, mi b){
	return a = a*b;
}

mi dp[MX][MX];
mi DP[MX][MX];
string ta[MX];
 
int main(){
	NACHO();
	// observacion 1: el largo de cualquier string que vaya de (0, 0) a (N-1, N-1)
	// tiene largo impar.
	// observacion 2: el caracter del "medio" de la string
	// cae en la diagonal que va de (0, N-1) a (N-1, 0).
	// a su vez, sea dp(a, r1, r2) la cantidad de palindromos en el tablero
	// con la string de tamaño 2*a+1 cuyo comienzo es la fila r1, fin fila r2
	// y el medio de la string cae en la diagonal de (0, N-1) a (N-1, 0).
	// al saber (a, r1, r2) podemos determinar c1 y c2.
	// c1 = n-a-r1
	// c2 = c1+(2*a+1-(r2-r1+1))
	int n; cin >> n;
	F0R(i, n) cin >> ta[i];
	F0R(i, n){
		DP[i][i] = 1;
	}
	FOR(a, 1, n){
		F0R(r1, n){
			int c1 = n-1-a-r1;
			if(c1 < 0) continue;
			F0R(r2, n){
				if(2*a+1 < r2-r1+1) continue;
				int c2 = c1+(2*a+1-(r2-r1+1));
				if(c2 >= n) continue;
				if(ta[r1][c1] != ta[r2][c2]) continue;
				if(r2-1 >= 0) dp[r1][r2] += DP[r1][r2-1];
				dp[r1][r2] += DP[r1][r2];
				if(r1+1 < n) dp[r1][r2] += DP[r1+1][r2];
				if(r1+1 < n && r2-1 >= 0) dp[r1][r2] += DP[r1+1][r2-1];
			}
		}
		F0R(r1, n){
			F0R(r2, n){
				DP[r1][r2] = dp[r1][r2];
				dp[r1][r2] = 0;
			}
		}
	}
	cout << (int)DP[0][n-1] << "\n";
}

