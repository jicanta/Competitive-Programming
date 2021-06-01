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
const int MX = 5e5+1;
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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Equation{
	tint val; int sgn;
	// si = s1*sgn+val
};

tint mini = -INF, maxi = INF;

void solve(Equation& a, Equation& b){
	if(a.sgn == 1){
		ckmin(maxi, (b.val-a.val)/2);
	}else{
		ckmax(mini, (a.val-b.val)/2);
	}
}

int main(){
	NACHO();
	// todos los elementos de s deben tener la misma paridad (ya que sino m tendria fracciones).
	// sean x, y, z tres elementos consecutivos de s.
	// (x+y)/2 = m1 y (y+z)/2 = m2
	// y = 2m2-z
	// (x+2m2-z)/2 = m1
	// x-z = 2m1-2m2
	// el primer elemento de s te determina todo
	// si escribo todo en funcion de a1,
	// queda a1, 2m1-a1, a1-2m1+2m2, 
	// en el ejemplo
	// s1 <= 4-s1 <= s1+6 <= 12-s1 bla bla
	// a su vez, el rango de loa s1 posibles es contiguo
	// por lo tanto, al resolver estas desigualdades acotamos s1 y obtenemos cuantas soluciones hay.
	int n; cin >> n;
	tint a, b; cin >> a >> b;
	tint prevv = a;
	tint prev = b;
	Equation A = {0, 1};
	Equation B = {2*a, -1};
	solve(A, B);
	F0R(i, n-2){
		tint x; cin >> x;
		Equation C;
		if(i & 1){
			C = {2*prev-2*prevv+A.val, -1};
			solve(B, C);
		}else{
			C = {2*prev-2*prevv+A.val, 1};
			solve(B, C);
		}
		A = B;
		B = C;
		prevv = prev;
		prev = x;
	}
	Equation C;
	if(n & 1){
		C = {2*prev-2*prevv+A.val, -1};
	}else C = {2*prev-2*prevv+A.val, 1};
	solve(B, C);
	if(maxi < mini) cout << 0 << "\n";
	else cout << maxi-mini+1 << "\n";
}


