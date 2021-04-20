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
 
void NACHO(string name = "radio"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

tint dp[MX][MX];
pl XA[MX], XB[MX];

tint d(pl a, pl b){
	return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	pl x, y; cin >> x.f >> x.s >> y.f >> y.s;
	string a, b; cin >> a >> b;
	F0R(i, n+1) F0R(j, m+1) dp[i][j] = inf;
	XA[0] = x; XB[0] = y;
	FOR(i, 1, n+1){
		int x = 0, y = 0;
		if(a[i-1] == 'N') ++y;
		else if(a[i-1] == 'S') --y;
		else if(a[i-1] == 'E') ++x;
		else --x;
		XA[i] = mp(XA[i-1].f+x, XA[i-1].s+y); 
	}
	FOR(i, 1, m+1){
		int x = 0, y = 0;
		if(b[i-1] == 'N') ++y;
		else if(b[i-1] == 'S') --y;
		else if(b[i-1] == 'E') ++x;
		else --x;
		XB[i] = mp(XB[i-1].f+x, XB[i-1].s+y); 
	}
	F0R(i, n+1){
		F0R(j, m+1){
			if(i == 0 && j == 0){
				dp[i][j] = 0;
			}else if(i == 0){
				dp[i][j] = dp[i][j-1]+d(x, XB[j]);
			}else if(j == 0){
				dp[i][j] = dp[i-1][j]+d(y, XA[i]);
			}else{
				ckmin(dp[i][j], dp[i-1][j]+d(XA[i], XB[j]));
				ckmin(dp[i][j], dp[i][j-1]+d(XA[i], XB[j]));
				ckmin(dp[i][j], dp[i-1][j-1]+d(XA[i], XB[j]));
			}
		}
	}
	cout << dp[n][m] << "\n";
}
