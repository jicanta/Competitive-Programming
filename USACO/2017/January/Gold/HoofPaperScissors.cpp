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
 
const int MOD = 1000000; 
const int mod = 998244353;
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
 
void NACHO(string name = "hps"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int get(char a){
	if(a == 'H') return 0;
	else if(a == 'P') return 1;
	else return 2;
}

char win(char a){
	if(a == 'H') return 'S';
	else if(a == 'S') return 'P';
	else return 'H';
}

int dp[MX][25][3];
// maximo si jugue hasta el i, cambie j veces, y estoy jugando con el k
char a[MX];

int main(){
	NACHO();
	int n, K;; cin >> n >> K;
	F0R(i, n) cin >> a[i];
	FOR(i, 1, n+1){
		F0R(j, K+1){
			F0R(k, 3){
				// comienzo una jugada nueva
				if(j >= 0){
					F0R(p, 3){
						if(p == k) continue;
						ckmax(dp[i][j][k], dp[i-1][j-1][p]+(get(win(a[i-1])) == k));
					}
				}
				// lo anexo a jugadas previas
				ckmax(dp[i][j][k], dp[i-1][j][k]+(get(win(a[i-1])) == k));
			}
		}
	}
	int ret = 0;
	F0R(j, K+1){
		F0R(k, 3) ckmax(ret, dp[n][j][k]);
	}
	cout << ret << "\n";
}


