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
 
void NACHO(string name = "cowmbat"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int a[30][30];
int dp[MX][30]; // minimo costo para pintas hasta el i poniendo 
				// la letra j en el i
int dpMin[MX];  // dado un i, nos dice cual es el minimo costo de
			    // pintar de forma correcta hasta el i
int SA[MX][30]; // nos dice el costo de pintar [0;i] de color j


int main(){
    NACHO();
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	F0R(i, m) F0R(j, m) cin >> a[i][j];
	F0R(k, m){
		F0R(i, m){
			F0R(j, m){
				ckmin(a[i][j], a[i][k]+a[k][j]);
			}
		}
	}
	F0R(j, m){
		FOR(i, 1, n+1){
			SA[i][j] = SA[i-1][j]+a[s[i-1]-'a'][j];
		}
	}
	F0R(i, n+1) F0R(j, m) dp[i][j] = inf;
	F0R(i, n+1) dpMin[i] = inf;
	dpMin[0] = 0;
	FOR(i, 1, n+1){
		F0R(j, m){
			// pinto este del mismo color que el anterior
			ckmin(dp[i][j], dp[i-1][j]+a[s[i-1]-'a'][j]);
			if(i >= k){
				// comienzo un streak en la posicion i-k
				ckmin(dp[i][j], dpMin[i-k]+SA[i][j]-SA[i-k][j]);
			}
			ckmin(dpMin[i], dp[i][j]);
		}
	}
	cout << dpMin[n] << "\n";
}


