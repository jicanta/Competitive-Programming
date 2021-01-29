#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
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
const int MX = 1e5+2; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
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

int la[MX];

vi parent (MX);
vector<set<int>> c (MX);

void init(int n){
	F0R(i, n){
		parent[i] = i;
		c[i] = {i};
	}
}

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if(u != v){
		if(sz(c[u]) < sz(c[v])) swap(u, v);
		trav(a, c[v]) c[u].ins(a);
		parent[v] = u;
	}
}

int main(){
    NACHO();
	int n, k; cin >> n >> k;
	vi a (n);
	iota(all(a), 0);
	vpi o (k);
	init(n+1);
	F0R(i, n) la[i] = i;
	F0R(i, k){
		int l, r; cin >> l >> r;
		--l, --r;
		o[i] = mp(l, r);
		c[a[l]].ins(r);
		c[a[r]].ins(l);
		la[a[l]] = r;
		la[a[r]] = l;
		swap(a[l], a[r]);
	}
	F0R(i, n){
		unite(i, la[i]);
	}
	F0R(i, n){
		cout << sz(c[find(i)]) << "\n";
	}
}
