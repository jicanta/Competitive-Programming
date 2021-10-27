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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } 
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } 
 
void NACHO(string name = "bphoto"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n;
tint B[MX], L[MX], R[MX];	

void upd(int pos, tint val){
	for(int i = pos; i <= n; i += i&(-i)) B[i] += val;
}

tint query(int pos){
	tint s = 0;
	for(int i = pos; i > 0; i -= i&(-i)) s += B[i];
	return s;
}

int main(){
    NACHO();
	cin >> n;
	++n;
	vi a(n-1);
	map<int, int> id;
	F0R(i, n-1) cin >> a[i];
	vi b = a;
	sort(all(b));
	trav(u, b) if(id.count(u) == 0) id[u] = sz(id) + 1;
	tint ret = 0;
	F0R(i, n-1){
		a[i] = id[a[i]];
		L[i] = query(n) - query(a[i]);
		upd(a[i], 1);
	}
	F0R(i, MX) B[i] = 0;
	R0F(i, n-1){
		R[i] = query(n) - query(a[i]);
		if(max(L[i], R[i]) > 2 * min(L[i], R[i])) ++ret;
		upd(a[i], 1);
	}
	cout << ret << "\n";
}


