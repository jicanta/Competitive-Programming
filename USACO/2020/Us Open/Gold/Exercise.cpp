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
const int MX = 10005;
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
 
void NACHO(string name = "exercise"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int M;

struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(tint _v):v(_v%M) { v += (v<0)*M; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= M) a.v -= M; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += M; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((tint)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, tint p) { assert(p >= 0); 
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,M-2); }
mi operator/(mi a, mi b) { return a*inv(b); }

vi primes;
bool vis[MX];
mi dp[1234][MX]; // suma de los k posibles si tengo
				 // suma de factores primos j
				 // y miro hasta el i primo

int main(){
	NACHO();
	// sea n el menor número tq existe una permutacion
	// de tamaño n con "order" k = p1^e1*p2^e2*...*pn^en (factorización en primos)
	// n = p1^e1+p2^e2+p3^e3+...+pn^en ya que queremos que los ciclos sean coprimos
	// y lo mas chicos posibles (si tuvieramos un ciclo de tamaño ab nos conviene tener uno de a y uno de b, ya que a+b < ab)
	// entonces lo que queremos es encontrar todos lo k tal que su respectivo n es <= N.
	// (ya que si la suma de los ciclos es menor, podemos rellenar con ciclos de tamaño 1).
	// lo podemos hacer con knapsack dp
	int n; cin >> n >> M;
	FOR(i, 2, n+1){
		if(!vis[i]){
			primes.pb(i);
			for(int j = i; j <= n; j += i){
				vis[j] = 1;
			}
		}
	}
	F0R(i, n+1){
		dp[0][i] = 1;
	}
	FOR(i, 1, sz(primes)+1){
		F0R(j, n+1){
			dp[i][j] += dp[i-1][j];
			int p = primes[i-1];
			while(p <= j){
				dp[i][j] += p*dp[i-1][j-p];
				p *= primes[i-1];
			}
		}
	}
	cout << (int)dp[sz(primes)][n] << "\n";
}

