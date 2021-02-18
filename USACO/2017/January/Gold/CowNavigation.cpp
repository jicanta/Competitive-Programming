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
const int MX = 25;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[5] = {1, -1, 0, 0, 0};
const int dy[5] = {0, 0, 1, -1, 0};
 
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
 
void NACHO(string name = "cownav"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct state{
	int xa, ya, xb, yb, da, db;
	// xa -> X pos cow facing right
	// xb -> X pos cow facing up
	// da -> direction cow facing right
	// db -> directon cow facing up
	// 0 -> down
	// 1 -> up
	// 2 -> right
	// 3 -> left
};

string a[MX];
bool vis[MX][MX][MX][MX][6][6];
int dist[MX][MX][MX][MX][6][6];
queue<state> q;

int getR(int dir){
	if(dir == 0) return 3;
	else if(dir == 1) return 2;
	else if(dir == 2) return 0;
	else return 1;
}

int getL(int dir){
	if(dir == 0) return 2;
	else if(dir == 1) return 3;
	else if(dir == 2) return 1;
	else return 0;
}

int main(){
	NACHO();
	int n; cin >> n;
	F0R(i, n) cin >> a[i];
	q.push({n-1, 0, n-1, 0, 1, 2});
	vis[n-1][0][n-1][0][1][2] = 1;
	while(sz(q)){
		auto u = q.front();
		q.pop();
		int xa = u.xa, ya = u.ya, xb = u.xb, yb = u.yb, da = u.da, db = u.db;
		bool reachA = (xa == 0 && ya == n-1), reachB = (xb == 0 && yb == n-1); 
		// move forward
		int na = da, nb = db;
		if(reachA || !valid(xa+dx[na], ya+dy[na], n, n) || a[xa+dx[na]][ya+dy[na]] != 'E') na = 4;
		if(reachB || !valid(xb+dx[nb], yb+dy[nb], n, n) || a[xb+dx[nb]][yb+dy[nb]] != 'E') nb = 4;
		if(!vis[xa+dx[na]][ya+dy[na]][xb+dx[nb]][yb+dy[nb]][(na == 4 ? da : na)][(nb == 4 ? db : nb)]){
			dist[xa+dx[na]][ya+dy[na]][xb+dx[nb]][yb+dy[nb]][(na == 4 ? da : na)][(nb == 4 ? db : nb)] = dist[xa][ya][xb][yb][da][db]+1;
			vis[xa+dx[na]][ya+dy[na]][xb+dx[nb]][yb+dy[nb]][(na == 4 ? da : na)][(nb == 4 ? db : nb)] = 1;
			q.push({xa+dx[na], ya+dy[na], xb+dx[nb], yb+dy[nb], (na == 4 ? da : na), (nb == 4 ? db : nb)});
		}
		
		// move right
		na = getR(da), nb = getR(db);
		if(!vis[xa][ya][xb][yb][na][nb]){
			dist[xa][ya][xb][yb][na][nb]= dist[xa][ya][xb][yb][da][db]+1;
			vis[xa][ya][xb][yb][na][nb] = 1;
			q.push({xa, ya, xb, yb, na, nb});
		}
		// move left
		na = getL(da), nb = getL(db);
		if(!vis[xa][ya][xb][yb][na][nb]){
			dist[xa][ya][xb][yb][na][nb] = dist[xa][ya][xb][yb][da][db]+1;
			vis[xa][ya][xb][yb][na][nb] = 1;
			q.push({xa, ya, xb, yb, na, nb});
		}
	}
	int mini = inf;
	F0R(i, 5) F0R(j, 5) if(vis[0][n-1][0][n-1][i][j]) ckmin(mini, dist[0][n-1][0][n-1][i][j]);
	cout << mini << "\n";
}


