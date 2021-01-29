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

tint S[2505][2505];

tint query(int a, int b, int c, int d){
	return S[c][d]-S[a-1][d]-S[c][b-1]+S[a-1][b-1];
}

int main(){
	NACHO();
	int n; cin >> n;
	vpi a (n);
	F0R(i, n) cin >>a[i].f >> a[i].s;
	sort(all(a));
	F0R(i, n) a[i].f = i+1;
	sort(all(a), [&](const pi &a, const pi &b){
		return a.s < b.s;
	});
	F0R(i, n) a[i].s = i+1;
	F0R(i, n) S[a[i].f][a[i].s] = 1;
	FOR(i, 1, n+1){
		FOR(j, 1, n+1) S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
	}
	tint ret = 0;
	sort(all(a));
	F0R(i, n){
		FOR(j, i, n){
			ret += query(i+1, 1, j+1, min(a[i].s, a[j].s)) * query(i+1, max(a[i].s, a[j].s), j+1, n);
		}
	}
	cout << ret + 1 << "\n";
}
