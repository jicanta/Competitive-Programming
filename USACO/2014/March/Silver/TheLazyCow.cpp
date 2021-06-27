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
const int MX = 805;
const tint INF = 1e18; 
const int inf = 2e8;
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
 
void NACHO(string name = "lazy"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int a[MX][MX];
int a_rot[MX][MX];
int S[MX][MX];
bool occ[MX][MX];

int query(int a, int b, int c, int d){
    return S[c][d]-S[a-1][d]-S[c][b-1]+S[a-1][b-1];
}

int main(){
    NACHO();
    int n, k; cin >> n >> k;
    F0R(i, n) F0R(j, n) cin >> a[i][j];
    F0R(i, n) F0R(j, n) a_rot[i+j][n-i+j-1] = a[i][j], occ[i+j][n-i+j-1] = true;
    FOR(i, 1, 2*n+1){
        FOR(j, 1, 2*n+1){
            S[i][j] += S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a_rot[i-1][j-1];
        }
    }
    int ret = 0;
    FOR(i, 1, 2*n+1){
        FOR(j, 1, 2*n+1){
            if(!occ[i-1][j-1]) continue;
            ckmax(ret, query(max(0, i-k), max(0, j-k), min(2*n, i+k), min(2*n, j+k)));
        }
    }
    cout << ret << "\n";
}