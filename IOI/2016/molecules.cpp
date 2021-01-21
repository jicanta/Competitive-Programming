#include <bits/stdc++.h>
#include "molecules.h"
 
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
const int MX = 1005; 
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
 
std::vector<int> find_subset(int l, int u, std::vector<int> w) {
	// mi intuicion me decia que si lo ordenabas, el subconjunto
	// siempre es un subarreglo
	// luego es solo hacer two pointers
	// Pd: perdi como 40 mins por no
	// leer que los indices eran 0-indexed QQ
	int n = sz(w);
	vpi a (n);
	F0R(i, n) a[i] = mp(w[i], i);
    sort(all(a));
	int L = -1, R = -1;
	int j = 0;
	tint sum = 0;
	F0R(i, n){
		while(j < n && sum+a[j].f <= u){
			sum += a[j].f;
			++j;
		}
		if(l <= sum && sum <= u){
			L = i, R = j-1;
		}
		sum -= a[i].f;
	}
	if(L == -1) return {};
	vi ret;
	FOR(i, L, R+1){
		ret.pb(a[i].s);
	}
	return ret;
}
