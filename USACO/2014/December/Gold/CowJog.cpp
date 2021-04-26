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
const int MX = 1e5+5;
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
 
void NACHO(string name = "cowjog"){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

tint a[MX];
vl dp;
 
int main(){
	NACHO();
	// dos vacas tienen que ir en dos lanes distintos
	// si una de ellas comienza antes que la otra  pero termina mas adelante.
	// es decir (l1, r1) y (l2, r2) van en un mismo lane (asumiendo que l1 < l2)
	// si r1 < r2.
	// ahora es casi identico a PCB BOI 2010.
	// A[i] me dice el r de un segmento con l=i. Quiero encontrar 
	// el minimo numero de increasing subsequences que me cubran A.
	// Esto es equivalente a la longest decreasing subsequence.
	int n, t; cin >> n >> t;
	F0R(i, n){
		tint x, v; cin >> x >> v;
		a[i] = x+v*t;
	}
	R0F(i, n){
		int ind = upper_bound(all(dp), a[i])-dp.begin();
		if(ind == sz(dp)) dp.pb(a[i]);
		else dp[ind] = a[i];
	}
	cout << sz(dp) << "\n";
}

