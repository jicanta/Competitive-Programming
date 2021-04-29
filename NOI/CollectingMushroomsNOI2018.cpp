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
const int MX = 5e5+5;
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
 
string a[MX];
vvi b;
int d;
int n, m;
 
void activate(int x, int y){
	int xUp = max(1, x-d);
	int yUp = max(1, y-d);
	int xDw = min(n, x+d);
	int yDw = min(m, y+d);
	++b[xUp][yUp]; 
	++b[xDw+1][yDw+1];
	--b[xUp][yDw+1];
	--b[xDw+1][yUp];
}
 
int main(){
	NACHO();
	int k; cin >> n >> m >> d >> k;
	b.rsz(n+2, vi(m+2, 0));
	F0R(i, n) cin >> a[i];
	F0R(i, n){
		F0R(j, m){
			if(a[i][j] == 'S') activate(i+1, j+1);
		}
	}
	FOR(i, 1, n+1){
		FOR(j, 1, m+1){
			b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];
		}
	}
	int ret = 0;
	FOR(i, 1, n+1){
		FOR(j, 1, m+1){
			if(a[i-1][j-1] == 'M' && b[i][j] >= k) ++ret;
		}
	}
	cout << ret << "\n";
}
/*
5 5 1 1
....M
.M...
..S..
.S...
...M.
*/
