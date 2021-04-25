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
 
void NACHO(string name = ""){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int a[1000005];
vi A, dp;
 
int main(){
	NACHO();
	F0R(i, 1e6+5) a[i] = -1;
	// los segmentos (l1, r1) y (l2, r2) no se intersecan (asumiendo l1 < l2)
	// si r1 < r2.
	// Sea A un arreglo en el que A[i]=el r de un segmento que tiene l=i.
	// Claramente una increasing subsequence de A cumple que no se intersecan.
	// Lo que nos pide el problema es cubrir A con la menor cantidad posible de
	// increasing subsequences.
	// Esto es equivalente e encontrar el largo de la longest decreasing subsequence.
	int n; cin >> n;
	F0R(i, n){
		int l, r; cin >> l >> r;
		a[l] = r;
	}
	F0R(i, 1e6+5) if(a[i] >= 0) A.pb(a[i]);
	reverse(all(A));
	F0R(i, sz(A)){
		int ind = lower_bound(all(dp), A[i])-dp.begin();
		if(ind == sz(dp)) dp.pb(A[i]);
		else dp[ind] = A[i];
	}
	cout << sz(dp) << "\n";
}

