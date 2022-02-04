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
using vs = vector<string>;
using vl = vector<tint>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
 
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
const int inf = 1e9;
const ld PI = acos(ld(-1)); 
const double eps = 1e-9;
 
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
 
pair<double, double> a[MX];
double ret[MX];
 
int main(){
	NACHO();
	int n; cin >> n;
	F0R(i, n) cin >> a[i].f >> a[i].s;
	// two balloons centered at (x1, r1) and (x2, r2)
	// touch if the distance between the centers equals
	// r1 + r2.
	// hence we have sqrt((x2-x1)^2+(r2-r1)^2) = r1+r2
	// (x2-x1)^2+(r2-r1)^2 = (r1+r2)^2
	// (x2-x1)^2 = 4r1r2
	// r2 = (x2-x1)^2/4r1
	// furthermore, if balloons (x1, r1) and (x2, r2)
	// have x1 < x2 and r1 < r2, then ballon 1 is useless
	// as ballon 2 will always limit us more.
	// therefore we mantain a stack with the property
	// that radius are non increasing. 
	stack<pair<int, double>> st;
	st.push(mp(a[0].f, a[0].s));
	ret[0] = a[0].s;
	FOR(i, 1, n){
		ret[i] = a[i].s;
		while(sz(st)){
			ckmin(ret[i], double((a[i].f - st.top().f) * (a[i].f - st.top().f) / (4 * st.top().s)));
			if(ret[i] >= st.top().s) st.pop();
			else break;
		}
		st.push(mp(a[i].f, ret[i]));
	}
	F0R(i, n){
		cout << fixed << setprecision(3) << ret[i] << "\n";
	}
}

