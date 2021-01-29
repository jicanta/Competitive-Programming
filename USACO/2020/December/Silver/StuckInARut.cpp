#include <bits/stdc++.h>

using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
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
const int mod = 998244353;
const int MX = 1005; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "lightson"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

struct cow{
	int x, y, id;
};

int main(){
	NACHO();
	int n; cin >> n;
	vector<cow> E, N;
	F0R(i, n){
		char a; int x, y;
		cin >> a >> x >> y;
		if(a == 'E'){
			E.pb({x, y, i});
		}else{
			N.pb({x, y, i});
		}
	}
	sort(all(E), [&](const cow &a, const cow &b){
		if(a.y == b.y) return a.x < b.x;
		return a.y < b.y;	
	});
	sort(all(N), [&](const cow &a, const cow &b){
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	vb fin (n, 0);
	vi ret (n, 0);
	F0R(i, sz(N)){
		F0R(j, sz(E)){
			cow a = N[i];
			cow b = E[j];
			if(fin[a.id] || fin[b.id]) continue; 
			// quiero ver si la a frena a la b
			int X = a.x, Y = b.y;
			if(b.x > X || a.y > Y) continue;
			if(Y-a.y < X-b.x){
				fin[b.id] = 1;
				ret[a.id] += ret[b.id] + 1;
			}else if(Y-a.y > X-b.x){
				fin[a.id] = 1;
				ret[b.id] += ret[a.id] + 1;
			}
		}
	}
	F0R(i, n) cout << ret[i] << "\n";
}
