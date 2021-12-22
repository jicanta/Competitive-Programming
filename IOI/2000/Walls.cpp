#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
using vvl = vector<vl>;
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
const int MX = 255;
const tint INF = 1e18; 
const int inf = 1e9;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int m, n, L;
int towns[MX], dist[MX][MX];
bool vis[MX][MX];
vi adj[MX];
vi regions[MX];
vi townRegions[MX];

int main(){
    NACHO();
	cin >> m >> n >> L;
	F0R(i, L) cin >> towns[i];
	F0R(i, m){
		int k; cin >> k;
		F0R(j, k){
			int x; cin >> x;
			regions[i].pb(x);
			townRegions[x].pb(i);
		}
		if(i == m-1) reverse(all(regions[i]));
	}
	F0R(i, m){
		FOR(j, i+1, m){
			F0R(k, sz(regions[i])){
				F0R(l, sz(regions[j])){
					bool share = (regions[i][k] == regions[j][l] && regions[i][(k+1)%sz(regions[i])] == regions[j][(l+1)%sz(regions[j])]);
					share |= (regions[i][(k+1)%sz(regions[i])] == regions[j][l] && regions[i][k] == regions[j][(l+1)%sz(regions[j])]);
					if(share){
						adj[i].pb(j);
						adj[j].pb(i);
					}
				}
			}
		}
	}
	F0R(i, m){
		queue<int> q;
		vis[i][i] = 1;
		dist[i][i] = 0;
		q.push(i);
		while(sz(q)){
			auto u = q.front(); q.pop();
			trav(v, adj[u]){
				if(!vis[i][v]){
					vis[i][v] = 1;
					dist[i][v] = dist[i][u] + 1;
					q.push(v);
				}
			}
		}
	}
	int ret = inf, bestRegion;
	F0R(i, m){
		int tot = 0;
		F0R(assa, L){
			int u = towns[assa];
			int minDist = inf;
			trav(v, townRegions[u]){
				ckmin(minDist, dist[i][v]);
			}
			tot += minDist;
		}
		if(ckmin(ret, tot)) bestRegion = i+1;
	}
	cout << ret << "\n";
	cout << bestRegion << "\n";
}
