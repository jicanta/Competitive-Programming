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
const int MX = 1e5+5; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "countcross"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

map<pair<pi, pi>, bool> bad;
bool visited[105][105];
int tab[105][105];
vi tams;
int cur;

void dfs(int x, int y, int n){
	visited[x][y] = 1;
	cur += (tab[x][y] == 1);
	F0R(k, 4){
		int xx = x+dx[k], yy = y+dy[k];
		if(valid(xx, yy, n, n) && !bad[mp(mp(x, y), mp(xx, yy))] && !visited[xx][yy]){
			dfs(xx, yy, n);
		}
 	}
}

int main(){
	NACHO();
	int n, k, r; cin >> n >> k >> r;
	F0R(i, r){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a, --b, --c, --d;
		bad[mp(mp(a, b), mp(c, d))] = 1;
		bad[mp(mp(c, d), mp(a, b))] = 1;
	}
	F0R(i, k){
		int x, y; cin >> x >> y;
		--x, --y;
		tab[x][y] = 1;
	}
	F0R(i, n){
		F0R(j, n){
			if(!visited[i][j]){
				cur = 0;
				dfs(i, j, n);
				tams.pb(cur);
			}
		}
	}
	int ret = 0;
	F0R(i, sz(tams)){
		FOR(j, i+1, sz(tams)){
			ret += tams[i] * tams[j];
		}
	}
	cout << ret << "\n";
}



