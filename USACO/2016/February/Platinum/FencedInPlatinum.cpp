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
const int MX = 1005;
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
 
void NACHO(string name = "fencedin"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vl x, y;
vl xdif, ydif;

int main(){
	NACHO();
	// supongamos que tenemos una linea vertical en 1
	// y otra en 2.
	// y que la distancia entre todas las demas lineas consecutivas es mayor 1.
	// entonces, todas las regiones en la columna entre 1 y 2
	// van a ser conectadas con este mismo costo.
	int a, b, n, m; cin >> a >> b >> n >> m;
	x.rsz(n+1); y.rsz(m+1);
	F0R(i, n) cin >> x[i];
	F0R(i, m) cin >> y[i];
	x[n] = a;
	y[m] = b;
	sort(all(x)); sort(all(y));
	xdif.pb(x[0]); ydif.pb(y[0]);
	FOR(i, 1, n+1) xdif.pb(x[i]-x[i-1]);
	FOR(i, 1, m+1) ydif.pb(y[i]-y[i-1]);
	sort(all(xdif)); sort(all(ydif));
	int xi = 1, xj = 1;
	tint ret = xdif[0]*(sz(ydif)-1)+ydif[0]*(sz(xdif)-1);
	while(xi < sz(xdif) && xj < sz(ydif)){
		if(xdif[xi] < ydif[xj]){
			ret += xdif[xi]*(sz(ydif)-xj);
			++xi;
		}else{
			ret += ydif[xj]*(sz(xdif)-xi);
			++xj;
		}
	}
	cout << ret << "\n";
}

