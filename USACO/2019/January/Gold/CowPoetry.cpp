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
const int MX = 5005;
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
 
void NACHO(string name = "poetry"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(tint _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((tint)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, tint p) { assert(p >= 0); 
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }

pi a[MX];
vi w[MX];
int allW[MX];
tint freq[MX];
mi dp[MX]; // cuantas formas tengo de hacer una linea con i silabas

int main(){
	NACHO();
	// lineas con la misma rima en la string
	// deben terminar si o si con la misma clase.
	// si f(x) es la cantidad de formas de crear una linea
	// que termine en x, para cada rima en la string la cantidad de
	// formas de hacer esto es f(x)^freq(i), donde freq(i)
	// es cuantas veces aparece la rima i en la string.
	// el resultado total es el producto de lo anterior para
	// todas las rimas en la string.
	// f(x) se calcula con dp.
	int n, m, k; cin >> n >> m >> k;
	F0R(i, n){
		int x, y; cin >> x >> y;
		w[y-1].pb(x);
		allW[i] = x;
	}
	F0R(i, m){
		char x; cin >> x;
		++freq[x-'A'];
	}
	dp[0] = 1;
	F0R(j, k+1){
		F0R(i, n){
			if(j+allW[i] <= k) dp[j+allW[i]] += dp[j];
		}
	}
	mi ret = 1;
	F0R(i, 26){
		if(!freq[i]) continue;
		mi act = 0;
		F0R(j, n){
			mi ways = 0; // formas de llenar una linea con 
						   // rima clase j
			trav(u, w[j]){
				ways += dp[k-u];
			}
			act += pow(ways, freq[i]);
		}
		ret *= act;
	}
	cout << (int)ret << "\n";
}
