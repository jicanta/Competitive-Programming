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
const int mod = 998244353;
const int MX = 505;
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
 
void NACHO(string name = "cownomics"){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

string a[MX], b[MX];
const int P = 9973, M = 1e9+9;
tint pw[MX];
tint hsh[2*MX][MX];

void calc_hash(string& a, int id){
	hsh[id][0] = 1;
	FOR(i, 1, sz(a)+1){
		hsh[id][i] = ((hsh[id][i-1]*P) % M + a[i-1]) % M;
	}
}

tint get_hash(int id, int l, int r){
	return (hsh[id][r+1]-pw[r-l+1]*hsh[id][l] % M + M) % M;
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	pw[0] = 1;
	FOR(i, 1, m+1) pw[i] = pw[i-1]*P%M;
	F0R(i, n) cin >> a[i];
	F0R(i, n) cin >> b[i];
	F0R(i, n) calc_hash(a[i], i);
	F0R(i, n) calc_hash(b[i], i+n);
	int low = 0, high = m;
	while(high-low > 1){
		int mid = low+(high-low)/2;
		bool okk = 0;
		F0R(i, m-mid){
			set<tint> hshB;
			F0R(k, n){
				hshB.ins(get_hash(k+n, i, i+mid));
			}
			bool ok = 1;
			F0R(k, n){
				if(hshB.count(get_hash(k, i, i+mid))) ok = 0;
			}
			if(ok) okk = 1;
		}
		if(okk) high = mid;
		else low = mid;
	}
	cout << high+1 << "\n";
}
 

