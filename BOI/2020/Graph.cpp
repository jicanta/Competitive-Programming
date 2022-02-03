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
const int MX = 1e5+5;
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

vpi adj[MX];
pi eq[MX];
double val[MX];
bool solvedComp[MX];
bool possible = 1;
double x = inf;

double solveEq(pi a, pi b){
	// ax+b = cx+d
	// (a-c)x = d-b
	// x = (d-b)/(a-c)
	if(a.f - b.f == 0){
		return 0;
	}
	return double(double(b.s - a.s) / double(a.f - b.f));
}

vi curComp;

void dfs(int node, int pa){
	solvedComp[node] = 1;
	curComp.pb(node);
	trav(u, adj[node]){
		if(u.f == pa) continue;
		if(!solvedComp[u.f]){
			if(u.s == 1){
				eq[u.f] = mp(-eq[node].f, -eq[node].s + 1);
			}else{
				eq[u.f] = mp(-eq[node].f, -eq[node].s + 2);
			}
			dfs(u.f, node);
		}else{
			// linear equation has already been assigned.
			// we can now find val[neighbor].
			bool bothEqual = 0;
			double ret = inf;
			if(u.s == 1){
				pi cur =  mp(-eq[node].f, -eq[node].s + 1);
				if(eq[u.f].f == cur.f && eq[u.f].s == cur.s) bothEqual = 1;
				if(eq[u.f].f == cur.f && eq[u.f].s != cur.s) possible = 0;
				ret = solveEq(cur, eq[u.f]);
			}else{
				pi cur =  mp(-eq[node].f, -eq[node].s + 2);
				if(eq[u.f].f == cur.f && eq[u.f].s == cur.s) bothEqual = 1;
				if(eq[u.f].f == cur.f && eq[u.f].s != cur.s) possible = 0;
				ret = solveEq(cur, eq[u.f]);
			}
			if(!bothEqual) x = ret;
		}
	}
}

void solveComp(int node){
	curComp.clear();
	x = inf;
	eq[node] = mp(1, 0);
	dfs(node, -1);
	if(x != inf){
		// at least one node had more than one equation,
		// so we could calculate x.
		trav(u, curComp) val[u] = eq[u].f * x + eq[u].s;
	}else{
		// we must find x s.t
		// |ax+b|+|cx+d|+|ex+f|+... is minimized
		// as slopes can only be 1 or -1
		// this problem is esentially
		// find x which minimizes |a1-x|+|a2-x|+...
		// it is well known that x equals the median of a1, a2, ..., an
		vi slopes;
		trav(u, curComp) slopes.pb(-eq[u].f * eq[u].s);
		sort(all(slopes));
		if(sz(slopes) & 1) x = slopes[sz(slopes)/2];
		else x = (slopes[sz(slopes)/2] + slopes[sz(slopes)/2-1]) / 2;
		trav(u, curComp) val[u] = eq[u].f * x + eq[u].s;
	}
}

int main(){
	NACHO();
	// if we assume node 1 has a value x, 
	// then we can determine for other nodes
	// a linear equation which defines the value of this node.
	// eg. if 1 and 2 are connected with an edge of weight 2,
	// 1 will have x and 2 will have -x+2.
	// if any node has more than one equation, we can easily find x.
	// if not, we will have a bunch of linear equations
	// x+a1, -x+a2, -x+a3, x+a4, ...
	// (slopes can only be 1 or -1)
	// we must now find x such that 
	// |x+a1|+|-x+a2|+|-x+a3|+...
	// such x equals the median of a1, a2, ..., an.
	// (if the slope is -1, we actually consider ai, and if it's 1, -ai)
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v, c; cin >> u >> v >> c; 
		--u, --v;
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
	}
	F0R(i, n) val[i] = 3;
	F0R(i, n){
		if(!solvedComp[i]){
			solveComp(i);
		}
	}
	F0R(i, n){
		trav(u, adj[i]){
			if(fabs(val[i] + val[u.f] - u.s) >= eps) possible = 0;
		}
	}
	if(!possible) cout << "NO\n";
	else{
		cout << "YES\n";
		F0R(i, n){
			cout << fixed << setprecision(6) << val[i] << " ";
		}
		cout << "\n";
	}
}

