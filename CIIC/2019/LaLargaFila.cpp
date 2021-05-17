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
 
const int MOD = 1000000; 
const int mod = 998244353;
const int MX = 500005;
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

map<string, int> id;
int a[105][105];
int pre[MX], suc[MX], h[MX];


int main(){
	NACHO();
	// operacion 3: vemos que si d > 30, la cuenta siempre da 0.
	// por eso, solo nos movemos a la derecha/izquierda a aquellos que esten a distancia hasta 30.
	// operacion 2 trivial
	// operacion 1: linked list
	// solo tenemos que cambiar el sucesor del predecesor de a, el predecesor del sucesor, el sucesor de a y el predecesor de a.
	// ta-daa
	int n, k, q; cin >> n >> k >> q;
	F0R(i, n){
		string S; int x;
		cin >> S >> x;
		--x;
		h[i] = x;
		id[S] = i;
	}
	suc[n-1] = -1;
	pre[0] = -1;
	F0R(i, n-1) suc[i] = i+1;
	FOR(i, 1, n) pre[i] = i-1;
	F0R(i, k) F0R(j, k) cin >> a[i][j];
	F0R(i, q){
		int t; cin >> t;
		if(t == 1){
			string a, b; cin >> a >> b;
			// c d a x j b
			// c d x j a b
			if(pre[id[a]] != -1) suc[pre[id[a]]] = suc[id[a]];
			if(suc[id[a]] != -1) pre[suc[id[a]]] = pre[id[a]];
			suc[pre[id[b]]] = id[a];
			pre[id[a]] = pre[id[b]];
			suc[id[a]] = id[b];
			pre[id[b]] = id[a];
		}else if(t == 2){
			string a; int x; cin >> a >> x;
			h[id[a]] = x-1;
		}else{
			int cont = 0;
			string p; cin >> p;
			int r = id[p];
			int cur = pre[r];
			tint ret = 0;
			while(cur != -1 && cont < 30){
				ret += a[h[cur]][h[r]]/(1<<cont);
				cur = pre[cur];
				++cont;
			}
			cont = 0;
			cur = suc[r];
			while(cur != -1 && cont < 30){
				ret += a[h[cur]][h[r]]/(1<<cont);
				cur = suc[cur];
				++cont;
			}
			cout << ret << "\n";
		}
	}
}


