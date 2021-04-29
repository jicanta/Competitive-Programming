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
const int mod = 998244353;
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

int main(){
	NACHO();
	// en vez de buscar minimizar las que cambiamos,
	// busquemos maximizar las que no cambiamos.
	// sean a_i1, a_i2, ..., a_ik los palos que no recorto.
	// claramente, a_ij <= M*ij
	// y ademas a_ij+1 <= a_ij+M*(ij+1-ij)
	// de esto sale a_i1 <= M*i1 ---> 0 <= M*i1-ai1
	// si sumamos, M*ij, 
	// M*ij+a_ij+1 <= a_ij+M*(ij+1-ij)+M*(ij)
	// M*ij-aij <= M*ij+1-a_ij+1
	// sea bi = M*i-ai
	// sigue que 0 <= bi <= bi+1
	// queremos encontrar entonces la longest non decreasing subsequence.
	// tadaa
	int n, M; cin >> n >> M;
	vi b;
	F0R(i, n){
		int x; cin >> x;
		if(x <= M*(i+1)){
			b.pb(M*(i+1)-x);
		}
	}
	vi dp;
	F0R(i, sz(b)){
		int ind = upper_bound(all(dp), b[i])-dp.begin();
		if(ind == sz(dp)) dp.pb(b[i]);
		else dp[ind] = b[i];
	}
	cout << n-sz(dp) << "\n";
}

