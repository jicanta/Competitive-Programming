#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define trav(a, x) for(auto& a : x)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
#define esta(x,c) ((c).find(x) != (c).end())
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int mod = 998244353;
const int MX = 255; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}

template<class T> bool valid(T x, T y, T n, T m){
    return (0<=x && x<n && 0<=y && y<m);
}

void NACHO(string name = "snowboots"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int dp[MX][MX];

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	vi a (n);
	vector<pi> b (m);
	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i].f >> b[i].s;
	
	forn(i, n) forn(j, m) dp[i][j] = inf;
	
	forn(i, m) dp[0][i] = i; //CASO BASE
	
	forsn(i, 1, n){
		forn(j, m){
			if(b[j].f < a[i]){
				dp[i][j] = inf;
				continue;
			}
			forn(k, j){
				dp[i][j] = min(dp[i][j], dp[i][k]+(j-k));
			}
			forn(k, b[j].s+1){
				if(i-k >= 0) dp[i][j] = min(dp[i][j], dp[i-k][j]);
			}
		}
	}
	
	int mini = inf;
	forn(j, m) mini = min(mini, dp[n-1][j]);
	cout << mini << "\n";
}
