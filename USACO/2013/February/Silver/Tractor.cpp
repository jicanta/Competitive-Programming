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
const int MX = 505;
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
 
void NACHO(string name = "tractor"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int a[MX][MX];
vector<pair<int,pi>> ed;
int maxComp = 0;

struct DSU{
	vi e; void init(int N) { e = vi(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y){
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; ckmax(maxComp, -e[x]);
		return 1;
	}
};

int main(){
	NACHO();
	int n; cin >> n;
	F0R(i, n) F0R(j, n) cin >> a[i][j];
	DSU D; D.init(n*n+n);
	F0R(i, n){
		F0R(j, n){
			F0R(k, 4){
				int x = i+dx[k], y = j+dy[k];
				if(valid(x, y, n, n)) ed.pb(mp(abs(a[i][j]-a[x][y]), mp(n*i+j, n*x+y)));
			}
		}
	}
	sort(all(ed));
	trav(u, ed){
		D.unite(u.s.f, u.s.s);
		if(maxComp >= n*n/2+(n&1)){
			cout << u.f << "\n";
			return 0;
		}
	}
}


