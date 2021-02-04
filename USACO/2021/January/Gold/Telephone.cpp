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
const int MX = 5e4;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int a[MX];
string b[60];
int w[60][60];
int last[60];
vpi adj[MX];

int main(){
	NACHO();
	int n, k; cin >> n >> k;
	F0R(i, n) cin >> a[i];
	F0R(i, k) cin >> b[i];
	F0R(i, k) F0R(j, k) w[i][j] = inf;
	F0R(i, n){
		F0R(j, k){
			if(b[a[i]-1][j] == '1' && last[j] != -1) adj[i].pb(mp(last[j], i-last[j]));
		}
		last[a[i]-1] = i;
	}
	F0R(i, k) last[i] = -1;
	R0F(i, n){
		F0R(j, k){
			if(b[a[i]-1][j] == '1' && last[j] != -1) adj[i].pb(mp(last[j], last[j]-i));
			if(b[a[i]-1][j] == '1' && j == a[n-1]-1) adj[i].pb(mp(n-1, n-1-i));
		}
		last[a[i]-1] = i;
	}
	vb visited (n, 0);
	vi dist (n, inf);
	priority_queue<pi> q;
	dist[0] = 0;
	q.push(mp(0, 0));
	while(sz(q)){
		auto s = q.top().s;
		q.pop();
		if(visited[s]) continue;
		visited[s] = 1;
		trav(u, adj[s]){
			if(dist[s]+u.s < dist[u.f]){
				dist[u.f] = dist[s]+u.s;
				q.push(mp(-dist[u.f], u.f));
			}
		}
	}
	if(dist[n-1] == inf) cout << -1 << "\n";
	else cout << dist[n-1] << "\n";
}

