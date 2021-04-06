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
const int MX = 805;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

string a[MX];
int x, y, sx, sy;
int dist[MX][MX];
int distM[MX][MX];
bool vis[MX][MX];
int n, s;

void bfs(){
	queue<pi> q;
	F0R(i, n){
		F0R(j, n){
			dist[i][j] = inf;
			if(a[i][j] == 'H'){
				dist[i][j] = 0;
				vis[i][j] = 1;
				q.push(mp(i, j));
			}
		}
	}
	while(sz(q)){
		auto u = q.front(); q.pop();
		F0R(k, 4){
			int xx = u.f+dx[k], yy = u.s+dy[k];
			if(valid(xx, yy, n, n) && !vis[xx][yy] && (a[xx][yy] == 'G' || a[xx][yy] == 'M')){
				dist[xx][yy] = dist[u.f][u.s]+1;
				vis[xx][yy] = 1;
				q.push(mp(xx, yy));
			}
		}
	}
}

bool bee[MX][MX];

bool can(int m){
	F0R(i, n) F0R(j, n) vis[i][j] = 0;
	vis[x][y] = 1;
	queue<pi> q;
	q.push(mp(x, y));
	if(dist[x][y]-m <= 0) return 0;
	while(sz(q)){
		auto u = q.front(); q.pop();
		F0R(k, 4){
			int xx = u.f+dx[k], yy = u.s+dy[k];
			if(valid(xx, yy, n, n) && !vis[xx][yy] && (a[xx][yy] == 'G' || a[xx][yy] == 'D') && (distM[u.f][u.s]+1)/s < dist[xx][yy]-m){
				distM[xx][yy] = distM[u.f][u.s]+1;
				vis[xx][yy] = 1;
				q.push(mp(xx, yy));
			}
		}
	}
	return vis[sx][sy];
}

int main(){
	NACHO();
	cin >> n >> s;
	F0R(i, n){
		cin >> a[i];
		F0R(j, n){
			if(a[i][j] == 'M') x = i, y = j;
			if(a[i][j] == 'D') sx = i, sy = j;
		}
	}
	bfs();
	int low = 0, high = MX*MX+5;
	if(!can(0)){
		cout << -1 << "\n";
		return 0;
	}
	while(high-low > 1){
		int mid = low+(high-low)/2;
		if(can(mid)) low = mid;
		else high = mid;
	}
	cout << low << "\n";
}
