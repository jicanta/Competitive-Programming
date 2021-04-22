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
const int MX = 4005;
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

int a[MX][MX];
int dp[MX][MX], dp2[MX][MX];
pi owo[MX], uwu[MX];
 
int main(){
	NACHO();
	int n, m, k; cin >> n >> m >> k;
	F0R(i, n) F0R(j, m) a[i][j] = 1, owo[i] = mp(-1, -1), uwu[j] = mp(-1, -1);
	F0R(i, k){
		int x, y; cin >> x >> y;
		a[x-1][y-1] = 0;
	}
	F0R(i, m) dp[0][i] = a[0][i];
	F0R(i, n) dp[i][0] = a[i][0];
	FOR(i, 1, n){
		FOR(j, 1, m){
			if(a[i][j] == 1){
				dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
			}else dp[i][j] = 0;
		}
	}
	F0R(i, n) F0R(j, m) if(dp[i][j]) dp2[i-dp[i][j]+1][j-dp[i][j]+1] = dp[i][j];
	int maxi = 0;
	pi best = mp(-1, -1);
	R0F(i, n){
		R0F(j, m){
			if(ckmax(maxi, dp2[i][j])){
				best = mp(i, j);
			}
			owo[i] = best;
		}
	}
	maxi = 0;
	best = mp(-1, -1);
	R0F(j, m){
		R0F(i, n){
			if(ckmax(maxi, dp2[i][j])){
				best = mp(i, j);
			}
			uwu[j] = best;
		}
	}
	maxi = 0;
	pi besta, bestb;
	F0R(i, n){
		F0R(j, m){
			if(dp2[i][j] < 1) continue;
			int p = dp2[i][j]+1;
			if(owo[i+p].f == -1 && uwu[j+p].f == -1) continue;
			pi ewe;
			if(owo[i+p].f == -1) ewe = uwu[j+p];
			else if(uwu[j+p].f == -1) ewe = owo[i+p];
			else if(dp2[owo[i+p].f][owo[i+p].s] > dp2[uwu[j+p].f][uwu[j+p].s]) ewe = owo[i+p];
			else ewe = uwu[j+p];
			if(ckmax(maxi, dp2[i][j]*dp2[i][j]+dp2[ewe.f][ewe.s]*dp2[ewe.f][ewe.s])) besta = mp(i, j), bestb = ewe;
		}
	}
	cout << besta.f << " " << besta.s << " " << dp2[besta.f][besta.s] << "\n";
	cout << bestb.f << " " << bestb.s << " " << dp2[bestb.f][bestb.s] << "\n";
}

