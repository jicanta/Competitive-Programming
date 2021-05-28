#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
const int MX = 1e5+5;
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

int a[35][35];
unordered_map<int, int> dp;
int n;

int solve(int mask){
	if(__builtin_popcount(mask) == 4){
		int aa = __builtin_ctz(mask);
		mask ^= (1<<aa);
		int b = __builtin_ctz(mask);
		mask ^= (1<<b);
		int c = __builtin_ctz(mask);
		mask ^= (1<<c);
		int d = __builtin_ctz(mask);
		mask ^= (1<<d);
		return max(a[aa][b]+a[c][d], max(a[aa][c]+a[b][d], a[aa][d]+a[b][c]));
	}
	if(mask == 0) return 0;
	int *it = &dp[mask];
	if(*it) return *it;	 
	int ret = 0;
	int m = mask;
	int firstBit =  __builtin_ctz(m);
	m ^= (1<<firstBit);
	int otM = mask;
	otM ^= (1<<firstBit);
	while(otM){
		int curFirstBit = __builtin_ctz(otM);
		otM ^= (1<<curFirstBit);
		ckmax(ret, a[firstBit][curFirstBit]+solve(m^(1<<curFirstBit)));
	}
	return *it = ret;
}

int main(){
	NACHO();
	cin >> n;
	F0R(i, n) F0R(j, n) cin >> a[i][j];
	cout << solve((1<<n)-1) << "\n";
	//cout << __builtin_ctz(1) << endl;
}

