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
 
const int MOD = 1e9+9; //change this
const tint mod = 998244353;
const int MX = 2e5+5;
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
 
void NACHO(string name = "superbull"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vector<pair<tint, pi>> ed;
int a[MX];

struct DSU{
	vi e; void init(int N){ e = vi(N, -1); }
	int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool unite(int a, int b){
		a = get(a), b = get(b);
		if(a == b) return 0;
		if(e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a; return 1;
	}
};

int main(){
	NACHO();
	int n; cin >> n;
	F0R(i, n) cin >> a[i];
	F0R(i, n){
		FOR(j, i+1, n){
			ed.pb(mp(a[i]^a[j], mp(i, j)));
		}
	}
	sort(rall(ed));
	tint ans = 0;
	DSU D; D.init(n);
	F0R(i, sz(ed)){
		int c = ed[i].f, u = ed[i].s.f, v = ed[i].s.s;
		if(D.unite(u, v)) ans += c;
	}
	cout << ans << "\n";
}

