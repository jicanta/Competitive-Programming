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
const int MX = 101;
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
 
void NACHO(string name = "visitfj"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int a[MX][MX];
int dist[MX][MX][5];
bool vis[MX][MX][5];

struct Node{
	int x, y, d, m;
	bool operator<(const Node &o) const{ return d > o.d; }
};

int modi(int x){
	int y = x;
	++y;
	if(y == 4) y = 1;
	return y;
}

int main(){
    NACHO();
	int n, t; cin >> n >> t;
	F0R(i, n) F0R(j, n) cin >> a[i][j];
	priority_queue<Node> q;
	q.push({0, 0, 0, 0});
	F0R(i, n) F0R(j, n) F0R(k, 5) dist[i][j][k] = inf;
	dist[0][0][0] = 0;
	while(sz(q)){
		auto u = q.top();
		int x = u.x, y = u.y, m = u.m;
		q.pop();
		if(vis[x][y][m]) continue;
		vis[x][y][m] = 1;
		F0R(k, 4){
			int xx = x+dx[k], yy = y+dy[k];
			if(valid(xx, yy, n, n)){
				if(dist[x][y][m]+t+(m == 2 ? a[xx][yy] : 0) < dist[xx][yy][modi(m)]){
					dist[xx][yy][modi(m)] = dist[x][y][m]+t+(m == 2 ? a[xx][yy] : 0);
					q.push({xx, yy, dist[xx][yy][modi(m)], modi(m)});
				}
			}
		}
	}
	int ret = inf;
	FOR(k, 1, 4) ckmin(ret, dist[n-1][n-1][k]);
	cout << ret << "\n";
}


