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
const int MX = 55;
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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "island"){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

char a[MX][MX];
int id[MX][MX], dist[MX][MX], dp[1<<15][MX];
bool vis[MX][MX], seenId[MX];
int n, m;

void dfs(int x, int y, int curId){
	vis[x][y] = 1;
	id[x][y] = curId;
	F0R(k, 4){
		int xx = x + dx[k], yy = y + dy[k];
		if(valid(xx, yy, n, m) && !vis[xx][yy] && a[xx][yy] == 'X'){
			dfs(xx, yy, curId);
		}
	}
}

int main(){
	NACHO();
	cin >> n >> m;
	F0R(i, n) F0R(j, m) cin >> a[i][j];
	int cur = 0;
	F0R(i, 16) F0R(j, 16) dist[i][j] = inf;
	F0R(i, n){
		F0R(j, m){
			if(a[i][j] == 'X' && !vis[i][j]){
				dfs(i, j, cur++);
			}
		}
	}
	F0R(i, n){
		F0R(j, m){
			if(a[i][j] == 'X' && !seenId[id[i][j]]){
				seenId[id[i][j]] = 1;
				dist[id[i][j]][id[i][j]] = 0;
				deque<pi> q;
				q.pb(mp(i, j));
				vvb v (n, vb(m, 0));
				v[i][j] = 1;
				vvi d (n, vi(m, 0));
				while(sz(q)){
					auto u = q.front(); q.pop_front();
					int x = u.f, y = u.s;
					F0R(k, 4){
						int xx = x + dx[k], yy = y + dy[k];
						if(valid(xx, yy, n, m) && !v[xx][yy] && a[xx][yy] != '.'){
							v[xx][yy] = 1;
							if(a[xx][yy] == 'X'){
								d[xx][yy] = d[x][y];
								q.push_front(mp(xx, yy));
								ckmin(dist[id[i][j]][id[xx][yy]], d[xx][yy]);
								ckmin(dist[id[xx][yy]][id[i][j]], d[xx][yy]);
							}else if(a[xx][yy] == 'S'){
								d[xx][yy] = d[x][y] + 1;
								q.pb(mp(xx, yy));
							}
						}
					}
				}
			}
		}
	}
	F0R(ma, 1<<cur) F0R(i, cur) dp[ma][i] = inf;
	F0R(i, cur) dp[1<<i][i] = 0;
	F0R(ma, 1<<cur){
		F0R(i, cur){
			if(ma&(1<<i)){
				F0R(j, cur){
					if(ma&(1<<j)){
						ckmin(dp[ma][j], dp[ma^(1<<j)][i] + dist[i][j]);
					}
				}
			}
		}
	}
	int mini = inf;
	F0R(i, cur) ckmin(mini, dp[(1<<(cur))-1][i]);
	cout << mini << "\n";
}

