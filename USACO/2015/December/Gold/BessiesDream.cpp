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
const int MX = 1001;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
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
 
tint cdiv(tint a, tint b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
tint fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "dream"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct state{
	int x, y, dir;
	bool orange, slide;
};

int n, m;
int a[MX][MX];
bool vis[MX][MX][4][2][2];
int dist[MX][MX][4][2][2];
queue<state> q;

int main(){
	NACHO();
	cin >> n >> m;
	F0R(i, n) F0R(j, m) cin >> a[i][j];
	q.push({0, 0, 0, 0, 0});
	while(sz(q)){
		auto u = q.front();
		q.pop();
		int x = u.x, y = u.y, dir = u.dir;
		int xx = x, yy = y;
		bool orange = u.orange;
		bool slide = u.slide;
		if(slide){
			xx += dx[dir], yy += dy[dir];
			bool block = 0;
			bool fl = 1;
			if(valid(xx, yy, n, m)){
				fl = 0;
				if(a[xx][yy] == 3 || a[xx][yy] == 0){ block = 1; goto en; }
				if(a[xx][yy] == 4 && !vis[xx][yy][dir][0][1]){
					vis[xx][yy][dir][0][1] = 1;
					dist[xx][yy][dir][0][1] = dist[x][y][dir][0][1]+1;
					q.push({xx, yy, dir, 0, 1});
				}else if(!vis[xx][yy][dir][a[xx][yy] == 2][0]){
					vis[xx][yy][dir][a[xx][yy] == 2][0] = 1;
					dist[xx][yy][dir][a[xx][yy] == 2][0] = dist[x][y][dir][0][1]+1;
					q.push({xx, yy, dir, a[xx][yy] == 2, 0});
				}
			}
			en:;
			if(block || fl){
				F0R(k, 4){
					int xxx = x+dx[k], yyy = y+dy[k];
					if(valid(xxx, yyy, n, m) && !vis[xxx][yyy][k][((a[xxx][yyy] == 2))][a[xxx][yyy] == 4] && a[xxx][yyy] != 0 && a[xxx][yyy] != 3){
						vis[xxx][yyy][k][(a[xxx][yyy] == 2)][a[xxx][yyy] == 4] = 1;
						dist[xxx][yyy][k][(a[xxx][yyy] == 2)][a[xxx][yyy] == 4] = dist[x][y][dir][0][1]+1;
						q.push({xxx, yyy, k, (a[xxx][yyy] == 2), a[xxx][yyy] == 4});
					}
				}
			}
		}else{
			F0R(k, 4){
				xx = x+dx[k], yy = y+dy[k];
				if(valid(xx, yy, n, m) && !vis[xx][yy][k][(a[xx][yy] != 4 && (a[xx][yy] == 2 || orange))][a[xx][yy] == 4] && a[xx][yy] != 0){
					if(a[xx][yy] == 3 && !orange) continue;
					vis[xx][yy][k][(a[xx][yy] != 4 && (a[xx][yy] == 2 || orange))][a[xx][yy] == 4] = 1;
					dist[xx][yy][k][(a[xx][yy] != 4 && (a[xx][yy] == 2 || orange))][a[xx][yy] == 4] = dist[x][y][dir][orange][0]+1;
					q.push({xx, yy, k, a[xx][yy] != 4 && (a[xx][yy] == 2 || orange), a[xx][yy] == 4});
				}
			}
		}
	}
	int mini = inf;
	F0R(k, 4){
		if(vis[n-1][m-1][k][0][0]) ckmin(mini, dist[n-1][m-1][k][0][0]);
		if(vis[n-1][m-1][k][1][0]) ckmin(mini, dist[n-1][m-1][k][1][0]);
		if(vis[n-1][m-1][k][0][1]) ckmin(mini, dist[n-1][m-1][k][0][1]);
		if(vis[n-1][m-1][k][1][1]) ckmin(mini, dist[n-1][m-1][k][1][1]);
	}
	if(mini == inf) mini = -1;
	cout << mini << "\n";
}


