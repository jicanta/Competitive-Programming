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
using vl = vector<tint>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
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
const int MX = 21;
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
 
void NACHO(string name = "guard"){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct Cow{
	int h, w, s;
};

int dp[1<<MX];

int main(){
	NACHO();
	int n, h; cin >> n >> h;
	vector<Cow> a(n);
	int ret = -1;
	F0R(i, 1<<n) dp[i] = -1;
	F0R(i, n) cin >> a[i].h >> a[i].w >> a[i].s;
	dp[0] = inf;
	F0R(m, 1<<n){
		int totH = 0;
		int totW = 0;
		F0R(i, n){
			if(m&(1<<i)) totH += a[i].h, totW += a[i].w;
		}
		F0R(i, n){
			if(m&(1<<i)){
				if(a[i].s < totW - a[i].w) continue;
				ckmax(dp[m], min(dp[m^(1<<i)], a[i].s - (totW - a[i].w)));
			}
		}
		if(totH >= h){
			ckmax(ret, dp[m]);
		}
	}
	if(ret == -1){
		cout << "Mark is too tall" << "\n";
	}else{
		cout << ret << "\n";
	}
}

