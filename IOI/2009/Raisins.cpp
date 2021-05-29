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
const int MX = 55;
const tint INF = 1e18; 
const int inf = 2e8;
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

int a[MX][MX];
int dp[MX][MX][MX][MX];
int S[MX][MX];

int sum(int a, int b, int c, int d){
	return S[c][d]-S[c][b-1]-S[a-1][d]+S[a-1][b-1];
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	F0R(i, n) F0R(j, m) cin >> a[i][j];
	FOR(i, 1, n+1){
		FOR(j, 1, m+1){
			S[i][j] += S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i-1][j-1];
		}
	}
	F0R(i, n+1) F0R(j, m+1) dp[i][j][i][j] = 0;
	ROF(i, 1, n+1){
		ROF(j, 1, m+1){
			FOR(k, i, n+1){
				FOR(l, j, m+1){
					int s = sum(i, j, k, l);
					if(k == i && l == j) continue;
					dp[i][j][k][l] = inf;
					FOR(cut, i, k){
						ckmin(dp[i][j][k][l], dp[i][j][cut][l]+dp[cut+1][j][k][l]+s);
					}
					FOR(cut, j, l){
						ckmin(dp[i][j][k][l], dp[i][j][k][cut]+dp[i][cut+1][k][l]+s);
					}
				}
			}
		}
	}
	cout << dp[1][1][n][m] << "\n";
}

