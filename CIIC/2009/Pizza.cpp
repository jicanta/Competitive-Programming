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
const int MX = 2e5+5;
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

struct SegTree{
	int size;
	vpl st;
	
	pl merge(pl a, pl b){
		if(a.f < b.f) return a;
		else return b;
	}
	
	void init(int n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		st.assign(2*size, mp(2*inf, 2*inf));
	}
	
	void build(int node, int tl, int tr, vi& a){
		if(tr-tl == 1){
			if(tl < sz(a)) st[node] = mp(a[tl], tl);
			return;
		}
		int tm = (tl+tr)/2;
		build(2*node+1, tl, tm, a);
		build(2*node+2, tm, tr, a);
		st[node] = merge(st[2*node+1], st[2*node+2]);
	}
	
	void build(vi& a) { build(0, 0, size, a); }
	
	pl query(int node, int tl, int tr, int l, int r){
		if(tl >= r || tr <= l) return mp(2*inf, 2*inf);
		if(l <= tl && tr <= r) return st[node];
		int tm = (tl+tr)/2;
		pi A = query(2*node+1, tl, tm, l, r);
		pi B = query(2*node+2, tm, tr, l, r);
		if(A.f < B.f) return A;
		else return B;
	}
	
	pl query(int l, int r) { return query(0, 0, size, l, r); }
	
	void update(int node, int tl, int tr, int pos, tint val){
		if(tr-tl == 1){
			st[node] = merge(st[node], mp(val, pos));
			return;
		}
		int tm = (tl+tr)/2;
		if(pos < tm) update(2*node+1, tl, tm, pos, val);
		else update(2*node+2, tm, tr, pos, val);
		st[node] = merge(st[2*node+1], st[2*node+2]);
	}
	
	void update(int pos, tint val) { update(0, 0, size, pos, val); }
	
};

int main(){
	NACHO();
	// sea X un punto de la pinta (X, 0)
	// para los puntos a la derecha de este punto, me conviene agarrar 
	// aquel que minimice su distancia a (0, 0).
	// para los puntos a su izquierda, me conviene agarrar
	// aquel que minimice su distancia a (inf, 0).
	// Entonces sale con ST.
	// Observacion clave: puede haber mas de una pizzeria en un punto XD
	// Podria aclararlo el problema...
	SegTree L, R;
	L.init(MX); R.init(MX);
	int q; cin >> q;
	F0R(owowowo, q){
		char t; cin >> t;
		if(t == 'I'){
			int x, y; cin >> x >> y;
			L.update(x, y+inf-x);
			R.update(x, x+y);
		}else{
			tint x; cin >> x;
			tint xL, yL;
			pl retL = L.query(0, x+1);	
			xL = retL.s;
			yL = retL.f-inf+xL;
			tint xR, yR;
			pl retR = R.query(x, 100001);	
			xR = retR.s;
			yR = retR.f-xR;
			cout << min(tint(abs(x-xL)+yL), tint(abs(x-xR)+yR)) << "\n";
			//cout << xL << " " << yL << " " << xR << " " << yR << endl;
		}
	}
}

