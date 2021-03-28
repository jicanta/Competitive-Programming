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
 
void NACHO(string name = "newbarn"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int depth[MX], anc[MX][18], comp[MX];
pi diam[MX];

int lca(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	R0F(i, 17){
		if((depth[a]-depth[b])&(1<<i)) a = anc[a][i];	
	}
	if(a == b) return a;
	R0F(i, 17){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i]; b = anc[b][i];
		}
	}
	return anc[a][0];
}

int dist(int a, int b){
	return depth[a]+depth[b]-2*depth[lca(a, b)];
}

int main(){
	NACHO();
	int n; cin >> n;
	int act = 0;
	int compAct = 0;
	F0R(i, n){
		char t; cin >> t;
		if(t == 'B'){
			++act;
			int x; cin >> x;
			if(x == -1){
				++compAct;
				comp[act] = compAct;
				diam[act] = mp(act, act);
				continue;
			}
			comp[act] = comp[x];
			depth[act] = depth[x]+1;
			anc[act][0] = x;
			FOR(i, 1, 17) anc[act][i] = anc[anc[act][i-1]][i-1];
			int d = dist(diam[comp[act]].f, diam[comp[act]].s);
			if(ckmax(d, dist(diam[comp[act]].f, act))) diam[comp[act]].s = act;
			if(ckmax(d, dist(act, diam[comp[act]].s))) diam[comp[act]].f = act;
		}else{
			int x; cin >> x;
			cout << max(dist(diam[comp[x]].f, x), dist(x, diam[comp[x]].s)) << "\n";
		}
	}
}

