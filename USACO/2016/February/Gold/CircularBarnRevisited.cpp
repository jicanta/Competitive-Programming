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
 
const int MOD = 1000000; 
const int mod = 998244353;
const int MX = 105;
const int MXK = 10;
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
 
void NACHO(string name = "cbarn2"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

tint dp[MX][MXK];

int main(){
	NACHO();
	// trabajar con rondas es dificil. Pensemos el problema en un array.
	// sea dp(i, j) la minima distancia total si vimos hasta el i y abrimos j puertas, y asumo que la i es la ultima
	// las transiciones son dp(i, j) = min(dp(k, j-1)+r[k]*(k-i)) para todo k > i
	// sin embargo, hay que arreglar el tema de que sea una ronda.
	// para ello, podemos probar todas las rotaciones del array.
	// la complejidad queda entonces O(n^3*k)
	int n, K; cin >> n >> K;
	vl a (n);
	F0R(i, n) cin >> a[i];
	tint ret = INF;
	F0R(start, n+1){
		//F0R(i, n) cout << a[i] << " ";
		//cout << endl;
		F0R(i, n) F0R(j, K+1) dp[i][j] = INF;
		dp[n][0] = 0;
		FOR(j, 1, K+1){
			F0R(i, n){
				tint cur = 0;
				for(int k = i+1; k < n; ++k){
					cur += a[k]*(k-i);
					ckmin(dp[i][j], dp[k+1][j-1]+cur);
				}
			}
		}
		ckmin(ret, dp[0][K]);
		rotate(a.begin(), a.begin()+1, a.end());
	}
	cout << ret << "\n";
}
/*
1 2 3
2 3 1
3 2 1
*/


