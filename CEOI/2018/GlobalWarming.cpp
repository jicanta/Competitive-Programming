#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
const int mod = 998244353;
const int MX = 2e5+5;
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

vi dp;
int L[MX], a[MX];

int main(){
	NACHO();
	// primero, vemos que siempre te conviene restarle a un prefijo.
	// Luego, sea L_i la LIS que termina en i, y R_i la LIS que comienza en i
	// si le reste al prefijo [1;i]. La respuesta es max(L_i+R_i-1)
	// Calcular L_i es trivial.
	// Para calcular R_i, voy de atrás para adelante.
	// Si x = 5
	// 10 8 9 10 2
	// 5 8 9 10 2
	// para poder correr el algoritmo de LIS, en vez de meter a[i] meto -a[i].
	// -2 
	// -10
	// -10 -9 -8
	int n, d; cin >> n >> d;
	F0R(i, n){
		int x; cin >> x;
		a[i] = x;
		auto ind = lower_bound(all(dp), x)-dp.begin();
		if(ind == sz(dp)) dp.pb(x);
		else dp[ind] = x;
		L[i] = ind+1;
	}
	int ret = sz(dp);
	dp.clear();
	R0F(i, n){
		int R = lower_bound(all(dp), -a[i]+d)-dp.begin();
		ckmax(ret, L[i]+R);
		int ind = lower_bound(all(dp), -a[i])-dp.begin();
		if(ind == sz(dp)) dp.pb(-a[i]);
		else dp[ind] = -a[i];
	}
	cout << ret << "\n";
}

