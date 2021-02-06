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
const int MX = 505;
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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = "gravity"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

string a[MX];
int dist[MX][MX][2];
pi pa[MX][MX][2];

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	F0R(i, n) cin >> a[i];
	int sx, sy, ex, ey;
	F0R(i, n){
		F0R(j, m){
			if(a[i][j] == 'C') sx = i, sy = j;
			if(a[i][j] == 'D') ex = i, ey = j;
		}
	}
	deque<pair<pi, int>> q;
	q.pf(mp(mp(sx, sy), 0));
	F0R(i, n){
		F0R(j, m) dist[i][j][0] = inf, dist[i][j][1] = inf;
	}
	dist[sx][sy][0] = 0;
	while(sz(q)){
		auto u = q.front(); q.pop_front();
		int x = u.f.f, y = u.f.s, g = u.s;		
		if(g == 0){
			bool ok = 1;
			if(x+1 < n && a[x+1][y] != '#'){
				ok = 0;
				if(dist[x][y][0] < dist[x+1][y][0]){
					dist[x+1][y][0] =  dist[x][y][0];
					q.pf(mp(mp(x+1, y), 0));
				}
			}else if(x != n-1 && ok){
				if(y-1 >= 0 && a[x][y-1] != '#' && dist[x][y][0] < dist[x][y-1][0]){
					dist[x][y-1][0] = dist[x][y][0];
					q.pf(mp(mp(x, y-1), 0));
				}
				if(y+1 < m && a[x][y+1] != '#' && dist[x][y][0] < dist[x][y+1][0]){
					dist[x][y+1][0] = dist[x][y][0];
					q.pf(mp(mp(x, y+1), 0));
				}
				if(x-1 >= 0 && a[x-1][y] != '#' && dist[x][y][0]+1 < dist[x-1][y][1]){
					dist[x-1][y][1] = dist[x][y][0]+1;
					q.pb(mp(mp(x-1, y), 1));
				}
			}
		}else{
			bool ok = 1;
			if(x-1 >= 0 && a[x-1][y] != '#'){
				ok = 0;
				if(dist[x][y][1] < dist[x-1][y][1]){
					dist[x-1][y][1] = dist[x][y][1];
					q.pf(mp(mp(x-1, y), 1));
				}
			}else if(x != 0 && ok){
				if(y-1 >= 0 && a[x][y-1] != '#' && dist[x][y][1] < dist[x][y-1][1]){
					dist[x][y-1][1] = dist[x][y][1];
					q.pf(mp(mp(x, y-1), 1));
				}
				if(y+1 < m && a[x][y+1] != '#' && dist[x][y][1] < dist[x][y+1][1]){
					dist[x][y+1][1] = dist[x][y][1];
					q.pf(mp(mp(x, y+1), 1));
				}
				if(x+1 < n && a[x+1][y] != '#' && dist[x][y][1]+1 < dist[x+1][y][0]){
					dist[x+1][y][0] = dist[x][y][1]+1;
					q.pb(mp(mp(x+1, y), 0));
				}
			}
		}
	}
	if(min(dist[ex][ey][0], dist[ex][ey][1]) == inf) dist[ex][ey][0] = -1;
	cout << min(dist[ex][ey][0], dist[ex][ey][1]) << "\n";
}



